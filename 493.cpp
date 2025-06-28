
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int reversePairs(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        return mergeSortAndCount(nums, 0, nums.size() - 1);
    }

private:
    int mergeSortAndCount(std::vector<int>& nums, int left, int right) {
        if (left >= right) {
            return 0;
        }

        int mid = left + (right - left) / 2;
        //conta pares na metade esquerda
        int count = mergeSortAndCount(nums, left, mid);
        //conta pares na metade direita
        count += mergeSortAndCount(nums, mid + 1, right);
        //conta pares que cruzam as metades
        count += countPairs(nums, left, mid, right);
        //mescla as duas metades
        merge(nums, left, mid, right);

        return count;
    }


    //função para contar os pares (i, j) tais que nums[i] > 2 * nums[j]
    //onde i está em [left, mid] e j está em [mid + 1, right].
    int countPairs(std::vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        for (int i = left; i <= mid; ++i) {
            //para cada elemento na metade esquerda, encontramos quantos na direita satisfazem a condição.
            while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        return count;
    }

    //função de mesclagem padrão do Merge Sort.
    void merge(std::vector<int>& nums, int left, int mid, int right) {
        std::vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        while (j <= right) {
            temp[k++] = nums[j++];
        }

        for (int l = 0; l < temp.size(); ++l) {
            nums[left + l] = temp[l];
        }
    }
};
