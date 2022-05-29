/**
 * 最长递增子序列:描述的是在一个已知序列{A1, A2, ..., An}中, 取出若干元素(不必连续)组成一个新的序列
 * {Ax, ..., Ay}, 新序列中的各个数之间依旧保持原序列的先后顺序, 该序列被称之为原序列的子序列
 * 对子序列中任意下标x < y有Ax < Ay, 则称子序列为原序列的一个递增子序列。
 * 最长递增子序列则是所有递增子序列中最长的子序列
 * 
 * Solution:
 * 首先设置一个数组dp[], 令dp[i]表示以A[i]作为末尾的最长递增子序列的长度. 
 * 于是最长递增子序列的长度便是dp[]中的最大值
 * 由于dp[i]是以A[i]作为末尾的最长递增子序列的长度, 因此只有两种情况:
 * 1.A[i]之前的元素都比A[i]大, 即dp[i] = 1.
 * 2.A[i]之前的元素A[j]都比A[i]小,此时只需将A[i]添加到以A[j]作为末尾的最长递增子序列,
 * 便能构成一个新的递增子序列。只需将i之前所有的元素逐一遍历, 便可获得以A[i]作为末尾的最长递增子序列的长度dp[i]
 * 
 * 状态转移方程:dp[i] = max(1, dp[j] + 1 | j < i && Aj < Ai)
 */

#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 25;

int height[MAXN];
int dp[MAXN];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &height[i]);
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (height[i] <= height[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            answer = max(answer, dp[i]);
        }
        printf("%d\n", answer);
    }
    return 0;
}
