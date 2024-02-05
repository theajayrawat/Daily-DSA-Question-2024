// https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>v(26,0);

        for(int i=0;i<s.size();i++)
        {
            int index=s[i]-'a';
            v[index]++;
        }


        for(int i=0;i<s.size();i++)
        {
            int index=s[i]-'a';
            if(v[index]==1)
                return i;
        }

        return -1;
    }
};

