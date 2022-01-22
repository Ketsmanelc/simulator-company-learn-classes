#include <iostream>
#include <cassert>
#include <vector>

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

class Team
{
    //Worker* workers = nullptr;
    std::vector<Worker*> worker{1};
    int amountWorkers = 0;
public:
    Team(int inAmountWorkers): amountWorkers (inAmountWorkers)
    {
        assert (inAmountWorkers > 0);
        for (int i = 0; i < inAmountWorkers; i++)
        {
            worker[i] = new Worker(this->getTask());
            worker.push_back(worker[i]);
        }
    }

    int getTask()
    {
        return 1 + std::rand() % (C - 1 + 1);
    }

};

class Manager
{
    int validTask = 0;
    int num = 0;
    int amountWorkers = 0;
    //Worker** workers = nullptr;
    int taskAmount = 0;
public:
    Manager (int inAmountTask, int inAmountWorkers):  validTask(inAmountTask), amountWorkers(inAmountWorkers)
    {
        assert (inAmountTask > 0);
        taskAmount = getAmountTask();
        Team* team = new Team(validTask);
    }


    int getAmountTask()
    {
        std::srand(validTask + num);
        return 1 + std::rand() % (amountWorkers - 1 + 1);
    }

};

class Head
{
    int teamAmount = 0;
public:
    Head(int inTeamAmount): teamAmount(inTeamAmount)
    {
        assert (inTeamAmount > 0);
        Manager **manager = nullptr;
        manager = new Manager *[teamAmount];
        for (int i = 0; i < teamAmount; i++) {

            std::cout << "Team #" << i + 1 << std::endl;
            std::cout << "Workers amount: ";
            int workersAmount = 0;
            std::cin >> workersAmount;
            std::cout << "Boss task: ";
            int bossTask = 0;
            std::cin >> bossTask;
            manager[i] = new Manager(workersAmount, bossTask);
        }
    }
};

int main() {
    int teamAmount;
    std::cout << "Team amount: ";
    std::cin >> teamAmount;
    Head* header = new Head(teamAmount);

    return 0;
}
