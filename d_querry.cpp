#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FOR(i,l,r,val) for (int i=l; i<=r; i+=val)
#define fill(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
const int N = 1e6+7 , oo = (int)1e6+7;
int f[N+7],mp[N+7],arr[N+7],pos[N+7];
vector<int> tree[N+7];

void merges(int id)
{
    int i=0,j=0;
    while (i<tree[id<<1].size() && j<tree[id<<1|1].size())
    {
        int t1=tree[id<<1][i],t2=tree[id<<1|1][j];
        if (t1<t2)
        {
            tree[id].push_back(t1); i++;
        }
        else
        {
            tree[id].push_back(t2); j++;
        }
    }
    for (i; i<tree[id<<1].size(); i++) tree[id].push_back(tree[id<<1][i]);
    for (j; j<tree[id<<1|1].size(); j++) tree[id].push_back(tree[id<<1|1][j]);
}

void build(int id, int l, int r)
{
    if (l>r) return;
    if (l==r)
    {
        tree[id].push_back(pos[l]);
        return;
    }
    int m=(l+r)>>1;
    build(id<<1,l,m); build(id<<1|1,m+1,r);
    merges(id);
}

int get(int id, int l, int r, int u, int v, int k)
{
    if (l>v || r<u) return 0;
    if (l>=u && r<=v)
    {
       int x = upper_bound(tree[id].begin(),tree[id].end(),k)-tree[id].begin();
       return tree[id].size() - x;
    }
    int m=(l+r)>>1;
    return get(id<<1,l,m,u,v,k) + get(id<<1|1,m+1,r,u,v,k);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    #define task "main"
    if (fopen(task".inp","r"))
    {
        (void)!freopen(task".inp","r",stdin);
        (void)!freopen(task".out","w+",stdout);
    }
    int n; cin>>n;
    fill(mp,oo); fill(pos,oo);
    for (int i=1; i<=n; i++) cin>>arr[i];
    for (int i=n; i>=1; i--)
    {
        pos[i]=mp[arr[i]];
        mp[arr[i]]=i;
    }
    build(1,1,n);
    int q; cin>>q;
    while (q--)
    {
        int l,r; cin>>l>>r;
        cout<<get(1,1,n,l,r,r)<<"\n";
    }
}
