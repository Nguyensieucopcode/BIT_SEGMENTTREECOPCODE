#include<bits/stdc++.h>

using namespace std;

#define int long long 
#define fill(x,y) memset(x,y,sizeof(x))
const int inf = 1e9+7, N = 1e3+7;
int arr[N+7][N+7],n,m;

bool check(int val)
{
    int dp[n+7][m+7],ans[n+7][m+7];
    fill(dp,0); fill(ans,-inf);
    dp[0][1]=1; ans[0][1]=val;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (ans[i-1][j]>arr[i][j] && dp[i-1][j]) ans[i][j]=ans[i-1][j]+arr[i][j],dp[i][j]=1;
            if (ans[i][j-1]>arr[i][j] && dp[i][j-1]) ans[i][j]=max(ans[i][j],ans[i][j-1]+arr[i][j]),dp[i][j]=1;
        }
    }
    return dp[n][m];
}

void brute()
{
    int ans = (int)1e9+7;
    for (int i=0; i<=(int)1e3; i++)
    {
        if (check(i)) 
        {
            cout<<i; return;
        }
    }
}

void binary()
{
    int l=1,r=(int)1e9+7,ans=(int)1e9+7;
    while (l<=r)
    {
        int g=(l+r)>>1;
        if (check(g)) 
        {
            ans=min(ans,g); r=g-1;
        }
        else l=g+1;
    }
    cout<<ans;
}

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);
    #define task "main"
    if (fopen(task".inp","r"))
    {
        (void)freopen(task".inp","r",stdin);
        (void)freopen(task".out","w+",stdout);
    }
    cin>>n>>m; int ma=0;
    for (int i=0; i<=n+1; i++)
    {
        for (int j=0; j<=m+1; j++) arr[i][j]=-inf;
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            cin>>arr[i][j];
            ma=max(ma,arr[i][j]);
        }
    }
    if (ma<=(int)1e3) brute(); else binary();
    
}
