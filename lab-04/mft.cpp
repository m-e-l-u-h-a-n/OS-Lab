#include<stdio.h>

int main()
{
    int mtotal, bsize, nob, extfrag, n, mreq[10], totalintfrag = 0;
    int i, p = 0;
    printf("Enter the total memory available (in Bytes): ");
    scanf("%d", &mtotal);
    printf("Enter the block size (in Bytes): ");
    scanf("%d", &bsize);
    nob = mtotal / bsize;
    extfrag = nob;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter memory required for process %d (in Bytes): ", i + 1);
        scanf("%d", &mreq[i]);
    }
    printf("\nNo. of Blocks available in memory: %d", nob);
    for(i = 0; i < n && p < nob; i++)
    {
        printf("\nProcess: %d\t\tMemory Required: %d", i + 1, mreq[i]);
        if(mreq[i] > bsize)
            printf("\t\tNA\t\t\t---");
        else
        {
            printf("\t\tAllocated\t\tMemory Left in block: %d", bsize - mreq[i]);
            totalintfrag += bsize - mreq[i];
            p++;
        }
    }
    if(i < n)
        printf("\nMemory is Full, Remaining Processes cannot be accomodated");
    printf("\n\nTotal Internal Fragmentation is %d", totalintfrag);
    printf("\nTotal External Fragmentation is %d\n", (extfrag - p) * bsize + (mtotal - bsize * nob));
}
