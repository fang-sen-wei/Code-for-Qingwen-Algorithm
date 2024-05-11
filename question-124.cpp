 //自然数分解之最大积
#include<cstdio>
#include<algorithm>
using namespace std;

int maxn(int n)//这是贪心的思路
{//贪心选择：每次都选择乘以3，若n-3不足3，则乘以2，最好避免得到1
    if(n<=3)
    {
        return n;
    }
    else if((n-3)<2)
    {
        return 2 * maxn(n-2);
    }
    else
    {
        return 3* maxn(n-3);
    }
}

int max_dy(int n)//动态规划，即优化问题
{
    if(n==1) return 1;
    else 
    {
        int k=1;
        for(int i=1;i<n;i++)
        {
            //max(max_dy(n-i), n-i)这个是决定是否继续分解，若n-i大，则不继续分解了
            k=max(k, i*max(max_dy(n-i), n-i));
        }
        return k;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    //贪心法
    if(n<3) printf("%d",1);
    else if(n==3) printf("%d",2);
    else printf("tanxin:%d\n",maxn(n));

    //动态规划
    printf("dynamic:%d",max_dy(n));
    

    
}