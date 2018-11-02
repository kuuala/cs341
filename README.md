CS341 Алгоритмы на графах
=
Лабораторные работы курса CS341 "Алгоритмы на графах" Института математики, механики и компьютерных наук Южного федерального университета.

**Условия заданий:**
1) [**Сражения за трон:**](https://github.com/qalanp/cs341graphsalgo/tree/master/lab_01)
	
	**Описание:** В компьютерной игре «Сражения за трон» действие происходит в фантастическом королевстве, разделенном на N провинций. Каждая провинция соседствует с di другими провинциями, при этом ∑di ≤ 6∙10^5. В игре принимают участие K сторон (игроков), причем K < N. В начале игры каждый игрок получает в свое распоряжение одну провинцию и армию в ней расположенную, причем два игрока не могут получить одну провинцию. Армии в игре за один ход перемещаются из текущей провинции в соседнюю. Естественно задача каждого игрока, победив в сражениях, захватить все провинции. Сережа взялся поиграть в эту стратегическую игру и сразу задался серьезным вопросом: сколько ходов нужно сделать ему, чтобы попытаться захватить стартовую провинцию другого игрока. Такая стратегия называется rush. Также Сереже интересно, нет ли у других сторон преимущества в в использовании этой стратегии. Сережа просит Вас написать программу, которая предоставит ему такую информацию. 

	**Требуется** написать программу, которая по начальному расположению игроков, определит пару игроков, для которых rush-стратегия потребует наименьшее число ходов.
	
	**Формат входных данных** В первой строке указаны числа N и K (2 ≤ N ≤ 10^5, 2 ≤ K ≤ 100). В следующих N строках описаны взаимоотношения соседства провинций. В строке с номером 2 описана провинция с номером 0 и ее соседи, в строке с номером 3 описана провинция с номером 1 и ее соседи и т.д. Описание соседей некоторой провинции представляет собой последовательность чисел. Первое число в этой последовательности это di (1 ≤ di ≤ N-1). Далее в строке следует di чисел, каждое из которых указывает номер одной провинции-соседа для i-ой провинции. В последней строке указано натуральных K чисел, означающие стартовые провинции игроков. Первое число соответствует игроку с номером 0, второе игроку с номером 1 и т.д. Все числа в строках разделены одиночными пробелами.
	
	**Формат выходных данных** Выходные данные представляют собой K + 1 строку. Первые K строк содержат по K чисел в каждой из них. Число, расположенное в i-ой строке и j-ое по порядку в ней, указывает расстояние от провинции (i-1)-ого игрока до провинции (j-1)-ого игрока. Игроки нумеруются от 0. В строке K+1 должна быть указана пара игроков, которая может использовать rush-стратегию за наименьшее количество ходов. Если таких пар несколько, то указать любую. Все числа в строках разделены одиночными пробелами


2) [**Купи Буратино**](https://github.com/qalanp/cs341graphsalgo/tree/master/lab_02)
	
	**Описание:** В России был разработан энергетический напиток нового поколения «Буратино». Этот напиток настолько хорош, что им заинтересовались за рубежом, но производство еще налажено слабо, и потому достать его непросто. Группа клиентов международной авиакомпании «Fly Safe» очень заинтересовалась этим напитком, и они активно обсуждают этот напиток в своем внутреннем чате. Кто-то из них предложил провести сравнение цен в магазинах «Duty Free», которые есть во всех аэропортах. Это предложение очень понравилось другим клиентам, и они обменялись информацией. Каждый из них сообщил, в какие города есть рейсы от «Fly Safe» из его родного города, а также информацию о том, сколько стоит «Буратино» в «Duty Free» аэропорта в его родном городе. Упомянутая группа клиентов летают только на рейсах от «Fly Safe», потому что это выгодно. 

	**Требуется** написать программу, которая определит для каждого клиента самую низкую цену, по которой он может купить «Буратино», используя возможности перелетов на самолетах компании «Fly Safe».
	
	**Формат входных данных** В первой строке указано число N (1 ≤ N ≤ 10^5) количество клиентов. Во второй строке указывается N целых чисел pi (1 ≤ pi ≤ 10^5) . Эти числа задают список цен на «Буратино» в аэропортах городов, где живут клиенты. Цены разделены одиночными пробелами. В следующих N строках описаны рейсы между городами. В строке с номером 3 описаны рейсы из города с номером 0, в строке с номером 4 рейсы из города с номером 1 и т.д. Описание исходящих из города рейсов представляет собой последовательность чисел разделенных одиночными пробелами. Первое число di в этой последовательности означает количество рейсов (от 0 до N-1) исходящих из города номер i. Далее в строке следует di чисел, каждое из которых описывает один рейс. А именно, это номер города (от 0 до N-1), в который можно перелететь из города номер i. Отметим что ∑di ≤ 10^5.
	
	**Формат выходных данных** В первой строке должно быть N чисел разделенных одиночными пробелами. При этом i-ое число означает минимальную цену, по которой клиент из i-ого города может купить «Буратино», используя рейсы «Fly Safe».

3) [**Моделирование Конца Света**](https://github.com/qalanp/cs341graphsalgo/tree/master/lab_03) 
	
	**Описание:** Отто Октавиус разработал новый суперкомпьютер для моделирования Конца Света. Человек-паук нашел сеть магистралей, по которым стекаются данные к Октавиусу. Магистрали ведут от узла к узлу, на которых происходит маршрутизация передачи данных, причем данные передаются всегда в одном направлении. Человек-Паук выяснил, что не существует пути, ведущего от одного узла к нему же, а также каждую пару узлов может соединять не более одной магистрали. Всего Человек-Паук насчитал N узлов и M магистралей. Соколиный Глаз (лидер Мстителей) принял решение о том, что бороться с Октавиусом нужно по возможности скрытно и постепенно, а именно по одной диверсии в день. Железный Человек получил задание определить путь, состоящий из магистралей, наибольшей пропускной способности, ведущий от городского Дата-Центра до лаборатории Октавиуса. Человек-Паук должен в течение дня снизить пропускную способность всех магистралей на этом пути вдвое. На следующий день, этот саботаж должен повториться. Всего Соколиный Глаз планирует провести D диверсий по одной в день. Отметим, что пропускные способности магистралей могут принимать только целочисленные значения, так что при диверсии их пропускные способности округляются вниз. Также, если путей наибольшей пропускной способности несколько, чтобы не вызывать подозрений, Железный Человек будет выбирать из них лексикографически наименьший (см. замечание ниже), поскольку такие пути, как выяснили Мстители, используются Октавиусом чаще и, соответственно, более изношены. 

	**Требуется** написать программу, которая промоделирует действия Мстителей, а также предоставит информацию для аналитического центра «S.H.I.E.L.D.», от которого поступают запросы о состоянии магистралей в определенные дни. Всего аналитический центр сделал Q запросов, и их интересует состояние магистралей после диверсий, проведенных в соответствующий день.
	
	**Формат входных данных** В первой строке указаны числа N, M, D, Q (2 ≤ N ≤ 10^5 , 1 ≤ M ≤ 3∙10^5 , 0 ≤ D ≤ 100, 1 ≤ Q ≤ 10^5) разделенные одиночными пробелами. Во второй строке указаны 2 числа (s, t): номера узлов, соответствующих городскому Дата-Центру и лаборатории Октавиуса (0 ≤ s,t <N, s ≠ t). В следующих M строках описаны магистрали. Каждая магистраль описывается тройкой целых чисел: x — узел-источник данных, y — узел-приемник данных, с — пропускная способность магистрали. (0 ≤ x,y < N, 0 ≤ c ≤ 10^18). Числа в строках разделены одиночными пробелами. В следующих Q строках описаны запросы. Каждый запрос – это тройка чисел: d — номер дня, для которого нужно уточнить пропускную способность магистрали (1 ≤ d ≤ D), а также x, y — интересующие Аналитический центр узлы.
	
	**Формат выходных данных** Выходные данные представляют собой Q строк. В каждой строке нужно вывести ответ на запрос. Ответом является пропускная способность магистрали в конце указанного дня, либо 0, если магистрали между соответствующими узлами в любом направлении не существует. Ответы на запросы должны следовать в том же порядке, что и сами запросы во входных данных.
	
	**Замечание:** Под лексикографическим порядком путей подразумевается лексикографический порядок последовательностей вершин, составляющих эти пути. Так, например, путь 1->25->4 меньше пути 1->26->4.

4) [**Игра в слова**](https://github.com/qalanp/cs341graphsalgo/tree/master/tree/master/lab_04)
	
	**Описание:** Создатели паутины слов пришли к выводу, что их паутина сбоит. В-создатель создатель говорит, что его вертикальные слова не могут приводить к сбоям в эфире, а Г-создатель то же самое утверждает о сотворенных им горизонтальных словах. Их спор разрешил Д-создатель, который сформулировал принцип конфликта духа паутины слов. Итак, паутина слов была создана из горизонтальных и вертикальных слов. Важным фактором является пересечение слов этих двух типов. Эти пересечения образуют точки концентрации духа паутины. А важность этих точек связана с двумя аспектами: вопервых, слова одного типа пересечься не могут в принципе, а во-вторых, противоположная направленность пересекающихся слов, дополняет точку пересечения, как Г-духом, так и В-духом. Конфликт духа паутины возникает вследствие того, что возникающая в паутине энергия начинает циркулировать по образовавшимся метациклам. Под метациклом понимается последовательность точек концентрации духа такая, что каждая следующая связана с предыдущей точкой концентрации частью вертикального или горизонтального слова. Чтобы прекратить сбои **необходимо** удалить части некоторых вертикальных и/или горизонтальных слов. Ваша миссия состоит в том, чтобы проанализировать существующие вертикальные и горизонтальные слова в паутине, затем определить точки концентрации духа, после чего разорвать существующие метациклы, путем удаления частей слов, соединяющих некоторые из пар точек концентрации. Главное! Суммарное число оставшихся букв должно быть минимально!
	
	**Формат входных данных** Первая строка входного файла содержит числа H и V (1 ≤ H, V ≤ 1000) — число горизонтальных и вертикальных слов в паутине. Следующие H строк содержат описания горизонтальных слов. Описание представляет собой три числа: r, c1, c2 (0 ≤ r, c1, c2 ≤ 10^6 , c1 < c2) такие, что соответствующее слово начинается в клетке (r, c1) и оканчивается в клетке (r, c2). Следующие V строк содержат описания вертикальных слов. Описание представляет собой три числа: r1, r2, c (0 ≤ r1, r2, c ≤ 10^6, r1 < r2) такие, что соответствующее слово начинается в клетке (r1, c) и оканчивается в клетке (r2, c).
	
	**Формат выходных данных** Выведите единственное число минимально возможное суммарное количество оставшихся букв. Если разрыв всех метациклов невозможен, то вывести -1.

5) [**Винтин и Шпунтик**](https://github.com/qalanp/cs341graphsalgo/tree/master/lab_05)
	
	**Описание:** Винтик и Шпунтик наконец доделали второй автомобиль и теперь планируют ездить друг к другу в гости. Но проезд в Солнечном городе оказался не столь безопасным. Для удобства будем считать, что в Солнечном городе все дороги являются отрезками прямых. Перекрестки - это пересечения двух и более дорог. Дома Винтика и Шпунтика расположены на отрезках дорог, но не на перекрестках. Итак, Винтик собрался ехать к Шпунтику. Из своего дома Винтик может поехать в одном из двух направлений. Доехав до перекрестка, он может поехать дальше по текущей дороге или свернуть на другую. Определим степень опасности поворота как угол поворота с одной улицы на другую в градусах (от 0 до 180). Чем круче поворот, тем Винтик сильнее подвержен опасности. Опасность всего пути равна сумме опасностей на каждом повороте. 

	**Требуется** написать программу, которая определяет маршрут с наименьшей опасностью для Винтика.
	
	**Формат входного файла** Первая строка содержит число N – количество дорог. Следующие N строк содержат по 4 целых числа xi1, yi1, xi2 и yi2 разделенных одиночными пробелами. Эти четыре числа задают две точки на плоскости, через которые проходит дорога (прямая). В следующих двух строках заданы координаты домов Винтика и Шпунтика, в виде пар целых чисел разделенных одиночным пробелом. Гарантируется, что совпадающих дорог нет, что дома Винтика и Шпунтика не лежат на перекрестках, но лежат на дорогах. Кроме того, координаты домов разные.
	
	**Формат выходного файла** В первой строке нужно указать величину наименьшей возможной опасности на пути Винтика к дому Шпунтику. В случае, если никакого пути не существует, вывести -1.

6) [**Микросхема**](https://github.com/qalanp/cs341graphsalgo/tree/master/tree/master/lab_06)
	
	**Описание** Доктор Эммет Браун разработал новую микросхему для манипулирования пространственно-временным континуумом (ПВК). Эта схема представляет собой решетку размера NxN. Все узлы по краям решетки предназначены для соединения с питанием схемы и в них расположены пины подключения. А в не граничных узлах решетки расположены специальные элементы ПВК-трансгрессии. В момент включения схемы, выбирается некоторый набор из K элементов ПВК-трансгрессии на схеме и K пинов. Затем каждый из выбранных элементов должен соединится с одним из пинов на границе решетки. Соединение элемента с пином выглядит как путь на решетке. Важным конструктивным ограничением на соединение между пинами и элементами является то, что если соединение элемента (i1, j1) с пином (r1, c1) проходит через узел (x1, y1), то соединение элемента (i2, j2) с пином (r2, c2) не может проходить через узел (x1, y1). Другими словами, пути соединения не могут пересекаться в узлах решетки. 

	**Требуется** написать программу, которая определяет пути соединения заданных наборов элементов ПВК-трансгрессии и пинов с учетом указанного ограничения.
	
	**Формат входного файла** Первая строка содержит числа N (3 ≤ N ≤ 100) и K (1 ≤ K ≤ 4 * N-2). Следующие две строки содержат описания расположения элементов ПВК-трансгрессии схемы. Каждая из этих строк содержит по K натуральных чисел от 1 до N-2 (включительно). Номер строки i-ого элемента - это i-ое число во второй строке файла, а номер столбца - это i-ое число в третьей строке файла. Следующие две строки содержат описания расположения пинов. Каждая из этих строк содержит по K натуральных чисел от 0 до N-1 (включительно). Номер строки i-ого пина - это i-ое число в четвертой строке файла, а номер столбца - это i-ое число в пятой строке файла. Гарантируется, что пины расположены на границах (нулевая или последняя строка или столбец).
	
	**Формат выходного файла** Если соединить все пины и элементы не удалось вывести -1. В противном случае, выходной файл должен содержать в i-ой строке описание i-го соединения схемы. Каждое соединение описывается последовательностью узлов, по которым оно проходит, начиная с узла элемента ПВК-трансгрессии и заканчивая узлом пина. каждый узел представляется числом вида i * N + j, где i - номер строки узла, а j - номер столбца от 0 до N-1.

7) [**Синхронные герои**](https://github.com/qalanp/cs341graphsalgo/tree/master/lab_extra)
	
	**Описание:** Тесей и Пейрифой пытаются пройти сразу два лабиринта! Каждый из героев находится в своем отдельном лабиринте. Каждый лабиринт представляет собой квадратную матрицу размером NxN. Некоторые клетки лабиринта свободные и по ним можно перемещаться, а некоторые заняты стенами. Выход в каждом из лабиринтов находится в клетке (0, 0). Самим героям не справится и они обратились к богине Афине. Богиня Афина командует ими одновременно. То есть когда Афина командует "Вправо!" оба героя сдвигаются на одну клетку вправо. При этом если для одного из героев на соседней клетке стена, то этот герой остается на месте. Если для обоих справа - стена, то оба останутся на месте. Как известно олимпийские боги очень горды. И, конечно же, Афина не попросит у Вас помощи. Поэтому **требуется** написать программу, определяющую наименьшую последовтельность команд, которую нужно произнести Афине. А она сама сможет ею воспользоваться (богиня все таки).
	
	**Формат входного файла**  Первая строка содержит пять целых чисел: N, R1, C1, R2, C2 (2 ≤ N ≤ 100, 0 ≤ R1, C1, R2, C2 < N). Число N описывает размер каждого из лабиринтов. Пара чисел R1, C1 описывает положение (строка, столбец) Тесея в его лабиринте. Пара чисел R2, C2 описывает положение (строка, столбец) Пейрифоя в его лабиринте. Далее следует описание лабиринта Тесея. Следующие N строк содержат по N целых чисел, каждое из которых может быть либо 0, либо 1. Число 0 означает, что в соответсвующей позиции клетка лабиринта свободна. Число 1 означает, что в соответвующей позиции лабиринта находится стена. Далее следует описание лабиринта Пейрифоя. Следующие N строк содержат по N целых чисел, каждое из которых может быть либо 0, либо 1. Число 0 означает, что в соответсвующей позиции клетка лабиринта свободна. Число 1 означает, что в соответвующей позиции лабиринта находится стена. Входные данные корректны в том смысле, что ни один из героев не может оказаться изначально на клетке со стеной. Для каждого героя существует маршрут, позволяющий ему покинуть свой лабиринт. Более того, существует последовательность команд Афины, позволяющая вывести героев из лабиринта.
	
	**Формат выходного файла** Единственная строка выходного файла содержит целое число - количество команд Афины.