//最小公倍数ii
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int list[n];
    int sum=1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
        sum*=list[i];
    }

    for(int i=*max_element(list,list+n);i<=sum;i++)
    {
        bool k=true;
        for(int j=0;j<n;j++)
        {
            if(i%list[j]!=0)
            {
                k=false;
                break;
            }
        }
        if(k)
        {
            printf("%d",i);
            break;
        }
    }
}