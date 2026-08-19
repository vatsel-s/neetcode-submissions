class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        //that involves us going down x for loops of that amount
        //we can pass over 2 arguments, starting argument, we can just pass function calls
        vector<vector<int>> output; 
        for(int i = 1; i <= n; i++)
        {
            vector<int> combination; 
            combination.push_back(i); 
            cout << i; 
            combinations(output, combination, i, n, k); 
        }
        return output; 
    }

    void combinations(vector<vector<int>>&output, vector<int> &combination, int curr, int n, int max_size)
    {
        if(combination.size() == max_size)
        {
            //add it to the returned output
            output.push_back(combination); 
        }
        else
        {
            for(int i = curr + 1; i <= n; i++)
            {
                cout << i; 
                combination.push_back(i); 
                combinations(output, combination, i, n, max_size); 
                combination.erase(combination.begin() + combination.size() - 1); 
            }
        }
    }
};