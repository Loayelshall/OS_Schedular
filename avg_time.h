#ifndef AVG_TIME_H
#define AVG_TIME_H

#include <iostream>
#include <QVector>
#include <numeric>
#include <algorithm>
#include "types.h"

using namespace std;

float avg_waiting_time(QVector<process> process_QVector, int num_of_processes);

#endif