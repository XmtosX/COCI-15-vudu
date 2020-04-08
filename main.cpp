#include <bits/stdc++.h>
using namespace std;
const int N=2e6+6;
int n,a[N],P;
long long pfx[N];
pair<long long,int> p[N];
int BIT[N];
int query(int x)
{
    int sum = 0;
    x++;
    while (x>0)
    {
        sum+= BIT[x];
        x-=x&(-x);
    }
    return sum;
}
void update(int x)
{
    x++;
    while (x <= n+1)
    {
        BIT[x] ++;
        x+=x&(-x);
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&P);
    for (int i=1;i<=n;i++)
    {
        pfx[i]=pfx[i-1]+a[i]-P;
        p[i]={pfx[i],i};
    }
    sort(p,p+n+1);
    pfx[p[0].second]=0;
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        if (p[i].first!=p[i-1].first)
            cnt++;
        pfx[p[i].second]=cnt;
    }
    long long ans=0;
    for (int i=0;i<=n;i++)
    {
        ans+= query(pfx[i]);
        update(pfx[i]);
    }
    cout <<ans;
    return 0;
}
