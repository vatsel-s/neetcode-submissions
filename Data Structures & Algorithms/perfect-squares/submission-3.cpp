class Solution {
public:
    int numSquares(int n) {
        vector<int> arr(n + 1, 0); 
        if(n == 1)
        {
            return 1; 
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= sqrt(n); j++)
            {
                int squared = j*j; 
                if(i + squared < n + 1 && (arr[i + squared] == 0 || arr[i] + 1 < arr[i + squared]))
                {
                    arr[i + squared] = arr[i] + 1; 
                }
            }
        }
        return arr[n]; 
    }
};