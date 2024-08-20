class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end, vector<int>& dp) {
        if (start > end) return 0;
        if (dp[start] != -1) return dp[start];

        int pick = nums[start] + robLinear(nums, start + 2, end, dp);
        int notpick = robLinear(nums, start + 1, end, dp);

        return dp[start] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Scenario 1: Exclude the last house
        vector<int> dp1(n, -1);
        int ans1 = robLinear(nums, 0, n - 2, dp1);

        // Scenario 2: Exclude the first house
        vector<int> dp2(n, -1);
        int ans2 = robLinear(nums, 1, n - 1, dp2);

        // The result is the maximum of the two scenarios
        return max(ans1, ans2);
    }
};
