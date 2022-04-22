//
// Created by jakgo on 2022-04-22.
//
#include <iostream>
#include <thread>
#include "../scheduler.h"
using namespace std;
static void print_hello_world(){
    cout << "Hello World" << endl;
}

static void print_goodbye_world(){
    cout << "Goodbye world" << endl;
}
static void print_later_test(){
    cout << "Goodbye Later" << endl;
}
int main()
{
    scheduler sc;
    sc.schedule(print_hello_world, 3, 10);
    sc.schedule(print_goodbye_world, 0, 3);
    sc.run_later(print_later_test, 3);
    uint64_t tick = 0;

    time_t lastDelay = 0;
    for(;;){
        time_t newDelay = 100 - lastDelay;
        this_thread::sleep_for(std::chrono::milliseconds(newDelay > 0 ? newDelay : 0));
        lastDelay = sc.onTick(tick++);
    }
    return 0;
}