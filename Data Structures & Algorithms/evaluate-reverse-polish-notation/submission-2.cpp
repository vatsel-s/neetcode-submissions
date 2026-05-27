class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack; 
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            {
                int num = stoi(tokens[i]); 
                stack.push_back(num); 
            }
            else 
            {
                int first = stack[stack.size() - 1]; 
                int second = stack[stack.size() - 2]; 
                int result = 0; 
                if(tokens[i] == "+")
                {
                    result = first + second; 
                }
                else if(tokens[i] == "-")
                {
                    result = second - first; 
                }
                else if(tokens[i] == "*")
                {
                    result = first * second; 
                }
                else 
                {
                    result = second/first; 
                }
                stack.erase(stack.begin() + stack.size()); 
                stack.erase(stack.begin() + stack.size()); 
                stack.push_back(result); 
            }
            
        }
        return stack[0]; 
    }
};
