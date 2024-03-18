
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        size_t n=points.size();
        //sort(points.begin(), points.end());
       sort(points.begin(), points.end(),[](vector<int>& a, vector<int>& b)->bool{
           return a[1]==b[1]? a[0] < b[0] : a[1] < b[1];
       });
        //for(vector<int> vec:points) cout<<"["<<vec[0]<<","<<vec[1]<<"]";
        int reach=points[0][1];
        int arrows=1;
        for(int i=1;i<n;i++){
            if(points[i][0]<=reach) continue;
            arrows++;
            reach=points[i][1];
        }
        return arrows;
    }
};