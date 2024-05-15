//最优装箱
#include<cstdio>
#include<algorithm>
using namespace std;
int n;//箱子的数目
void box(int W,int list[])
{
    int count=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if((W-list[i]) >= 0)
        {
            count++;
            W-=list[i];
            sum+=list[i];
        }
        else
        {
            printf("%d %d",count,sum);
            break;
        } 
    }
}
int main()
{
    int W;
    scanf("%d %d",&n,&W);
    int list[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
    }
    sort(list,list+n);//正常升序即可
    box(W,list);
}