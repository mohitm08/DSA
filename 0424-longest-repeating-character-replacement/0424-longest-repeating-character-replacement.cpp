class Solution {
public:
    int characterReplacement(string s, int k) {
    int hashh[26]={0};
    int left=0;
    int maxf=0;
    int maxl=0;
    for(int right=0;right<s.size();right++){
        hashh[s[right]-'A']++;
        maxf=max(hashh[s[right]-'A'],maxf);
        while((right-left+1)-maxf>k){
            hashh[s[left]-'A']--;
            left++;
        }
        maxl=max(right-left+1,maxl);
    }
    return maxl;
    }
};