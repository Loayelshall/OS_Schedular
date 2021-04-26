#include "PRI.h"


void PRI::get_input_burst_arrival_time_priority(vector<process> &pri_process, int num_of_proceses)
{
    for (size_t i = 0; i < num_of_proceses; i++)
    {
        int burst_time, arrival_time, priority_num;
        cout << "Enter burst time for process " << i + 1 << ": \n";
        cin >> burst_time;
        cout << "Enter arrival time for process " << i + 1 << ": \n";
        cin >> arrival_time;
        cout << "Enter priority number for process " << i + 1 << ": \n";
        cin >> priority_num;
        pri_process[i].process_num = i + 1;
        pri_process[i].burst_time = burst_time;
        pri_process[i].arrival_time = arrival_time;
        pri_process[i].priority_num = priority_num;
    }
}

void PRI::calc_new_order_np(vector<process> &pri_process, vector<process> &pri_process_new, int num_of_proceses)
{
    int current_time = 0, min_index = -1;
    // sort wrt arrival time
    sort(pri_process.begin(), pri_process.end(), [](process a, process b) { return a.arrival_time < b.arrival_time; });
    current_time = pri_process[0].arrival_time;
    while (!pri_process.empty())
    {
        int highest_pri = -1, min_index = -1;
        for (size_t i = 0; i < pri_process.size(); i++)
        {
            if (pri_process[i].arrival_time <= current_time)
            {
                if (highest_pri == -1)
                {
                    highest_pri = pri_process[i].priority_num;
                    min_index = i;
                }
                else
                {
                    if (pri_process[i].priority_num < highest_pri)
                    {
                        highest_pri = pri_process[i].priority_num;
                        min_index = i;
                    }
                }
            }
        }
        if (min_index == -1)
            current_time = pri_process[0].arrival_time;
        else
        {
            pri_process[min_index].start_time = current_time;
            pri_process_new.push_back(pri_process[min_index]);
            current_time += pri_process[min_index].burst_time;
            pri_process.erase(pri_process.begin() + min_index);
        }
    }
}

void PRI::calc_new_order_p(vector<process> &pri_process, vector<process> &pri_process_new, int num_of_proceses)
{
    int current_time = 0, min_index = -1;
    // sort wrt arrival time
    sort(pri_process.begin(), pri_process.end(), [](process a, process b) { return a.arrival_time < b.arrival_time; });
    current_time = pri_process[0].arrival_time;
    while (!pri_process.empty())
    {
        int highest_pri = -1, min_index = -1;
        for (size_t i = 0; i < pri_process.size(); i++)
        {
            if (pri_process[i].arrival_time <= current_time)
            {
                if (highest_pri == -1)
                {
                    highest_pri = pri_process[i].priority_num;
                    min_index = i;
                }
                else
                {
                    if (pri_process[i].priority_num < highest_pri)
                    {
                        highest_pri = pri_process[i].priority_num;
                        min_index = i;
                    }
                }
            }
        }
        if (min_index == -1)
            current_time = pri_process[0].arrival_time;
        else
        {
            process current = pri_process[min_index];
            current.start_time = current_time;
            current_time += pri_process[min_index].burst_time;
            int highest_pri_p = current.priority_num, min_index_p = -1;
            for (size_t i = 0; i < pri_process.size(); i++)
            {
                if (pri_process[i].arrival_time <= current_time && i != min_index)
                {
                    if (pri_process[i].priority_num < highest_pri_p)
                    {
                        highest_pri_p = pri_process[i].priority_num;
                        min_index_p = i;
                    }
                }
            }
            if (min_index_p == -1)
            {
                pri_process_new.push_back(current);
                pri_process.erase(pri_process.begin() + min_index);
            }
            else
            {
                current_time = pri_process[min_index_p].arrival_time;
                current.burst_time = pri_process[min_index_p].arrival_time - current.start_time;
                pri_process_new.push_back(current);
                pri_process[min_index].burst_time -= current.burst_time;
            }
        }
    }
}
