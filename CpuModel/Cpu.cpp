#include "Cpu.h"
#include "Task.h"
#include <iostream>

using namespace std;

Cpu::Cpu(int _coresCount) {
    coresCount = _coresCount;
    cores = new Core[coresCount];
}

Core* Cpu::getCores() {
    return cores;
}

int Cpu::getCoresCount() {
    return coresCount;
}

queue<Task> Cpu::getTaskQueue() {
    return taskQueue;
};

int Cpu::getFreeCoresCount() {
    int count = 0;
    for (int i = 0; i < coresCount; i++) {
        if (!cores[i].getIsBusy()) {
            count++;
        }
    }
    return count;
};

void Cpu::distributeTask(Task task) {
    int assignedCoresCount = 0;

    for (int i = 0; i < coresCount && assignedCoresCount != task.coresCount; i++) {
        if (!cores[i].getIsBusy()) {
            cores[i].addTask(task);
            assignedCoresCount++;
        }
    }
};

void Cpu::execute() {
    for (int i = 0; i < coresCount; i++) {
        cores[i].execute();
    }

    Task task = taskQueue.front();
    taskQueue.pop();

    if (task.coresCount <= getFreeCoresCount()) {
        distributeTask(task);
    } else taskQueue.push(task);
};

void Cpu::addTask(Task task) {
    taskQueue.push(task);
};

void Cpu::print() {
    for (int i = 0; i < coresCount; i++) {
        cores[i].print();
    }

    cout << " ================TASKS QUERY================ " << endl;

    for (int i = 0; i < taskQueue.size(); i++) {
        cout << "TASK: " << taskQueue._Get_container()[i].id << " steps: " << taskQueue._Get_container()[i].stepsCount << endl;
    }
};