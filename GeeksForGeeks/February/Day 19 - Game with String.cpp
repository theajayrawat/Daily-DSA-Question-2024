// https://www.geeksforgeeks.org/problems/game-with-string4100/1
// TC: O(NlogN)
// SC: O(N)

class Solution{
public:
    int minValue(string s, int k){
        // code here
       unordered_map<char,int> mp;
        for(auto x:s){
            mp[x]++;
        }
        priority_queue<int> heap;
        for(auto s:mp){
            heap.push(s.second);
        }
        int x;
        while(k--){
            x = heap.top();
            heap.pop();
            heap.push(x-1);
        }
        int ans = 0;
        while(!heap.empty()){
            x=heap.top();
            ans += x*x;
            heap.pop();
        }
        return ans;

    }
};