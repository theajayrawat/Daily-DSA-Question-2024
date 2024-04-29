// https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1
// TC: O(N*M)
// SC: O(1)

class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& a) {
        // Code here
        int i=0,j=0;
        vector<int> ans;
        int dir=1;
        while(1)
        {
            if(a[i][j]==0)
            {
                if(dir==1)j++;
                else if(dir==-1)j--;
                else if(dir==2)i++;
                else i--;
            }
            else
            {
                a[i][j]=0;
                
                if(dir==1)
                {
                    i++;
                    dir=2;
                }
                else if(dir==-1)
                {
                    i--;
                    dir=-2;
                }
                else if(dir==2)
                {
                    j--;
                    dir=-1;
                }
                else 
                {
                    j++;
                    dir=1;
                }
            }
            if(j<0)
            {
                ans.push_back(i);
                ans.push_back(j+1);
                return ans;
            }
            if(j>m-1)
            {
                ans.push_back(i);
                ans.push_back(j-1);
                return ans;
            }
            
            if(i<0)
            {
                ans.push_back(i+1);
                ans.push_back(j);
                return ans;
            }
            if(i>n-1)
            {
                ans.push_back(i-1);
                ans.push_back(j);
                return ans;
            }

        }
    
    }

};