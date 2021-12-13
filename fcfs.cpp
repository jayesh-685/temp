#include "bits/stdc++.h"
using namespace std;


int main () {
    int n;
    cout << "Enter no of processes" << endl;
    cin >> n;
    int processes[n];
    cout << "Enter burst time of processes" << endl;
    for (int i=0; i<n; i++)
        cin >> processes[i];

    int turnAroundTime = 0;

    for (int i=0; i<n; i++) {
        turnAroundTime += processes[i];
        cout << "Turn around time for process " << i+1 << " is " << turnAroundTime << " seconds\n";
        cout << "Waiting time for process " << i+1 << " is " << turnAroundTime-processes[i] << " seconds\n";
    }
}
