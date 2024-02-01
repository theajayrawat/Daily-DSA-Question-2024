// https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1
// TC: O(N)
// SC: O(1)

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
          bitset<26> b(0);
        for(char c : s){
            c = tolower(c);
            if(isalpha(c)){
                b[c-'a'] = 1;
            }
        }
        return b.count() == 26;
    }

};