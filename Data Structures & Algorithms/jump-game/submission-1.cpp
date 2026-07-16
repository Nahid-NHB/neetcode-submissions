class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > farthest) return false; // If we can't reach index i
            farthest = max(farthest, i + nums[i]);
        }
        return true;
    }
};
