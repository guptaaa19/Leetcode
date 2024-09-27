class MyCalendar {
private:
    map<int, int> mp;

public:
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            sum += it->second;
            // before closing if any case happens where we start another event,
            // before we could give a - to close a +, we gave extra +1 ->
            // intersection
            if (sum > 1) {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

