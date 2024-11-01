#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 64;

struct Node {
    int l, r;
} nodes[MAXN];

bool isCompleteBinaryTree(int root) {
    queue<int> q;
    q.push(root);
    bool gotNullNode = false;
    //层序遍历时，把-1也入队，-1入队后默认为完全二叉树，则后续再遇到非-1的节点即判断错误，返回false
    //全部出队无异常返回true
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (front == -1) {
            gotNullNode = true;
        } else {
            if (gotNullNode) {
                return false;
            }
            q.push(nodes[front].l);
            q.push(nodes[front].r);
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &nodes[i].l, &nodes[i].r);
    }
    printf(isCompleteBinaryTree(0) ? "Yes": "No");
    return 0;
}