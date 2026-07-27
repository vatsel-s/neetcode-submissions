class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores; 
        for(int i = 0; i < operations.size(); i++)
        {
            if(operations[i] == "D")
            {
                scores.push_back(scores[scores.size() - 1] * 2); 
            }
            else if(operations[i] == "+")
            {
                scores.push_back(scores[scores.size() - 1] + scores[scores.size() - 2]); 
            }
            else if(operations[i] == "C")
            {
                scores.erase(scores.begin() + scores.size()); 
            }
            else
            {
                int val = stoi(operations[i]); 
                scores.push_back(val); 
            }
        }
        int total = 0; 
        for(int i = 0; i < scores.size(); i++)
        {
            total += scores[i]; 
        }
        return total; 
    }
};