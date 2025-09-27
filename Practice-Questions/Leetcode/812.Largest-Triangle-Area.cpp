class Solution {
public:
    double func(vector<vector<int>>&v,int i,int j,int k){
        double x=v[i][0]*(v[j][1]-v[k][1]);
        double y=v[j][0]*(v[k][1]-v[i][1]);
        double z=v[k][0]*(v[i][1]-v[j][1]);
        return abs(x+y+z);
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double area=0;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                for(int k=j+1;k<points.size();k++){
                    double x=func(points,i,j,k);
                    area=max(area,x);
                }
            }
        }
        return area/(double)2;
    }
};
