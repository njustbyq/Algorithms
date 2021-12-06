/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start

/*
 * Permutation P(n, d): 
 * P([1, 2, 3], 0, 3, [False] * 3, [], ans)
 * [[1, 2, 3],[1, 3, 2],
 *  [2, 1, 3],[2, 3, 1],
 *  [3, 1, 2],[3, 2, 1]]
 * 
 * P(nums, d, n, used, curr, ans):
 *   if d == n:
 *      ans.append(curr)
 *      return
 * 
 *   for i = 0 to len(nums):
 *     if used[i]: continue
 *     used[i] = True
 *     curr.push(nums[i])
 *     P(nums, d + 1, n, curr, ans)
 *     curr.pop()
 *     used[i] = False
 * 
 * Combination C(n, d)
 * C([1, 2, 3], 0, 3, [], ans)
 * [[1, 2, 3]]
 * 
 * C(nums, d, n, s, curr, ans):
 *   if d == n:
 *      ans.append(curr)
 *      return
 * 
 *   //组合数中顺序不变，不能重复
 *   //从第s个元素开始取, i + 1表示不能重复
 *   for i = s to len(nums)
 *      curr.push(nums[i])
 *      C(nums, d + 1, n, i + 1, curr, ans)
 *      curr.pop() 
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, ans);
        return ans;
    }
private:
    void dfs(vector<int>& candidates, int target, int s, vector<int>& cur, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(cur);
            return;
        }

        for (int i = s; i < candidates.size(); i++) {
            if(candidates[i] > target) break;
            cur.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, cur, ans);
            cur.pop_back();
        }
    }
};
// @lc code=end

