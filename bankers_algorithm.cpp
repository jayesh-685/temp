#include "bits/stdc++.h"
using namespace std;

int main () {
    int n;
    cout << "Enter no of processes:" << endl;
    cin >> n;
    int m;
    cout << "Enter no of resources:" << endl;
    cin >> m;

    int allocated[n][m];
    cout << "Enter resources already allocated to the processes" << endl;
    for (int i=0; i<n; i++) 
        for (int j=0; j<m; j++)
            cin >> allocated[i][j];

    int max_required[n][m];
    cout << "Enter maximum required resources" << endl;
    for (int i=0; i<n; i++) 
        for (int j=0; j<m; j++)
            cin >> max_required[i][j];

    int available_resources[m];
    cout << "Enter available resources" << endl;
    for (int i=0; i<m; i++)
        cin >> available_resources[i];

    int status[n] = {0};

    int required[n][m];
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            required[i][j] = max_required[i][j] - allocated[i][j];

    
    vector <int> safe_sequence;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (status[i] == 0) {
                int flag=0;
                for (int k=0; k<m; k++) {
                    if (required[j][k] > available_resources[k]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    safe_sequence.push_back(j+1);
                    for (int l=0; l<m; l++)
                        available_resources[l] += allocated[j][l];
                    status[j] = 1;
                }
            }
        }
    }

    cout << "Safe sequence: " << endl;
    for (int v:safe_sequence)
        cout << v << " ";
    cout << endl;
}
