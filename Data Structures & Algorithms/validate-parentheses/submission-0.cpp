class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        stack.push_back(s[0]);
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == ']' && stack[stack.size() -1] == '[' || s[i] == '}' && stack[stack.size() -1] == '{' || s[i] == ')' && stack[stack.size() -1] == '(')
            {
                stack.erase(stack.begin() + stack.size() -1); 
            }
            else 
            {
                stack.push_back(s[i]); 
            }
        }
        if(stack.size() != 0)
        {
            return false; 
        }
        return true; 
    }
};
