class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) < abs(ans)) {
                ans = nums[i];
            } else if (abs(nums[i]) == abs(ans)) {
                ans = max(ans, nums[i]);
            }
        }
        return ans;
    }
};