class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> arr(s.size()); 
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] == 1 || i == 0)
            {
                for(int j = 0; j < wordDict.size(); j++)
                {
                    int len = wordDict[j].size(); 
                    if(s.substr(i, len) == wordDict[j])
                    {
                        if(i + len == s.size())
                        {
                            return true; 
                        }
                        else if(i + len < s.size())
                        {
                            arr[i + len] = 1; 
                            cout << i + len << endl; 
                        } 
                    }
                }
            }
        }
        return false; 
    }
};
