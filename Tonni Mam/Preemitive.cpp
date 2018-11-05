
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxl 10000000
using namespace std;

int n,indg=0;
bool sign[1000];
int wating[1000],turn[1000];
priority_queue< pair<int,pair<int,int> >,vector< pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >q;

struct preemtv
{
    int bt;
    int art;
    int proc;
} p[1000],p1[1000];

struct gannt
{
    int procg;
    int startg;
    int endg;
} ganntchart[1000];

bool compare1(preemtv x, preemtv y)
{
    return x.art<y.art;
}

void Check(int cnt)
{
    for(int i=1; i<n; i++)
    {
        if(sign[i] && cnt>=p[i].art ) q.push( make_pair(p[i].bt, make_pair(p[i].art,p[i].proc)) ), sign[i]=false;
    }
}
void Avarage()
{
    int totw=0,tott=0;
    for(int i=0; i<indg; i++)
    {
        int prc1=ganntchart[i].procg,st= ganntchart[i].startg, en=ganntchart[i].endg;
        wating[prc1] += st-p1[prc1-1].art;
        totw += wating[prc1];
        p1[prc1-1].art=en;
    }
    printf("The Avarage time of All process is %.10f\n",(double)totw/(double)n);
}
void Preemtive()
{
    int start1=p[0].art, proc1=p[0].proc, bt1=p[0].bt, bt2=bt1,cnt=0;
    while( q.empty() && bt2 > 0)
    {
        bt2--, cnt++, Check(cnt);
    }
    ganntchart[indg].procg=proc1;
    ganntchart[indg].startg=start1;
    ganntchart[indg].endg=abs(bt1-bt2);
    indg++;

    if(bt2 > 0) q.push(make_pair( abs(bt1-cnt), make_pair(start1,proc1) ));

    while( !(q.size() == 1) )
    {
        start1=q.top().second.first, proc1=q.top().second.second, bt1=q.top().first, bt2=bt1;
        q.pop();

        int proc2=q.top().second.second,cnt1=0;
        while(q.top().first >= bt1 && proc2 == q.top().second.second && bt1 > 0 )
        {
            bt1--, cnt++, cnt1++, Check(cnt);
        }

        int rembt= abs(cnt1-bt2);
        ganntchart[indg].procg=proc1;
        ganntchart[indg].startg= ganntchart[indg-1].endg;
        ganntchart[indg].endg= cnt;
        indg++;
        if(bt1 != 0) q.push(make_pair(rembt,make_pair(start1,proc1)));
    }
    ganntchart[indg].procg= q.top().second.second;
    ganntchart[indg].startg= ganntchart[indg-1].endg;
    ganntchart[indg].endg= cnt+q.top().first;
    indg++;

    printf("\n\nThe Gannt Chart is\n");
    for(int i=0; i<indg; i++)
    {
        printf("P%d      %d      %d\n",ganntchart[i].procg,ganntchart[i].startg,ganntchart[i].endg);
    }
    printf("\n\n");
    Avarage();
}

int main()
{
    memset(sign,true,sizeof sign);
    printf("Enter the Number of Processor\n");
    scanf("%d",&n);

    printf("Enter the Arraival time\n");
    for(int i=0; i<n; i++) scanf("%d",&p[i].art);
    printf("Enter the Burst time\n");
    for(int i=0; i<n; i++) scanf("%d",&p[i].bt);
    for(int i=1; i<=n; i++) p[i-1].proc=i;
    for(int i=0; i<n; i++) p1[i]=p[i];

    sort(p,p+n,compare1);
    Preemtive();

    return 0;
}

