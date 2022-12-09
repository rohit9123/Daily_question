#include <bits/stdc++.h>
using namespace std;
int pre[2005];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            pre[i]=(pre[i-1]^a);
        }
        bool yes=!pre[n];
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<n;j++)
            yes|=(pre[i]==(pre[j]^pre[i]) && pre[i]==(pre[n]^pre[j]));
        }
        puts(yes? "YES":"NO");
    }
}