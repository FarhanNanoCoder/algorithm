#include <bits/stdc++.h>
using namespace std;

int main()
{
    int proCount = 5, resCount = 3;
    int ans[proCount];
    bool completed[proCount];
    int ansIndex = 0;

    int alloc[proCount][resCount] = {{0, 1, 0},
                                     {2, 0, 0},
                                     {3, 0, 2},
                                     {2, 1, 1},
                                     {0, 0, 2}};

    int max[proCount][resCount] = {{7, 5, 3},
                                   {3, 2, 2},
                                   {9, 0, 2},
                                   {2, 2, 2},
                                   {4, 3, 3}};

    int avail[resCount] = {3, 3, 2};

    int need[proCount][resCount];

    // calculating the needs

    for (int i = 0; i < proCount; i++)
    {
        for (int j = 0; j < resCount; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Every task is incomplete
    for (int i = 0; i < proCount; i++)
    {
        completed[i] = false;
    }

    // almost iteration = procedure count
    for (int i = 0; i < proCount; i++)
    {
        // iterating through all precedures
        for (int j = 0; j < proCount; j++)
        {
            // checking the procedure's status
            if (completed[j] == false)
            {
                // not yet completed
                int isPossible = true;
                // checking the availability
                for (int k = 0; k < resCount; k++)
                {
                    if (need[j][k] > avail[k])
                    {
                        isPossible = false;
                        break;
                    }
                }
                if (isPossible)
                {
                    ans[ansIndex++] = j;
                    completed[j] = true;
                    for (int t = 0; t < resCount; t++)
                    {
                        // restoring the prev allocated resources
                        avail[t] += alloc[j][t];
                    }
                }
            }
        }
    }

    bool allProComplete = true;

    for (int i = 0; i < proCount; i++)
    {
        if (!completed[i])
        {
            allProComplete = false;
            break;
        }
    }

    if (allProComplete)
    {
        cout << "SAFE" << endl;
        for (int i = 0; i < proCount - 1; i++)
        {
            cout << "P" << ans[i] << "->";
        }
        cout << "P" << ans[proCount - 1] << endl;
    }
    else
    {
        cout << "UNSAFE" << endl;
    }
}
