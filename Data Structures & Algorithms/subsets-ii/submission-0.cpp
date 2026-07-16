class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        backtrack(nums, 0, subset, res);
        return res;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& res) {
        res.push_back(subset); // Add current subset

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue; // Skip duplicate elements
            
            subset.push_back(nums[i]);
            backtrack(nums, i + 1, subset, res);
            subset.pop_back(); // Backtrack
        }
    }
};
