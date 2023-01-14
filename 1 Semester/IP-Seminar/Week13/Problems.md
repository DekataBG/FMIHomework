# Задачи за седмица 13

### Зад. 1

Създайте динамичен масив от цели числа с размер N (число, въведено от потребителя). Въведете елементите на масива от клавиатурата, отпечатайте ги и после се погрижете за почистването на паметта.

### Зад. 2

Напишете функция `int* createArray(int size)` , която създава динамичен масив с размер `size` и която кара потребителя да въведе елементите на масива. Функцията да връща указател към началото на новосъздадения масив. Използвайте функцията в `main` функцията и след това се погрижете да почистите заделената памет.

### Зад. 3

Напишете функция `char* concat(char* first, char* second)` ,която връща указател към новосъздаден (динамично) символен низ, който представлява конкатенацията на `first` и `second`.

### Зад. 4

Напишете функция `int* toSet(int* arr, int size, int& setSize)` , която приема масив `arr` с размер `size` и която връща указател към новосъздаден (динамично) масив, който съдържа в себе си множеството от елементите на `arr`. В променливата `setSize` да се запази размерът на новосъздадения масив. Пример:

```c++
	int arr[] = {1, 2, 1, 3, 4, 2, 8, 8, 9};
	int setSize = 0;
	int *set = toSet(arr,9,setSize);
    // след изпълнението на функцията set сочи към масива {1,2,3,4,8,9} и setSize е равно на 6
```


---

### Зад. 5

Напишете функция `void add(int*& arr, int& size, int newElement)` , която добавя към края на масива `arr` елемента `newElement` като за целта да се задели (динамично) памет за нов масив с дължина `size` + 1, да се копират всички предишни елементи на `arr` + новия елемент в новия масив, да се изчисти паметта, която е ползвал `arr` и накрая `arr` да сочи към новосъздадения масив и променливата `size` да е увеличена с 1.

### Зад. 6

Напишете функция `void insertAt(int*& arr, int& size, int newElement, int index)` , която е генерализация на предишната. Разликата е, че вмъква новия елемнт на позиция 
`index`. Отново трябва да се заделя памет и да се изчиства старата. 

### Зад. 7

Напише функция `void resize(int*& arr, int& size, int newSize)`, която трябва да пренасочи `arr` към нов, динамично създаден масив с размер `newSize`. Максимален брой елементи от стария буфер трябва да бъдат копирани в новия. Ако новият размер е по-голям, да се добавят "свободни" места - нули. Ако е по-малък, да се премахнат елементите от края.

### Зад. 8

Напишете фунцкия `void copy(int* arrayFrom, int sizeFrom, int*& arrayTo, int& sizeTo)`, която копира елементите от `arrayFrom` в `arrayTo` като предварително зачиства паметта, към която сочи `arrayTo`.