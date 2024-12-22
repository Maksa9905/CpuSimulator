#pragma once

#include "Task.h"

class Core {
    bool isBusy;
    Task * task;
    int currentStepIndex;
    int freeStepsCount;
    int solvedTasksCount;

public:
    Core();
    Core(
        bool _isBusy, 
        Task _task,
        int _currentStepIndex, 
        int _freeStepsCount, 
        int _solvedTasksCount
    );

    bool getIsBusy();
    Task getTask();
    int getCurrentStepIndex();
    int getFreeStepsCount();
    int getSolvedTasksCount();

    void setIsBusy(bool _isBusy);
    void setTask(Task _task);
    void setCurrentStepIndex(int _currentStepIndex);
    void setFreeStepsCount(int _freeStepsCount);
    void setSolvedTasksCount(int _solvedTasksCount);

    void addTask(Task _task);

    void execute();

    void print();

    void printTask();
};