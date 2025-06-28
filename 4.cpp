
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {

        if (nums2.size() < nums1.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;

        while (low <= high) {
            // particaoX é o ponto de corte no primeiro array.
            int partitionX = (low + high) / 2;
            // particaoY é calculado para que o total de elementos à esquerda seja (n1+n2+1)/2
            int partitionY = (n1 + n2 + 1) / 2 - partitionX;

            int maxLeftX = (partitionX == 0) ? std::numeric_limits<int>::min() : nums1[partitionX - 1];
            int minRightX = (partitionX == n1) ? std::numeric_limits<int>::max() : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? std::numeric_limits<int>::min() : nums2[partitionY - 1];
            int minRightY = (partitionY == n2) ? std::numeric_limits<int>::max() : nums2[partitionY];

            // verifica se encontramos a partição correta.
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // s o número total de elementos for par
                if ((n1 + n2) % 2 == 0) {
                    return (double)(std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
                } else { // Se for ímpar.
                    return (double)std::max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                // a partição em X está muito à direita
                high = partitionX - 1;
            } else {
                // a partição em X está muito à esquerda
                low = partitionX + 1;
            }
        }
        return 0;
    }
};

