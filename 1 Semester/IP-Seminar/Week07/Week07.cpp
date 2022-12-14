#include <iostream>
#include <cmath>

void problem1()
{
    int n;
    int matrix[100][100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << "Enter matrix[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }   
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << matrix[i][j] << " ";
        }   
        std::cout << std::endl;
    }
}

void problem2()
{
    int n, sum = 0;

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int element;

            std::cout << "Enter matrix[" << i << "][" << j << "]: ";
            std::cin >> element;

            sum += element;
        }   
    }

    std::cout << "The sum is " << sum;
}

int deFlatten(int arr[], int columns, int i, int j)
{
    int index = i * columns + j;

    return arr[index];
}

void problem3()
{
    int n;
    int arr[100];
    int columns, row, col;

    std::cout << "Enter array size: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter array element: ";
        std::cin >> arr[i];
    }

    std::cout << "Enter number of columns: ";
    std::cin >> columns;

    std::cout << "Enter row: ";
    std::cin >> row;

    std::cout << "Enter column: ";
    std::cin >> col;

    std::cout << "Matrix[" << row << "][" << col << "] = " << deFlatten(arr, columns, row, col) << std::endl;
}

bool equalDiagonals(int matrix[][100], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(matrix[i][i] != matrix[i][n - i - 1])
        {
            return false;
        }
        
    }

    return true;
}

void problem4()
{
    int n;
    int matrix[100][100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << "Enter matrix[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }   
    }

    std::cout << (equalDiagonals(matrix, n) ? "The diagonals are equal" : "The diagonals arent equal") << std::endl;
}

bool zeroBelowDiagonal(int matrix[][100], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(matrix[i][j] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

void problem5()
{
    int n;
    int matrix[100][100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << "Enter matrix[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }   
    }

    std::cout << (zeroBelowDiagonal(matrix, n) ? "The elements below the main diagonal are zero" 
        : "The elements below the main diagonal arent zero") << std::endl;
}

void problem6()
{
    int n, m;
    int matrix[100][100];
    int maxNumbers[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter m: ";
    std::cin >> m;

    for(int i = 0; i < n; i++)
    {
        int max = INT_MIN;
        for(int j = 0; j < m; j++)
        {
            int element;

            std::cout << "Enter matrix[" << i << "][" << j << "]: ";
            std::cin >> element;
            matrix[i][j] = element;

            if(element > max)
            {
                max = element;
            }
        }
        maxNumbers[i] = max;  
    }

    for(int i = 0; i < n; i++)
    {
        std::cout << maxNumbers[i] << std::endl;
    }
}

void problem7()
{
    int n, m, row1, row2;
    int matrix[100][100];
    int buffer[100];

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

    std::cout << "Enter row1: ";
    std::cin >> row1;

    std::cout << "Enter row2: ";
    std::cin >> row2;

    for(int i = 0; i < m; i++)
    {
        int temp = matrix[row2][i];
        matrix[row2][i] = matrix[row1][i];
        matrix[row1][i] = temp;
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

int decodeNumber(int n)
{
    int ctr = 0;
    while(n % 2 == 0)
    {
        n /= 2;
        ctr++;
    }

    return ctr;
}

void showPath(int buffer[], int size)
{
    std::cout << "One path is: ";

    int row0 = decodeNumber(buffer[0]);
    int col0 = (buffer[0] / pow(2, row0)) / 2;
    std::cout << "(" << row0 << ", " << col0 << ")";

    for(int i = 1; i < size; i++)
    {
        int row = decodeNumber(buffer[i]);
        int col = (buffer[i] / pow(2, row)) / 2;
        std::cout << " -> (" << row << ", " << col << ")";
    }
    std::cout << std::endl;
}

void findPath(int matrix[][100], int rows, int cols, int currentRow, int currentCol, int buffer[], int bufferSize)
{
    buffer[bufferSize] = pow(2, currentRow) * (2 * currentCol + 1);

    if(currentRow == rows - 1 && currentCol == cols - 1)
    {
        showPath(buffer, bufferSize + 1);
        return;
    }
    if(currentCol != cols - 1 && matrix[currentRow][currentCol + 1] == 1)
    {
        findPath(matrix, rows, cols, currentRow, currentCol + 1, buffer, bufferSize + 1);
    }
    if(currentRow != rows - 1 && matrix[currentRow + 1][currentCol] == 1)
    {
        findPath(matrix, rows, cols, currentRow + 1, currentCol, buffer, bufferSize + 1);
    }
    if(currentCol != cols - 1 && currentRow != rows - 1 && matrix[currentRow + 1][currentCol + 1] == 1)
    {
        findPath(matrix, rows, cols, currentRow + 1, currentCol + 1, buffer, bufferSize + 1);
    }
}

void problem8()
{
    int n, m;
    int matrix[100][100];

    std::cout << "Enter rows: ";
    std::cin >> n;

    std::cout << "Enter columns: ";
    std::cin >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cout << "Enter matrix[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    int buffer[100];
    findPath(matrix, n, m, 0, 0, buffer, 0);
}

void showWinner(char board[3][3], int row, int col)
{
    char symbol = board[row][col] == 'X' ? '1' : '2';
    board[0][0] = symbol;
}

bool rowWins(char board[3][3], int row)
{
    if(board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != '-')
    {
        showWinner(board, row, 0);
        return true;
    }

    return false;
}

bool colWins(char board[3][3], int col)
{   
    if(board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != '-')
    {
        showWinner(board, 0, col);
        return true;
    }

    return false;
}

bool diagonalWins(char board[3][3])
{   
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-')
        || (board[0][2] && board[1][1] == board[2][0] && board[1][1] != '-'))
    {
        showWinner(board, 1, 1);
        return true;
    }

    return false;
}

bool isFinished(char board[3][3])
{   
    for(int i = 0; i < 3; i++)
    {
        if(rowWins(board, i) || colWins(board, i))
        {
            return true;
        }
    }

    return diagonalWins(board);
}

bool invalidCoordinates(char board[3][3], int row, int col)
{
    return row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != '-';
}

void printBoard(char board[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout << board[i][j] << " ";
        }    
        std::cout << std::endl;
    }
}

void problem9()
{
    char board[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    bool winner = false;

    int ctr = 0;
    while(!isFinished(board) && ctr != 9)
    {
        int row, col;

        std::cout << (ctr % 2 == 0 ? "Place X: " : "Place O: ");
        std::cout << "Enter the cell's coordinates(1, 2, 3): ";
        std::cin >> row >> col;

        if(invalidCoordinates(board, row, col))
        {
            std::cout << "Invalid coordinates" << std::endl;
        }
        else
        {
            char symbol = ctr % 2 == 0 ? 'X' : 'O';
            board[row - 1][col - 1] = symbol;

            ctr++;
            printBoard(board);
        }
    }

    std::cout << "The game finished" << std::endl;

    if(board[0][0] == '1')
    {
        std::cout << "X wins";
    }
    else if(board[0][0] == '2')
    {
        std::cout << "O wins";
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
    problem9();


    return 0;
}