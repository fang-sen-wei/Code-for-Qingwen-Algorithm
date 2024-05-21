//木棒切割问题-for循环解决
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-5;
int n;
int f(int *list,int k)
{
    int ans=0;
    for(int i=*max_element(list,list+n);i>0;i--)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=list[j]/i;
        }
        if(sum>=k)
        {
            ans=i;
            break;
        }
    }
    return ans;
}
int main()
{
    int k;
    scanf("%d %d",&n,&k);
    int list[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
    }
    printf("%d",f(list,k));

}