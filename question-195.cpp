//最大公约数ii,n个数的公约数
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int list[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
    }
    //从最小元素往下遍历，找到第一个即可
    for(int i=*min_element(list,list+n);i>=1;i--)
    {
        bool f=true;
        for(int j=0;j<n;j++)
        {
            if(list[j]%i!=0)
            {
                f=false;
                break;
            }
        }
        if(f)
        {
            printf("%d",i);
            break;       
        }
    }
}