class LRUCache {
private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    list<pair<int, int>> lru_list;

    void move_to_front(int key, list<pair<int, int>>::iterator it) {
        int value = it->second;
        lru_list.erase(it);
        lru_list.push_front({key, value});
        cache[key] = lru_list.begin();
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        auto it = cache[key];
        int value = it->second;
        move_to_front(key, it);
        return value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            auto it = cache[key];
            move_to_front(key, it);
            lru_list.front().second = value;
        } else {
            if (cache.size() == capacity) {
                int lru_key = lru_list.back().first;
                lru_list.pop_back();
                cache.erase(lru_key);
            }
            lru_list.push_front({key, value});
            cache[key] = lru_list.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */