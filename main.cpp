#include <iostream>
#include <cassert>

enum Tasks
{
    NONE,
    A,
    B,
    C
};

class Worker
{
    int task = NONE;
public:
    Worker(int inTask): task(inTask)
    {
        assert(inTask > 0 && inTask <= 3);
    }

    int getTask()
    {
        return task;
    }
    void setTask(int inTask)
    {
        task = inTask;
    }
};

class Manager
{
    int validTask = 0;
    int num = 0;
    int amountWorkers = 0;
    Worker** workers = nullptr;
    int taskAmount = 0;
public:
    Manager (int inAmountWorkers, int inAmountTask): amountWorkers(inAmountWorkers), validTask(inAmountTask)
    {
        assert (inAmountWorkers > 0);
        workers = new Worker*[inAmountWorkers];
        taskAmount = getAmountTask();
        for (int i = 0; i < amountWorkers && i < taskAmount; i++)
        {
            workers[i] = new Worker(this->getTask());
        }
    }
    int getAmountTask()
    {
        std::srand(validTask + num);
        return 1 + std::rand() % (amountWorkers - 1 + 1);
    }
    int getTask()
    {
        return 1 + std::rand() % (C - 1 + 1);
    }
};

int main() {
    int teamAmount;
    std::cout << "Team amount: ";
    std::cin >> teamAmount;
    Manager** manager = nullptr;
    manager = new Manager*[teamAmount];
    for(int i = 0; i < teamAmount; i++)
    {
        std::cout << "Team #" << i + 1 << std::endl;
        std::cout << "Workers amount: ";
        int workersAmount = 0;
        std::cin >> workersAmount;
        std::cout << "Boss task: ";
        int bossTask = 0;
        std::cin >> bossTask;
        manager[i] = new Manager(workersAmount, bossTask);
    }
    return 0;
}
