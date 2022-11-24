#include <iostream>
#include <cstring>

void problem1()
{
    int n, m;
    int matrix[100][100];

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

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void problem2()
{
    int n, m;
    int matrix[100][100];

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter m: ";
    std::cin >> m;

    int sum = 0, product = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int element;

            std::cout << "Enter matrix[" << i << "][" << j << "]: ";
            std::cin >> element;

            if(i == j)
            {
                sum += element;
            }
            if(i == m - j - 1)
            {
                product *= element;
            }
        }
    }

    std::cout << "The sum of the main diagonal is: " << sum 
        << "\nThe product of the second diagonal is: " << product << std::endl;
}

void problem3()
{
    int n, m;
    int matrix1[100][100], matrix2[100][100], matrix3[100][100];

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter m: ";
    std::cin >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cout << "Enter matrix1[" << i << "][" << j << "]: ";
            std::cin >> matrix1[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cout << "Enter matrix2[" << i << "][" << j << "]: ";
            std::cin >> matrix2[i][j];

            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cout << matrix3[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void problem4()
{
    int n, m, scalar;
    int matrix[100][100];

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

    std::cout << "Enter a scalar: ";
    std::cin >> scalar;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] * scalar << " ";
        }
        std::cout << std::endl;
    }
}

void problem5()
{
    int n, m;
    int matrix[100][100], tMatrix[100][100];

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

            tMatrix[j][i] = matrix[i][j];
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << tMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void problem6()
{
    int n, m;
    int matrix[100][100];

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

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cout << matrix[n - 1 - i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void problem7()
{
    char string[5];
    int n, m;
    int matrix[100][100];

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

    std::cout << "Enter a string: ";
    std::cin >> string;

    if(strcmp(string, "left") == 0)
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                std::cout << matrix[j][m - 1 - i] << " ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                std::cout << matrix[n - 1 - j][i] << " ";
            }
            std::cout << std::endl;
        }
    }
}

void problem8()
{
    int n, m;
    int matrix[100][100];

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

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cout << (i % 2 == 0 ? matrix[i][j] : matrix[i][m - 1 - j]) << " ";
        }
    }
}

void problem9()
{
    int n, m;
    int matrix[100][100];

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

    for(int i = 0; i < n / 2 + n % 2; i++)
    {
        for(int j = i; j < m - i; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        for(int k = 1 + i; k < n - i; k++)
        {
            std::cout << matrix[k][m - 1 - i] << " ";
        }
        for(int l = m - 2 - i; l >= i; l--)
        {
            std::cout << matrix[n - 1 - i][l] << " ";
        }
        for(int r = n - 2 - i; r >= i + 1; r--)
        {
            std::cout << matrix[r][i] << " ";
        }
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
    //problem7();
    //problem8();
    //problem9();


    return 0;
}