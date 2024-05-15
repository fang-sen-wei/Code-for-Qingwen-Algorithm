//有限制的选数III
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
int ans=0;
int list[13];
void dfs(int ind,int sum)
{
    if(ind==n)
    {
        if(sum==m) ans++;
        return;
    }
    if(sum>m) return;
    else
    {
        int nextind=ind+1;
        int num=1;
        while(nextind<n and list[nextind]==list[ind]) 
        {
            nextind++;
            num++;
        }
        //让相同元素在一个层里，然后本层选择不同的个数去下一层。
        //牛逼
        for(int i=0;i<=num;i++)//共有num个重复的数字
        {
            dfs(nextind,sum+i*list[ind]);//本层选i个重复的数，然后遍历到下一个元素
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
    }
    dfs(0,0);
    printf("%d",ans);
}