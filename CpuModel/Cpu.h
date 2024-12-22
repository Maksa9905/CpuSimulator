#pragma once

#include "Core.h"
#include <queue>

using namespace std;

class Cpu {
    Core* cores;
    int coresCount;
    queue<Task> taskQueue;

public:
    Cpu(int _coresCount);
    Core* getCores();
    int getCoresCount();
    queue<Task> getTaskQueue();

    int getFreeCoresCount();

    void distributeTask(Task task);

    void execute();

    void addTask(Task task);

    void print();
};