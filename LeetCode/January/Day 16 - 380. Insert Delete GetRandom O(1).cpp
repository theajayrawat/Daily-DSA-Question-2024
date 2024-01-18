// https://leetcode.com/problems/insert-delete-getrandom-o1/
// TC: O(1)
// SC: O(1)

class RandomizedSet {
public:
   unordered_map<int,int>mp;
    vector<int>vec;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
            return false;
        vec.push_back(val);
        mp[val] = vec.size()-1;
        return true;
    }
    
    bool remove(int val) {
         if(mp.find(val)==mp.end())
            return false;

        int idx = mp[val];
        int n=vec.size();
        int temp=vec[n-1];
        swap(vec[idx],vec[n-1]);
        vec[idx]= temp;
        mp[temp]= idx;
        vec.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand()%vec.size();
        return vec[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */