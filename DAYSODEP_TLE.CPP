#include<bits/stdc++.h>

using namespace std;

#define int long long 
const int N = 1e6+7;
int tree[N*4+7];

int uoc(int x)
{
	int tmp=0;
	for (int i=1; i<=trunc(sqrt(x)); i++) if (x%i==0)
	{
		if (x/i==i) tmp++; else tmp+=2;
	}
	return tmp;
}

void update(int id, int l, int r, int pos, int val)
{
	if (l>pos || r<pos ) return;
	if (l==r) 
	{
		tree[id]=val; return;
	}
	int m = (l+r) >> 1;
	update(id<<1,l,m,pos,val),update(id<<1|1,m+1,r,pos,val);
	tree[id]=max(tree[id<<1],tree[id<<1|1]);
}

int get(int id, int l, int r, int u, int v)
{
	if (l>v || r<u) return 0;
	if (l>=u && r<=v) return tree[id];
	int m = (l+r) >>1;
	return max(get(id<<1,l,m,u,v),get(id<<1|1,m+1,r,u,v));
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int n; cin>>n;
	int arr[n+7];
	memset(tree,0,sizeof(tree));
	for (int i=1; i<=n; i++)
	{
		int x; cin>>x;
		arr[i]=uoc(x);
	}
	for (int i=1; i<=n; i++)
	{
		int x = get(1,1,N,1,arr[i]-1)+1;
		update(1,1,N,arr[i],x);
	}
	cout<<get(1,1,N,1,N);
}
