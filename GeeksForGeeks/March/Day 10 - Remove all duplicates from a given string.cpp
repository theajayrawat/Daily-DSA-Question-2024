// https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1
// TC: O(N)
// SC: O(1)

class Solution{
public:
    string removeDuplicates(string str) {
        vector<int> hash(256, 0);
        string ans;
        for (char c : str) {
            if (hash[c] == 0) {
                ans.push_back(c);
                hash[c]++;
            }
        }

        return ans;
    }
};

