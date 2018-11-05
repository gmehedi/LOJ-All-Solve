#include<bits/stdc++.h>
using namespace std;

int n,mini,arrival[1000+2],burst[1000+2],proc[1000+2];
int table[1000+2],totalw=0,totalt=0,wating[1000+2],turn[1000+2];
// Pls try to find out bug int he code...
void Sort()
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arrival[i]>arrival[j])
            {
                swap(arrival[i],arrival[j]),
                swap(proc[i],proc[j]),
                swap(burst[i],burst[j]);
            }

        }
    }
}

void Sort2()
{
    for(int i=1; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(burst[i]>burst[j] )
            {
                swap(arrival[i],arrival[j]),
                swap(proc[i],proc[j]),
                swap(burst[i],burst[j]);
            }
        }
    }
}

int main()
{
    while(1)
    {
        scanf("%d",&n);

        for(int i=1; i<=n; i++) proc[i-1]=i;
        printf("Enter the values of Arrival time\n");
        for(int i=0; i<n; i++) scanf("%d",&arrival[i]);

        printf("Enter the values of Burst time\n");
        for(int i=0; i<n; i++) scanf("%d",&burst[i]);
        Sort();
        Sort2();

        for(int i=0; i<n; i++)  table[i+1]=burst[i];
        table[0]= arrival[0];
        for(int i=1; i<=n; i++) table[i] += table[i-1];

        for(int i=0; i<=n; i++) printf("%d ",table[i]);
        printf("\n");

        for(int i=0; i<n; i++) totalw += (table[i]-arrival[i]), wating[i]= (table[i]-arrival[i]);

        for(int i=1; i<=n; i++) totalt += (table[i]-arrival[i-1]), turn[i-1]= (table[i]-arrival[i-1]) ;

        double avrgw = (double) totalw/(double) n;
        double avrgt = (double) totalt/(double) n;

        printf("\n\nProcess  Arrival  Burst    W.T     T.T\n");
        for(int i=0; i<n; i++)
        {
           printf(" p%d        %d       %d       %d       %d\n",proc[i],arrival[i],burst[i],wating[i],turn[i]);
        }
        printf("\n\nThe Avarage wating time is %.10f\n", avrgw);
        printf("The Avarage turn around time is %.10f\n",avrgt);
    }
    return 0;
}
