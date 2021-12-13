#include "bits/stdc++.h"
using namespace std;

int main () {
    int n;
    cout << "Enter no of processes" << endl;
    cin >> n;
    int burst_time[n];
    int remaining_time[n];
    cout << "Enter burst time of processes" << endl;
    for (int i=0; i<n; i++) {
        cin >> burst_time[i];
        remaining_time[i] = burst_time[i];
    }

    int time_quantum;
    cout << "Enter time quantum:" << endl;
    cin >> time_quantum;

    int waiting_time[n] = {0};
    int t=0;
    while (true) {
        bool completed = true;
        for (int i=0; i<n; i++) {
            if (remaining_time[i] != 0) {
                completed = false;
                if (remaining_time[i] > time_quantum) {
                    t += time_quantum;
                    remaining_time[i] -= time_quantum;
                } else {
                    t += remaining_time[i];
                    remaining_time[i] = 0;
                    waiting_time[i] = t-burst_time[i];
                }
            }
        }
        if (completed)
            break;
    }

    int turnaround_time[n];
    for (int i=0; i<n; i++)
        turnaround_time[i] = burst_time[i] + waiting_time[i];

    cout << "Process id    burst time   turnaround time    waiting time" << endl;
    for (int i=0; i<n; i++) {
        cout << i+1 << "\t\t" << burst_time[i] << "\t\t" << turnaround_time[i] << "\t\t" << waiting_time[i] << endl;
    }

    return 0;    
}
