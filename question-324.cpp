//多终点问题
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct node
{
    int x;
    int y;
}node;
int n,m;
queue<node> q;
int num[101][101];

int help[101][101]={0};
bool judge(int x, int y)
{
    if(x>=n or y>=m or x<0 or y<0) return false;
    if(help[x][y]==1 or num[x][y]==1) return false;
    return true;
}

int a[]={0,0,1,-1};
int b[]={1,-1,0,0};
int res[101][101];

//x,y表示终点
int bfs(int x,int y)
{
    node temp;
    temp.x=0;
    temp.y=0;
    help[0][0]=1;
    int step=0;
    q.push(temp);
    while(!q.empty())
    {
        int n=q.size();
        for(int j=0;j<n;j++)
        {
            node front=q.front();
            q.pop();
            //直接记录本次的step；
            res[front.x][front.y]=step;
            
            for(int i=0;i<4;i++)
            {
                int newx=front.x+a[i];
                int newy=front.y+b[i];
                if(judge(newx,newy))
                {
                    temp.x=newx;
                    temp.y=newy;
                    q.push(temp);
                    help[newx][newy]=1;
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
        for(int j=0;j<m;j++)
        {
            scanf("%d",&num[i][j]);
            res[i][j]=-1;
        }
    }
    bfs(n-1,m-1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j>0) printf(" ");
            printf("%d",res[i][j]);
        }
        printf("\n");
    }
}