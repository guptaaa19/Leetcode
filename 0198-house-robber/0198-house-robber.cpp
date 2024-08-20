class Solution {
public:
    int f(int idx, vector<int> &nums, vector<int> &dp) {
        if (idx < 0) return 0; // Base case: index out of bounds
        if (idx == 0) return nums[0]; // Base case: only one house to rob
        if (dp[idx] != -1) return dp[idx]; // Return cached result
        
        // Choose to rob the current house or skip it
        int pick = nums[idx] + f(idx - 2, nums, dp);
        int notpick = f(idx - 1, nums, dp);
        
        return dp[idx] = max(pick, notpick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // Edge case: no houses
        
        vector<int> dp(n, -1); // Initialize dp array with -1
        return f(n - 1, nums, dp); // Start from the last house
    }
};
