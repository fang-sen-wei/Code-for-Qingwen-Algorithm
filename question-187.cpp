//左小数
#include<cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    int list[n];
    int max=0;//记录前i个数中最大的值
    int ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
        if(list[i]>max)
        {
            max=list[i];
            ans++;
        }
    }
    printf("%d",ans);

}