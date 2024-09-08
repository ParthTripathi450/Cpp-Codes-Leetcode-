class Solution {
public:
    vector <int> NSE(vector<int> arr){
        vector <int> nse(arr.size(),0);
        stack <int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? arr.size():st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> PSEE(vector<int>arr){
        vector <int> psee(arr.size(),0);
        stack <int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            psee[i] = st.empty() ? -1:st.top();
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector <int> psee = PSEE(arr);
        vector <int> nse = NSE(arr);
        int total = 0;
        int mod = (int) (1e9+7);
        for(int i=0;i<arr.size();i++){
            int left = i-psee[i];
            int right = nse[i] - i;
            total = (total + (right*left*arr[i])%mod)%mod;
        }
        return total;
    }
};