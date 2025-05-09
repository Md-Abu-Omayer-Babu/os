#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("priority_input.txt");
    int n;
    in >> n;
    int bt[n], pr[n], wt[n], tat[n], index[n];
    for (int i = 0; i < n; i++) {
        in >> bt[i];
        index[i] = i;
    }
    for (int i = 0; i < n; i++) in >> pr[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (pr[index[i]] > pr[index[j]])
                swap(index[i], index[j]);

    wt[index[0]] = 0;
    for (int i = 1; i < n; i++)
        wt[index[i]] = wt[index[i - 1]] + bt[index[i - 1]];
    for (int i = 0; i < n; i++)
        tat[index[i]] = wt[index[i]] + bt[index[i]];

    int totalWT = 0, totalTAT = 0;
    cout << "ID\tBT\tPR\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        totalWT += wt[i];
        totalTAT += tat[i];
        cout << "P" << i + 1 << "\t" << bt[i] << "\t" << pr[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }
    cout << "Avg WT: " << (float)totalWT / n << ", Avg TAT: " << (float)totalTAT / n << "\n";
    return 0;
}
