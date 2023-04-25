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

struct data
{
    int v1;int v2;
    int x; int type;
}quest[N+7];

void build(int id, int l, int r)
{
    if (l>r) return;
    if (l==r)
    {
        tree[id].val = arr[l];
        return;
    }
    int m=(l+r)>>1;
    build(id<<1,l,m); build(id<<1|1,m+1,r);
    tree[id].val = tree[id<<1].val + tree[id<<1|1].val;
}

void down(int id, int k, int dff, int kt) // CẬP NHẬT LẠI GIÁ TRỊ CẦN CẬP NHẬT TẠI CÁC NÚT CON CỦA NÚT THỨ ID.
{
    tree[id].val = tree[id].val + k*dff;
    if (k>1)
    {
        tree[id<<1].lazy += dff;
        tree[id<<1|1].lazy += dff;
    }
    if (kt) tree[id].lazy = 0;
    return;
}

void update(int id, int l, int r, int u, int v, int k)
{
    down(id,r-l+1,tree[id].lazy,1);
    if (l>v || r<u) return;
    if (l>=u && r<=v)
    {
        down(id,r-l+1,k,0); return;
    }
    int m=(l+r)>>1;
    update(id<<1,l,m,u,v,k),update(id<<1|1,m+1,r,u,v,k);
    tree[id].val = tree[id<<1].val + tree[id<<1|1].val;
}

int get(int id, int l, int r, int u, int v)
{
    down(id,r-l+1,tree[id].lazy,1);
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
        (void)freopen(task".inp","r",stdin);
        (void)freopen(task".out","w+",stdout);
    }
    int n,m; cin>>n>>m;
    FOR(i,1,n) cin>>arr[i];
    build(1,1,n);
    FOR(i,1,m)
    {
        int t; cin>>t;
        if (t==1)
        {
            int l,r,k; cin>>l>>r>>k;
            quest[i].v1 = l;
            quest[i].v2 = r;
            quest[i].x = k;
            quest[i].type = 1;
        }
        if (t==2)
        {
            int pos; cin>>pos;
            quest[i].v1 = quest[pos].v1;
            quest[i].v2 = quest[pos].v2;
            quest[i].x = -quest[pos].x;
            quest[i].type = 1;
        }
        if (t==3)
        {
            int l,r; cin>>l>>r;
            quest[i].v1 = l; quest[i].v2 = r;
            quest[i].type = 2;
        }
    }
    FOR(i,1,m)
    {
        int t = quest[i].type;
        if (t==1)
        {
            int l = quest[i].v1 , r = quest[i].v2 , k = quest[i].x;
            update(1,1,n,l,r,k);
        }
        else
        {
            int l = quest[i].v1 , r = quest[i].v2;
            cout<<get(1,1,n,l,r)<<"\n";
        }
    }
}
