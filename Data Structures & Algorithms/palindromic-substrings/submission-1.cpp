class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() == 0)
        {
            return 0; 
        }
        int count = 0; 
        //counting odd palindromes
        for(int i = 0; i < s.size(); i++)
        {
            count++;
            int left = i - 1; 
            int right = i + 1;  
            while(left >= 0 && right < s.size())
            {
                if(s[left] == s[right])
                {
                    count++; 
                    left--; 
                    right++; 
                }
                else 
                {
                    break; 
                }
            }
        }
        //counting even palindromes
        for(int i = 0; i < s.size() - 1; i++)
        {
            if(s[i] == s[i+1])
            {
                count++; 
                int left = i-1; 
                int right = i+2;
                while(left >= 0 && right < s.size())
                {
                    if(s[left] == s[right])
                    {
                        count++; 
                        left--; 
                        right++; 
                    }
                    else 
                    {
                        break; 
                    }
                }
            }
        }
        return count; 
    }
};
