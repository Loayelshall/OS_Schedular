#ifndef RR_H
#define RR_H

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "types.h"

using namespace std;

namespace RR
{
    int get_input_burst_and_arrival_time(vector<process> &rr_process, int num_of_proceses);
    void calc_new_order(vector<process> &rr_process, vector<process> &rr_process_new, int num_of_proceses);
}

#endif