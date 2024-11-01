#include<cstdio>
#include<vector>
using namespace std;
typedef struct node
{
    int lchild;
    int rchild;
    int father;
    int layer;
}node;
node tree[50];
int num;
void layer_biao(int root) {
    if (root == -1) return;
    if (tree[root].father != -1) {
        tree[root].layer = tree[tree[root].father].layer + 1;
    } else {
        tree[root].layer = 0;
    }
    layer_biao(tree[root].lchild);
    layer_biao(tree[root].rchild);
}

int together_father(int a, int b)
{
    if(a==b) return a;
    if(tree[a].father==tree[b].father) return tree[a].father;
    if(tree[a].layer < tree[b].layer)
        return together_father(a,tree[b].father);
    else if(tree[a].layer==tree[b].layer) return together_father(tree[a].father,tree[b].father);
    else return together_father(tree[a].father,b);
}
int main()
{
    scanf("%d",&num);
    int k1,k2;
    scanf("%d %d",&k1,&k2);
    tree[0].layer=0;
    for(int i=0;i<num;i++)
    {
        scanf("%d %d",&tree[i].lchild,&tree[i].rchild);
        tree[tree[i].lchild].father=i;
        tree[tree[i].rchild].father=i;
    }
    layer_biao(0);
    printf("%d",together_father(k1,k2));
}


/*
int LCA(int root, int p, int q) {
    if (root == -1) {
        return -1;
    }
    if (root == p || root == q) {
        return root;
    }
    int leftResult = LCA(nodes[root].l, p, q);
    int rightResult = LCA(nodes[root].r, p, q);
    if (leftResult != -1 && rightResult != -1) {
        return root;
    } else if (leftResult != -1) {
        return leftResult;
    } else {
        return rightResult;
    }
}
*/


