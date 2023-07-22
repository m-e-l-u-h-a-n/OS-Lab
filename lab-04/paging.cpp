#include<stdio.h>
int main()
{
    int ms;
    printf("Enter the logical memory size: ");
    scanf("%d", &ms);
    int pageS, pageT, p[100], pagen, offset, addlog, addphy;
    char ch = 'y';
    printf("\nYour memory size is %d", ms);
    printf("\nEnter page size: ");
    scanf("%d", &pageS);

    pageT = ms / pageS;

    for(int i = 0; i < pageT; i++)
    {
        printf("\nEnter the frame of page %d: ", i + 1);
        scanf("%d", &p[i]);
    }
    do
    {
        printf("\nEnter a logical address: ");
        scanf("%d", &addlog);
        pagen = addlog / pageS;
        offset = addlog % pageS;
        addphy = (p[pagen] * pageS) + offset;
        if(addlog >= 0 && addlog < ms)
            printf("\nPhysical address is: %d", addphy);
        else printf("Enter valid logical address: ");
        printf("\nDo you want to continue(n/y)?: ");
        scanf(" %c", &ch);
    }
    while(ch == 'y');
}
