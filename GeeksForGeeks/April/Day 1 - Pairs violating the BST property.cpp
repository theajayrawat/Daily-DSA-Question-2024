// https://www.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1
// TC: O(NlogN)
// SC: O(N)

class Solution
{
public:
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;   
        int left = low;     
        int right = mid + 1; 
        int count = 0;
        
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                count += mid - left + 1;
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }


        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
        return count;
    }
    int mergeSort(vector<int> &arr, int low, int high)
    {
        int cnt = 0;
        if (low >= high)
            return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);      
        cnt += mergeSort(arr, mid + 1, high); 
        cnt += merge(arr, low, mid, high);
        return cnt;
    }
    void inorder(Node *root, vector<int> &vect)
    {
        if (root == NULL)
            return;
        inorder(root->left, vect);
        vect.push_back(root->data);
        inorder(root->right, vect);
    }
    int pairsViolatingBST(int n, Node *root)
    {
        vector<int> vect;
        inorder(root, vect);
        int count = mergeSort(vect, 0, vect.size() - 1);
        return count;
    }
};