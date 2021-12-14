#include "bits/stdc++.h"
using namespace std;

int main () {
    
    vector <string> file_names;
    vector <int> lengths, start_point;
    int disk_size = 199;
    vector <int> disk (disk_size, 0);

    while (true) {
        string name;
        int length, start;
        cout << "Enter file name:" << endl;
        cin >> name;
        auto it = find(file_names.begin(), file_names.end(), name);
        if (it != file_names.end()) {
            cout << "File already exists" << endl;
            continue;
        }
        cout << "Enter file size:" << endl;
        cin >> length;
        cout << "Enter start point:" << endl;
        cin >> start;

        if (start<0 || start>disk_size || start+length>disk_size) {
            cout << "File cannot be created" << endl;
        } else {
            bool allocated = true;
            for (int i=start; i<start+length; i++) {
                if (disk[i] == 1) {
                    allocated = false;
                    cout << "Memory already occupied" << endl;
                    break;
                }
            }
            if (allocated) {
                file_names.push_back(name);
                start_point.push_back(start);
                for (int i=start; i<start+length; i++)
                    disk[i] = 1;
            }
        }

        char choice;
        cout << "Add another file?" << endl;
        cin >> choice;
        if (choice == 'n')
            break;
    }
}