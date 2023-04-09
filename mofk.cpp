// fail 9/100.
#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e3+7;
int pre[N+7][N+7];

string chuyen(int x)
{
    string tmp="";
    while (x>0)
    {
        tmp=char(x%10+'0')+tmp; x/=10;
    }
    return tmp;
}

int sm(int x1, int y1, int x2, int y2)
{
    return pre[x2][y2]-pre[x2][y1-1]-pre[x1-1][y2]+pre[x1-1][y1-1];
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
    int n,m,q;
    cin>>n>>m>>q;
    memset(pre,0,sizeof(pre));
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            char x; cin>>x;
            pre[i][j]=pre[i-1][j]+pre[i][j-1]+(x=='B')-pre[i-1][j-1];
        }
    }
    set <string> s;
    for (int i=1 ;i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            int cl=sm(1,1,i,j-1),cr=sm(1,j,i,m),bl=sm(n,1,i+1,j-1),br=sm(i+1,j,n,m);
            string tmp = chuyen(cl)+' '+chuyen(cr)+' '+chuyen(bl)+' '+chuyen(br);
            s.insert(tmp);
        }
    }
    while (q--)
    {
        int a,b,c,d; cin>>a>>b>>c>>d;
        string tmp=chuyen(a)+' '+chuyen(b)+' '+chuyen(c)+' '+chuyen(d);
        auto x=s.find(tmp);
        if (x!=s.end())
        {
        	cout<<"YES\n"; 
		}
		else cout<<"NO\n";
    }
}
