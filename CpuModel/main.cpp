#include "Cpu.h"
#include <iostream>
#include "UUID.h"
#include <thread>
#include <chrono>

using namespace std;

const int MILI_SECOND = 1000000;

int main() {
    srand(time(nullptr));

    int coresCount;
    int stepTime;

    int minCoresCount;
    int maxCoresCount;

    int minStepsCount;
    int maxStepsCount;

    cout << "Enter cores count: ";
    cin >> coresCount;
    cout << endl;

    cout << "Enter step time (in miliseconds): ";
    cin >> stepTime;
    cout << endl;

    cout << "Enter task's min cores count: ";
    cin >> minCoresCount;
    cout << endl;

    cout << "Enter task's max cores count: ";
    cin >> maxCoresCount;
    cout << endl;

    cout << "Enter task's min steps count: ";
    cin >> minStepsCount;
    cout << endl;

    cout << "Enter task's max steps count: ";
    cin >> maxStepsCount;
    cout << endl;


    Cpu cpu(coresCount);

    for (int i = 0; i < 1000; i++) {
        this_thread::sleep_for(std::chrono::nanoseconds(MILI_SECOND * stepTime));

        int coresCount = minCoresCount + rand() % (maxCoresCount - minCoresCount);
        int stepsCount = minStepsCount + rand() % (maxStepsCount - minStepsCount);

        Task task = { coresCount, stepsCount, UUID().getUUID() };

        system("cls");
        cpu.print();

        cpu.addTask(task);
        cpu.execute();
    };

    return 0;
};
