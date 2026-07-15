class Solution {
public:
    int numDecodings(string s) {

        vector<int> arr(s.size()); 
        //base case
        if(s.size() == 0 || s[0] == '0')
        {
            return 0; 
        }
        if(s.size() == 1)
        {
            return 1; 
        }
        arr[0] = 1; 

        //base case part 2
        if(stoi(s.substr(0, 2)) <= 26 && s[1] != '0')
        {
            arr[1] = 2; 
        }
        else if(s[1] == '0' && stoi(s.substr(0, 2)) > 26)
        {
            arr[1] = 0; 
        }
        else
        {
            arr[1] = 1; 
        }
        
        for(int i = 2; i < s.size(); i++)
        {
            //from 2 away //this must not have worked
            if(s.substr(i-1, 2) <= "26" && s.substr(i-1, 2) >= "10")
            {
                arr[i] += arr[i - 2]; 
            }
            if(s[i] != '0')
            {
                arr[i] += arr[i - 1];
            }
            
        }
        for(int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << endl; 
        }
        return arr[s.size() - 1]; 
    }
};
