# Game Turn-Based Strategy

## Цель игры

Вы появляетесь на карте, у вас под контролем замок и казарма. Юниты в них будут увеличиваться каждые 7 ходов. Ваша цель - победить врага. Где-то на карте спрятано сокровище, получив которое вы увеличите атаку своих юнитов. Победа достигается тогда, когда вы побеждаете своего врага. Поражение тогда, когда проигрываете ему или у вас с ним ничья. Управление с помощью консоли, перемещение по карте так же возможно с помощью символов "w", "a", "s", "d".

## Игровая модель.

Игра представляет собой стратегию. В самом начале мы можем выбрать сторону в конфликте: 
1. эльфы
2. гномы
3. люди

У каждой фракции есть свои города, где можно нанимать юнитов, которые будут появляться каждые 7 ходов.

## Юниты.

Создается 3 виртуальных класса: Army_of_men, Army_of_dwarves, Army_of_elves. У каждого класса уже заданы стандартные методы:
1. info - юнит говорит к какой фракции и к какому виду войск он относится;
2. attack — юнит говорит, что начинает ближний/дальний бой;
3. deffed — юнит говорит, что защищается;
4. getStrength - юнит возвращает свою силу.

От каждого класса будут наследоваться виды войск: пехота, лучники, конница.

## Архитектура. 
При старте Игры создается конкретная фабрика (в зависимости от выбранной фракции), которая по специализации юнита (пехотинец, лучник/арбалетчик, конница) создает требуемый объект. 

В начале игры буде доступна небольшая (базовая армия) с константным числом юнитов. (К примеру, 10 пехотинцев, 10 лучников, 5 конницы). Это создастся автоматически при помощи фабрики. 

В коде реализована фабрика и строитель. 

## Строитель.
Есть класс Army, в котором в public будут храниться векторы со всеми войсками всех фракций и метод void. 

Есть класс Army_builder в котором есть методы по постройке каждого юнита всех фракций с определенным числом.

От него наследуется классы:
1. Men_army_builder;
2. Dwarves_army_builder;
3. Elfs_army_builder.

В них описываются методы по созданию юнитов принадлежащих определенной фракции. То есть, к примеру, для фракции "Люди" будут описаны только методы по созданию юнитов фракции "Люди".
Создается класс-распределитель - Director, в котором есть метод crateArmy(). В него передается ссылка на то, какой фракции он должен создавать юнитов, например, Men_army_builder, так же передаются целочисленные позиционные аргументы, которые будут показывать сколько и чего он должен создать. К примеру, `Army *elfs_army = dir.createArmy(elfs_builder, 15, 10, 5)`;
создаст для армии эльфов 15 единиц пехоты, 10 единиц лучников, 5 единиц конницы. 
Таким образом, строитель можно использовать для найма юнитов в городах. То есть, в городе можно нанять 30 пехоты людей, но мы хотим нанять только 20, мы указываем для кого, и сколько мы хотим получить юнитов. То есть мы можем получить сразу несколько видов юнитов за раз, что позволяет использовать это именно для общего найма юнитов в городах.

## Фабрика

Для каждой фракции создается фабрика. Она не знает сколько и каких объектов мы можем создать. От нее наследуются классы в которых описывается метод по созданию определенного юнита данной фракции. 
Таким образом, достаточно указать какой юнит нам необходим и мы получим его. Можно использовать при создании одного юнита или армии юнитов одной фракции.

## Что и где использовать?

И фабрику и строитель можно использовать для создания юнитов, но строитель удобнее использовать в том случае, если мы хотим получить смешанную армию, состоящую к примеру из юнитов расы людей и эльфов. А фабрику лучше использовать в том случае, если хотим создать армию юнитов внутри одной фракции.
В плане реализации различие будет в том, что строитель вернет сразу несколько юнитов, которые будут храниться в соответствующих векторах, а фабрика вернет только одного юнита, и чтобы его не "потерять" нужно самому создавать хранилище этих юнитов.

## Компоновщик

Можно найти в файле composite_unit.hpp. Может использоваться для получения суммарной атаки армии, в будущем, возможно для суммарной защиты армии, но последнего в этой реализации нет. 

## Адаптер

В данной сборке не представлен адаптер, так как архитектура игры является довольно простой и смысла в его добавлении я не вижу. В будущем, если архитектура игры будет усложнена, его можно будет использовать для совмещения работы компоновщика и 2-х функций, которые будут описаны дальше.

## tools_for_army.hpp

В этом хедере реализованы функции объединения войск(пехота объединяется с пехотой и тд.), на данном этапе я отдаю большее предпочтение именно ей, нежели "компоновщику", и функция битвы одной армии с другой армией, где победитель тот, у кого сила армии больше, соответственно сохраняется его армия, но с определёнными потерями.

## Прокси/декоратор

Декоратор. Он нужен, чтобы расширить функционал какого-нибудь класса и тд, но на данный момент все расширение легко производится с помощью незначительной оптимизации архитектуры.
Прокси. Нет смысла вводить дополнительный уровень косвенности, он не улучшит, не ухудшит код, просто будет занимать место, доступ ко всем объектам прямой и никакие условия на доступ к ним не нужны.

## Тесты для описанного функционала

В файлах `test_factory_and_building.cpp`, `test_composite.cpp` и `test_tools_for_army.cpp` находятся набор тестов, который показывает работоспособность каждого класса. 

При запуске игры мы попадаем в меню, где можем начать игру или изменить сложность игры.

## Strategy

В игре есть 3 сложности, которые выбираются в самом начале игры. Происходит это с помощью этого паттерна. Создан класс Change_complexity с виртуальным методом change_complexity, наследуются 3 класса: Complexity_1, Complexity_2 и Complexity_3. В них реализована процедура изменения сложности игры. Изменяются значение сложности и бонус сокровища. Все значения берутся из соответствующих файлов. Код с этим находится в файле change_complexity. Наследуемые методы создаются в классе самой игры.

Далее начинается игра, выбирается раса (люди, эльфы, гномы), вводится имя. Далее представляется карта и игровая панель. Реализовано перемещение по карте, взаимодействие с предметами (сокровищем/ замком / казармой) происходит только в том случае, если вы стоите на той же клетке, где и располагается предмет. При взаимодействии с сокровищем вы его берете и характеристики вашего героя увеличиваются. При взаимодействии с замком или казармой показывается гарнизон этих зданий и предлагается перераспределить их в свою армию. Переносится всё войско, делить на части его нельзя.

Перемещение по карте требует 1 ход. Каждые 7 ходов население в замках/ казармах увеличивается на константу. Увеличение происходит с помощью паттерна "Observer".

## Observer

Используется для того, чтобы когда пройдет 7 ходов увеличить количество юнитов в замке и казарме. Код с реализацией лежит в файлах "Observe" и "Building".

При победе/ поражении/ ничьей появляется рамочка с сообщением о об этом и игра завершается.

Паттерны Cor, Visitor и Command не использовались в моем проекте, так как я считаю, что их наличие не уместно. Command в основном нужен для отката событий, чего в моей игре не предусмотренно. Visitor не нужен, так как его просто негде использовать. Cor не нужен, так как я нигде не выполняю последовательную обработку запросов.
