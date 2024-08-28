class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>arr(n+m);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), arr.begin()); 
        int z = n + m;
        if(z%2!=0){
            return arr[z/2];
        }else{
            return (arr[(z / 2) - 1] + arr[z / 2]) / 2.0;
        }
        
    }
};