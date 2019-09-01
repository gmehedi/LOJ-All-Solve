
#include <bits/stdc++.h>
 
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
#define maxl 1000000
#define psz 20
#define Fin      freopen("input.txt","r",stdin)
#define Fout     freopen("output.txt","w",stdout)
using namespace std;
 
/*----------------------Graph Moves----------------*/
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
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

struct str{
    string ss;
};

vector<str>v;
bool compare(str x, str y){
    string temp1 = "", temp2 = "";
    temp1 = (x.ss + y.ss);
    temp2 = (y.ss + x.ss);
    return ( temp1 > temp2 );
}

ll Xor(ll temp){
    ll p[10] = {temp, 1LL, temp+1LL, 0LL};
    return p[ (temp % 4LL) ];
}

ll Convert(string s){
    ll now = 0;
    for(int i = 0; i < int(s.size()); i++){
        now = ( (now*10LL) + (s[i] - '0') );
    }
    return now;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    string s;
    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++){
        cin >> s;
        v.push_back( { s } );
    }
    sort(v.begin(),v.end(),compare);

    /*cout<<"Series"<<endl;
    for(int i = 0; i < n; i++){

        cout<<v[i].ss<<endl;
    }*/
      
    ll mini = min ( Convert( v[0].ss ), min( Convert( v[n/2].ss ), Convert( v[n-1].ss ) ) );
    ll maxi = max ( Convert( v[0].ss ), max( Convert( v[n/2].ss ), Convert( v[n-1].ss ) ) );
   //cout<<"M  "<<mini<<"  "<<maxi<<endl;
    cout << ( Xor(maxi) ^ Xor(mini-1) ) << endl;

    /*ll ans = mini;
    for(int i = mini+1; i <= maxi; i++) ans ^= i;
    */
    
    
    return 0;
}

