class Solution:
    def countRangeSum(self, nums, lower, upper):
        # Calcula prefix sums: soma acumulada
        prefix_sums = [0]
        for num in nums:
            prefix_sums.append(prefix_sums[-1] + num)

        def count_while_merge_sort(lo, hi):
            if hi - lo <= 1:
                return 0
            mid = (lo + hi) // 2
            count = count_while_merge_sort(lo, mid) + count_while_merge_sort(mid, hi)

            j = k = mid
            for left in prefix_sums[lo:mid]:
                # Move j até que right[j] - left >= lower
                while k < hi and prefix_sums[k] - left < lower:
                    k += 1
                # Move j até que right[j] - left > upper
                while j < hi and prefix_sums[j] - left <= upper:
                    j += 1
                count += j - k

            # Ordena (merge)
            prefix_sums[lo:hi] = sorted(prefix_sums[lo:hi])
            return count

        return count_while_merge_sort(0, len(prefix_sums))
