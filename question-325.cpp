#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y;
    int step; // 记录步数
};

int n, m;
int num[101][101];
int help[101][101] = {0};
int a[] = {0, 0, 1, -1};
int b[] = {1, -1, 0, 0};

bool judge(int x, int y) {
    if (x >= n || y >= m || x < 0 || y < 0) return false;
    if (help[x][y] == 1 || num[x][y] == 1) return false;
    return true;
}

int bfs(int x, int y) {
    queue<node> q;
    node start = {0, 0, 0}; // 起点，步数初始化为0
    help[0][0] = 1;
    q.push(start);

    while (!q.empty()) {
        //不按照层次来+step，把step也存入点的信息中
        node front = q.front();
        q.pop();
        if (front.x == x && front.y == y) return front.step;

        // 处理传送
        if (num[front.x][front.y] == 2) {
            for (int i1 = 0; i1 < n; i1++) {
                for (int j1 = 0; j1 < m; j1++) {
                    if (judge(i1, j1) && num[i1][j1] == 2 && !(i1 == front.x && j1 == front.y)) {
                        node teleport = {i1, j1, front.step}; // 传送步数不变
                        q.push(teleport);
                        help[i1][j1] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int newx = front.x + a[i];
            int newy = front.y + b[i];
            if (judge(newx, newy)) {
                node next = {newx, newy, front.step + 1};
                q.push(next);
                help[newx][newy] = 1;
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &num[i][j]);
        }
    }

    int result = bfs(n - 1, m - 1);
    cout << result << endl;

    return 0;
}
