class LRUCache{
    private:
    int cap;
    list<pair<int,int> > cache; // <key, val>
    unordered_map<int, list<pair<int,int> >::iterator> itmap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(itmap.find(key) != itmap.end()){
            cache.splice(cache.begin(), cache, itmap[key]);
            itmap[key] = cache.begin();
            return itmap[key]->second;
        }else return -1;
    }
    
    void set(int key, int value) {
        
        if(itmap.find(key) != itmap.end()){
            
            itmap[key]->second = value;
            cache.splice(cache.begin(),cache, itmap[key]);
            itmap[key] = cache.begin();
            
        }else{
            
           if(cache.size() == cap ){
            
                itmap.erase(cache.back().first);
                cache.pop_back();
            } 
            cache.push_front(make_pair(key,value));
            itmap[key] = cache.begin();
            itmap[key]->second = value;
        }
        
    }
};
