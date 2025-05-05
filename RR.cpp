#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("rr_input.txt");
    int n, q;
    in >> n;
    int bt[n], rem[n], wt[n] = {0}, tat[n];
    for (int i = 0; i < n; i++) {
        in >> bt[i];
        rem[i] = bt[i];
    }
    in >> q;

    int time = 0;
    bool done;

    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (rem[i] > 0) {
                done = false;
                int exec = (rem[i] > q) ? q : rem[i];
                rem[i] -= exec;
                for (int j = 0; j < n; j++)
                    if (j != i && rem[j] > 0)
                        wt[j] += exec;
                time += exec;
            }
        }
    } while (!done);

    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

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