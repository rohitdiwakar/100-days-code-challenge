class Solution {
public:
    int pivotInteger(int n) {
        if(n==1)return 1;
        vector<int>v;
        v.push_back(1);
        if(n>1){
            for(int i=1;i<n;i++){
                v.push_back(v[i-1]+i+1);
            }
            int t=0;
            for(int i=n-1;i>=0;i--){
               t+=i+1;
               if(v[i]==t)return i+1;
            }
        }
        return -1;
    }
};