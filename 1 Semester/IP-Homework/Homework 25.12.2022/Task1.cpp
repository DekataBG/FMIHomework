#include <iostream>

void getInput(int &n, int &k);
void manageChange(int n, int k);
void lessMoney();
void exactMoney();
void moreMoney(int difference, int money);
void printChange(int count, int money);


int main()
{
    int n, k;

    getInput(n, k);

    manageChange(n, k);


    return 0;
}


void getInput(int &n, int &k)
{
    double nInLevs, kInLevs;

    do
    {
        std::cout << "Enter N: ";
        std::cin >> nInLevs;

        if(nInLevs <= 0)
        {
            std::cout << "N must be positive!" << std::endl;
        }
    } while(nInLevs <= 0);

    do
    {
        std::cout << "Enter K: ";
        std::cin >> kInLevs;

        if(kInLevs <= 0)
        {
            std::cout << "K must be positive!" << std::endl;
        }
    } while(kInLevs <= 0);

    n = (int)(nInLevs * 100);
    k = (int)(kInLevs * 100);
}

void manageChange(int n, int k)
{
    double difference = k - n;

    if(difference < 0)
    {
        lessMoney();
    }
    else if(difference == 0)
    {
        exactMoney(); 
    }
    else
    {
        moreMoney(k - n, 0);
    }
}

void lessMoney()
{
    std::cout << "Money is not enough" << std::endl;
}

void exactMoney()
{
    std::cout << "Alright" << std::endl;
}

void moreMoney(int difference, int index)
{
    int money[13] = {100 * 100, 50 * 100, 20 * 100, 10 * 100, 5 * 100,
                    2 * 100, 1 * 100, 50, 20, 10, 5, 2, 1};

    if(difference == 0)
    {
        return;
    }

    int current = money[index];
    int count = difference / current;
    difference -= count * current;

    moreMoney(difference, index + 1);

    printChange(count, current);
}

void reduceDifference(int &difference, int money)
{
    int count = difference / money;
    difference -= count * money;

    if(count > 0)
    {
        std::cout << count << " - ";

        if(money >= 100)
        {
            std::cout << money / 100 << " lv" << std::endl;
        }
        else
        {
            std::cout << money << " st" << std::endl;
        }
    }
}

void printChange(int count, int money)
{
    if(count > 0)
    {
        if(money >= 100)
        {
            std::cout << count << " - " << money / 100 << " lv" << std::endl;
        }
        else
        {
            std::cout << count << " - " << money << " st" << std::endl;
        }
    }
}