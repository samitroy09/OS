#include <stdio.h>

int main()
{
    printf("----------FCFS----------\n");

    int n = 5;

    // printf("Enter number of processes: ");
    // scanf("%d", &n);

    int AT[] = {0, 1, 2, 3, 4};
    int BT[] = {5, 7, 6, 2, 4};
    int CT[n], TAT[n], WT[n];

    // // input Arrival time and burst time
    // for (int i = 0; i < n; i++) {
    //     printf("P%d Arrival Time: ", (i+1));
    //     scanf("%d", &AT[i]);
    //     printf("P%d Burst Time: ", (i+1));
    //     scanf("%d", &BT[i]);
    // }

    // calculate CT, TAT, WT
    for (int i = 0; i < n; i++)
    {

        int io = 2;

        if (i == 0)
            CT[i] = AT[i] + BT[i] + io;
        else
            CT[i] = (CT[i - 1] > AT[i] ? CT[i - 1] : AT[i]) + BT[i] + io;
            
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
    }

    // print result
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    float avgTAT = 0;
    float avgWT = 0;
    for (int i = 0; i < n; i++)
    {
        avgTAT += TAT[i];
        avgWT += WT[i];
    }
    printf("Average TAT =  %.2f\n", (avgTAT / n));
    printf("Average WT =  %.2f\n", (avgWT / n));

    return 0;
}