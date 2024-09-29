class AllOne {
    unordered_map<string,int> mp;
public:
    AllOne() {

    }
    
    void inc(string key) {
        mp[key]++;
    }
    
    void dec(string key) {
        mp[key]--;
    }
    
    string getMaxKey() {
        int max=INT_MIN;
        string maxKey;
        for(auto& key : mp)
        {
            if(key.second>max)
            {
                max=key.second;
                maxKey=key.first;
            }
        }
        return maxKey;
    }
    
    string getMinKey() {
        int min=INT_MAX;
        string minKey;
        for(auto& key : mp)
        {
            if(key.second<min)
            {
                min=key.second;
                minKey=key.first;
            }
        }
        return minKey;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */