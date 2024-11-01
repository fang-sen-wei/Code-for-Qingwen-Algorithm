#include <cstdio>
#include <vector>
//树的遍历
using namespace std;

const int MAXN = 50;
//树的节点用vector来表示
struct Node {
    vector<int> children;
} nodes[MAXN];

vector<int> pre;

void afterOrder(int root) {
    for (int i = 0; i < nodes[root].children.size(); i++) {
        afterOrder(nodes[root].children[i]);
    }
    pre.push_back(root);
}
//preorder 即入vector的push_back放到最前面即可

int main() {
    int n, k, child;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);//该节点的子节点数目
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            nodes[i].children.push_back(child);
        }
    }
    afterOrder(0);
    for (int i = 0; i < pre.size(); i++) {
        printf("%d", pre[i]);
        if (i < (int)pre.size() - 1) {
            printf(" ");
        }
    }
    return 0;
}