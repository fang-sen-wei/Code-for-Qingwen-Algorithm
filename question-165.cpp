//旋转数组II
#include <cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 100000;
int n, target;
//用struct存下每个数以及他的index即可
struct node
{
    int val;
    int index;
    node(){}
    node(int _val,int _index){val=_val;index=_index;}
}NODE[MAXN];

int binarySearch() {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (NODE[mid].val == target and NODE[mid-1].val<target) {
            return NODE[mid].index;
        } else if (NODE[mid].val < target) {
            l = mid + 1;
        } else if (NODE[mid].val > target or NODE[mid+1].val==target) {
            r = mid - 1;
        }
    }
    return -1;
}
//按值升序进行排序，值相同，索引低的排在前面，因为要找第一个相同的元素
bool cmp(node &a, node &b)
{
    if(a.val != b.val)return a.val<b.val;
    else return a.index<b.index;
}

int main() {
    scanf("%d%d", &n, &target);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &NODE[i].val);
        NODE[i].index=i;
    }
    sort(NODE,NODE+n,cmp);
    printf("%d", binarySearch());
    return 0;
}