// https://leetcode.com/problems/group-anagrams/
// TC: O(N*KlogK) "K is length of string"
// SC: O(N)


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, vector<string>> anagramGroups;
        vector<vector<string>> result;

        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagramGroups[sortedStr].push_back(str);
        }

        for (auto& group : anagramGroups) {
            result.push_back(group.second);
        }

        return result;
    }
};
