#ifndef TYPES_H
#define TYPES_H

struct process
{
    int process_num;
    float burst_time, arrival_time, priority_num, start_time, stop_time, waiting_time;
};

struct wait_time
{
    float wait_time, stop_time = -1;
};
#endif