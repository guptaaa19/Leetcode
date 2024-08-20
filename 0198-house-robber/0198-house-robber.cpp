class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int prev2 = 0;
        int prev1 = nums[0];

        for(int i=1;i<n;++i){
            int cur = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};


// Space Optimization
