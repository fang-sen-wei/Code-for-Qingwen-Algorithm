//区间不相交问题
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node
{
    int x;
    int y;
    node(){}
    node(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
};

bool cmp(node a,node b)//按区间结束来排
{
    if(a.y != b.y) return a.y<b.y;
    else return a.x<b.x;
}
int main()
{
    int n;
    scanf("%d",&n);
    node list[n];
    int ans=1;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        list[i]=node(a,b);
    }
    sort(list,list+n,cmp);//按闭区间结束最早的排序
    int y0=list[0].y;//第一个区间的y
    for(int i=1;i<n;i++)
    {
        if(list[i].x>=y0)//找到第一个x大于等于y0的
        {
            y0=list[i].y;
            ans++;
        }
    }
    printf("%d",ans);


    
    
}
