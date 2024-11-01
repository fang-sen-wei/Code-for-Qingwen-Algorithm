#include<cstdio>
#include<vector>
using namespace std;

typedef struct node
{
    int x;
    int y;
}node;

int n,m;//矩阵的大小以及终点
vector<node> t;
vector<vector<node>> res;

int a[]={0,0,-1,1};
int b[]={1,-1,0,0};

int help[6][6]={0};
int num[6][6];

bool judge(int x, int y)//是否可以遍历
{
    if(x>=n or y>=m or x<0 or y<0) return false;//超出边界
    if(help[x][y]==1 or num[x][y]==1) return false;//已经被访问过
    return true;
}

void dfs(int x, int y)
{
    if(judge(x,y)==false) return;//只有到边界了才停止
    node temp;
    temp.x=x;
    temp.y=y;
    t.push_back(temp);
    help[x][y]=1;//表示已经访问

    if(temp.x==n-1 and temp.y==m-1) //如果是终点
    {
        res.push_back(t);
    }
    else
    {
        for(int i=0;i<4;i++)
        {
            if(judge(x+a[i],y+b[i]))
            {
                dfs(x+a[i],y+b[i]);
            }
        }
    }
    t.pop_back();//回溯
    help[x][y]=0;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
    dfs(0,0);//从0，0开始，第0层
    printf("%d",res.size());
}