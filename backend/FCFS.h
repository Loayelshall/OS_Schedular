#ifndef FCFS_H
#define FCFS_H

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "types.h"

using namespace std;

namespace FCFS
{
    int get_input_burst_and_arrival_time(vector<process> &fcfs_process, int num_of_proceses);
    void calc_waiting_time(vector<process> &fcfs_process, int num_of_proceses);
    void print_waiting_time_avg_waiting_time(vector<process> &fcfs_process, int num_of_proceses);
    void calc_new_order(vector<process> &fcfs_process, vector<process> &fcfs_process_new, int num_of_proceses);
}

#endif