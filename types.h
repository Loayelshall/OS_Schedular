#ifndef TYPES_H
#define TYPES_H

struct process
{
    int process_num;
    float burst_time, waiting_time, arrival_time, remaining_time, priority_num, start_time, stop_time;
};

#endif
