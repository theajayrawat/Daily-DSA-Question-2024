// https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1
// TC: O(N)
// SC: O(N)

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        vector<int>v(3,0);
        
        int hi=0, lo=0,n=S.size(), ans=INT_MAX;
        
        while(hi<n){
            v[S[hi]-'0']++;
            while(v[0] && v[1] && v[2]){
                ans=min(ans,hi-lo+1);
                v[S[lo]-'0']--;
                lo++;
            }
            hi++;
        }
        
         return ans==INT_MAX?-1:ans;
    }
};
