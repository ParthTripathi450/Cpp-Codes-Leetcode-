class LRUCache {
    int capacity;
    list<pair<int,int>> cacheList;
    unordered_map<int, list<pair<int,int>>::iterator> cacheMap;
public:
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()){
            return -1;
        }
        auto node = cacheMap[key];
        int value = node->second;

        cacheList.erase(node);
        cacheList.push_front({key,value});
        cacheMap[key] = cacheList.begin();

        return value;
    }
    
    void put(int key, int value) {
        if(cacheMap.find(key) != cacheMap.end()){
            cacheList.erase(cacheMap[key]);
        }
        cacheList.push_front({key,value});
        cacheMap[key] = cacheList.begin();

        if(cacheMap.size() > capacity){
            auto lru = cacheList.back();
            cacheMap.erase(lru.first);
            cacheList.pop_back();
        }


    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */