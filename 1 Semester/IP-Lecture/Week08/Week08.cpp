// Problems from section 3.3, 3.4 and 3.5 from https://github.com/stranxter/lecture-notes/blob/master/homeworks/Problems%20in%20Programming.pdf

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

void problem3_17()
{
    int array1[50], array2[50];
    int n, ctr = 0;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element for array 1: ";
        std::cin >> array1[i];

        std::cout << "Enter element for array 2: ";
        std::cin >> array2[i];

        if (array1[i] == array2[i])
        {
            ctr++;
        }
    }

    std::cout << ctr << " equal elements";
}

bool contains(int array[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            return true;
        }
    }

    return false;
}

void problem3_18()
{
    int array1[50], array2[50];
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element for array 1: ";
        std::cin >> array1[i];

        std::cout << "Enter element for array 2: ";
        std::cin >> array2[i];
    }

    bool similar = true;
    for (int i = 0; i < n; i++)
    {
        if (!contains(array1, n, array2[i]) || !contains(array2, n, array1[i]))
        {
            similar = false;
            break;
        }
    }

    std::cout << (similar ? "The arrays are similar" : "The arrays are not similar");
}

void problem3_19()
{
    int matrix[50][50];
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << "Enter matrix [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (matrix[i][j] % 2 == 1)
            {
                sum += matrix[i][j];
            }
        }
    }

    std::cout << "The sum of the odd numbers below the main diagonal is " << sum;
}

bool isMinimalElementInRow(int matrix[][50], int size, int row, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (element > matrix[row][i])
        {
            return false;
        }
    }

    return true;
}

bool isMinimalElementInCol(int matrix[][50], int size, int col, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (element > matrix[i][col])
        {
            return false;
        }
    }

    return true;
}

void problem3_20()
{
    int matrix[50][50];
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << "Enter matrix [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isMinimalElementInRow(matrix, n, i, matrix[i][j]) && isMinimalElementInCol(matrix, n, j, matrix[i][j]))
            {
                std::cout << matrix[i][j] << std::endl;
            }
        }
    }
}

bool isPeriodic(int array[], int size, int period)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] != array[i % period])
        {
            return false;
        }
    }

    return true;
}

void problem3_21()
{
    int array[50];
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    for (int i = 1; i <= n / 2; i++)
    {
        if (isPeriodic(array, n, i))
        {
            std::cout << "The array has period " << i << std::endl;
            return;
        }
    }

    std::cout << "The array is not periodic" << std::endl;
}

void problem3_22()
{
    int matrix1[50][50], matrix2[50][50], matrix3[50][50];
    int n, m;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter m: ";
    std::cin >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << "Enter element for matrix A[" << i << "][" << j << "]: ";
            std::cin >> matrix1[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << "Enter element for matrix B[" << i << "][" << j << "]: ";
            std::cin >> matrix2[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int col = 0; col < m; col++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += matrix1[i][j] * matrix2[j][col];
            }
            matrix3[i][col] = sum;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix3[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void problem3_23()
{
    int array[50];
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    bool sorted = true;
    do
    {
        sorted = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                sorted = false;

                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    } while (!sorted);

    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
}

void bubbleSort(int array[], int size)
{
    bool sorted = true;
    do
    {
        sorted = true;
        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                sorted = false;

                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    } while (!sorted);
}

int unsortedness(int array[], int size)
{
    int arrayCopy[50];
    for (int i = 0; i < size; i++)
    {
        arrayCopy[i] = array[i];
    }

    bubbleSort(arrayCopy, size);

    int ctr = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] != arrayCopy[i])
        {
            ctr++;
        }
    }

    return ctr;
}

void problem3_24()
{
    int array[50];
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    int unsorted = unsortedness(array, n);

    std::cout << "Unsortedness: " << unsorted;
}

bool isSorted(int array[], int size, int startPoint)
{
    for (int i = startPoint; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }

    return true;
}

bool swappable(int array[], int size)
{
    for (int i = 1; i < size - 1; i++)
    {
        if (isSorted(array, i, 0) && isSorted(array, size - i, i) && array[size - 1] <= array[0])
        {
            return true;
        }
    }

    return false;
}

void problem3_25()
{
    int array[50];
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    std::cout << (swappable(array, n) ? "The array is swappable" : "The array is not swappable") << std::endl;
}

void problem3_26()
{
    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        int array[50];
        int n;

        std::cout << "Enter n: ";
        std::cin >> n;

        for (int i = 0; i < n; i++)
        {
            array[i] = rand() % 100;
        }

        clock_t start = std::clock();

        bubbleSort(array, n);

        clock_t end = std::clock();

        long milliseconds = (double)(end - start) / (CLOCKS_PER_SEC / 1000.0);

        std::cout << n << ": " << milliseconds << " ms \n";
    }
}

void sortRows(int matrix[][50], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            int index = j;
            for (int k = j + 1; k < cols; k++)
            {
                if (matrix[i][k] < matrix[i][index])
                {
                    index = k;
                }
            }

            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][index];
            matrix[i][index] = temp;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void sortColumns(int matrix[][50], int rows, int cols)
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows - 1; j++)
        {
            int index = j;
            for (int k = j + 1; k < rows; k++)
            {
                if (matrix[k][i] < matrix[index][i])
                {
                    index = k;
                }
            }

            int temp = matrix[j][i];
            matrix[j][i] = matrix[index][i];
            matrix[index][i] = temp;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void problem3_27()
{
    int matrix[50][50];
    int n, m;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter m: ";
    std::cin >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << "Enter matrix [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    sortRows(matrix, n, m);
    std::cout << std::endl;
    sortColumns(matrix, n, m);
}

void bozoSort(int array[], int size)
{
    srand(time(0));

    while (!isSorted(array, size, 0))
    {
        int index1 = rand() % size;
        int index2 = rand() % size;

        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }
}

void problem3_28()
{
    int array[50];
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    clock_t start = std::clock();

    bozoSort(array, n);

    clock_t end = std::clock();

    long milliseconds = (double)(end - start) / (CLOCKS_PER_SEC / 1000.0);

    std::cout << n << " elements: " << milliseconds << " ms \n";
}

bool equalDiagonals(char matrix[][30][7], int size)
{
    char word1[181], word2[181];
    for (int i = 0; i < 181; i++)
    {
        word1[i] = '\0';
        word2[i] = '\0';
    }

    for (int i = 0; i < size; i++)
    {
        int j = i;

        int length1 = strlen(matrix[i][j]);
        int length2 = strlen(matrix[size - 1 - i][j]);

        for (int k = 0; k < length1; k++)
        {
            word1[strlen(word1)] = matrix[i][j][k];
        }

        for (int k = 0; k < length2; k++)
        {
            word2[strlen(word2)] = matrix[size - 1 - i][j][k];
        }
    }

    std::cout << word1 << " " << word2 << std::endl;
    return strcmp(word1, word2) == 0;
}

void problem3_55()
{
    char wordMatrix[30][30][7];
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << "Matrix [" << i << "][" << j << "]: ";
            std::cin >> wordMatrix[i][j];
        }
    }

    std::cout << (equalDiagonals(wordMatrix, n) ? "The main diagonal equals the secondary diagonal"
                                                : "The words from the diagonals are different")
              << std::endl;
}

void problem3_56()
{
    char matrix[20][20][10];
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << "Matrix [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < n / 2 + n % 2; i++)
    {
        for(int j = i; j < n - i; j++)
        {
            std::cout << matrix[i][j];
        }
        for(int k = 1 + i; k < n - i; k++)
        {            
            std::cout << matrix[k][n - 1 - i];
        }
        for(int l = n - 2 - i; l >= i; l--)
        {
            std::cout << matrix[n - 1 - i][l];
        }
        for(int r = n - 2 - i; r >= i + 1; r--)
        {
            std::cout << matrix[r][i];
        }
    }
}

void insertAt(char array[][50], int size, int index, char element[])
{
    for(int i = size; i > index; i--)
    {
        strcpy(array[i], array[i - 1]);
    }

    strcpy(array[index], element);
}

void insertStudent(char students[][50], int size, char student[])
{    
    if(size == 0)
    {
        strcpy(students[0], student);
        return;
    }

    for(int i = 0; i < size; i++)
    {
        if(strcmp(students[i], student) > 0)
        {
            insertAt(students, size, i, student);
            break;
        }
    }
}

void insertGrade(char grades[][50], int size, char group[])
{
    if(size == 0)
    {
        strcpy(grades[0], group);
        return;
    }

    for(int i = 0; i < size; i++)
    {
        if(strcmp(grades[i], group) > 0)
        {
            insertAt(grades, size, i, group);
            break;
        }
    }
}

void problem3_57()
{
    int studentsCount, gradesCount;

    char students[20][50];
    char grades[20][50];

    std::cout << "Enter students count: ";
    std::cin >> studentsCount;
    
    std::cout << "Enter grades count: ";
    std::cin >> gradesCount;

    std::cin.ignore(2, '\n');

    for(int i = 0; i < studentsCount; i++)
    {
        char student[50];

        std::cout << "Enter a student: ";
        std::cin.getline(student, 50);

        insertStudent(students, i, student);
    }

    for(int i = 0; i < gradesCount; i++)
    {
        char grade[50];

        std::cout << "Enter a grade: ";
        std::cin.getline(grade, 12);

        insertGrade(students, i, grade);
    }

    for(int i = 0; i < studentsCount; i++)
    {
        std::cout << students[i] << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < gradesCount; i++)
    {
        std::cout << grades[i] << " ";
    }
}

int main()
{
    // problem3_17();
    // problem3_18();
    // problem3_19();
    // problem3_20();
    // problem3_21();
    // problem3_22();
    // problem3_23();
    // problem3_24();
    // problem3_25();
    // problem3_26();
    // problem3_27();
    // problem3_28();
    // problem3_55();
    // problem3_56();
    problem3_57();


    return 0;
}