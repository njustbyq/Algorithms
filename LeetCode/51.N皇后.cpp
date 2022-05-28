/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后 
 */

/*
 * 回溯算法模版
 * 皇后的约束条件 :
 * 不能同行, 不能同列, 不能同斜线
 * 
 * 回溯模版:
 * void backtrack(parameter) {
 *    if (终止条件) {
 *        存放结果;
 *        return;
 *    }
 *    for (选择 : 本层集合中的元素) {
 *        处理节点;
 *        backtrack(路径, 选择列表); //递归
 *        回溯, 撤销处理结果;
 *    }
 * }
 */

// @lc code=start
class Solution {
private:
vector<vector<string>> result;
void backtrack(int n, int row, vector<string>& chessboard) {
    if (row == n) {
        result.push_back(chessboard);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (IsValid(row, col, chessboard, n)) {
            chessboard[row][col] = 'Q';
            backtrack(n, row + 1, chessboard);
            chessboard[row][col] = '.';
        }
    }
}
bool IsValid(int row, int col, vector<string>& chessboard, int n) {
    for (int i = 0; i < row; i++) {
        if (chessboard[i][col] == 'Q') {
            return false;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}
public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        std::vector<std::string> chessboard(n, std::string(n, '.'));
        backtrack(n, 0, chessboard);
        return result;
    }
};
// @lc code=end

