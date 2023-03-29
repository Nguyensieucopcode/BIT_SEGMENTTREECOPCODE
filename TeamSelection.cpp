#include<bits/stdc++.h>

using namespace std;

const int nmax = 1e6 + 7;
int bit[nmax+7];

struct node 
{
    int x;
	int y; int z; 
} arr[nmax+7];

void update(int idx, int val)
{
    while (idx<=nmax)
    {
        bit[idx]=min(bit[idx],val);
        idx += idx & (-idx);
    }
}

int get(int idx)
{
    int res=nmax;
    while (idx>0)
    {
        res=min(res,bit[idx]);
        idx -= (idx & (-idx));
    }
    return res;
}

bool cmp(node x, node y)
{return x.x<y.x;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n; cin>>n;
    /* có thể sort tăng dần, mục tiêu là đếm số cặp có vị trí lệch nhau, có thể dùng segment hoặc các cấu trúc dữ liệu khác, đây là code cop
    ở code trên, ý tưởng sẽ lấy các phần tử của bảng xếp hạng đầu tiên làm chuẩn, lưu lại các vị trí rồi đếm các số cặp nghịch biến, có thể dùng set hoặc map 
    để làm tương tự. */
    for (int i=1; i<=n; i++) {int val; cin>>val ; arr[val].x=i;}
    for (int i=1 ;i<=n; i++) {int val; cin>>val ; arr[val].y=i;}
    for (int i=1; i<=n; i++) {int val; cin>>val ; arr[val].z=i;}
    sort(arr+1,arr+n+1,cmp);
    int ans=0;
    memset(bit,nmax,sizeof(bit));
    for (int i=1; i<=n; i++)
    {
        if (get(arr[i].z)>arr[i].y) ans++;
        update(arr[i].z,arr[i].y);
    }
    cout<<ans;
}
