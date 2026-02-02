class Solution {
public:
void erase_one(multiset<long long>& ms, long long x) {
    auto it = ms.find(x);
    if (it != ms.end()) ms.erase(it);
}
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long ans= LLONG_MAX;
        long long sum =0;
       multiset<long long>st;
       multiset<long long>pq;
       long long mini = LLONG_MAX , maxi = LLONG_MIN;
       for(int i = 1; i<n; i++){
            
         if(i==1){
            for(int j = i+1; j<=i+dist && j < n; j++){
                st.insert(nums[j]);
            }
           
     int ct = 0;
auto it = st.begin();

while (it != st.end()) {
    if (ct < k - 2) {
        sum += *it;
          maxi = max(maxi , *it);
        ct++;
        ++it;
      
    } else {
        pq.insert(*it);
        it = st.erase(it); 
    }
}
        //  for(auto it : st){
        //     cout<<it<<" "<<i<<endl;
        //  }
         }
         else{
        //     if( i + dist < n){
        //         pq.push(nums[i + dist]);

        //     }
        // if(!pq.empty() && pq.top() < maxi){
        //     sum = sum - maxi + pq.top();
        //     st.insert(pq.top());
        //     pq.pop();
        //     pq.push(maxi);
        //     erase_one(st , maxi);
        // }
        // erase_one(st , nums[i]);
        int num1 ;
        
        int val = min(n - 1 ,i + dist);
        int v1 = val - i + 1 + 1; 
           
                num1 = nums[val];
          
            if(v1<k){
                break;
            }
            if(i + dist < n){
                 pq.insert(num1);
            }
            // cout<<"set begin"<<i<<"->"<<endl;
            // for(auto it : st){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            if(st.size() < k -2){
                while(!pq.empty() && st.size() < k -2){
                    sum += *pq.begin(); 
                    st.insert(*pq.begin());
                    pq.erase(pq.begin());
                }
            }
            if(!st.empty())
                 maxi = max(*pq.begin(), *st.rbegin());
                else
                 maxi = *pq.begin();
            if(!pq.empty() && *pq.begin() < maxi){
                erase_one(st , maxi);
                int mx = maxi;
                if(!st.empty())
                 maxi = max(*pq.begin(), *st.rbegin());
                else
                 maxi = *pq.begin();
                sum -= mx;
                st.insert(*pq.begin());
                sum += *pq.begin();
                pq.erase(pq.begin());
                pq.insert(mx);
            }
            if(st.find(nums[i]) != st.end()){
                sum -= nums[i];
                erase_one(st , nums[i]);
                if(!pq.empty()){
                    st.insert(*pq.begin());
                    maxi = max(maxi , *st.rbegin());
                    sum += *pq.begin();
                    pq.erase(pq.begin());
                }
            }
            else{
                erase_one(pq , nums[i]);
            }
            // cout<<"set for"<<i<<"->"<<endl;
            // for(auto it : st){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            // cout<<"sum for"<<i<<"->"<<sum<<endl;
         }
         
            ans = min(ans , (sum + nums[0] + nums[i]));
            // cout<<ans<<" "<<i<<endl;
       }
       return ans ;
    }
};

