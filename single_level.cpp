#include "bits/stdc++.h"
using namespace std;

int main () {
    string directory_name;
    cout << "Enter directory name" << endl;
    cin >> directory_name;
    vector <string> file_names;
    while (true) {
        string name;
        cout << "Enter file name" << endl;
        cin >> name;
        auto it = find(file_names.begin(), file_names.end(), name);
        if (it == file_names.end()) {
            file_names.push_back(name);
            cout << "File created successfully" << endl;
        } else {
            cout << "File already exists" << endl;
        }
        char choice;
        cout << "Add another file?" << endl;
        cin >> choice;
        if (choice == 'n')
            break;
    }
    cout << "Directory name: " << directory_name << endl;
    cout << "File names:" << endl;
    for (auto v: file_names)
        cout << v << " ";
}