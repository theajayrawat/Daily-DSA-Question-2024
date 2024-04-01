// https://leetcode.com/problems/length-of-last-word/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans;
        string word;
        stringstream st(s);
        while(st>>word){
            ans=word.size();
        }
        return ans;
    }
};