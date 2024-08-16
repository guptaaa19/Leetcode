class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        vector<int> dp(n, 1); // Every element is a subsequence of length 1 by itself

        int maxLength = 1; // At least one element in the sequence

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};
