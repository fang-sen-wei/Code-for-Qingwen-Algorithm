//区间选点问题
#include<cstdio>
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
bool cmp(node a,node b)
{
    if(a.x != b.x) return a.x > b.x;//按左端点从大到小排序
    else return a.y<b.y;//左端点相同，按右端点从小到大排序
}
int main()
{
    int n;
    scanf("%d",&n);
    node list[n];
    
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        list[i]=node(a,b);
    }

    sort(list,list+n,cmp);
    int x0=list[0].x;//第一个区间的左端点一定被选上
    int ans=1;
    for(int i=1;i<n;i++)
    {
        if(list[i].y < x0)
        {
            ans++;
            x0=list[i].x;
        }
    }
    
    printf("%d",ans);
}