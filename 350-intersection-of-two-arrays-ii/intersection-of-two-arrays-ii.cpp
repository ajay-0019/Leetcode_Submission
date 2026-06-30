class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        if(nums1.size()>nums2.size()){
            for(int i=0;i<nums2.size();i++){
                mp[nums2[i]]++;
            }
            for(int i=0;i<nums1.size();i++){
                if(mp.contains(nums1[i]) && mp[nums1[i]]!=0){
                    ans.push_back(nums1[i]);
                    mp[nums1[i]]--;
                }
            }
            return ans;
        }
        for(int i=0;i<nums1.size();i++){
                mp[nums1[i]]++;
            }
            for(int i=0;i<nums2.size();i++){
                if(mp.contains(nums2[i]) && mp[nums2[i]]!=0){
                    ans.push_back(nums2[i]);
                    mp[nums2[i]]--;
                }
            }
            return ans;
    }
};