//中间数
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int list[n];
    int a[n]={0};//记录元素i左侧包括自己在内最大的数；
    int b[n]={0};//记录元素i右侧包括自己在内最小的数；
    int maxn=0;
    int minx=1000000;
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&list[i]);
        if(list[i]>maxn)
        {
            maxn=list[i];
        }
        a[i]=maxn;
    }

    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        if(list[i]<minx)
        {
            minx=list[i];
        }
        b[i]=minx;
        if(list[i]==a[i] and list[i]==b[i])//如果左边最大值是自己，右边最小值是自己，那么就是中间数
        {
            ans++;
        }    
    }
    printf("%d",ans);
}