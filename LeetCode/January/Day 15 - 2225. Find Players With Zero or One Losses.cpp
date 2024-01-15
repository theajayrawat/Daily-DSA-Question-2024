// https://leetcode.com/problems/find-players-with-zero-or-one-losses/
// SC: O(N)
// TC: O(N)

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>win,lose;
         for(int i=0;i<matches.size();i++){
            win[matches[i][0]]++;
            lose[matches[i][1]]++;
         }
        vector<int>winn,losee;
        vector<vector<int>>ans;
        for(auto i:lose){
            if(i.second==1)losee.push_back(i.first);
        }
        for(auto i:win){
            if(lose.find(i.first)==lose.end())winn.push_back(i.first);
        }
        sort(winn.begin(),winn.end());
        sort(losee.begin(),losee.end());
        ans.push_back(winn);
        ans.push_back(losee);
        return ans;
    }
};