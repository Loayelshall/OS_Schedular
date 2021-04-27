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
    void get_input_burst_and_arrival_time(vector<process> &fcfs_process, int num_of_proceses); // Used for testing
    void calc_new_order(vector<process> &fcfs_process, vector<process> &fcfs_process_new, int num_of_proceses);
}

#endif