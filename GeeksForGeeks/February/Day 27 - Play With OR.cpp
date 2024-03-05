// https://www.geeksforgeeks.org/problems/play-with-or5515/1
// TC: O(N)
// SC: O(1)


int* game_with_number(int arr[], int n)
{
    
    // Complete the function
    
     for(int i=0; i<n-1; i++) {
        arr[i] = arr[i] | arr[i+1];
    }
    
    return arr;
}

