//
// Created by jakgo on 2022-04-22.
//

#ifndef CSCHEDULER_SCHEDULER_H
#define CSCHEDULER_SCHEDULER_H

#include <vector>
#include "task.h"
#include "time_utils.h"
class scheduler{
private:
    std::vector<task> taskList;
public:
    time_t onTick(uint64_t currentTick);
    void clear_all_tasks();
    void schedule(void(*ifp)(), uint64_t delay, uint64_t period);
    void run_later(void(*ifp)(), uint64_t delay);
};
#endif //CSCHEDULER_SCHEDULER_H
