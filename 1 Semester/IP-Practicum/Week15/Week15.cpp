#include <iostream>

void problem1()
{
  int n;

  std::cout << "Enter n: ";
  std::cin >> n;   

  int *arr = new int[n];
  for(int i = 0; i < n; i++)
  {
    std::cout << "Enter element: ";
    std::cin >> arr[i];
  }

  for(int i = 0; i < n; i++)
  {
    std::cout << arr[n - 1 - i] << " ";
  }

  delete []arr;
}

struct IntVector
{
  int *arr;
  int size;

  void push_back(int a)
  {
    int *newArr = new int[size + 1];
    
    for(int i = 0; i < size; i++)
    {
      newArr[i] = arr[i];
    }
    newArr[size] = a;

    delete[] arr;
    arr = newArr;

    size++;
  }

  void pop_back()
  {
    int *newArr = new int[size - 1];
    
    for(int i = 0; i < size - 1; i++)
    {
      newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;

    size--;
  }

  int getOnIndex(int idx)
  {
    return arr[idx];
  }
};

void problem2()
{
  IntVector vector {nullptr, 0};

  vector.push_back(1);
  vector.push_back(2);
  vector.push_back(3);
  vector.push_back(4);
  vector.push_back(5);
  vector.pop_back();

  std::cout << vector.getOnIndex(0) << std::endl;
  std::cout << vector.getOnIndex(1) << std::endl;
  std::cout << vector.getOnIndex(2) << std::endl;
  std::cout << vector.getOnIndex(3) << std::endl;

  vector.pop_back();
  vector.pop_back();

  std::cout << vector.getOnIndex(0) << std::endl;
  std::cout << vector.getOnIndex(1) << std::endl;

  delete []vector.arr;
}

struct Graph
{
  int **matrix;
  int n;
  int m;

  void buildMatrix()
  {
    std::cout << "Enter the number of vertices: ";
    std::cin >> n;

    std::cout << "Enter the number of edges: ";
    std::cin >> m;

    matrix = new int*[n];
    for(int i = 0; i < n; i++)
    {
      matrix[i] = new int[n];
    }

    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        matrix[i][j] = 0;
      }
    }

    for(int i = 0; i < m; i++)
    {
      int v1, v2;

      std::cout << "Enter the first vertex of the edge: ";
      std::cin >> v1;
      
      std::cout << "Enter the second vertex of the edge: ";
      std::cin >> v2;

      matrix[v1 - 1][v2 - 1] = 1;
      matrix[v2 - 1][v1 - 1] = 1;
    }
  }

  void showMatrix()
  {
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        std::cout << matrix[i][j] << " ";
      }
      
      delete []matrix[i];
      std::cout << std::endl;
    }

    delete []matrix;
  }
};

void problem3()
{
  Graph graph;

  graph.buildMatrix();
  graph.showMatrix();
}

void problem4()
{
  int n, m;
  int *arr1 = new int[n];
  int *arr2 = new int[m];

  std::cout << "Enter n: ";
  std::cin >> n;

  std::cout << "Enter m: ";
  std::cin >> m;

  for(int i = 0; i < n; i++)
  {
    std::cout << "Enter element for array 1: ";
    std::cin >> arr1[i];
  }

  for(int i = 0; i < m; i++)
  {
    std::cout << "Enter element for array 2: ";
    std::cin >> arr2[i];
  }

  int *arr3 = new int[n + m];
  for(int i = 0; i < n; i++)
  {
    arr3[i] = arr1[i];
  }
  for(int i = 0; i < m; i++)
  {
    arr3[i + n] = arr2[i];
  }

  for(int i = 0; i < n + m; i++)
  {
    std::cout << arr3[i] << " ";
  }

  delete []arr1;
  delete []arr2;
  delete []arr3;
}


int main() 
{
  // problem1();
  // problem2();
  // problem3();
  // problem4();


  return 0;
}