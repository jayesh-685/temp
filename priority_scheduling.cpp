#include "bits/stdc++.h"
using namespace std;

void sort_priority (int** arr, int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j][2] > arr[j+1][2]) {
                swap(arr[j][2], arr[j+1][2]);
                swap(arr[j][1], arr[j+1][1]);
                swap(arr[j][0], arr[j+1][0]);
            }
        }
    }
}

void traverse (int** arr, int n) {
    for (int i=0; i<n; i++)
        cout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << endl;
}

void solution (int** processes, int n) {
    int turnAroundTime = 0;

    for (int i=0; i<n; i++) {
        turnAroundTime += processes[i][1];
        cout << "Turn around time for process " << processes[i][0] << " is " << turnAroundTime << " seconds\n";
        cout << "Waiting time for process " << processes[i][0] << " is " << turnAroundTime-processes[i][1] << " seconds\n";
    }
}


int main () {
    int n;
    cout << "Enter no of processes:" << endl;
    cin >> n;
    int** processes = (int**)malloc(n*sizeof(int*));
    for (int i=0; i<n; i++) {
        *(processes+i) = (int*)malloc(3*sizeof(int));
    }

    for (int i = 0; i<n; i++) {
        processes[i][0] = i+1;
        cout << "Enter Burst Time for process " << i+1 << endl;
        cin >> processes[i][1];
        cout << "Enter priority for process " << i+1 << endl; 
        cin >> processes[i][2];
    }

    traverse(processes, n);
    sort_priority(processes, n);

    solution(processes, n);
    
}