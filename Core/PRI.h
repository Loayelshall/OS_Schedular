#ifndef PRI_H
#define PRI_H

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>
#include "types.h"

using namespace std;

namespace PRI
{
    void get_input_burst_arrival_time_priority(vector<process> &pri_process, int num_of_proceses);
    void calc_new_order_np(vector<process> &pri_process, vector<process> &pri_process_new, int num_of_proceses);
    void calc_new_order_p(vector<process> &pri_process, vector<process> &pri_process_new, int num_of_proceses);
}

#endif