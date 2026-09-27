class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st; 
        vector<int> result(temperatures.size(), 0); 
        pair<int, int> val(temperatures[0], 0); 
        st.push(val); 
        for(int i = 1; i < temperatures.size(); i++)
        {
            pair<int, int> top = st.top(); 
            while(!st.empty() && top.first < temperatures[i])
            {
                result[top.second] = i - top.second; 
                st.pop(); 
                top = st.top(); 
            }
            pair<int, int> num(temperatures[i], i); 
            st.push(num); 
        }
        return result; 
    }
};
