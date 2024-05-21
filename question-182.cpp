//集合求差双指针法
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int l1[n],l2[m];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&l1[i]);
    }
    for(int i=0;i<m;i++) scanf("%d",&l2[i]);
 
    
    int list[10000];
    fill(list,list+1000,-1);
    int i=0,j=0;
    int ind=0;
    while(i<n and j<m)
    {
        if(l1[i]==l2[j])//一样的跳过
        {
            i++;
            j++;
        }
        else if(l1[i]<l2[j])//小于的选中，不可能重复
        {
            list[ind++]=l1[i++];
        } 
        else//s2的更小，那就往后递进
        {
            j++;
        }
    }
    while(i<n) list[ind++]=l1[i++];
    
    for(int i=0;i<ind;i++)
    {
        if(i>0) printf(" ");
        printf("%d",list[i]);
    }
    
        
}