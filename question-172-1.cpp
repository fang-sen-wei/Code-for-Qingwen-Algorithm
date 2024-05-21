//木棒切割问题-2分搜索
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-5;
int n;
int f(int k,int *list)
{
    int l,r,mid;
    l=0;
    r=*max_element(list,list+n);
    while(l<r)
    {
        mid=(l+r)/2;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=list[i]/mid;
        }
        if(sum>=k) r=mid;
        else l=mid+1; 
    }
    return mid;
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
    printf("%d",f(k,list));

}