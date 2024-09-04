class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int res = 0;
        long cur = 0;
        for(int r=0;r<nums.size();r++){
            long target = nums[r];
            cur += target;

            while((r-l+1)*target -cur>k){
                cur -= nums[l];
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};