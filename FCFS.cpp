#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("fcfs_input.txt");
    int n;
    in >> n;
    int bt[n], wt[n], tat[n];
    for (int i = 0; i < n; i++) in >> bt[i];

    wt[0] = 0;
    tat[0] = bt[0];

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
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
