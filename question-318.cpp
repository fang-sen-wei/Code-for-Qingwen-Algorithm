//数字操作
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n;
const int maxn=100001;
vector<int> res;
queue<int> q;
bool help[maxn]={0};//用于避免重复数字的计算，反正子层元素都一样,且先遇到的层数肯定比后遇到的层数少
int bfs(int x)
{
    int step=0;
    q.push(x);
    help[x]=1;
    while(true)
    {
        //每一层元素的个数
        int size=q.size();
        //遍历每一层元素，将他们的后续入队
        //所以判断只能放在for循环里面
        for(int i=0;i<size;i++)
        {
            int front=q.front();//队头元素弹出
            q.pop();
            //判断调节是否符合
            if(front==n) return step;
            //将该元素的下一层都入队
            if(front*2<=n and help[front*2]==0) 
            {
                q.push(front*2);
                help[front*2]=1;
            }
            if(front+1<=n and help[front+1]==0)
            {
               q.push(front+1); 
               help[front+1]=1;
            } 
        }
        step++;
    }
}
int main()
{
    scanf("%d",&n);
    int step=bfs(1);
    
    cout<<step;
}