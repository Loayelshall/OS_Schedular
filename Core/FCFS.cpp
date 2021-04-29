#include "FCFS.h"

void FCFS::get_input_burst_and_arrival_time(QVector<process> &fcfs_process, int num_of_proceses)
{
    int burst_time, arrival_time;
    for (size_t i = 0; i < num_of_proceses; i++)
    {
        cout << "Enter burst time for process " << i + 1 << ": \n";
        cin >> burst_time;
        cout << "Enter arrival time for process " << i + 1 << ": \n";
        cin >> arrival_time;
        fcfs_process[i].process_num = i + 1;
        fcfs_process[i].burst_time = burst_time;
        fcfs_process[i].arrival_time = arrival_time;
    }
}

void FCFS::calc_new_order(QVector<process> &fcfs_process, QVector<process> &fcfs_process_new, int num_of_proceses)
{
    float current_time;
    sort(fcfs_process.begin(), fcfs_process.end(), [](process a, process b) { return a.arrival_time < b.arrival_time; });
    current_time = fcfs_process[0].arrival_time;
    for (size_t i = 0; i < num_of_proceses; i++)
    {
        if (fcfs_process[i].arrival_time > current_time)
            current_time = fcfs_process[0].arrival_time;
        fcfs_process[i].start_time = current_time;
        current_time += fcfs_process[i].burst_time;
        fcfs_process_new.push_back(fcfs_process[i]);
    }
}
