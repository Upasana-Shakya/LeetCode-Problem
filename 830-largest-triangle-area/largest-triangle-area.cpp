class Solution {
public:
    double area(vector<int>A, vector<int>B, vector<int>C){
        int x1 = A[0], y1 = A[1];
        int x2 = B[0], y2 = B[1];
        int x3 = C[0], y3 = C[1];

        return 0.5 * abs(x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1);
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double res = 0.0;

        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                for(int k=j+1 ; k<n ; k++){
                    res = max(res, area(points[i], points[j], points[k]));
                }
            }
        }
        return res;
    }
};