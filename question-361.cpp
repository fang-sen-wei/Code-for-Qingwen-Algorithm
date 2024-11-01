#include<iostream>
#include<algorithm>
using namespace std;
int father[101];
int class_num[101];
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        father[i]=i;
        class_num[i]=0;
    }
}
int find(int x) {
    if (father[x] != x) {
        father[x] = find(father[x]); // 路径压缩
    }
    return father[x];
}


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
        //合并后并不是所有节点都是压缩路径的
        //所以使用find（i）
        ++class_num[find(i)];
        if(father[i]==i)
        {
            sum++;
        }
    }
    printf("%d\n",sum);
    sort(class_num,class_num+n+1,greater<int>());
    for(int i=0;i<sum;i++)
    {
        if(i>0) printf(" ");
        printf("%d",class_num[i]);
    }

}