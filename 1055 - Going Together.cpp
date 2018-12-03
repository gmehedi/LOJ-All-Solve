#include<bits/stdc++.h>
#define maxl 20
using namespace std;

string s[maxl];
vector<int>a,b,c;
vector<pair<int,int> >from;
int n;
const int fx[]={0,-1,0,1};
const int fy[]={-1,0,1,0};
bool sign[20][20];

struct str
{
    int si;
    int sj;
    int scnt;
};

bool check(int i, int j)
{
    if( i>=0 && j>=0 && i<n && j<n && s[i][j] != '#' ) return true;
    return false;
}

bool Bfs(int i1, int j1, int flag)
{
    queue<str>q;
    sign[i1][j1]=false;

    bool sign1=false;

    q.push({i1,j1,0});

    while(!q.empty())
    {
        int i2=q.front().si;
        int j2=q.front().sj;
        int cnt2=q.front().scnt;
        q.pop();

        if(s[i2][j2] == 'X')
        {
            if(flag == 1) a.push_back(cnt2);
            if(flag == 2) b.push_back(cnt2);
            if(flag == 3) c.push_back(cnt2);
            sign1=true;
        }
        for(int i=0; i<4; i++)
        {
            int i3=fx[i]+i2;
            int j3=fy[i]+j2;
            if(check(i3,j3) && sign[i3][j3])
            {
                sign[i3][j3]=false;
                q.push({i3,j3,cnt2+1});
            }

        }
    }
    if(sign1) return true;
    return false;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        char temp[100];
        for(int i=0; i<n; i++) { scanf("%s",temp); s[i]=(string)temp; }

        for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(s[i][j] >='A' && s[i][j] <= 'Z')from.push_back(make_pair(i,j));
        bool no= false;
        for(int i=0; i<3; i++)
        {
            memset(sign,true,sizeof sign);
            if( Bfs(from[i].first,from[i].second, i+1) ) continue;
            else { no=true; break; }
        }
        if(no)
        {
            printf("Case %d: trapped\n",cas++);
        }
        else
        {


        }
        for(int i=0; i<(int)a.size(); i++) cout<<a[i]<<" ";
        cout<<endl;
        for(int i=0; i<(int)b.size(); i++) cout<<b[i]<<" ";
        cout<<endl;
        for(int i=0; i<(int)c.size(); i++) cout<<c[i]<<" ";
        cout<<endl;
    }
    return 0;
}
