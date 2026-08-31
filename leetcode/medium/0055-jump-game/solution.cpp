class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxsize = 0;
        for (int i = 0; i < n; i++) {
            if (i > maxsize) {
                return false;
            }
            maxsize = max(maxsize, nums[i] + i);
        }

        return true;
    }
};