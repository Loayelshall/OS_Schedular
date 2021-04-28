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
    int sum_of_burst_time = 0;
    sort(fcfs_process.begin(), fcfs_process.end(), [](process a, process b) { return a.arrival_time < b.arrival_time; });
    for (size_t i = 0; i < num_of_proceses; i++)
    {
        process temp_process = fcfs_process[i];
        if (i == 0)
        {
            temp_process.start_time = temp_process.arrival_time;
            fcfs_process_new.push_back(temp_process);
        }
        else if (temp_process.arrival_time > fcfs_process[i - 1].start_time + fcfs_process[i - 1].burst_time)
        {
            temp_process.start_time = temp_process.arrival_time;
            fcfs_process_new.push_back(temp_process);
        }
        else
        {
            temp_process.start_time = fcfs_process[i - 1].start_time + fcfs_process[i - 1].burst_time;
            fcfs_process_new.push_back(temp_process);
        }
    }
}
