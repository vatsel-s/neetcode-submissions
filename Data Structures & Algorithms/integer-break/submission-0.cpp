class Solution {
public:
    int integerBreak(int n) {
        vector<int> arr(n, 0); 
        arr[0] = 1; 
        for(int i = 0; i < arr.size(); i++)
        {
            int curr_max = 1; 
            for(int j = 0; j < i; j++)
            {
                int diff = i - j; 
                int multiplier = max(arr[j], j + 1);
                //cout << multiplier << " " << diff << endl; 
                curr_max = max(multiplier * diff, curr_max); 
            }
            arr[i] = curr_max;
            //cout << curr_max << endl;  
        }
        return arr[arr.size() - 1]; 
    }
};