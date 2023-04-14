#include<bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> ii;
#define fi first
#define se second
const int N = 1e2+7;
ii arr[N+7];
int gh;
vector<ii> l,r;
int u,v;
int tree[N*4+7];

void build(int id, int l1, int r1)
{
    if (l1>r1) return;
    if (l1==r1)
    {
        tree[id]=r[l1].se; return;
    }
    int m=(l1+r1)>>1;
    build(id<<1,l1,m); build(id<<1|1,m+1,r1);
    tree[id]=max(tree[id<<1],tree[id<<1|1]);
}

int get(int id, int l1, int r1, int u1, int v1)
{
    if (l1>v1 || r1<u1) return 0;
    if (l1>=u1 && r1<=v1) return tree[id];
    int m = (l1+r1) >> 1;
    return max(get(id<<1,l1,m,u1,v1),get(id<<1|1,m+1,r1,u1,v1));
}

void check(string s,int start, int kt)
{
    int id=start,tmp=0; s=' '+s;
    int weight=0,value=0;
    for (int i=1; i<s.size(); i++)
    {
        if (s[i]=='1') weight+=arr[id].fi,value+=arr[id].se; id++;
    }
    if (!kt) r.push_back(make_pair(weight,value)); else l.push_back(make_pair(weight,value));
}

void dq(string s, int id, int start , int kt)
{
    if (id==gh+1)
    {
        check(s,start,kt);
        return;
    }
    dq(s+'0',id+1,start,kt); dq(s+'1',id+1,start,kt);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    #define task "main"
    if (fopen(task".inp","r"))
    {
        (void)freopen(task".inp","r",stdin);
        (void)freopen(task".out","w+",stdout);
    }
    int n; cin>>n>>u>>v;
    gh=n/2;
    for (int i=1; i<=n; i++) cin>>arr[i].fi>>arr[i].se;
    dq("",1,1,1); dq("",1,n>>1|1,0);
    sort(r.begin(),r.end(),[] (ii x, ii y)
         {
             return x.fi<y.fi;
         });
    build(1,0,r.size()-1);

}
