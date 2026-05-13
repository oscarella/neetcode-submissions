class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;
    int capacity;
public:
    LRUCache(int capacity): capacity{capacity} { }

    int get(int key) {
        if (!cache.count(key)) return -1;
        else { // key exists
            order.erase(cache[key].second);
            order.push_back(key);
            cache[key].second == --order.end();
            return cache[key].first;
        }
    }
    
    void put(int key, int value) {
        /*
        - If it exists, remove it
        - Add to end w/ updated iterator
        - If exceed, delete from front
        */
        if (cache.count(key)) {
            order.erase(cache[key].second);
            cache.erase(key);
        }
        order.push_back(key);
        cache[key] = {value, --order.end()};
        if (cache.size() > capacity) {
            int delKey = order.front();
            order.pop_front();
            cache.erase(delKey);
        }
    }
};
