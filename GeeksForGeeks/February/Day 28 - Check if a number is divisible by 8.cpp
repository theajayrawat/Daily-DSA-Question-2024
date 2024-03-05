// https://www.geeksforgeeks.org/problems/check-if-a-number-is-divisible-by-83957/1
// TC: O(1)
// SC: O(1)

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
          int n = s.size();

        if(n<=3){

            int a = stoi(s);

            if(a%8==0)
                return 1;

            return -1;

        }

        string lastThreeDigit = s.substr(n-3,3);

        int a = stoi(lastThreeDigit);

        return a%8==0?1:-1;
    }
};