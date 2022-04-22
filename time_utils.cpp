//
// Created by jakgo on 2022-04-22.
//

#include "time_utils.h"
struct timeval time_now{};
static void update_current_time(){
    gettimeofday(&time_now, nullptr);
}
time_t get_current_time_mills(){
    update_current_time();
    return (get_current_time_secs() * 1000) + (get_current_time_usecs() / 1000);
}
time_t get_current_time_secs(){
    update_current_time();
    return time_now.tv_sec;
}
time_t get_current_time_usecs(){
    update_current_time();
    return time_now.tv_usec;
}