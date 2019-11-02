
#include<stdio.h>

int Ans(char s1[1000000],char s2[1000000], double num, int isMinus1, int isMinus2 ){

  //  printf("S  %s  %s  %d   %d\n",s1,s2,isMinus1, isMinus2);
    int i = 0;
    for( i = 0; i < 12; i++) num = (num * 10);
    double num1 = 0, num2 = 0;
    int len1 = 0, len2 = 0, flag1 = 0, flag2 = 0;

    for( i = 0; s1[i] != '\0'; i++){
        if(flag1 != 0) len1++;
        if(s1[i] != '.'){

            num1 = (num1 * 10) + (s1[i]-'0');
        }
        else flag1 = 1;
    }
    for( i = 0; i < (12-len1); i++) num1 = (num1 * 10);

    for( i = 0; s2[i] != '\0'; i++){
        if(flag2 != 0) len2++;
        if(s2[i] != '.'){
            num2 = (num2 * 10) + (s2[i]-'0');
        }
        else flag2 = 1;
    }
    double res = 0.0;
  //  printf("Len   %d   %d\n",len1,len2);
    for( i = 0; i < (12-len2); i++) num2 = (num2 * 10);

    if(isMinus1) num1 = (num1 * (-1));
    if(isMinus2) num2 = (num2 *(-1));

    if(num1 > num2){
        res = num1 - num2;
    }
    else res = num2 - num1;
  // printf("All %f   %f   %f   %f\n",num1,num2,res, num);
  //  printf("M   %f\n",res);
    if(res > num) return 1;

    return 0;
}

int Check(char s1[10000], char s2[10000], double num){
    char x1[10000],y1[10000],x2[10000],y2[10000];
    // printf("tttffg\n");

    int i = 0, j = 0, minusx1 = 0, minusy1 = 0, minusx2 = 0, minusy2 = 0;
    if(s1[0] == '-') minusx1 = 1;
    if(s2[0] == '-') minusx2 = 1;

    while(s1[i] != ','){
        x1[i] = s1[i];
        i++;
    }
    x1[i] = '\0';
    while( 1 ){
        if(s1[i] == '-') minusy1 = 1;
        if(s1[i] >= '0' && s1[i] <= '9') break;
        i++;
    }

    j = 0;
    while(s1[i] != '\0'){
        y1[j] = s1[i];
        i++, j++;
    }

    y1[j] = '\0';
    //........................//
   // printf("dfghjk\n");

    i = 0, j = 0;
    while(s2[i] != ','){
        x2[i] = s2[i];
        i++;
    }
    x2[i] = '\0';
    while( 1 ){
        if(s2[i] == '-') minusy2 = 1;
        if( (s2[i] >= '0' && s2[i] <= '9') ) break;
        i++;
    }
    j = 0;
    while(s2[i] != '\0'){
        y2[j] = s2[i];
        i++, j++;
    }
   //printf("F  %d  %d  %d  %d  %d\n",x1,x2,y1,y2);

    int res1 = Ans(x1,x2,num,minusx1,minusx2);
    int res2 = Ans(y1,y2,num,minusy1,minusy2);

    return (res1 == 1 || res2 == 1);

}

int myFunction(char s1[1000000],char s2[1000000], double num){
    return Check(s1,s2,num);
}

int main(){

    int ans = myFunction("33.145334,-117.243233","33.145333,-117.243334",0.000100);

    if(ans == 1) {
        printf("It's true\n");
    }
    else  printf("It's false\n");

    return 0;
}

/*

"33.145334,-117.243233",33.145333,-117.243334",0,000100

*/





#include <bits/stdc++.h>
#include <string>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <iostream>
#define vpii vector< pair<int,int> >
#define vi vector<int>
#define for0(i,a) for(int i=0;i<a;i++)
#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define ull              unsigned long long
#define f                first
#define s                second
#define sqr(x)           (x)*(x)
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              100000007
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define loop(i,n)        for(int i=0;i<n;i++)
#define loop1(i,n)       for(int i=1;i<=n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define intlim           2147483648
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define mk(x1,y1) make_pair(x1, y1)
#define maxl 1000
#define psz 20
#define Fin      freopen("in.txt","r",stdin)
#define Fout     freopen("out.txt","w",stdout)


/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
//ios_base::sync_with_stdio(false);
 //cin.tie(NULL);
using namespace std;


vector<int>g[maxl + 3];
int value[maxl + 2];
bool sign[maxl + 3];
int n, k;

struct str{

    int node;
    int val;

    bool operator< (const str & temp) const{
        return val < temp.val;
    }

};

int Bfs1(){

    queue<int>q1;
    int ans = 0;
    memset(sign, true, sizeof sign);
    q1.push(1);
    sign[1] = false;

    while(!q1.empty()){

        int u = q1.front();
        q1.pop();

        if(value[u] != k) continue;
        ans += k;
        priority_queue<str>q;

        for(auto v : g[u]){
            if(!sign[v]) continue;
            sign[v] = false;
          //  cout<<"U  "<<u<<"  "<<v<<"  "<<value[v]<<endl;
            q.push( {v, value[v]} );
        }
        for(int i = 0; i < k; i++){
               // cout<<"Q  "<<q.top().node<<"  "<<q.top().val<<endl;
            q1.push(q.top().node);
            q.pop();
        }

      //  cout<<"HH"<<endl;
    }

    return ans;
}


void Bfs(){

    queue<int>q;
    memset(sign, true, sizeof sign);
    q.push(1);
    sign[1] = false;
    while(!q.empty()){

        int f = q.front();
        q.pop();
        if(g[f].size() >= (k + 1) || (f == 1 && g[f].size() >= k) ){
            value[f] = k;
        }
        else value[f] = 0;

        for(auto v : g[f]){
            if(sign[v]){
                sign[v] = false;
                q.push(v);
            }
        }
    }
}


int main(){

    int t, cas = 1;
    scanf("%d",&t);

    while(t--){
        scanf("%d%d",&n,&k);

        for(int i = 1; i < n; i++){
            int u, v;
            scanf("%d%d",&u, &v);
            g[u].pb(v);
            g[v].pb(u);
        }
        Bfs();

        printf("Case %d: %d\n", cas++, Bfs1() + 1);
        for(int i = 0; i <= n; i++){
            g[i].clear();
        }

    }

    return 0;
}


/*

3

6 2
1 2
1 3
2 4
3 5
3 6


6 3
1 2
1 3
1 4
4 5
4 6

6 4
1 2
1 3
1 4
4 5
4 6



*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <bits/stdc++.h>
#define pii              pair <ull,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define ull              unsigned long long
#define f                first
#define s                second
#define sqr(x)           (x)*(x)
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              1000000007
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define loop(i,n)        for(int i=0;i<n;i++)
#define loop1(i,n)       for(int i=1;i<=n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define intlim           2147483648
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define mk(x1,y1) make_pair(x1, y1)
#define maxl 1000001
#define psz 20
using namespace std;

bool sign[maxl + 2];
vector<ll>prime;

void Prime()
{
    memset(sign, true, sizeof sign);
    prime.pb(2);
    for(ll i = 3; i * i <= maxl; i += 2){
        if(sign[i]){
            for(ll j = i * i; j <= maxl; j += (i * 2LL)) sign[j] = false;
        }
    }
    for(ll i = 3; i <= maxl; i += 2LL){
        if(sign[i]) prime.pb(i);
    }
}
vector<pii>v[maxl + 3];

void Factorization(ll num, int ind)
{
    ll temp=num,res=1;

    for(int i=0; prime[i] * prime[i] <= temp && i<prime.size(); i++)
    {
        if(prime[i] > temp) break;
        int ans=0;
        while(temp % prime[i] == 0) temp /= prime[i], ans++;
        if(ans > 0) v[ind].pb( mk(prime[i], ans) );
    }

    if(temp>1) v[ind].pb(mk(temp,1));

}


///////////////////////////////////////////////////////////////////////////////////////
struct str{
    vector<pii> sum;
    vector<pii> prop;
}
tree[maxl*4LL+2LL];

void Prop(ll node, ll s, ll e)
{
    //cout<<"E  "<<s<<"  "<<e<<"  "<<e-s+1<<"   "<<tree[node].prop<<endl;
   // tree[node].sum += (e-s+1LL)*tree[node].prop;
   tree[node].sum = Add(tree[node].sum, tree[node].prop);

    if(s == e)
    {
        tree[node].prop.clear();
        return;
    }

  //  tree[node*2LL].prop+=tree[node].prop;
   tree[node*2LL].prop = Add( tree[node].prop, tree[node * 2LL].pro );
   // tree[(node*2LL)+1LL].prop+=tree[node].prop;
   tree[node*2LL + 1LL].prop = Add( tree[node].prop, tree[node * 2LL + 1].pro );
    tree[node].prop.clear();
    //cout<<"SS  "<<tree[node].sum<<endl;
    return;

}

void Build(ll node, ll s, ll e)
{
    if(s == e) { Add( tree[node].sum = v[s]); return; }
    ll mid = (s+e)/2LL;

    Build(node*2LL,s,mid);
    Build((node*2LL)+1LL,mid+1LL,e);

    tree[node].sum.clear() , tree[node].prop.clear();
}

void Update(ll node, ll s, ll e, ll i, ll j, vector<pii> pr)
{
    if(tree[node].prop.size() != 0LL)
    {
        Prop(node,s,e);
    }
    if(s>j || e<i) return;
    if(s>=i && e<=j)
    {
        tree[node].prop = pr;
     //   tree[node].prop = prop;
        Prop(node,s,e);
        return;
    }
    ll mid = (e+s)/2LL;

    Update(node*2LL,s,mid,i,j,prop);
    Update((node*2LL)+1LL,mid+1LL,e,i,j,prop);

    tree[node].sum = Add( tree[node*2LL].sum, tree[(node*2LL)+1LL].sum );
}

vector<pii> Qry(ll node, ll s, ll e, ll i, ll j)
{
    if(tree[node].prop != 0LL)
    {
        Prop(node,s,e);
    }
    if(s>j || e<i) return 0LL;
    if(s>=i && e<=j)
    {
        return tree[node].sum;
    }
    ll mid = (e+s)/2LL;
    vector<pii> p1 = Qry(node*2LL,s,mid,i,j);
    vector<pii> p2 = Qry((node*2LL)+1LL,mid+1LL,e,i,j);

   // tree[node].sum = tree[node*2LL].sum+tree[(node*2LL)+1LL].sum;
   tree[node].sum = ( tree[node*2LL].sum, tree[(node*2LL)+1LL].sum );

    return Add(p1, p2);
}

int  main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        Build(1LL,1LL,maxl);
        ll n,c,l,r;
        scanf("%lld %lld",&n,&c);

        while(c--)
        {
            int types;
            scanf("%d %lld %lld",&types,&l,&r);
           // l++,r++;
            if(types)
            {
                printf("%lld\n",Qry(1LL,1LL,maxl,l,r));
            }
            else
            {
                ll val;
                scanf("%lld",&val);
                Update(1LL,1LL,maxl,l,r,val);
            }

        }
    }

    return 0;


