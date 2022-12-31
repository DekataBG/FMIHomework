#include <iostream>
#include <cstring>

struct Vehicle
{
    char name[50];
    int speed;
};

struct Tamagotchi
{
    char name[21];
    int energy, attackPower;
    Vehicle vehicle;

    void printStatus()
    {
        std::cout << "Name: " << name << "\nEnergy: " << energy << "\nVehicle name: " 
            << vehicle.name << "\nVehicle speed: " << vehicle.speed <<  std::endl;
    }

    void speak(char speech[])
    {
        if(energy > 1)
        {
            std::cout << speech << std::endl;
        }

        energy -= 2;
    }

    void sleep(int hours)
    {
        energy += 8 * hours;
        energy = energy >= 100 ? 100 : energy;
    }

    void fightWith(Tamagotchi other)
    {
        if(attackPower < other.attackPower)
        {
            std::cout << "The winner is " << other.name << std::endl;
        }
        else if(attackPower == other.attackPower)
        {
            std::cout << "Draw!" << std::endl;
        }
        else
        {
            std::cout << "The winner is " << name << std::endl;
        }
    }

    int compare(Tamagotchi other)
    {
        return attackPower - other.attackPower;
    }
};

void problem1()
{
    Tamagotchi tamagotchi;

    std::cout << "Enter the Tamagotchi's name: ";
    std::cin.getline(tamagotchi.name, 20);

    std::cout << "Name: " << tamagotchi.name;
}

void problem2()
{
    Tamagotchi tamagotchi;

    std::cout << "Enter the Tamagotchi's name: ";
    std::cin.getline(tamagotchi.name, 20);

    tamagotchi.printStatus();

}

void readTamagotchi(Tamagotchi &tamagotchi)
{
    Vehicle vehicle;

    std::cout << "Enter the Tamagotchi's name: ";
    std::cin >> tamagotchi.name;

    std::cout << "Enter the Tamagotchi's energy: ";
    std::cin >> tamagotchi.energy;

    std::cout << "Enter the vehicle's name: ";
    std::cin.ignore();
    std::cin.getline(tamagotchi.vehicle.name, 50);
    
    std::cout << "Enter the vehicle's speed: ";
    std::cin >> tamagotchi.vehicle.speed;
}

void problem3()
{
    Tamagotchi tamagotchi;

    readTamagotchi(tamagotchi);
    std::cout << "Name: " << tamagotchi.name << std::endl;
}

void problem4()
{
    Tamagotchi tamagotchi;

    readTamagotchi(tamagotchi);
    tamagotchi.printStatus();
}

void problem5()
{
    Tamagotchi tamagotchi;
    char speech[51];
    int hours;

    readTamagotchi(tamagotchi);
    tamagotchi.printStatus();

    std::cout << "Enter speech: ";
    std::cin.ignore();
    std::cin.getline(speech, 50);

    std::cout << "Enter hours: ";
    std::cin >> hours;

    tamagotchi.speak(speech);
    tamagotchi.sleep(hours);

    tamagotchi.printStatus();
}

void problem6()
{
    Tamagotchi mainTamagotchi;
    Tamagotchi enemyTamagotchi;

    readTamagotchi(mainTamagotchi);
    readTamagotchi(enemyTamagotchi);

    std::cout << "Enter " << mainTamagotchi.name << "'s attack: ";
    std::cin >> mainTamagotchi.attackPower;
    
    std::cout << "Enter " << enemyTamagotchi.name << "'s attack: ";
    std::cin >> enemyTamagotchi.attackPower;

    mainTamagotchi.fightWith(enemyTamagotchi);
}

void singSong(char songs[][50], Tamagotchi tamagotchies[], int size)
{
    for(int i = 0; i < size; i++)
    {
        tamagotchies[i].speak(songs[i]);
    }
}

void problem7()
{
    Tamagotchi tamagotchies[10];
    char songs[50][50];
    int n;

    std::cout << "Enter size: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        Tamagotchi tamagotchi;
        char song[50];

        readTamagotchi(tamagotchi);

        std::cout << "Enter song: ";
        std::cin.ignore();
        std::cin.getline(song, 50);
        strcpy(songs[i], song);
    }

    singSong(songs, tamagotchies, n);
}

Tamagotchi findTheStrongest(Tamagotchi tamagotchies[], int size)
{
    Tamagotchi strongest = tamagotchies[0];
    
    for(int i = 1; i < size; i++)
    {
        if(strongest.compare(tamagotchies[i]) < 0)
        {
            strongest = tamagotchies[i];
        }
    }

    return strongest;
}

void problem8()
{
    Tamagotchi tamagotchies[10];
    int n;

    std::cout << "Enter size: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        Tamagotchi tamagotchi;

        readTamagotchi(tamagotchi);

        std::cout << "Enter " << tamagotchi.name << "'s attack power: ";
        std::cin >> tamagotchi.attackPower;

        tamagotchies[i] = tamagotchi;
    }

    Tamagotchi strongest = findTheStrongest(tamagotchies, n);
    strongest.printStatus();
    std::cout << "Power: " << strongest.attackPower << std::endl;
}

void problem9()
{
    Tamagotchi tamagotchi;

    readTamagotchi(tamagotchi);
    tamagotchi.printStatus();
}

void race(Tamagotchi tamagotchies[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i; j < size - 1; j++)
        {
            if(tamagotchies[j].vehicle.speed < tamagotchies[j + 1].vehicle.speed)
            {
                Tamagotchi current = tamagotchies[j];
                tamagotchies[j] = tamagotchies[i];
                tamagotchies[i] = current;
            }
        }
    }
}

void problem10()
{
    Tamagotchi tamagotchies[10];
    int n;

    std::cout << "Enter size: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        Tamagotchi tamagotchi;

        readTamagotchi(tamagotchi);

        tamagotchies[i] = tamagotchi;
    }

    race(tamagotchies, n);

    for(int i = 0; i < n; i++)
    {
        tamagotchies[i].printStatus();
    }
}


int main()
{
    // problem1();
    // problem2();
    // problem3();
    // problem4();
    // problem5();
    // problem6();
    // problem7();
    // problem8();
    // problem9();
    // problem10();


    return 0;
}