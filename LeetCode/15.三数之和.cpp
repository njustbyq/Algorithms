/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

/*
 * Solution 0: Brute Force (TLE)
 * 1. Sort all the numbers.
 * 2. Try all possible triplets (i, j, k).
 * 3. Use a set or hashset to remove duplicates.
 * 
 * Time Complexity: O(n^3logn) / O(n^3)
 * Space Complexity: O(n^2)
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        const int n = nums.size();
        set<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++)
            for(int j = i + 1; j < nums.size(); j++)
                for(int k = j + 1; k < nums.size(); k++)
                    if(nums[i] + nums[j] + nums[k] == 0)
                        ans.insert({nums[i], nums[j], nums[k]});
        return vector<vector<int>>{begin(ans), end(ans)};
    }
};

// @lc code=end

/*
 * Solution 1: HashTable
 * Instead of enumerating all triples, we just need to enumerate all
 * pairs of <nums[i], nums[j]>, check whether the third element
 * (0 - nums[i] - nums[j]) exist or not.
 * <-3, 1>, we check whether 2 exists or not.
 * <0, 0>, we need to check not only the existence of 0, but also make sure
 * count[0] >= 3
 * 
 * How to remove duplicates:
 * 1.Make sure nums[i] <= nums[j] <= nums[k]
 * 2.For each position, only use the first occurence of each num.
 * e.g. skip the num[i] if nums[i] == nums[i - 1]
 * 
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        unordered_map<int, int> c;
        for(int x : nums) ++c[x];
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            if(i && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n; j++) {
                if(j - 1 != i && nums[j] == nums[j - 1]) continue;
                const int t = 0 - nums[i] - nums[j];
                // nums[i] <= nums[j] <= nums[k]
                if(t < nums[j]) continue;
                if(!c.count(t)) continue;
                // Make sure that we have enough count
                if(c[t] >= 1 + (nums[i] == t) + nums[j] == t) {
                    ans.push_back({nums[i], nums[j], t});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
 * Solution 2: Two Pointers
 * 1.Sort nums
 * 2.Enumerate nums[i]
 * 3.Use two pointers to find all possible pairs
 * of <j, k> such that 
 * a. i < j < k 
 * b.nums[i] + nums[j] + nums[k] == 0
 * How to move pointers?
 * Let t = 0 - nums[i]
 * 1.nums[j] + nums[k] > t, too large, decrease k 
 * 2.nums[j] + nums[k] < t, too small, increase j
 * Use the same method in Solution 1 to remove duplications.
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        const int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            if(i && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while(j < k) {
                if(nums[j] + nums[k] > -nums[i]) k--;
                else if(nums[j] + nums[k] < -nums[i]) j++;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j + 1]) j++;
                    while(j < k && nums[k] == nums[k - 1]) k--;
                    j++; k--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
