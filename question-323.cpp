//字符迷宫问题
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef struct node
{
    int x;
    int y;
}node;
int a[]={0,0,1,-1};
int b[]={1,-1,0,0};
int n,m;
int help[101][101]={0};
char num[101][101];//存储的是字符
bool judge(int x, int y)
{
    if(x>=n or y>=m or x<0 or y<0) return false;
    if(help[x][y]==1 or num[x][y]=='*') return false;
    return true;
}
//*代表墙走不了

int start_x,start_y;//迷宫起点
int end_x,end_y;//迷宫终点
int bfs(int x, int y)
{
    int step=0;
    queue<node> q;
    node temp;
    temp.x=x;
    temp.y=y;
    help[x][y]=1;
    q.push(temp);
    while(!q.empty())//如果一直走那就是相当于找出路了
    {
        int size=q.size();
        for(int i=0;i<size;i++)//遍历本层所有元素
        {
            node front=q.front();
            q.pop();
            if(front.x==end_x and front.y==end_y) return step;//到达终点，返回步数
            for(int j=0;j<4;j++)//将本层元素的子层元素都入队
            {
                if(judge(front.x+a[j], front.y+b[j]))
                {
                    help[front.x+a[j]][front.y+b[j]]=1;
                    temp.x=front.x+a[j];
                    temp.y=front.y+b[j];
                    q.push(temp);
                }
            }
        }
        step++;
    }
    return -1;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",&num[i]);
    }
    //找到起点和终点
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(num[i][j]=='S')
            {
                start_x=i;
                start_y=j;
            }
            if(num[i][j]=='T')
            {
                end_x=i;
                end_y=j;
            }
        }
    }
    int step=bfs(start_x,start_y);
    cout<<step;
    
}