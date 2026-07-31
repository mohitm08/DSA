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
        long long sumSubarrayMins(vector<int>& arr) {
            vector<int> nse=findNSE(arr);
        vector<int> pse=findPSE(arr);
        long long total=0;
        for(int i=0;i<arr.size();i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            total=(total+(left*right*1LL*arr[i]));
        }
        return total;
    }

    vector<int> findNGE(vector<int> &arr) {
            int n=arr.size();
            vector<int>ans(n);
            stack<int>s;
            for(int i=n-1;i>=0;i--){
                while(!s.empty() && arr[s.top()]<=arr[i]){
                    s.pop();
                }
                ans[i]=!s.empty()?s.top():n;
                s.push(i);
            }
            return ans;
        }
        vector<int> findPGE(vector<int>&arr){
            int n=arr.size();
            vector<int>ans(n);
            stack<int>s;
            for(int i=0;i<n;i++){
                while(!s.empty() && arr[s.top()]<arr[i]){
                    s.pop();
                }
                ans[i]=!s.empty()?s.top():-1;
                s.push(i);
            }
            return ans;
        }
        long long sumSubarrayMaxs(vector<int>& arr) {
            vector<int> nge=findNGE(arr);
        vector<int> pge=findPGE(arr);
        long long total=0;
        for(int i=0;i<arr.size();i++){
            int left=i-pge[i];
            int right=nge[i]-i;
            total=(total+(left*right*1LL*arr[i]));
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {

            // long long sum=0;
        // for(int i=0;i<nums.size();i++){
        //     int mini=nums[i];
        //     int maxi=nums[i];
            
        //     for(int j=i;j<nums.size();j++){
        //         mini=min(mini,nums[j]);
        //         maxi=max(maxi,nums[j]);
        //         sum=sum+(maxi-mini);
        //     }

        // }
        // return sum;


        long long maxi=sumSubarrayMaxs(nums);
        long long mini=sumSubarrayMins(nums);
        return maxi-mini;
    }
};