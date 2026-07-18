class Solution {
public:
   int findgc(int a,int b){
    return (b%a==0)?a:findgc(b%a,a);
   }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int minn=nums[0];
        int maxn=nums[nums.size()-1];
        return findgc(minn,maxn);
    }
};