//区间和
#include<cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    int list[n];
    for(int i=0;i<n;i++) scanf("%d",&list[i]);
    
    int k;//查询k次
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        int l,r,sum=0;
        scanf("%d %d",&l,&r);
        while(l<=r)
        {
            sum += list[l-1];
            l++; 
        }
        printf("%d\n",sum);
    }
}