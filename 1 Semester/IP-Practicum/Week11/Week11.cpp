#include <iostream>

bool existsPath(int matrix[][50], int rows, int cols, int x1, int y1, int x2, int y2)
{
    matrix[x1][y1] = 1;

    if(x1 == x2 && y1 == y2)
    {
        return true;
    }

    if(y1 + 1 != cols && matrix[x1][y1 + 1] == 0 
        && existsPath(matrix, rows, cols, x1, y1 + 1, x2, y2))
    {
        return true;
    }

    if(y1 - 1 != -1 && matrix[x1][y1 - 1] == 0 
        && existsPath(matrix, rows, cols, x1, y1 - 1, x2, y2))
    {
        return true;
    }
    
    if(x1 + 1 != rows && matrix[x1 + 1][y1] == 0 
        && existsPath(matrix, rows, cols, x1 + 1, y1, x2, y2))
    {
        return true;
    }

    if(x1 - 1 != -1 && matrix[x1 - 1][y1] == 0 
        && existsPath(matrix, rows, cols, x1 - 1, y1, x2, y2))
    {
        return true;
    }

    return false;
}

void problem2()
{
    int n, m, x1, x2, y1, y2;
    int matrix[50][50];

    std::cout << "Enter n: ";
    std::cin >> n;
    
    std::cout << "Enter m: ";
    std::cin >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cout << "Enter matrix[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Enter x1: ";
    std::cin >> x1;

    std::cout << "Enter y1: ";
    std::cin >> y1;

    std::cout << "Enter x2: ";
    std::cin >> x2;

    std::cout << "Enter y2: ";
    std::cin >> y2;

    std::cout << "A path exists: " 
        << std::boolalpha << existsPath(matrix, n, m, x1, y1, x2, y2);
}

int main()
{
    problem2();

    return 0;
}