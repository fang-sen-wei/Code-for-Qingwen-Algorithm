//树的写法
#include<iostream>
using namespace std;
typedef struct node
{
    int data;
    node* lchild;
    node* rchild;
}node;

node* newNode(int data)
{
    node* temp=new node;//不用new的话，temp只是局部变量
    temp->data=data;
    temp->lchild=temp->rchild=NULL;
    return temp;
}

void insert(node* &root, int data)
{
    if(root==NULL)
    {
        root=newNode(data);
        return;
    }
    //这样子存下来的树，中序遍历就是从大到小
    if(data>=root->data)//某个条件就去左子树
    {
        insert(root->lchild, data);
    }
    else
    {
        insert(root->rchild, data);
    }
}
void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    preorder(root->lchild);
    cout<<root->data<<" ";
    preorder(root->rchild);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0); 
    int num;
    cin>>num;
    node* root=NULL;
    for(int i=0;i<num;i++)
    {
        int data;
        cin>>data;
        insert(root,data);
    }
    preorder(root);
}