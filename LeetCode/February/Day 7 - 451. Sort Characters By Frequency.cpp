// https://leetcode.com/problems/sort-characters-by-frequency/
// TC: O(NlogN)
// SC: O(N)

class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto &i:s){
            mp[i]++;
        }

        vector<pair<int,char>>v;
        for(auto &i:mp){
            v.push_back(make_pair(i.second,i.first));
        }

        sort(v.rbegin(), v.rend());
        string str="";
        for(auto &i:v){
            while(i.first--){
                str+=i.second;
            }
            
        }

        return str;
    }
};
