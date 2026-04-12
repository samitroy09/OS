#include <stdio.h>

int main()
{
    printf("----------FCFS----------\n");

    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int AT[n], BT[n], CT[n], TAT[n], WT[n], P[n];

    // Input Arrival time and burst time an pid
    for (int i = 0; i < n; i++) {
        P[i] = i + 1;   // Process number
        printf("P%d Arrival Time: ", i+1);
        scanf("%d", &AT[i]);
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &BT[i]);
    }

    // 🔹 Sort by Arrival Time (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (AT[j] > AT[j + 1]) {

                // Swap AT
                int temp = AT[j];
                AT[j] = AT[j + 1];
                AT[j + 1] = temp;

                // Swap BT
                temp = BT[j];
                BT[j] = BT[j + 1];
                BT[j + 1] = temp;

                // Swap Process ID
                temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
        }
    }

    // Calculate CT, TAT, WT
    for (int i = 0; i < n; i++) {

        if (i == 0)
            CT[i] = AT[i] + BT[i];
        else
            CT[i] = (CT[i-1] > AT[i] ? CT[i-1] : AT[i]) + BT[i];

        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
    }

    // Output
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               P[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    return 0;
}