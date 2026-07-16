class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
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
            if (candidates[i] > remain) continue;  
            
            path.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], i, path, result);
            path.pop_back();
        }
    }
};