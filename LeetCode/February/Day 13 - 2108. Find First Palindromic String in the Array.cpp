// hhttps://leetcode.com/problems/find-first-palindromic-string-in-the-array/
// TC: O(N*M)
// SC: O(M)

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string s : words) {
            string reversed = s;
            reverse(reversed.begin(), reversed.end());
            
            if (s == reversed) {
                return s;
            }
        }
        return "";
    }
};

