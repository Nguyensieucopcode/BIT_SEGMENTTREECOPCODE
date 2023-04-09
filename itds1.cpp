#include<bits/stdc++.h>
#include <algorithm>

using namespace std;

#define int long long
const int N = 1e5+7;
int arr[N+7];

multiset <int> tree[N*4+6];

void merges(int id)
{
	for (auto ir : tree[id<<1]) tree[id].insert(ir);
	for (auto ir : tree[id<<1|1]) tree[id].insert(ir);
}

void build(int id, int l, int r)
{
	if (l>r) return;
	if (l==r)
	{
		tree[id].insert(arr[l]);
		return;
	}
	int m = (l+r)>>1;
	build(id<<1,l,m),build(id<<1|1,m+1,r);
	merges(id);
}

void update(int id, int l, int r, int pos, int val)
{
	if (l>pos || r<pos) return;
	if (l==r)
	{
	    tree[id].erase(tree[id].find(arr[pos]));
	    tree[id].insert(val);
		return;
	}
	int m = (l+r) >>1;
	update(id<<1,l,m,pos,val); update(id<<1|1,m+1,r,pos,val);
	tree[id].erase(tree[id].find(arr[pos])); tree[id].insert(val);
}

int get(int id, int l, int r, int u, int v, int k)
{
	if (l>v || r<u) return (int)1e10;
	if (l>=u &&  r<=v)
	{
		auto x = tree[id].lower_bound(k);
		if (x==tree[id].end()) return (int)1e10;
		return *x;
	}
	int m = (l+r)>>1;
	return min(get(id<<1,l,m,u,v,k),get(id<<1|1,m+1,r,u,v,k));
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #define task "ITDS1"
    if (fopen(task".inp","r"))
    {
        (void)freopen(task".inp","r",stdin);
        (void)freopen(task".out","w+",stdout);
    }
    int n,q; cin>>n>>q;
    for (int i=1; i<=n; i++) cin>>arr[i];
    build(1,1,n);
    while (q--)
    {
    	int tp,l,r,k; cin>>tp>>l>>r;
    	if (tp==1)
        {
            update(1,1,n,l,r);
            arr[l]=r;
        }
    	else
    	{
    		int k; cin>>k;
    		int x =get(1,1,n,l,r,k);
    		if (x==(int)1e10) cout<<-1<<"\n"; else cout<<x<<"\n";
		}
	}
}
