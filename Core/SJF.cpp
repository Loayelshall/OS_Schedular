
#include "SJF.h"

void SJF::get_input_burst_and_arrival_time(vector<process> &sjf_process, int num_of_proceses)
{
    for (size_t i = 0; i < num_of_proceses; i++)
    {
        int burst_time, arrival_time;
        cout << "Enter burst time for task " << i + 1 << ": \n";
        cin >> burst_time;
        cout << "Enter arrival time for task " << i + 1 << ": \n";
        cin >> arrival_time;
        sjf_process[i].process_num = i + 1;
        sjf_process[i].burst_time = burst_time;
        sjf_process[i].arrival_time = arrival_time;
        sjf_process[i].stop_time = arrival_time;
    }
}

void SJF::calc_new_order_np(vector<process> &sjf_process, vector<process> &sjf_process_new, int num_of_proceses)
{
    int current_time = 0, min_index = -1;
    // sort wrt arrival time
    sort(sjf_process.begin(), sjf_process.end(), [](process a, process b) { return a.arrival_time < b.arrival_time; });
    current_time = sjf_process[0].arrival_time;
    while (!sjf_process.empty())
    {
        int min_burst_time = 0, min_index = -1;
        for (size_t i = 0; i < sjf_process.size(); i++)
        {
            if (sjf_process[i].arrival_time <= current_time)
            {
                if (min_burst_time == 0)
                {
                    min_burst_time = sjf_process[i].burst_time;
                    min_index = i;
                }
                else
                {
                    if (sjf_process[i].burst_time < min_burst_time)
                    {
                        min_burst_time = sjf_process[i].burst_time;
                        min_index = i;
                    }
                }
            }
        }
        if (min_index == -1)
            current_time = sjf_process[0].arrival_time;
        else
        {
            sjf_process[min_index].start_time = current_time;
            sjf_process_new.push_back(sjf_process[min_index]);
            current_time += sjf_process[min_index].burst_time;
            sjf_process.erase(sjf_process.begin() + min_index);
        }
    }
}

void SJF::calc_new_order_p(vector<process> &sjf_process, vector<process> &sjf_process_new, int num_of_proceses)
{
    int current_time = 0, min_index = -1;
    // sort wrt arrival time
    sort(sjf_process.begin(), sjf_process.end(), [](process a, process b) { return a.arrival_time < b.arrival_time; });
    current_time = sjf_process[0].arrival_time;
    while (!sjf_process.empty())
    {
        int min_burst_time = 0, min_index = -1;
        for (size_t i = 0; i < sjf_process.size(); i++)
        {
            if (sjf_process[i].arrival_time <= current_time)
            {
                if (min_burst_time == 0)
                {
                    min_burst_time = sjf_process[i].burst_time;
                    min_index = i;
                }
                else
                {
                    if (sjf_process[i].burst_time < min_burst_time)
                    {
                        min_burst_time = sjf_process[i].burst_time;
                        min_index = i;
                    }
                }
            }
        }
        if (min_index == -1)
            current_time = sjf_process[0].arrival_time;
        else
        {
            process current = sjf_process[min_index];
            current.start_time = current_time;
            current_time += sjf_process[min_index].burst_time;
            int min_burst_time_p = current.burst_time, min_index_p = -1;
            for (size_t i = 0; i < sjf_process.size(); i++)
            {
                if (sjf_process[i].arrival_time <= current_time && i != min_index)
                {
                    if (sjf_process[i].burst_time < min_burst_time_p)
                    {
                        min_burst_time_p = sjf_process[i].burst_time;
                        min_index_p = i;
                    }
                }
            }
            if (min_index_p == -1)
            {
                sjf_process_new.push_back(current);
                sjf_process.erase(sjf_process.begin() + min_index);
            }
            else
            {
                current_time = sjf_process[min_index_p].arrival_time;
                current.burst_time = sjf_process[min_index_p].arrival_time - current.start_time;
                sjf_process_new.push_back(current);
                sjf_process[min_index].burst_time -= current.burst_time;
            }
        }
    }
}