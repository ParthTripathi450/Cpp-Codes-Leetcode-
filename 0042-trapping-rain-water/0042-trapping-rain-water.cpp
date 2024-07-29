class Solution {
public:
    int trap(vector<int>& height) {
        int smax[height.size()];
        smax[height.size()-1]=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--){
            smax[i]=max(smax[i+1],height[i]);
        }
        int pmax[height.size()];
        pmax[0]=height[0];
        for(int i=1;i<height.size();i++){
            pmax[i]=max(pmax[i-1],height[i]);
        }
        int total=0;
        for(int i=0;i<height.size();i++){
            int premax = pmax[i];
            int sufmax = smax[i];
            if(height[i]<premax && height[i]<sufmax){
                total+=min(premax,sufmax)-height[i];
            }
        }
        return total;
    }
};