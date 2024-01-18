// https://leetcode.com/problems/determine-if-string-halves-are-alike
// TC: O(N)
// SC: O(1)

class Solution {
public:
    bool isCheck(char c){
        c= tolower(c);
        if(c =='a'|| c == 'e' || c == 'i' || c == 'o'|| c =='u')
            return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isCheck(s[i])){
                if(i<n/2)
                    count++;
                else
                    count--;
            }
        }

        return count==0;
    }
};

