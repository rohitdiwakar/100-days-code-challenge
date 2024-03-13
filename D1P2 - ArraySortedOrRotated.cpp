//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

class Solution {
public:
    bool check(vector<int>& nums) {
      int cnt=0;
      int n=nums.size();
      for(int i=1;i<n;i++){
       if(nums[i-1]>nums[i])cnt++;
      }
      if(cnt==1){
        if(nums[n-1]<=nums[0])return true;
        else return false;
      }
      if(cnt>1){
        return false;
      }
      return true;
    }
};