//01串
#include<cstdio>
#include<vector>
using namespace std;
vector<vector<int> > result;
vector<int> k;
void print01(int index,int n)
{
    if(index==n) {
       result.push_back(k); 
       return;
    }
    else
    {
        //这里看成树，左子树为0，右子树为1的二叉树，每次先去0的子树，再去1的子树
        //类似于中序遍历，每次都是先0后1

        k.push_back(0);//访问0
        print01(index+1,n);//然后访问子树
        k.pop_back();//删除本元素，相当于回到父亲节点
        k.push_back(1);//访问1
        print01(index+1,n);//访问子树
        k.pop_back();//删除本元素，相当于回到父亲节点

    }
}
int main()
{
    int n;
    scanf("%d",&n);
    print01(0,n);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            printf("%d",result[i][j]);
        }
        printf("\n");
    }
    
}
