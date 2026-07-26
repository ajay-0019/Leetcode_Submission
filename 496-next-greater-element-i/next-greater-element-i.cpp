class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            bool check=true;
            for(int j=i+1;j<nums2.size();j++){
                if(nums2[j]>nums2[i]){
                    mp[nums2[i]]=nums2[j];
                    check=false;
                    break;
                }
            }
            if(check){
                mp[nums2[i]]=-1;
            }
        }

        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};