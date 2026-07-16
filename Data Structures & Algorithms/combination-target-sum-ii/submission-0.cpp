class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates properly
        backtrack(candidates, target, 0, path, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int remain, int start, vector<int>& path, vector<vector<int>>& result) {
        if (remain == 0) {
            result.push_back(path);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue; // Skip duplicates
            
            if (candidates[i] > remain) break; // Stop if the number exceeds the remaining sum
            
            path.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], i + 1, path, result); // Move to the next index
            path.pop_back();
        }
    }
};
