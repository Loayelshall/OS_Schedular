#include "RR.h"

int RR::get_input_burst_and_arrival_time(QVector<process> &rr_process, int num_of_proceses)
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

void RR::calc_new_order(QVector<process> &rr_process, QVector<process> &rr_process_new, int num_of_proceses, float quantum_time)
{
    int current_time = 0, min_index = -1;
    // sort wrt arrival time
    sort(rr_process.begin(), rr_process.end(), [](process a, process b) { return a.arrival_time < b.arrival_time; });
    current_time = rr_process[0].arrival_time;
    while (!rr_process.empty())
    {
        for (size_t i = 0, j = 1; i < rr_process.size(); i++, j++)
        {
            if (rr_process.size() == 1)
            {
                rr_process_new.push_back(rr_process[i]);
                rr_process.erase(rr_process.begin() + i);
            }
            else
            {
                if (j == rr_process.size() && rr_process.size() > 1)
                    j = 0;

                if (rr_process[i].arrival_time <= current_time)
                {
                    if (current_time + quantum_time <= rr_process[j].arrival_time)
                    {
                        if (rr_process[i].burst_time <= rr_process[j].arrival_time)
                        {
                            current_time += rr_process[i].burst_time;
                            rr_process_new.push_back(rr_process[i]);
                            rr_process.erase(rr_process.begin() + i);
                            i--;
                        }
                        else
                        {
                            process current_process = rr_process[i];
                            current_process.burst_time = rr_process[j].arrival_time - current_time;
                            current_time += current_process.burst_time;
                            rr_process[i].burst_time -= current_process.burst_time;
                            rr_process_new.push_back(current_process);
                        }
                    }
                    else
                    {
                        if (rr_process[i].burst_time > quantum_time)
                        {
                            process current_process = rr_process[i];
                            current_process.burst_time = quantum_time;
                            current_time += current_process.burst_time;
                            rr_process[i].burst_time -= quantum_time;
                            rr_process_new.push_back(current_process);
                        }
                        else
                        {
                            current_time += rr_process[i].burst_time;
                            rr_process_new.push_back(rr_process[i]);
                            rr_process.erase(rr_process.begin() + i);
                            i--;
                        }
                    }
                }
            }
        }
        current_time = rr_process[0].arrival_time;
    }
}