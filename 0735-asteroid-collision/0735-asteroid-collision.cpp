class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       int n=asteroids.size();
       stack<int>s;
       for(int i=0;i<n;i++){
        if(asteroids[i]>0)s.push(asteroids[i]);
        else{
            int a=-asteroids[i];
            while(!s.empty() && s.top()>0 && a>s.top()){
                s.pop();
            }
            if(s.empty() || s.top()<0)s.push(asteroids[i]);
            else if(s.top()==a)s.pop();
        }
       }
       vector<int> ans(s.size());

for(int i = s.size() - 1; i >= 0; i--) {
    ans[i] = s.top();
    s.pop();
}
       return ans;
    }
};