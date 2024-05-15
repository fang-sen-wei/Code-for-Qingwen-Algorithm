//整数配对
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int S[n],T[m];
    for(int i=0;i<n;i++) scanf("%d",&S[i]);
    for(int i=0;i<m;i++) scanf("%d",&T[i]);
    sort(S,S+n);
    sort(T,T+m);
    //双指针
    int i=0,j=0;
    int ans=0;
    while(i!=n and j!=m)
    {
        if(S[i]<=T[j])
        {
            ans++;
            i++;
            j++;
        }
        else j++;
    }
    printf("%d",ans);
}