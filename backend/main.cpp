#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "FCFS.h"
#include "SJF.h"

using namespace std;

int main()
{
    int num_of_proceses, sum_of_burst_time = 0, sum_of_waiting_time = 0, sched_type;
    cout << "Enter number of proceses: \n";
    cin >> num_of_proceses;

    cout << "Enter scheduling criteria (1 for FCFS, 2 for SJF): \n";
    cin >> sched_type;
    if (sched_type == 1)
    {
        vector<process> fcfs_process(num_of_proceses), fcfs_process_new;
        sum_of_burst_time = FCFS::get_input_burst_and_arrival_time(fcfs_process, num_of_proceses);
        FCFS::calc_new_order(fcfs_process, fcfs_process_new, num_of_proceses);
        FCFS::calc_waiting_time(fcfs_process, num_of_proceses);
        FCFS::print_waiting_time_avg_waiting_time(fcfs_process, num_of_proceses);
    }
    else if (sched_type == 2)
    {
        bool sjf_preemptive;
        cout << "preemptive?: \n";
        cin >> sjf_preemptive;
        vector<process> sjf_process(num_of_proceses), sjf_process_new;
        SJF::get_input_burst_and_arrival_time(sjf_process, num_of_proceses);
        if (sjf_preemptive)
        {
            SJF::calc_new_order_p(sjf_process, sjf_process_new, num_of_proceses);
        }
        else
        {
            SJF::calc_new_order_np(sjf_process, sjf_process_new, num_of_proceses);
            sum_of_waiting_time = SJF::calc_waiting_time_np(sjf_process_new, num_of_proceses);
            SJF::print_waiting_time_avg_waiting_time_np(sjf_process_new, num_of_proceses, sum_of_waiting_time);
        }
    }
}