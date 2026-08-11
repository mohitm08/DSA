class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int lastSmallest=INT_MIN;
        int largest=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]-1==lastSmallest){
                count++;
                lastSmallest=nums[i];
            }
            else if(nums[i]!=lastSmallest){
                count=1;
                lastSmallest=nums[i];
            }
            largest=max(largest,count);
        }
        return largest;
    }
};