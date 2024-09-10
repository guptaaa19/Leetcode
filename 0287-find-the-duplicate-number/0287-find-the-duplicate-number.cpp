class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(int i: nums){
            mp[i]++;
            if(mp[i]>1)
            return i;
        }
        return -1;
    }
};
