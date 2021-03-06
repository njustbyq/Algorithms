/**
 * 0-1背包问题描述的是，有n件物品，每件物品的重量为w[i]，其价值为v[i]，现在有
 * 容量为m的背包，如何选择物品使得装入背包物品的价值最大。
 * 对于这个问题，最先想到的肯定是枚举所有物品的排列组合，再从中找出价值最大的组合。
 * 但是其时间复杂度达到O(2^n).而使用动态规划方法，其时间复杂度只有O(nm)。
 * 
 * 首先设置一个二维数组dp[][], 令dp[i][j]表示前i个物品装进容量为j的背包能获得的最大价值,
 * 因此dp[n][m]的值就是0-1背包问题的解.
 * 
 * 1.对于容量为j的背包, 如果不放入第i件物品, 那么问题就转换成将前i-1个物品放入容量为j的背包的问题, 即dp[i][j] = dp[i - 1][j]
 * 2.对于容量为j的背包, 如果放入第i件物品, 那么当前背包的容量就变成了j - w[i], 并得到这个物品的价值v[i]. 
 *   之后这个问题就转化成将前i - 1个物品放入容量为j - w[i]的背包问题, 即dp[i][j] = dp[i - 1][j - w[i]] + v[i]
 * 因此可得到状态转移方程:
 *   dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i])
 * 转移时要注意j - w[i]的值是否为非负值, 若为负则代表背包当前的容量无法放入第i件物品, 不能转移.
 * 而对于边界情况, 如果装入0件物品, 那么无论给定背包的容量有多大,能够获得的价值为0；如果背包的容量为0，那么也无法装入任何物品，此时能够获得的
 * 价值也必定为0。于是可以得到:
 *   dp[i][0] = 0 (0 <= i <= n)
 *   dp[0][j] = 0 (0 <= j <= m)
 * 这样的状态转移，只需依次遍历 i和j便能求得各dp[i][j]的值.
 * 状态转移的特点，可以发现dp[i][j]的转移仅与dp[i - 1][j - w[i]]和dp[i - 1][j]有关，
 * 即仅与二维数组中本行的上一行有关。根据这个特点，可以将原本的二维数组优化为一维数组，并用如下方式完成状态转移：
 *   dp[j] = max(dp[j], dp[j - w[i]] + v[i])
 * 为了保证状态正确转移, 必须保证在每次更新中确定状态dp[j]时，dp[j- w[i]]尚末被本次更新修改。
 * 这就需要在每次更新中，倒序地遍历所有j的值，因为只有这样才能保证在确定dp[j]的值时，dp[j- w[i]]的值尚未被修改，从而完成正确的状态转移.
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1001;

int dp[MAXN];
int v[MAXN];
int w[MAXN];

int main() {
    int n, m;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &w[i], &v[i]);
    }

    for (int i = 0; i <= m; i++) {
        dp[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = m; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}

