#include<cstdio>
const int max=26;
int marix[max][max]={0};
void luoxuan(int n) {
    int num = 1; // 计数，赋值用
    int r = 0, h = 0; // 行和列的索引
    int a = 0, b = n - 1; // 左右边界
    int c = 0, d = n - 1; // 上下边界

    while (a <= b and c <= d) {
        for (int i = a; i <= b; i++) { // 上边界
            marix[c][i] = num++;
        }
        c++; // 上边界结束，上边界+1

        for (int i = c; i <= d; i++) { // 右边界
            marix[i][b] = num++;
        }
        b--; // 右边界结束，右边界-1

        for (int i = b; i >= a; i--) { // 下边界
            marix[d][i] = num++;
        }
        d--; // 下边界结束，下边界-1

        for (int i = d; i >= c; i--) { // 左边界
            marix[i][a] = num++;
        }
        a++; // 左边界完成，左边界+1
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    luoxuan(n);
    for(int i=0;i<n;i++)
    {
        int first=1;
        for(int j=0;j<n;j++)
        {
            if(first)//每行第一个元素
            {
                printf("%d",marix[i][j]);
                first=0;
            }
            //其余元素前面加个空格
            else printf(" %d",marix[i][j]);
        }
        printf("\n");
    }
    return 0;
}