class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    int maxeq = INT_MIN;
    priority_queue<pair<int, int>> pq; // {y - x, x} => {points[i][1] - points[i][0], points[i][0]}
    
    for (int i = 0; i < points.size(); i++) {
        int x = points[i][0];
        int y = points[i][1];
        
        // Remove points outside the window of size k
        while (!pq.empty() && x - pq.top().second > k) {
            pq.pop();
        }
        
        if (!pq.empty()) {
            maxeq = max(maxeq, y + x + pq.top().first);
        }
        
        pq.push({y - x, x});
    }
    
    return maxeq;
}


};
