//一次走一步或者2步
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct node {
    int x;
    int y;
} node;

int a[] = {0, 0, 1, -1, 0, 0, 2, -2};
int b[] = {1, -1, 0, 0, 2, -2, 0, 0};
int n, m;
int help[101][101] = {0};
int num[101][101];

bool judge(int x, int y) {
    if (x >= n || y >= m || x < 0 || y < 0) return false;
    if (help[x][y] == 1 || num[x][y] == 1) return false;
    return true;
}

int bfs(int x, int y) {
    int step = 0;
    queue<node> q;
    node temp;
    temp.x = x;
    temp.y = y;
    help[x][y] = 1;
    q.push(temp);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            node front = q.front();
            q.pop();
            if (front.x == n - 1 && front.y == m - 1) return step;
            for (int j = 0; j < 4; j++) {
                int next_x1 = front.x + a[j];
                int next_y1 = front.y + b[j];
                if (judge(next_x1, next_y1)) { // 先走一步
                    help[next_x1][next_y1] = 1;
                    temp.x = next_x1;
                    temp.y = next_y1;
                    q.push(temp);

                    int next_x2 = front.x + a[j + 4];
                    int next_y2 = front.y + b[j + 4];
                    if (judge(next_x2, next_y2)) { // 再走1步
                        help[next_x2][next_y2] = 1;
                        temp.x = next_x2;
                        temp.y = next_y2;
                        q.push(temp);
                    }
                }
            }
        }
        step++;
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
    int step = bfs(0, 0);
    cout << step;

    return 0;
}
