/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start

/*
 * DFS, Combination C(L, N) 同39题
 * Time Complexity: O(2^n)
 * Space Complexity: O(kn)
 * How to remove duplicates?
 * 1. Use C++ Set 
 * 2. Disallow same number in same depth
 * 
 * Solution 1:
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        std::sort(candidates.begin(), candidates.end());
        vector<int> curr;
        dfs(candidates, target, 0, ans, curr);
        return vector<vector<int>> (ans.begin(), ans.end());
    }
private:
    void dfs(const vector<int>& candidates, int target, int s, set<vector<int>>& ans, vector<int>& curr) {
        if(target == 0) {
            ans.insert(curr);
            return;
        }

        for(int i = s; i < candidates.size(); i++) {
            int num = candidates[i];
            if (num > target) return;
            curr.push_back(num);
            dfs(candidates, target - num, i + 1, ans, curr);
            curr.pop_back();
        }
    }
};

/*
 * Solution2: Disallow same number in same depth
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        std::sort(candidates.begin(), candidates.end());
        vector<int> curr;
        dfs(candidates, target, 0, ans, curr);
        return vector<vector<int>> (ans.begin(), ans.end());
    }
private:
    void dfs(const vector<int>& candidates, int target, int s, vector<vector<int>>& ans, vector<int>& curr) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }

        for(int i = s; i < candidates.size(); i++) {
            int num = candidates[i];
            if (num > target) return;
            if(i > s && candidates[i] == candidates[i - 1]) continue;
            curr.push_back(num);
            dfs(candidates, target - num, i + 1, ans, curr);
            curr.pop_back();
        }
    }
};
// @lc code=end

