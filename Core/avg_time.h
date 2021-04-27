#ifndef AVG_TIME_H
#define AVG_TIME_H

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "types.h"

using namespace std;

float avg_waiting_time(vector<process> process_vector, int num_of_processes);

#endif