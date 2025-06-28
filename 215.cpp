
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        //o k-ésimo maior elemento é o (n-k)-ésimo menor elemento.
        int target_index = nums.size() - k;

        while (left <= right) {
            int pivot_index = partition(nums, left, right);
            if (pivot_index == target_index) {
                return nums[pivot_index];
            } else if (pivot_index < target_index) {
                left = pivot_index + 1;
            } else {
                right = pivot_index - 1;
            }
        }
        return -1;
    }

private:
    //função de partição que coloca o pivô em sua posição correta no array ordenado.
    int partition(std::vector<int>& nums, int left, int right) {
        //escolhe o último elemento como pivô.
        int pivot_value = nums[right];
        int store_index = left;

        for (int i = left; i < right; ++i) {
            if (nums[i] < pivot_value) {
                std::swap(nums[i], nums[store_index]);
                store_index++;
            }
        }
        //move o pivô para sua posição final.
        std::swap(nums[store_index], nums[right]);
        return store_index;
    }
};

