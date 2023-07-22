#include<bits/stdc++.h>
using namespace std;

void firstFit(int sizeb[], int m, int sizep[], int n, int allocp[])
{
    int isallocb[m] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (sizeb[j] >= sizep[i] && !isallocb[j])
            {
                allocp[i] = j + 1;
                isallocb[j] = 1;
                sizeb[j] -= sizep[i];
                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << sizep[i] << "\t\t";
        if (allocp[i] != 0)
            cout << allocp[i] ;
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

    int allocp[n] = {};

    firstFit(sizeb, m, sizep, n, allocp);

    return 0 ;
}