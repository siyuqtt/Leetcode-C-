class LRUCache{
    private:
    int cap;
    list<pair<int,int> > cache; // <key, val>
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    list<pair<int, int> >::iterator get_it(int key){
        return find_if(cache.begin(), cache.end(),[&](pair<int, int> a){ return a.first == key;});
    }
    
    int get(int key) {
        auto it = get_it(key);
        if(it != cache.end()){
            return it->second;
        }else return -1;
    }
    
    void set(int key, int value) {
        auto it = get_it(key);
        if(it != cache.end()){
            
            it->second = value;
            cache.splice(cache.end(),cache,it);
            
        }else{
            
           if(cache.size() == cap ){
            
                cache.pop_front();
            } 
            cache.push_back(make_pair(key,value));
        }
        
    }
};
