#ifndef SJF_H
#define SJF_H


#include <QApplication>
#include <iostream>
#include <QVector>
#include <queue>
#include <numeric>
#include <algorithm>
#include "types.h"

using namespace std;

namespace SJF
{
    void get_input_burst_and_arrival_time(QVector<process> &sjb_process, int num_of_proceses);
    void calc_new_order_np(QVector<process> &sjf_process, QVector<process> &sjf_process_new, int num_of_proceses);
    void calc_new_order_p(QVector<process> &sjf_process, QVector<process> &sjf_process_new, int num_of_proceses);
    float calc_waiting_time_np(QVector<process> &sjb_process, int num_of_proceses);
    void print_waiting_time_avg_waiting_time_np(QVector<process> &sjb_process, int num_of_proceses, float sum_of_waiting_time);
}

#endif
