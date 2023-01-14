#include <iostream>
#include <cstring>

void swap(char str[], int i1, int i2)
{
    int temp = str[i1];
    str[i1] = str[i2];
    str[i2] = temp;
}

void permutationsHelper(char str[], int start, int end)
{
    if(start == end - 1)
    {
        std::cout << str << std::endl;
    }

    for(int i = start; i < end; i++)
    {
        swap(str, start, i);
        permutationsHelper(str, start + 1, end);
        swap(str, start, i);
    }
}

void permutations(char str[])
{
    permutationsHelper(str, 0, strlen(str));
}

void problem1()
{
    char string[100];

    std::cout << "Enter a string: ";
    std::cin.getline(string, 100);

    permutations(string);
}

bool isInMaze(int maze[50][50], int x, int y, int rows, int cols)
{
    if(x >= rows || x < 0 || y >= cols || y < 0)
    {
        return false;
    }

    return true;
}

bool canGo(int maze[50][50], int start_x, int start_y, int rows, int cols)
{
    if(isInMaze(maze, start_x, start_y, rows, cols) && maze[start_x][start_y] == 0)
    {
        return true;
    }

    return false;
}

bool path(int maze[50][50], int start_x, int start_y, int end_x, int end_y, int rows, int cols)
{
    if(start_x == end_x && start_y == end_y)
    {
        std::cout << "(" << start_x << ", " << start_y << ")";
        return true;
    }

    maze[start_x][start_y] = 1;

    if(canGo(maze, start_x + 1, start_y, rows, cols) 
        && path(maze, start_x + 1, start_y, end_x, end_y, rows, cols))
    {
        std::cout << " -> (" << start_x << ", " << start_y << ")";
        return true;
    }

    if(canGo(maze, start_x - 1, start_y, rows, cols) 
        && path(maze, start_x - 1, start_y, end_x, end_y, rows, cols))
    {
        std::cout << " -> (" << start_x << ", " << start_y << ")";
        return true;
    }

    if(canGo(maze, start_x, start_y - 1, rows, cols) 
        && path(maze, start_x, start_y - 1, end_x, end_y, rows, cols))
    {
        std::cout << " -> (" << start_x << ", " << start_y << ")";
        return true;
    }
    
    if(canGo(maze, start_x, start_y + 1, rows, cols) 
        && path(maze, start_x, start_y + 1, end_x, end_y, rows, cols))
    {
        std::cout << " -> (" << start_x << ", " << start_y << ")";
        return true;
    }

    return false;
}

void problem2()
{
    int n, m, x1, x2, y1, y2;
    int maze[50][50];

    std::cout << "Enter n: ";
    std::cin >> n;
    
    std::cout << "Enter m: ";
    std::cin >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cout << "Enter maze[" << i << "][" << j << "]: ";
            std::cin >> maze[i][j];
        }
    }

    int start_x, start_y, end_x, end_y;

    std::cout << "Enter start_x: ";
    std::cin >> start_x;
    
    std::cout << "Enter start_y: ";
    std::cin >> start_y;
    
    std::cout << "Enter end_x: ";
    std::cin >> end_x;
    
    std::cout << "Enter end_y: ";
    std::cin >> end_y;

    if(!path(maze, end_x, end_y, start_x, start_y, m, n))
    {
        std::cout << "A path doesn't exist" << std::endl;
    }
    
    }

void removeIntElement(int numbers[], int size, int index)
{
    for(int i = index; i < size - 1; i++)
    {
        numbers[i] = numbers[i + 1];
    }
}

void addIntElement(int numbers[], int size, int index, int element)
{
    for(int i = size; i > index; i--)
    {
        numbers[i] = numbers[i - 1];
    }

    numbers[index] = element;
}

void printIntArray(int numbers[], int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << numbers[i] << " ";
    }

    std::cout << std::endl;
}

void generateCombinations(int numbers[], int size, int elements[], int count, int k, int index)
{
    if(count == k)
    {
        printIntArray(elements, count);
        return;
    }

    for(int i = index; i < size; i++)
    {
        int removedElement = numbers[i];

        elements[count] = removedElement;

        removeIntElement(numbers, size, i);

        generateCombinations(numbers, size - 1, elements, count + 1, k, i);

        addIntElement(numbers, size, i, removedElement);
    }
}

void problem3()
{
    int n;
    int array[100], numbersToPrint[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    for(int k = 0; k <= n; k++)
    {
        generateCombinations(array, n, numbersToPrint, 0, k, 0);
    }
}

void generateNumbers(int index, int n, int numbers[], int size, int sum)
{
    if(size == n + 1)
    {
        if(sum == n)
        {
            for(int i = 0; i < size; i++)
            {
                std::cout << numbers[i] << " ";
            }
            std::cout << std::endl;
        }

        return;
    }

    numbers[size] = index + 1;

    for(int i = index; i <= n; i++)
    {
        generateNumbers(i, n, numbers, size + 1, sum + index + 1);
    }
}

void numbersWithSumN(int n, int numbers[])
{
    for(int i = 0; i < n; i++)
    {
        generateNumbers(0, i, numbers, 0, 0);
    }
}

void problem4()
{
    int n;
    int numbers[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    numbersWithSumN(n, numbers);
}

void problem5()
{
    
}


int main()
{
    // problem1();
    // problem2();
    //problem3();
    problem4();
    //problem5();

    return 0;
}