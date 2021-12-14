#include "bits/stdc++.h"
using namespace std;

void sort_burst_time (int** arr, int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j][1] > arr[j+1][1]) {
                swap(arr[j][1], arr[j+1][1]);
                swap(arr[j][0], arr[j+1][0]);
            }
        }
    }
}

void solution (int** processes, int n) {
    int turnAroundTime = 0;

    cout << "Process \t Waiting Time \t Turn Around Time" << endl;
    for (int i=0; i<n; i++) {
        turnAroundTime += processes[i][1];
        cout << processes[i][0] << "\t\t" << turnAroundTime - processes[i][1] << "\t\t" << turnAroundTime << endl;
    }
}


int main () {
    int n;
    cout << "Enter no of processes" << endl;
    cin >> n;
    int** processes = (int**)malloc(n*sizeof(int*));
    for (int i=0; i<n; i++) {
        *(processes+i) = (int*)malloc(2*sizeof(int));
    }

    for (int i = 0; i<n; i++) {
        processes[i][0] = i+1;
        cout << "Enter Burst Time for process " << i+1 << endl;
        cin >> processes[i][1];
    }

    sort_burst_time(processes, n);

    solution(processes, n);
    
}