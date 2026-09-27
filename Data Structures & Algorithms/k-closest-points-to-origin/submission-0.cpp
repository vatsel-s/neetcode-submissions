class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //we have to add all these points to a heap, have a score with them as 
        //well, we're going to have something that indexes them to original array
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        for(int i = 0; i < points.size(); i++)
        {
            pq.push({pow(points[i][0], 2) + pow(points[i][1], 2), i}); 
        }
        vector<vector<int>> result; 
        for(int i = 0; i < k; i++)
        {
            result.push_back(points[pq.top().second]); 
            pq.pop(); 
        }
        return result; 
    }
};
