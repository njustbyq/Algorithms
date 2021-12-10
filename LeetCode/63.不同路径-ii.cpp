/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start

/*
 * The same as 62
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(n == 0) return 0;
        int m = obstacleGrid[0].size();

        //
        f_ = vector<vector<int>>(n + 1, vector<int>(m + 1, INT_MIN));
        return paths(m, n, obstacleGrid);
    }
private:
    vector<vector<int>> f_;

    int paths(int x, int y, const vector<vector<int>>& o) {
        if(x <= 0 || y <= 0) return 0;

        if(x == 1 && y == 1) return 1 - o[0][0];
        
        if(f_[y][x] != INT_MIN) return f_[y][x];

        if(o[y - 1][x - 1] == 1) {
            f_[y][x] = 0;
        } else {
            f_[y][x] = paths(x - 1, y, o) + paths(x, y - 1, o); 
        }
        return f_[y][x];
    }
};
// @lc code=end

