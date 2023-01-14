#include <iostream>
#include <cmath>
#include <cstring>

struct Vector3D
{
    double x, y, z;

    double length(const Vector3D& V)
    {
        return sqrt(V.x * V.x + V.y * V.y + V.z * V.z);
    }

    double dotProduct(const Vector3D& V1, const Vector3D& V2)
    {
        return V1.x * V2.x + V1.y * V2.y + V1.z * V2.z;
    }

    Vector3D crossProduct(const Vector3D& V1, const Vector3D& V2)
    {
        double x = V1.y * V2.z - V1.z * V2.y;
        double y = V1.z * V2.x - V1.x * V2.z;
        double z = V1.x * V2.y - V1.y * V2.x;

        return Vector3D { x, y, z };
    }

    double triple(const Vector3D& V1, const Vector3D& V2, const Vector3D& V3)
    {
        return dotProduct(V1, crossProduct(V2, V3));
    }

    void multiplyByScalar(Vector3D& V, double scalar)
    {
        V.x *= scalar;
        V.y *= scalar;
        V.z *= scalar;
    }

    void normalizeVector(Vector3D& V)
    {
        double length = V.length(V);

        V.x /= length;
        V.y /= length;
        V.z /= length;
    }

    Vector3D getNegative(const Vector3D& V)
    {
        double newX = -1 * V.x;
        double newY = -1 * V.y;
        double newZ = -1 * V.z;

        return Vector3D { newX, newY, newZ };
    }

    Vector3D sum(const Vector3D& V1, const Vector3D& V2)
    {
        double newX = V1.x + V2.x;
        double newY = V1.y + V2.y;
        double newZ = V1.z + V2.z;

        return Vector3D { newX, newY, newZ };
    }

    Vector3D difference(const Vector3D& V1, const Vector3D& V2)
    {
        return sum(V1, getNegative(V2));
    }
};

struct Box
{
    Vector3D min, max;

    Vector3D getCenter(const Box& box)
    {
        double newX = (min.x + max.x) / 2;
        double newY = (min.y + max.y) / 2;
        double newZ = (min.z + max.z) / 2;

        return Vector3D { newX, newY, newZ };
    }

    Vector3D getExtent(const Box& box)
    {
        double newX = (max.x + min.x);
        double newY = (max.y + min.y);
        double newZ = (max.z + min.z);

        return Vector3D { newX, newY, newZ };
    }

    bool intersectBox(const Box& B1, const Box& B2)
    {
        if(!((B2.min.x >= B1.min.x && B2.min.x <= B1.max.x) || 
            (B2.max.x >= B1.min.x && B2.max.x <= B1.max.x)))
        {
            return false;
        }

        if(!((B2.min.y >= B1.min.y && B2.min.y <= B1.max.y) || 
            (B2.max.y >= B1.min.y && B2.max.y <= B1.max.y)))
        {
            return false;
        }

        if(!((B2.min.z >= B1.min.z && B2.min.z <= B1.max.z) || 
            (B2.max.z >= B1.min.z && B2.max.z <= B1.max.z)))
        {
            return false;
        }

        return true;
    }
};

struct Worker
{
    char name[1025];
    double salary;
    Worker *boss;

    void printCEO()
    {
        while(boss->boss != nullptr)
        {
            boss = boss->boss;
        }

        std::cout << boss->name << std::endl;
    }
};

struct Team
{
    char name[1025];
    Worker workers[100];
    int workersCount;
};

struct Company
{
    char name[1025];
    Team teams[50];
    int teamsCount;

    bool isWorkerInCompany(char name[])
    {
        for(int i = 0; i < teamsCount; i++)
        {
            Team team = teams[i];
            int workersCount = team.workersCount;

            for(int j = 0; j < workersCount; j++)
            {
                if(strcmp(name, team.workers[j].name) == 0)
                {
                    return true;
                }
            }
        }

        return false;
    }
};