#include "RR.h"

int RR::get_input_burst_and_arrival_time(vector<process> &rr_process, int num_of_proceses)
{
    int burst_time, arrival_time, sum_of_burst_time = 0;
    for (size_t i = 0; i < num_of_proceses; i++)
    {
        cout << "Enter burst time for process " << i + 1 << ": \n";
        cin >> burst_time;
        cout << "Enter arrival time for process " << i + 1 << ": \n";
        cin >> arrival_time;
        sum_of_burst_time += burst_time;
        rr_process[i].process_num = i + 1;
        rr_process[i].burst_time = burst_time;
        rr_process[i].arrival_time = arrival_time;
    }
    return sum_of_burst_time;
}