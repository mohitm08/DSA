class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
       int m[256]={0};
       for(int i=0;i<s.size();i++){
        m[s[i]]++;
       } 
       for(int i=0;i<t.size();i++){
        m[t[i]]--;
       } 
       for(int i=0;i<s.size();i++){
        if(m[s[i]]!=0){return false;
        break;}
       } 
       return true;
    }
};