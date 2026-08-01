class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(k>=n)return "0";
        stack<int>s;
        s.push(num[0]);
        for(int i=1;i<n;i++){
            while(!s.empty() && s.top()>num[i] && k>0){
                s.pop();
                k--;
            }
         s.push(num[i]);
        }
        while(k>0){
            s.pop();
            k--;
        }
        if(s.empty())return "0";

        string res="";
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        while(res.size()!=0 && res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        return res.empty()?"0":res;

    }
};