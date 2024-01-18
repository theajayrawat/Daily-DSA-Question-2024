// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int,int>mp;
        for(auto &i:s){
            mp[i]++;
        }
        for(auto &i:t){
            mp[i]--;
            if(mp[i]==0){
                mp.erase(i);
            }
        }

        int cnt=0;
        for(auto &i:mp){
            if(i.second<0)
                cnt+=abs(i.second);
        }

        return cnt;
    }
};

