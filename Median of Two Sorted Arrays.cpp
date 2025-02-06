// Brute force O(n+m) & O(n+m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> nums;
        int i=0, j=0;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]){
                nums.push_back(static_cast<double>(nums1[i]));
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                j++;
            }
        }

        while(i<nums1.size()){
            nums.push_back(nums1[i]);
            i++;
        }

        while(j<nums2.size()){
            nums.push_back(nums2[j]);
            j++;
        }

        int n = nums.size();
        if(n%2 != 0) return nums[n/2];
        else{
            return (nums[(n / 2) - 1] + nums[n / 2]) / 2.0;
        }
    }
};

// Better O(n+m) & O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int size = n + m;

        int idx = 0;
        int ele , ele1 = 0;
        int i=0, j = 0;

        while(i<n && j<m){
            if(nums1[i] < nums2[j]){
                if(size%2 == 0 && idx == (size/2)-1) ele1 = nums1[i];
                if(idx == (size/2)) ele = nums1[i];
                idx++;
                i++;
            }
            else{
                if(size%2 == 0 && idx == (size/2)-1) ele1 = nums2[j];
                if(idx == (size/2)) ele = nums2[j];
                idx++;
                j++;
            }
        }

        while(i<nums1.size()){
            if(size%2 == 0 && idx == (size/2)-1) ele1 = nums1[i];
            if(idx == (size/2)) ele = nums1[i];
            idx++;
            i++;
        }

        while(j<nums2.size()){
            if(size%2 == 0 && idx == (size/2)-1) ele1 = nums2[j];
            if(idx == (size/2)) ele = nums2[j];
            idx++;
            j++;
        }
        cout<<"ele "<<ele<<endl;
        cout<<"ele1 "<<ele1<<endl;
        return size%2 == 0 ? static_cast<double>(ele+ele1)/2 : ele;
    }
};
