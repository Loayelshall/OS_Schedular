#include <iostream>
#include <queue>
#include <numeric>
#include <algorithm>

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
        queue<int> fcfs_process, waiting_time;
        for (size_t i = 0; i < num_of_proceses; i++)
        {
            int burst_time;
            waiting_time.push(sum_of_burst_time);
            cout << "Enter burst time for task " << i + 1 << ": \n";
            cin >> burst_time;
            sum_of_burst_time += burst_time;
            fcfs_process.push(burst_time);
        }
        cout << " Waiting time" << '\n';
        for (size_t i = 0; i < num_of_proceses; i++)
        {
            int wait_time = waiting_time.front();
            sum_of_waiting_time += wait_time;
            waiting_time.pop();
            cout << wait_time << "   ";
        }
        cout << '\n'
             << " Average Waiting time" << '\n'
             << sum_of_waiting_time / num_of_proceses;
    }
    else if (sched_type == 2)
    {
        bool sjb_preemptive;
        cout << "preemptive?: \n";
        cin >> sjb_preemptive;
        struct sjb_st
        {
            int burst_time, process_num, waiting_time;
        };
        vector<sjb_st> sjb_process(num_of_proceses);

        for (size_t i = 0; i < num_of_proceses; i++)
        {
            int burst_time;
            cout << "Enter burst time for task " << i + 1 << ": \n";
            cin >> burst_time;
            sjb_process[i].process_num = i + 1;
            sjb_process[i].burst_time = burst_time;
        }
        if (sjb_preemptive)
        {
            // TODO
        }
        else
        {
            sort(sjb_process.begin(), sjb_process.end(), [](sjb_st a, sjb_st b) { return a.burst_time < b.burst_time; });
            cout << " Waiting time" << '\n';
            for (size_t i = 0; i < num_of_proceses; i++)
            {
                sjb_process[i].waiting_time = sum_of_burst_time;
                sum_of_waiting_time += sjb_process[i].waiting_time;
                sum_of_burst_time += sjb_process[i].burst_time;
                cout << "P" << sjb_process[i].process_num << "=" << sjb_process[i].waiting_time << "   ";
            }
            cout << '\n'
                 << " Average Waiting time" << '\n'
                 << sum_of_waiting_time / num_of_proceses;
        }
    }
}