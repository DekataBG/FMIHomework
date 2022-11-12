#include <iostream>

void problem1()
{
    int n;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element;
        
        std::cout << "Enter element: ";
        std::cin >> element;

        array[i] = element;
    }

    for(int i = 0; i < n; i++)
    {        
        std::cout << array[i] << " ";
    }
}

void problem2()
{
    int n;
    int array1[100];
    int array2[100];
    bool same = true;

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element1;
        int element2;
        
        std::cout << "Enter element for array1: ";
        std::cin >> element1;

        std::cout << "Enter element for array2: ";
        std::cin >> element2;

        array1[i] = element1;
        array2[i] = element2;
    }

    for(int i = 0; i < n; i++)
    {
        if(array1[i] != array2[i])
        {
            same = false;
        }
    }

    std::cout << std::boolalpha << same;
}

void problem3()
{
    int n;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element;
        
        std::cout << "Enter element: ";
        std::cin >> element;

        array[i] = element;
    }

    int max = array[0];
    int second = array[0];

    for(int i = 1; i < n; i++)
    {
        int element = array[i];

        if(second < element)
        {
            second = element;
        }

        if(max < second)
        {
            int temp = max;
            max = second;
            second = temp;
        }
    }

    std::cout << second;
}

void problem4()
{
    int n;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element;
        
        std::cout << "Enter element: ";
        std::cin >> element;

        array[i] = element;
    }

    int max = 0, ctr = 0;
    int previous = array[0];
    int element = previous;

    for(int i = 1; i < n; i++)
    {
        if(array[i] == previous)
        {
            ctr++;
        }
        else
        {
            previous = array[i];
            ctr = 0;
        }

        if(max <= ctr)
        {
            element = previous;
            max = ctr;
        }
    }

    std::cout << element;
}

void problem5()
{
    int n;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element;
        
        std::cout << "Enter element: ";
        std::cin >> element;

        array[i] = element;
    }

    for(int i = 0; i < n; i++)
    {
        bool unique = true;

        for(int j = 0; j < n; j++)
        {
            if(j != i && array[j] == array[i])
            {
                unique = false;
                break;
            }
        }
        if(unique)
        {
            std::cout << array[i] << " ";
        }
    }
}

void problem6()
{
    int n, sum;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element;
        
        std::cout << "Enter element: ";
        std::cin >> element;

        array[i] = element;
    }

    std::cout << "Enter sum: ";
    std::cin >> sum;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(array[j] == sum - array[i])
            {
                std::cout << "(" << array[i] << " " << array[j] << ") ";
                break;
            }
        }
    }
}

bool zero = false;
void variations(int n, int k, int array[], int index, int buffer[], int bufferSize)
{
    if(k == 0)
    {
        int sum = 0;
        for(int i = 0; i < bufferSize; i++)
        {
            sum += buffer[i];
        }

        if(sum == 0)
        {
            zero = true;
        }
        return;
    }

    buffer[bufferSize] = array[index];

    for(int i = index; i < n; i++)
    {
        variations(n, k - 1, array, i + 1, buffer, bufferSize + 1);
    }
}

void allVariationsWithKElements(int n, int k, int array[], int buffer[], int bufferSize)
{
    for(int i = 0; i < n; i++)
    {
        if(zero)
        {
            break;
        }
        variations(n, k, array, i, buffer, bufferSize);
    }
}

void allVariations(int n, int array[], int buffer[], int bufferSize)
{
    for(int i = 1; i <= n; i++)
    {
        if(zero)
        {
            break;
        }

        allVariationsWithKElements(n, i, array, buffer, bufferSize);
    }

    std::cout << std::boolalpha << zero;
}

void problem7()
{
    int n;
    int array[100];

    std::cout << "Enter size: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element;
        
        std::cout << "Enter element: ";
        std::cin >> element;

        array[i] = element;
    }

    int buffer[100];

    allVariations(n, array, buffer, 0);

}

void problem8()
{
    int n;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element;
        
        std::cout << "Enter element: ";
        std::cin >> element;

        array[i] = element;
    }

    bool palyndrome = true;
    for(int i = 0; i < n; i++)
    {
        if(array[i] != array [n - i - 1])
        {
            palyndrome = false;
        }
    }

    std::cout << std::boolalpha << palyndrome;
}

void problem9()
{
    int n;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element;
        
        std::cout << "Enter element: ";
        std::cin >> element;

        array[i] = element;
    }

    double median;
    if(n % 2 == 1)
    {
        median = array[n / 2];
    }
    else
    {
        median = ((double)array[n / 2 - 1] + (double)array[n / 2]) / 2;
    }

    std::cout << "Median: " << median;
}

void insert(int array[], int size, int element)
{
    for(int i = 0; i < size; i++)
    {
        if(element <= array[i])
        {
            for(int j = size; j > i; j--)
            {
                array[j] = array[j - 1];
            }

            array[i] = element;

            return;
        }
    }

    array[size] = element;
}

void problem10()
{
    int n, k;
    int array1[100];
    int array2[200];

    std::cout << "Enter size1: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element;
        
        std::cout << "Enter element: ";
        std::cin >> element;

        array1[i] = element;
    }

    std::cout << "Enter size2: ";
    std::cin >> k;

    for(int i = 0; i < k; i++)
    {
        int element;
        
        std::cout << "Enter element: ";
        std::cin >> element;

        array2[i] = element;
    }

    int ctr = 0;
    for(int i = 0; i < n; i++)
    {
        insert(array2, k + i, array1[i]);
    }

    for(int i = 0; i < k + n; i++)
    {
        std::cout << array2[i] << " ";
    }
    
}

bool binarySearch(int array[], int size, int element)
{
    bool contains = false;
    int start = 0, end = size - 1;
    
    while(start != end - 1)
    {
        int middle = (start + end) / 2;

        if(array[middle] == element)
        {
            return true;
        }
        else if(array[middle] < element)
        {
            start = middle;
        }
        else
        {
            end = middle;
        }
    }

    return false;
}

void problem11()
{
    int n, element;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element;
        
        std::cout << "Enter element: ";
        std::cin >> element;

        array[i] = element;
    }

    std::cout << "Enter element to search: ";
    std::cin >> element;

    std::cout << std::boolalpha << binarySearch(array, n, element);
}

void bubbleSort(int array[], int size)
{
    bool ordered = true;
    do
    {
        ordered = true;

        for(int i = 1; i < size; i++)
        {
            if(array[i] < array[i - 1])
            {
                int temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;

                ordered = false;
            }
        }
    }
    while(!ordered);

    for(int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }

    std::cout << "\n";
}

void selectionSort(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int min = i;
        
        for(int j = i + 1; j < size; j++)
        {
            if(array[min] > array[j])
            {
                min = j;
            }
        }

        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }

    for(int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }

    std::cout << "\n";
}

void move(int array[], int size, int index, int elementIndex)
{
    int element = array[elementIndex];

    for(int i = elementIndex; i > index; i--)
    {
        array[i] = array[i - 1];
    }
    array[index] = element;

    for(int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
}

void insertionSort(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i; j >= 0; j--)
        {
            if(array[j] < array[i])
            {
                move(array, size, j + 1, j);
            }
        }
    }

    for(int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
}

void problem12()
{
    int n;
    int array1[100];
    int array2[100];
    int array3[100];

    std::cout << "Enter size: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element;
        
        std::cout << "Enter element: ";
        std::cin >> element;

        array1[i] = element;
        array2[i] = element;
        array3[i] = element;
    }

    std::cout << "Bubble sort: ";
    bubbleSort(array1, n);
    
    std::cout << "Selection sort: ";
    selectionSort(array2, n);

    std::cout << "Insertion sort: ";
    selectionSort(array3, n);
}

void problem13()
{
   int n;
    int array[100];
    int secondHalf[50];

    std::cout << "Enter size: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element;
        
        std::cout << "Enter element: ";
        std::cin >> element;

        array[i] = element;
    }

    int middle = n % 2 == 0 ? n / 2 : n / 2 + 1;
    for(int i = n - 1; i >= middle; i--)
    {
        secondHalf[n - 1 - i] = array[i];
    }

    for(int i = middle; i < n; i++)
    {
        array[i] = secondHalf[i - middle];
    }

    for(int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
}

void problem14()
{
    //unclear task
}

void problem15()
{
    //unclear task
}

bool isPalyndrome(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] != array[size - 1 - i])
        {
            return false;
        }
    }

    return true;
}

void problem16()
{
    int n;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element;
        
        std::cout << "Enter element: ";
        std::cin >> element;

        array[i] = element;
    }

    for(int i = 0; i < n; i++)
    {
        int newArray[100];
        for(int i = 0; i < n; i++)
        {
            newArray[i] = array[i];
        }

        for(int j = i - 1; j >= 0; j--)
        {
            newArray[n - j + i - 1] = array[j];
        }

        if(isPalyndrome(newArray, n + i))
        {
            for(int t = 0; t < n + i; t++)
            {
                std::cout << newArray[t] << " ";
            }

            break;
        }
    }
}

void problem17()
{
    int n, t;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element;
        
        std::cout << "Enter element: ";
        std::cin >> element;

        array[i] = element;
    }

    std::cout << "Enter positions: ";
    std::cin >> t;

    t %= n;
    t = t >= 0 ? t : n + t;

    int newArray[100];
    for(int i = 0; i < n; i++)
    {
        newArray[(i + t) % n] = array[i];
    }

    for(int i = 0; i < n; i++)
    {
        std::cout << newArray[i] << " ";
    }
}


int main()
{
    //problem1();
    //problem2();
    //problem3();
    //problem4(); 
    //problem5(); 
    //problem6(); 
    problem7();//!
    //problem8(); 
    //problem9(); 
    //problem10(); 
    //problem11();
    //problem12();
    //problem13();
    //problem14();
    //problem15();
    //problem16();
    //problem17();


    return 0;
}