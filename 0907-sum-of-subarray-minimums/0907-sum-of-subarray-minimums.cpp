class Solution {
public:
 vector<int> findNSE(vector<int> &arr) {
            int n=arr.size();
            vector<int>ans(n);
            stack<int>s;
            for(int i=n-1;i>=0;i--){
                while(!s.empty() && arr[s.top()]>=arr[i]){
                    s.pop();
                }
                ans[i]=!s.empty()?s.top():n;
                s.push(i);
            }
            return ans;
        }
        vector<int> findPSE(vector<int>&arr){
            int n=arr.size();
            vector<int>ans(n);
            stack<int>s;
            for(int i=0;i<n;i++){
                while(!s.empty() && arr[s.top()]>arr[i]){
                    s.pop();
                }
                ans[i]=!s.empty()?s.top():-1;
                s.push(i);
            }
            return ans;
        }
    int sumSubarrayMins(vector<int>& arr) {
        //BRUTE:
        // long long sum=0;
        // int mod=1e9+7;
        // for(int i=0;i<arr.size();i++){
        //     int mini=arr[i];
        //     for(int j=i;j<arr.size();j++){
        //         mini=min(mini,arr[j]);
        //         sum=(sum+mini)%mod;
        //     }
        // }
        // return sum;

        //OPTIMIZED:

       
         
        vector<int> nse=findNSE(arr);
        vector<int> pse=findPSE(arr);
        int mod=1e9+7;
        int total=0;
        for(int i=0;i<arr.size();i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            total=(total+(left*right*1LL*arr[i]))%mod;
        }
        return total;
    }
};