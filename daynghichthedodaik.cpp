#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fill(x,y) memset(x,y,sizeof(x))
#define FOR(i,l,r) for (int i=l; i<=r; i++)
#define endl "\n"
const int N = 1e5+7 , mod = 1e9;
int tree[N*4+7][11],arr[N+7],dp[N+7][11];
int n,k;

void update(int id, int node, int l, int r, int pos, int val)
{
    if (l>pos || r<pos) return;
    if (l==r)
    {
        tree[id][node] = (tree[id][node] % mod + val % mod ) % mod;
        return;
    }
    int m=(l+r)>>1;
    update(id<<1,node,l,m,pos,val); update(id<<1|1,node,m+1,r,pos,val);
    tree[id][node] = ( tree[id<<1][node] % mod  + tree[id<<1|1][node] % mod ) % mod;
}

int get(int id, int node, int l, int r, int u, int v)
{
    if (l>v || r<u) return 0;
    if (l>=u && r<=v) return tree[id][node] % mod  ;
    int m=(l+r)>>1;
    return ( get(id<<1,node,l,m,u,v) % mod  + get(id<<1|1,node,m+1,r,u,v) % mod ) % mod;
}

void sub1()
{
    for (int i=1; i<=n; i++) dp[i][0]=1;
    for (int i=1; i<=n; i++) dp[i][1]=1;
    for (int i=2; i<=n; i++)
    {
        for (int t=2; t<=min(i,k); t++)
        {
            for (int j=1; j<i; j++)
            {
                if (arr[i]<arr[j]) dp[i][t] = (dp[i][t] % mod + dp[j][t-1] % mod) % mod;
            }
        }
    }
    int ans=0;
    for (int i=1; i<=n; i++) ans = (ans % mod + dp[i][k] % mod) % mod ;
    cout<<ans % mod<<"\n";
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
    cin>>n>>k;
    fill(tree,0); fill(dp,0);
    for (int i=1; i<=n; i++) cin>>arr[i];
    for (int i=1; i<=n; i++)
    {
        update(1,1,1,n,arr[i],1);
        int x=arr[i]+1;
        for (int j=2; j<=min(i,k); j++)
        {
            int diff = get(1,j-1,1,n,x,n) % mod;
            update(1,j,1,n,arr[i],diff);
        }
        //cout<<endl;
    }
    cout<<get(1,k,1,n,1,n) % mod <<"\n";
}

