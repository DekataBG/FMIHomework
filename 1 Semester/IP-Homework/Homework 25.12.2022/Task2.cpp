#include <iostream>

void getInput(int maze[8][8]);
void getOutput(int maze[8][8]);
bool path(int maze[8][8], int start_x, int start_y, int end_x, int end_y);
bool canGo(int maze[8][8], int start_x, int start_y);
bool isInMaze(int maze[8][8], int x, int y);

int main()
{
    int maze[8][8];

    getInput(maze);

    getOutput(maze);
    

    return 0;
}

void getInput(int maze[8][8])
{
    int defaultMaze[8][8] = {
    {0, 1, 0, 1, 1, 0, 1, 0}, 
    {0, 1, 0, 0, 0, 0, 1, 1}, 
    {0, 1, 1, 0, 1, 0, 1, 0}, 
    {0, 1, 0, 0, 0, 0, 0, 1}, 
    {0, 0, 0, 1, 1, 1, 0, 0}, 
    {0, 1, 0, 0, 0, 1, 1, 0}, 
    {0, 1, 0, 1, 0, 0, 1, 1}, 
    {0, 1, 0, 0, 1, 0, 0, 0}};

    char option;

    std::cout << "Would you like to use the default maze(from the task description)? [Y/y]";
    std::cin >> option;

    if(option == 'Y' || option == 'y')
    {
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                maze[i][j] = defaultMaze[i][j];
            }
        }
    }
    else
    {
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                std::cout << "Enter maze[" << i << "][" << j << "]: ";
                std::cin >> maze[i][j];
            }
        }
    }
}

void getOutput(int maze[8][8])
{
    int start_x, start_y, end_x, end_y;

    std::cout << "Enter start_x: ";
    std::cin >> start_x;
    
    std::cout << "Enter start_y: ";
    std::cin >> start_y;
    
    std::cout << "Enter end_x: ";
    std::cin >> end_x;
    
    std::cout << "Enter end_y: ";
    std::cin >> end_y;

    if(!path(maze, end_x, end_y, start_x, start_y))
    {
        std::cout << "A path doesn't exist" << std::endl;
    }
}

bool path(int maze[8][8], int start_x, int start_y, int end_x, int end_y)
{
    if(start_x == end_x && start_y == end_y)
    {
        std::cout << "(" << start_x << ", " << start_y << ")";
        return true;
    }

    maze[start_x][start_y] = 1;

    if(canGo(maze, start_x + 1, start_y) && path(maze, start_x + 1, start_y, end_x, end_y))
    {
        std::cout << " -> (" << start_x << ", " << start_y << ")";
        return true;
    }

    if(canGo(maze, start_x - 1, start_y) && path(maze, start_x - 1, start_y, end_x, end_y))
    {
        std::cout << " -> (" << start_x << ", " << start_y << ")";
        return true;
    }

    if(canGo(maze, start_x, start_y - 1) && path(maze, start_x, start_y - 1, end_x, end_y))
    {
        std::cout << " -> (" << start_x << ", " << start_y << ")";
        return true;
    }
    
    if(canGo(maze, start_x, start_y + 1) && path(maze, start_x, start_y + 1, end_x, end_y))
    {
        std::cout << " -> (" << start_x << ", " << start_y << ")";
        return true;
    }

    return false;
}

bool canGo(int maze[8][8], int start_x, int start_y)
{
    if(isInMaze(maze, start_x, start_y) && maze[start_x][start_y] == 0)
    {
        return true;
    }

    return false;
}

bool isInMaze(int maze[8][8], int x, int y)
{
    if(x >= 8 || x < 0 || y >= 8 || y < 0)
    {
        return false;
    }

    return true;
}
