// https://www.geeksforgeeks.org/problems/castle-run3644/1
// TC: O(N)
// SC: O(N)

class Solution
{
public:
    int isPossible(vector<vector<int>> paths)
    {
        // Code here
        for (int i = 0; i < paths.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < paths.size(); j++)
            {
                if (paths[i][j] == 1)
                {

                    count++;
                }
            }
            if (count % 2 != 0)
                return false;
        }
        return true;
    }
};
