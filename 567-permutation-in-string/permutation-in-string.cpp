class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        vector<int> nums1(26,0);
        for(int i=0;i<s1.size();i++){
            nums1[s1[i] - 'a']++;
        }
        vector<int> nums2(26,0);
        for(int i=0;i<s1.size();i++){
            nums2[s2[i] - 'a']++;
        }
        if (nums1 == nums2)
            return true;
        for(int i=s1.size();i<s2.size();i++){
            nums2[s2[i]-'a']++;
            nums2[s2[i-s1.size()]-'a']--;
            if(nums1==nums2){
                return true;
            }
        }
        return false;
    }
};