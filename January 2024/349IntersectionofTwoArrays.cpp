#include <vector>
#include <algorithm>

class Solution {
public:
    int binarySearch(const std::vector<int>& array, int target) {
        int left = 0;
        int right = array.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if the middle element is the target
            if (array[mid] == target) {
                return mid; // Return the index if found
            }

            // If the target is smaller, search in the left half
            if (array[mid] > target) {
                right = mid - 1;
            } 
            // If the target is larger, search in the right half
            else {
                left = mid + 1;
            }
        }

        // If the loop terminates without finding the target, return -1
        return -1;
    }

    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        int array = 0;
        if (nums1.size() > nums2.size()) {
            std::sort(nums2.begin(), nums2.end());
            array = 2;
        } else {
            std::sort(nums1.begin(), nums1.end());
            array = 1;
        }
        std::vector<int> result;
        if (array == 1) {
            for (int i = 0; i < nums2.size(); i++) {
                int idx = binarySearch(nums1, nums2[i]);
                if (idx != -1 && result.empty()) {
                    result.push_back(nums2[i]);
                    nums1[idx] = -1;
                }
            }
        } else {
            for (int i = 0; i < nums1.size(); i++) {
                int idx = binarySearch(nums2, nums1[i]);
                if (idx != -1 && result.empty()) {
                    result.push_back(nums1[i]);
                    nums2[idx] = -1;
                }
            }
        }
        return result;
    }
};
