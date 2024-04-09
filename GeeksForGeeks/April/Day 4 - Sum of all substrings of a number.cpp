// https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1
// TC: O(N)
// SC: O(1)

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    int mod = 1e9+7;
    long long sumSubstrings(string s){
        
        // your code here
        long long ans = 0, prev = 0;
        for(int i = 0; i < s.length(); i++) {
            int num = s[i] - '0';
            prev = ((prev*10) % mod + (num*(i+1)) % mod) % mod;
            ans = (ans % mod + prev % mod) % mod;
        }
        return ans;
    }
};