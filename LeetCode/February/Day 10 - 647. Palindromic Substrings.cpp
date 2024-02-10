// https://leetcode.com/problems/palindromic-substrings/
// TC: O(N^2)
// SC: O(1)

class Solution { 
public:
    int count = 0;
    int countSubstrings(string s) {
        if (s.length() == 0) {
            return 0;
        }
        for (int i = 0; i < s.length(); i++) {
            help(s, i, i);
            help(s, i, i + 1);
        }
        return count;
    }

    void help(string& s, int left, int right) {
        while (left >= 0 &&  s[left] == s[right] && right < s.size() ) {
            count++;
            left--;
            right++;
        }
    }
};