class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);  
        
        for (int i = 0; i < n; ++i) {
            string time = timePoints[i];
            int h = stoi(time.substr(0, 2));  
            int m = stoi(time.substr(3, 2));  
            minutes[i] = h * 60 + m;      
        }
        
        sort(minutes.begin(), minutes.end()); 
        
        int mini = INT_MAX;
        
        for (int i = 1; i < n; ++i) {
            mini = min(mini, minutes[i] - minutes[i - 1]);
        }
        
        // difference between the first and last times in a 24-hour cycle
        mini = min(mini, 24*60 - (minutes[n - 1] - minutes[0]));
        
        return mini;
    }
};
