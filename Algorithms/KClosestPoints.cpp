class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size()/2;
        sort(points.begin(), points.end(), comparedistance);
        vector<vector<int>> solution;
        for(int i = 0; i < K; i++){
            solution.push_back(points[i]);
        }
        return solution;
        
    }
    
    static bool comparedistance(vector<int>& point1, vector<int>& point2){
        return (pow(point1[0], 2) + pow(point1[1], 2)) < (pow(point2[0], 2) + pow(point2[1], 2));
    }
};