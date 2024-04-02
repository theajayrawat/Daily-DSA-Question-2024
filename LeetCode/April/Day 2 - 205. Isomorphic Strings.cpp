// https://leetcode.com/problems/isomorphic-strings/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())return 0;
        unordered_map<int,int>map_s,map_t;
        int length=s.size();
        for(int i=0;i<length;i++){
            if(map_s[s[i]]!=map_t[t[i]])return 0;
            map_s[s[i]]=i+1;
            map_t[t[i]]=i+1;
        }
        return 1;
    }
};