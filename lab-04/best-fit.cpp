#include<bits/stdc++.h>
using namespace std;


void bestFit(int sizeb[], int m, int sizep[], int n)
{
    int allocp[n] = {0}, isallocb[m] = {0};

    for (int i = 0; i < n; i++)
    {
        int bst = -1;
        for (int j = 0; j < m; j++)
        {
            if (sizeb[j] >= sizep[i] && !isallocb[j])
            {
                if (bst == -1)
                    bst = j;
                else if (sizeb[bst] > sizeb[j])
                    bst = j;
            }
        }

        if (bst != -1)
        {
            allocp[i] = bst + 1;
            isallocb[bst] = 1;
            sizeb[bst] -= sizep[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i + 1 << "\t\t" << sizep[i] << "\t\t";
        if (allocp[i] != 0)
            cout << allocp[i];
        else
            cout << "NA";
        cout << endl;
    }
}

int main()
{
    int sizeb[] = {100, 500, 200, 300, 600};
    int sizep[] = {212, 417, 112, 426};
    int m = sizeof(sizeb) / sizeof(sizeb[0]);
    int n = sizeof(sizep) / sizeof(sizep[0]);
    bestFit(sizeb, m, sizep, n);

    return 0 ;
}