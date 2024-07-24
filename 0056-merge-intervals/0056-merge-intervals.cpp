class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector <vector<int>> res;
        for(int i=0;i<intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(!res.empty() && end <= res.back()[1]) continue;
            for(int j=i+1;j<intervals.size();j++){
                if(intervals[j][0] <= end){
                    end = max(end,intervals[j][1]);
                }
                else{
                    break;
                }
            }
            res.push_back({start,end});
        }
        return res;
    }
};