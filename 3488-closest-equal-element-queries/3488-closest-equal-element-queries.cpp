class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int sz = nums.size();
        unordered_map<int, vector<int>> indices;
        
        // 1. Group indices by their values
        for (int i = 0; i < sz; i++) {
            indices[nums[i]].push_back(i);
        }
        
        // 2. Calculate minimum circular distances
        for (auto& pair : indices) {
            vector<int>& arr = pair.second;
            int m = arr.size();
            
            if (m == 1) {
                nums[arr[0]] = -1;
                continue;
            }
            
            for (int i = 0; i < m; i++) {
                int j = arr[i];
                
                // Get immediate neighbors in the list (with wrap-around)
                int f = arr[(i + 1) % m];
                int b = arr[(i - 1 + m) % m];
                
                // Calculate minimum circular distances
                // min(direct_distance, circular_wrap_distance)
                int dist_f = min(abs(j - f), sz - abs(j - f));
                int dist_b = min(abs(j - b), sz - abs(j - b));
                
                // Overwrite the original array
                nums[j] = min(dist_f, dist_b);
            }
        }
        
        // 3. Answer the queries
        vector<int> res;
        res.reserve(queries.size());
        for (int q : queries) {
            res.push_back(nums[q]);
        }
        
        return res;
    }
};