#ifndef FCFS_H
#define FCFS_H

#include <iostream>
#include <QVector>
#include <numeric>
#include <algorithm>
#include "types.h"

using namespace std;

namespace FCFS
{
    void get_input_burst_and_arrival_time(QVector<process> &fcfs_process, int num_of_proceses); // Used for testing
    void calc_new_order(QVector<process> &fcfs_process, QVector<process> &fcfs_process_new, int num_of_proceses);
}

#endif