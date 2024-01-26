// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
// T.C : O(NlogN)
// S.C : O(N)

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(pair<double,Item>a,pair<double,Item>b){
        return a.first>b.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,Item>>v;
        for(int i=0;i<n;i++){
            double d=(double)arr[i].value/arr[i].weight;
            pair<double,Item>p=make_pair(d,arr[i]);
            v.push_back(p);
        }
        sort(v.begin(),v.end(),cmp);
        double ans=0;
        for(int i=0;i<n;i++){
            if(v[i].second.weight>W){
                ans+=W*v[i].first;
                break;
            }
            ans+=v[i].second.value;
            W-=v[i].second.weight;
        }
        return ans;
    }
        
};