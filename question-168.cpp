#include <cstdio>
//旋转数组的中位数
const int MAXN = 100000;
int n, a[MAXN];

int binarySearch() {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] < a[r]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
//先找到最小值的index索引
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int c=binarySearch();
    int b=0;
    //按照奇偶，利用%找到中位数的index即可
    if(n%2 == 1)
    {
        c=(c+n/2)%(n);
    }
    else
    {
        c=(c-1+n/2)%(n);
        b=(c+1)%(n);
    }
    //printf("%d %d ",c,b);
    printf("%.1f", (a[c]+a[b]) / 2.0);
    return 0;
}