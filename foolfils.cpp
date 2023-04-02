#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int arr[N+7],tree[N*4+1];

void update(int id, int l, int r, int i, int val)
{
    if (l>i || r<i) return;
    if (l==r)
    {
        tree[id]=val; return;
    }
    int mid = (l+r) >> 1;
    update(id*2,l,mid,i,val),update(id*2+1,mid+1,r,i,val);
    tree[id]=max(tree[id*2],tree[id*2+1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return 0;
    if (l>=u && r<=v)
    {
        return tree[id];
    }
    int m = (l+r) >> 1;
    return max(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}

int main()
{
    cin.tie(0) -> sync_with_stdio(false); 
    #define task "foofils"
    if (fopen(task".inp","r"))
    {
        (void)freopen(task".inp","r",stdin);
        (void)freopen(task".out","w+",stdout);
    }
    int n,k; cin>>n>>k;
    memset(tree,0,sizeof(tree));
    for (int i=1; i<=n; i++) cin>>arr[i];
    int l=1,r=(int)1e5+1;
    for (int i=1; i<=n; i++)
    {
        int x = max(arr[i]-k,l);
        int y = get(1,l,r,x,arr[i]-1)+1;
        update(1,l,r,arr[i],y);
    }
    cout<<get(1,l,r,l,r);
}
