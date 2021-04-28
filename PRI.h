#ifndef PRI_H
#define PRI_H

#include <iostream>
#include <QVector>
#include <queue>
#include <numeric>
#include <algorithm>
#include "types.h"

using namespace std;

namespace PRI
{
    void get_input_burst_arrival_time_priority(QVector<process> &pri_process, int num_of_proceses);
    void calc_new_order_np(QVector<process> &pri_process, QVector<process> &pri_process_new, int num_of_proceses);
    void calc_new_order_p(QVector<process> &pri_process, QVector<process> &pri_process_new, int num_of_proceses);
}

#endif
