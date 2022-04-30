//
// Created by jakgo on 2022-04-22.
//

#include "scheduler.h"
#include "task.h"
#include "time_utils.h"
#include <vector>
#include <stdint.h>

time_t scheduler::onTick(uint64_t currentTick) {
    time_t startTime = get_current_time_mills();
    for (std::vector<task>::iterator ptr = taskList.begin(); ptr < taskList.end(); ptr++) {
        (*ptr).execute(currentTick);
    }
    return get_current_time_mills() - startTime;
}

void scheduler::schedule(void(*ifp)(), uint64_t delay, uint64_t period) {
    taskList.push_back(task(ifp, delay, period));
}

void scheduler::run_later(void(*ifp)(), uint64_t delay){
    taskList.push_back(task(ifp, delay));
}
void scheduler::clear_all_tasks() {
    taskList.clear();
}
