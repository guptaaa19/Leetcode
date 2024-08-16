class Solution {
public:
    // Function to solve the problem with memoization
    int solveMemo(vector<int>& coins, int x, vector<int>& dp) {
        // Base case: If x is 0, no coins are needed
        if(x == 0) {
            return 0;
        }
        // If x is less than 0, return a large number to indicate not possible
        if(x < 0) {
            return INT_MAX;
        }
        // If the result is already computed, return it
        if(dp[x] != -1) {
            return dp[x];
        }
        
        int mini = INT_MAX;
        // Try every coin and choose the minimum
        for(int i = 0; i < coins.size(); i++) {
            int ans = solveMemo(coins, x - coins[i], dp);
            if(ans != INT_MAX) {
                mini = min(mini, 1 + ans);
            }
        }
        
        // Store the result in dp array and return it
        dp[x] = mini;
        return mini;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        // Create a DP array initialized with -1 (uncomputed state)
        vector<int> dp(amount + 1, -1);
        // Call the memoized function
        int ans = solveMemo(coins, amount, dp);
        // If the answer is still a large number, it means it's not possible
        if(ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};
