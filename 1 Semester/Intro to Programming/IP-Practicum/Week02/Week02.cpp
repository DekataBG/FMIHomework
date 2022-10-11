#include <iostream>
#include <cmath>

#include <iomanip> //for setprecision

void problem1()
{
    int years;

    std::cout << "Enter years: ";
    std::cin >> years;

    if(years >= 18)
    {
        std::cout << "Happy Misho";
    }
    else
    {
        std::cout << "Sad Misho";
    }

}

void problem2()
{
    double money, whiskey, nargile;
    int people;

    std::cout << "Enter Misho's money: ";
    std::cin >> money;

    std::cout << "Enter the whiskey's price: ";
    std::cin >> whiskey;

    std::cout << "Enter the nargile's price: ";
    std::cin >> nargile;

    std::cout << "Enter the number of people: ";
    std::cin >> people;

    bool canOrder = money >= ceil(whiskey / people) + nargile;

    std::cout << std::boolalpha << canOrder;
}

void problem3()
{
    double taxi1, taxi2, taxi3, first, second, third;

    std::cout << "Enter taxi1's price: ";
    std::cin >> taxi1;

    std::cout << "Enter taxi2's price: ";
    std::cin >> taxi2;

    std::cout << "Enter taxi3's price: ";
    std::cin >> taxi3;

    first = taxi1 <= taxi2 ? taxi1 <= taxi3 ? taxi1 : taxi3 : taxi2 <= taxi3 ? taxi2 : taxi3;
    third = taxi1 >= taxi2 ? taxi1 >= taxi3 ? taxi1 : taxi3 : taxi2 >= taxi3 ? taxi2 : taxi3;
    second = taxi1 + taxi2 + taxi3 - first - third;

    std::cout << first << " " << second << " " << third;
}

void problem4()
{
    double a, b, c;
    int negativeSigns = 0;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Enter c: ";
    std::cin >> c;

    if(a < 0)
    {
        negativeSigns++;
    }
    if(b < 0)
    {
        negativeSigns++;
    }
    if(c < 0)
    {
        negativeSigns++;
    }

    if(a == 0 || b == 0 || c == 0)
    {
        std::cout << "The product is 0.";
    }
    else if(negativeSigns % 2 == 1)
    {
        std::cout << "The product is negative.";
    }
    else
    {
        std::cout << "The product is positive.";
    }
}

void problem5()
{
    double a, b, c;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Enter c: ";
    std::cin >> c;

    if(a == 0)
    {
        if(b == 0)
        {
            if(c == 0)
            {
                std::cout << "Infinitely many roots";
            }
            else
            {
                std::cout << "no roots";
            }
        }
        else
        {
            double root = - c / b;
            std::cout << root;
        }
    }
    else
    {
        double discriminant = b * b - 4 * a * c;

        if(discriminant < 0)
        {
            std::cout << "no roots";
        }
        else if(discriminant == 0)
        {
            double root = - b / (2 * a);
            std::cout << root;
        }
        else
        {
            double root1 = (- b - sqrt(discriminant)) / (2 * a);
            double root2 = (- b + sqrt(discriminant)) / (2 * a);

            std::cout << root1 << " " << root2;
        }
    }
}

void problem6()
{
    double a, b;
    char operation;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter operation: ";
    std::cin >> operation;

    std::cout << "Enter b: ";
    std::cin >> b;

    switch(operation)
    {
        case '+': 
            std::cout << a + b;
            break;
        case '-': 
            std::cout << a - b;
            break;
        case '*': 
            std::cout << a * b;
            break;
        case '/': 
            std::cout << a / b;
            break;
        case '^': 
            std::cout << pow(a, b);
            break;
        case 'V': 
            std::cout << sqrt(a) << " " << sqrt(b);
            break;
        default:
            std::cout << std::fixed << std::setprecision(b) << a;
            break;
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


    return 0;
}