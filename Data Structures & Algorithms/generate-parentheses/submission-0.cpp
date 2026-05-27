class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result; 
        string currentStr = "";
        findCombinations(result, currentStr, 0, 0, n); 
        return result; 
    }

    void findCombinations(vector<string>& results, string str, int open, int total_open, int n)
    {
        cout << str << " " << str.size() << " " << open << " " << n << endl; 
        if(str.size() == n*2)
        {
            results.push_back(str); 
            return; 
        }
        if(open != n && total_open<n)
        {
            string new_str = str + "("; 
            findCombinations(results, new_str, open+1, total_open+1, n); 
        }
        if(open != 0)
        {
            string other_str = str + ")"; 
            findCombinations(results, other_str, open-1, total_open, n);
        }
    }
};
