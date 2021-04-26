#include "FCFS.h"

int FCFS::get_input_burst_and_arrival_time(vector<process> &fcfs_process, int num_of_proceses)
{
    int burst_time, arrival_time, sum_of_burst_time = 0;
    for (size_t i = 0; i < num_of_proceses; i++)
    {
        cout << "Enter burst time for task " << i + 1 << ": \n";
        cin >> burst_time;
        cout << "Enter arrival time for task " << i + 1 << ": \n";
        cin >> arrival_time;
        sum_of_burst_time += burst_time;
        fcfs_process[i].process_num = i + 1;
        fcfs_process[i].burst_time = burst_time;
        fcfs_process[i].arrival_time = arrival_time;
    }
    return sum_of_burst_time;
}

void FCFS::calc_waiting_time(vector<process> &fcfs_process, int num_of_proceses)
{
    int sum_of_burst_time = 0;
    sort(fcfs_process.begin(), fcfs_process.end(), [](process a, process b) { return a.arrival_time < b.arrival_time; });
    for (size_t i = 0; i < num_of_proceses; i++)
    {
        fcfs_process[i].waiting_time = sum_of_burst_time;
        sum_of_burst_time += fcfs_process[i].burst_time;
    }
}

void FCFS::print_waiting_time_avg_waiting_time(vector<process> &fcfs_process, int num_of_proceses)
{
    int sum_of_waiting_time = 0;
    cout
        << " Waiting time" << '\n';
    for (size_t i = 0; i < num_of_proceses; i++)
    {
        int wait_time = fcfs_process[i].waiting_time;
        sum_of_waiting_time += wait_time;
        cout << wait_time << "   ";
    }
    cout << '\n'
         << " Average Waiting time" << '\n'
         << sum_of_waiting_time / num_of_proceses;
}