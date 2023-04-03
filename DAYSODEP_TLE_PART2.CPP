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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int n; cin>>n;
	int arr[n+7];
	for (int i=1; i<=n; i++)
	{
		int x; cin>>x; arr[i]=uoc(x);
	}
	vector<int> lis;
	for (int i=1; i<=n; i++)
	{
		int x = lower_bound(lis.begin(),lis.end(),arr[i])-lis.begin();
		if (x>=lis.size())
		{
			lis.push_back(arr[i]); 
		}
		else 
		{
			lis[x]=min(lis[x],arr[i]);
		}
	}
	cout<<lis.size();
}
