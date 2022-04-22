#ifndef CSCHEDULER_TASK_H
#define CSCHEDULER_TASK_H
#include <stdint.h>

class task{
private:
    void (*fp)();
    uint64_t delay;
    uint64_t period;
    uint64_t lastExecution;
public:
    task(void(*ifp)(), uint64_t delay, uint64_t period);
    task(void(*ifp)(), uint64_t delay);
    void execute(uint64_t currentTick);
    bool is_completed();
};


#endif //CSCHEDULER_TASK_H
