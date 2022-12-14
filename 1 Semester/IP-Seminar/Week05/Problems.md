# Задачи за седмица 5

### Зад. 1

* Създайте и инициализирайте масив от цели числа с 5 елемента
    * "на ръка" като задавате стойностите на елементите един по един
    * с инициализиращ списък
* Отпечатайте елементите на вече създадения и инициализиран масив
    * "на ръка" като отпечатвате елементите един по един
    * със цикъл
* Да се напише програма, която създава масив с максимален размер 20. Програмата да кара потребителя да въведе реалния размер n <= 20 и след това го кара да въведе първите n на брой елементи на масива и после ги отпечатва.

### Зад. 2

Да се направи програма, която създава масив с n<=20 елемента, които се въвеждат от клавиатурата. Програмата да печата на екрана произведението на елементите.

### Зад. 3

Да се напише програма, която кара потребителя да въведе от клавиатурата символен низ с дължина не повече от 50 символа и да го отпечатва на екрана само ако започва с главна буква.

### Зад. 4

Да се напише програма, която кара потребителя да въведе от клавиатурата символен низ с размер n <= 50 и да отпечатва на екрана дали е въведено съобщително, въпросително, възклицателно изречение или не е въведено изречение. 

### Зад. 5

Напишете програма, която при въведен числов масив с размер n (0 <= n <= 20) извежда на екрана всички числа, които са четни.

### Зад. 6

Напишете програма, която при въведен числов масив с размер n (0 <= n <= 20) извежда на екрана сумата на всички числа, които са на позиции в масива, кратни на 3.

### Зад. 7

Напишете програма, която при въведен числов масив с размер n (0 <= n <= 20) извежда на екрана всички числа, но в обратен ред.

### Зад. 8

Да се напише фукнция `bool contains(int array[], int size, int elem)`, която проверява дали `elem` е елемент на `array`.

### Зад. 9

Да се напише фукнция `void replace(int array[], int size, int find, int search)`, която заменя всички срещания на `find` в `array` с `replace`.

### Зад. 10

Да се напише програма, която кара потребителя да въведе масив от цели числа и в нов масив на i-тата позиция да се записва броя на числата, които са по-малки от i-тия елемнт на първия масив и стоят на позция по-голяма от него(т.е. са вдясно от него).

Пример:

```
<< input 	
>> array1[]={1, 2, 3, 4, 2, 3}
<< output
<< array2[]={0, 0, 1, 2, 0, 0}
```


# Седмица 5 - Домашна работа

> **Забележка** - това не е официална и не е задължителна домашна работа. Няма да влияе на крайната ви оценка по никакъв начин. Това е възможност за вас да получите детайлно ревю на кода си. Изберете си една от трите задачи и изпратете решението си на имейл(или в Messenger, или в Discord). Ще получите детайлна и при необходимост многократна обратна връзка за решението си.


## Зад. 1

Напишете програма, която намира сумата на елементите в масив(с максимална големина до 256 елемента), намиращи се между най-големия и най-малкия елемент в масива.

Пример:

```c++

int arr[] = {1, 8, 12, -5, 3, 9, -8} 
// Най-големият елемент е 12, най-малкият е -8. Сумата на елементите между тях е -5 + 3 + 9 = 7


int arr[] = {11, 208, -5, 3, 0} 
// Най-големият елемент е 208, най-малкият е -5. Сумата на елементите между тях е 0 (няма елементи)


int arr[] = {33, 28, -54, 20, 144} 
// Най-големият елемент е 144, най-малкият е -54. Сумата на елементите между тях е 20 (само един елемент)
```

## Зад. 2

Напишете програма, която отпечатва броя на срещанията на всеки символ в символен низ.

Пример:

```c++
char arr[] = "еxample"
/*
    е -> 2
    x -> 1
    a -> 1
    m -> 1
    p -> 1
    l -> 1
*/

char arr[] = "Hello world!"
/*
    H -> 1
    e -> 1
    l -> 3
    o -> 2
    <space> -> 1
    w -> 1
    r -> 1
    d -> 1
    ! -> 1
*/
```

## Зад. 3

Напишете програма, която проверява дали два масива съдържат еднакво множество от елементи.

```c++
int arr1[] = {1, 12, 1, 33, 5}
int arr2[] = {12, 33, 33, 33, 33, 5, 1, 1}
/*
    Множеството от елементи на arr1 е {1, 5, 12, 33}
    Множеството от елементи на arr2 е {1, 5, 12, 33}
    Двата масива съдържат еднакво множество от елементи
*/

int arr1[] = {13, -5, 6, 9, 13, -1}
int arr2[] = {12, 13, 6, 9, -1, 44, 8, 7, 8, -5}
/*
    Множеството от елементи на arr1 е {-1, -5, 6, 9, 13}
    Множеството от елементи на arr2 е {-1, -5, 6, 7, 8, 9, 12, 13, 44}
    Двата масива не съдържат еднакво множество от елементи(но пък arr1 е подмножество на arr2)
*/
```