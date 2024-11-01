#include<iostream>
using namespace std;
int father[101];
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        father[i]=i;
    }
}
int find(int x)
{
    int a=x;//记录当前节点
    while(father[x] != x)
    {
        x=father[x];
    }
    //路径压缩，使得运行速度更快
    while(a != father[a])
    {
        int b=a;
        a=father[a];
        father[b]=x;
    }
    return x;
}
/*

int find(int x) {
    if (father[x] != x) {
        father[x] = find(father[x]); // 路径压缩
    }
    return father[x];
}

*/

void get_together(int a, int b)
{
    int a_father=find(a);
    int b_father=find(b);
    if(a_father != b_father)
    {
        father[a_father]=b_father;
    }
}

int main()
{
    int n,m;//n人数，m关系数
    scanf("%d %d",&n,&m);
    init(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        get_together(a,b);
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(father[i]==i)
        {
            sum++;
        }
    }
    printf("%d",sum);


}