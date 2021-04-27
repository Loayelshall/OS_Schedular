#include "avg_time.h"

float avg_waiting_time(vector<process> process_vector, int num_of_processes)
{
    vector<wait_time> time_vec(num_of_processes);
    float sum = 0;
    for (int i = 0; i < process_vector.size(); i++)
    {
        if (time_vec[process_vector[i].process_num - 1].stop_time == -1)
            time_vec[process_vector[i].process_num - 1].stop_time = process_vector[i].arrival_time;

        time_vec[process_vector[i].process_num - 1].wait_time = process_vector[i].start_time - time_vec[process_vector[i].process_num - 1].stop_time;
        time_vec[process_vector[i].process_num - 1].stop_time = process_vector[i].start_time + process_vector[i].burst_time;
    }
    for (int i = 0; i < num_of_processes; i++)
    {
        sum += time_vec[i].wait_time;
    }
    return sum / num_of_processes;
}