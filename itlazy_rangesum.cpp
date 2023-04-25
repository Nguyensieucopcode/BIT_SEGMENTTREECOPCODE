#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FOR(i,l,r) for (int i=l; i<=r; i++)
const int N = 1e5+7;
struct node
{
    int val; int lazy;
} tree[N*4+7];
int arr[N+7];

void build(int id, int l, int r)
{
    if (l>r) return;
    if (l==r)
    {
        tree[id].val=arr[l]; return;
    }
    int m=(l+r)>>1;
    build(id<<1,l,m),build(id<<1|1,m+1,r);
    tree[id].val=tree[id<<1].val + tree[id<<1|1].val;
}

void down(int id, int l, int r, int k, int kt)
{
    tree[id].val = tree[id].val + (r-l+1)*k;
    if (l!=r)
    {
        tree[id<<1|1].lazy += k;
        tree[id<<1].lazy += k;
    }
    if (kt) tree[id].lazy=0;
    return;
}

void update(int id, int l, int r, int u, int v, int k)
{
    down(id,l,r,tree[id].lazy,1);
    if (l>v || r<u) return;
    if (l>=u && r<=v)
    {
        down(id,l,r,k,0); return;
    }
    int m=(l+r)>>1;
    update(id<<1,l,m,u,v,k);
    update(id<<1|1,m+1,r,u,v,k);
    tree[id].val = tree[id<<1].val + tree[id<<1|1].val;
}


int get(int id, int l, int r, int u, int v)
{
    down(id,l,r,tree[id].lazy,1);
    if (l>v || r<u) return 0;
    if (l>=u && r<=v) return tree[id].val;
    int m=(l+r)>>1;
    return get(id<<1,l,m,u,v) + get(id<<1|1,m+1,r,u,v);
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
    int n,q; cin>>n>>q;
    FOR(i,1,n) cin>>arr[i];
    build(1,1,n);
    while (q--)
    {
        int t,x,y; cin>>t>>x>>y;
        if (t==1)
        {
            int k; cin>>k;
            update(1,1,n,x,y,k);
        }
        else cout<<get(1,1,n,x,y)<<"\n";
    }
}
