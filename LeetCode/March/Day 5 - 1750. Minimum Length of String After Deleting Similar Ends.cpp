// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int minimumLength(string s) {
        int begin = 0;
        int end = s.length() - 1;

        while (begin < end && s[begin] == s[end]) {
            char c = s[begin];
            while (begin <= end && s[begin] == c) {
                begin++;
            }
            while (end > begin && s[end] == c) {
                end--;
            }
        }

        return end - begin + 1;
    }
};

