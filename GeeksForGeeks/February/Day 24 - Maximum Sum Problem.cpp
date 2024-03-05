// https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1
// TC: O(logN)
// SC: O(1)

class Solution
{
    public:
        int maxSum(int n)
        {
            //code here.
            if(n==1 || n==0)
                return n;
            return max(n,maxSum(n/2)+maxSum(n/3)+maxSum(n/4));
        }
};

