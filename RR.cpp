#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("rr_input.txt");
    int n, q;
    in >> n;
    int bt[n], rem[n], wt[n], tat[n], ct[n];
    for (int i = 0; i < n; i++) {
        in >> bt[i];
        rem[i] = bt[i];
    }
    in >> q;

    int time = 0;
    bool done = false;

    while (!done) {
        done = true;
        
        for (int i = 0; i < n; i++) {
            if (rem[i] > 0) {
                done = false;
                
                int exec = (rem[i] > q) ? q : rem[i];
                time += exec;
                rem[i] -= exec;
                
                if (rem[i] == 0) {
                    ct[i] = time;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
    }

    int totalWT = 0, totalTAT = 0;
    cout << "ID\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        totalWT += wt[i];
        totalTAT += tat[i];
        cout << "P" << i + 1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }
    cout << "Avg WT: " << (float)totalWT / n << ", Avg TAT: " << (float)totalTAT / n << "\n";
    return 0;
}