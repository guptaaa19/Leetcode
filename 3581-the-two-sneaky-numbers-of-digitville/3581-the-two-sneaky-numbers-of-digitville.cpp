class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto num: mp){
            if(num.second>1){
                ans.push_back(num.first);
            }
        }
        return ans;
    }
};