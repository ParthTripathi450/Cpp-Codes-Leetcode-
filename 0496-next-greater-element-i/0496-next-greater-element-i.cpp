class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> temp;
        vector<int> arr(nums1.size(), 0);
        stack <int> stk;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!stk.empty() && stk.top() <= nums2[i]) stk.pop();
            if(stk.empty()){
                auto it = find(nums1.begin(), nums1.end(), nums2[i]);
                if(it!= nums1.end()){
                    arr[distance(nums1.begin(), it)] = -1;
                    temp.push_back(-1);
                }
            }
            else{
                temp.push_back(stk.top());

                auto it = find(nums1.begin(), nums1.end(), nums2[i]);
                if(it!= nums1.end()){
                    arr[distance(nums1.begin(), it)] = stk.top();
                    temp.push_back(stk.top());
                }
            } 
            stk.push(nums2[i]);
        }
        return arr;

    }
};