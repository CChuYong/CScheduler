#include "task.h"
#include <stdint.h>

#define ZERO 0

task::task(void(*ifp)(), uint64_t delay, uint64_t period){
    this->fp = ifp;
    this->delay = delay;
    this->lastExecution = delay;
    this->period = period;
}

task::task(void(*ifp)(), uint64_t delay){
    this->fp = ifp;
    this->delay = delay;
    this->lastExecution = delay;
    this->period = ZERO;
}

void task::execute(uint64_t currentTick){
    if(is_completed()) return;
    if(delay > ZERO){
        delay--;
        return;
    }
    if(period == ZERO) period--;
    if((currentTick - lastExecution) % period == ZERO){
        (*fp)();
        this->lastExecution = currentTick;
    }
}

bool task::is_completed(){
    return this->period < ZERO;
}