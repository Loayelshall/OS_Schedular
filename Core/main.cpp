#include <iostream>
#include <QVector>
#include <numeric>
#include <algorithm>
#include "FCFS.h"
#include "SJF.h"
#include "PRI.h"
#include "RR.h"
#include "avg_time.h"

using namespace std;
// Used for testing
int main()
{
    int num_of_proceses, sum_of_burst_time = 0, sum_of_waiting_time = 0, sched_type;
    cout << "Enter number of proceses: \n";
    cin >> num_of_proceses;

    cout << "Enter scheduling criteria (1 for FCFS, 2 for SJF, 3 for PRI or 4 for RR): \n";
    cin >> sched_type;
    if (sched_type == 1)
    {
        QVector<process> fcfs_process(num_of_proceses), fcfs_process_new;
        FCFS::get_input_burst_and_arrival_time(fcfs_process, num_of_proceses);
        FCFS::calc_new_order(fcfs_process, fcfs_process_new, num_of_proceses);
    }
    else if (sched_type == 2)
    {
        bool sjf_preemptive;
        cout << "preemptive?: \n";
        cin >> sjf_preemptive;
        QVector<process> sjf_process(num_of_proceses), sjf_process_new;
        SJF::get_input_burst_and_arrival_time(sjf_process, num_of_proceses);
        if (sjf_preemptive)
            SJF::calc_new_order_p(sjf_process, sjf_process_new, num_of_proceses);

        else
            SJF::calc_new_order_np(sjf_process, sjf_process_new, num_of_proceses);
    }
    else if (sched_type == 3)
    {
        bool pri_preemptive;
        cout << "preemptive?: \n";
        cin >> pri_preemptive;
        QVector<process> pri_process(num_of_proceses), pri_process_new;
        PRI::get_input_burst_arrival_time_priority(pri_process, num_of_proceses);
        if (pri_preemptive)
            PRI::calc_new_order_p(pri_process, pri_process_new, num_of_proceses);

        else
            PRI::calc_new_order_np(pri_process, pri_process_new, num_of_proceses);
    }
    else if (sched_type == 4)
    {
        float quantum_time;
        cout << "enter quantum: \n";
        cin >> quantum_time;
        QVector<process> rr_process(num_of_proceses), rr_process_new;
        RR::get_input_burst_and_arrival_time(rr_process, num_of_proceses);
        RR::calc_new_order(rr_process, rr_process_new, num_of_proceses, quantum_time);
        for (int i = 0; i < rr_process.size(); i++)
        {
            cout << "rr_process[" << i << "].process_num"
                 << "=" << rr_process[i].process_num << '\n'
                 << "rr_process[" << i << "].burst_time"
                 << "=" << rr_process[i].burst_time << '\n'
                 << "rr_process[" << i << "].start_time"
                 << "=" << rr_process[i].start_time << '\n'
                 << "rr_process[" << i << "].waiting_time"
                 << "=" << rr_process[i].waiting_time << '\n'
                 << "rr_process[" << i << "].arrival_time"
                 << "=" << rr_process[i].arrival_time << '\n'
                 << "time= " << time << '\n';
        }
    }
}