/*
  Created by Akrem Ben Zaoui.
  
  Codeforces 242C King's Path | link = https://codeforces.com/contest/242/problem/C
  
  used technique & algorithms :
       - data structures : map , set and queue 
       - Graph algos : Augemented BFS for shortest path .
*/

/*
  Useful #define 
*/
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define invrep(i,a,b) for(int i=a;i>=b;i--)
#define lp(i,n) for(int i=0;i<n;i++)
#define PB(a) push_back(a)
#define MP make_pair
#define F first
#define S second
#define SZ(x) (int)x.size()
#define E endl
#define ALL(v) v.begin(),v.end()
#define EPS 0.0000000001
#define PI 3.14159265358979323846
#define DEC greater<int>()
/*
  Useful type definitions
*/
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ii>  vii;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<pll> vll;
typedef vector<char> vc;
typedef vector<string> vs;
/*
   Useful functions
*/
//vector functions
ll sum_vector(vi v)
{
    int n = SZ(v);
    ll s = 0;
    lp(i,n) s+=v[i];
    return s;
}
vl cum_vector(vi v)
{
    int n = SZ(v);
    vl cum(n);
    cum[0] = v[0];
    rep(i,1,n-1) cum[i] = v[i] + cum[i-1];
    return cum;
}
//input output functions
void eyle(bool a){cout<<(a?"yes\n":"no\n");}
vi in(int n){vi v(n);lp(i,n)cin>>v[i];return v;}
void out(vi v){int n = SZ(v);lp(i,n){cout<<v[i]<<" ";}cout<<endl;}
//compare functions
bool isInteger(double x){return floor(x)==ceil(x);}
ll mi(ll a,ll b){return a>b?b:a;}
ll ma(ll a,ll b){return a>b?a:b;}
int compare_double(double a,double b){return fabs(a-b)<=EPS?0:a-b>0?1:-1;}
bool same_vectors(vi v1,vi v2){
    int n1 = SZ(v1),n2 = SZ(v2);
    if(n1!=n2)
        return false;
    lp(i,n1){
        if(v1[i]!=v2[i])
            return false;}
    return true;
}
//maths functions
double myLog(int base,ll N){return (double)log(N)/log(base);}
int gcd(int a, int b)
{
    if (b == 0)
      return a;
    return gcd(b, a % b);
}
ll LCM(vi v,int n){ll ans = v[0];
for (int i = 1; i < n; i++){ans=(((v[i]*ans))/(gcd(v[i],ans)));}
return ans;}
//convert functions
int  ctoi(char c){return c-'0';}
//sort functions
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{return (a.second > b.second);}
bool DECpair(const pair<int,int> &a,const pair<int,int> &b)
{return (a.first > b.first);}4

/*
   Main Program . Starts here !
*/

const int N = 1000000000;
vii children(ii cor)
{
    vii res;
    if(cor.S<N)
        res.PB(MP(cor.F,cor.S+1));
    if(cor.S>1)
        res.PB(MP(cor.F,cor.S-1));
    if(cor.F<N)
        res.PB(MP(cor.F+1,cor.S));
    if(cor.F>1)
        res.PB(MP(cor.F-1,cor.S));
    if(cor.F<N && cor.S<N)
        res.PB(MP(cor.F+1,cor.S+1));
    if(cor.F>1 && cor.S>1)
        res.PB(MP(cor.F-1,cor.S-1));
    if(cor.F<N && cor.S>1)
        res.PB(MP(cor.F+1,cor.S-1));
    if(cor.F>1 && cor.S<N)
        res.PB(MP(cor.F-1,cor.S+1));
    return res;
}

set<ii> allowed;

bool is_allowed(ii co)
{
    if(allowed.find(co)==allowed.end())
        return false;
    return true;
}
/*
   Function to run for each test case :
*/
void solve()
{
    int x0,x1,y0,y1,n;
    cin>>x0>>y0>>x1>>y1>>n;
    vi r(n),a(n),b(n);
    lp(i,n)
        cin>>r[i]>>a[i]>>b[i];
    lp(i,n)
    {
        rep(j,a[i],b[i])
        {
            allowed.insert(MP(r[i],j));
        }
    }
    map<pair<int,int>,int> dis;
    dis[MP(x0,y0)] = 0;
    queue<ii> q;
    q.push(MP(x0,y0));
    while(!q.empty())
    {
        ii par = q.front();
        q.pop();
        vii childs = children(par);
        for(ii child:childs)
        {
            if(is_allowed(child))
            {
                if(dis.find(child)==dis.end())//not visited
                    {
                        dis[child] = dis[par]+1;
                        q.push(child);
                    }
            }
        }
    }
    cout<<(dis.find(MP(x1,y1))==dis.end()?-1:dis[MP(x1,y1)])<<endl;
}
/* main function */
int main()
{
  //  freopen("input.txt","r",stdin);
    fast;
    int t=1;
  //  cin>>t;
    while(t--)
        solve();
}
