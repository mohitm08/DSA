class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            sum+=(nums[i]%2);
            int rem =sum-k;
            if(mpp.find(rem)!=mpp.end()){
                count+=mpp[rem];
            }
            mpp[sum]++;
        }
        return count;
    }
};