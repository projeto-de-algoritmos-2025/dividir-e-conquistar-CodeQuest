class Solution:
    def sortArray(self, nums):
        # Caso base: array com 0 ou 1 elemento já está ordenado
        if len(nums) <= 1:
            return nums

        # Divide o array em duas partes
        mid = len(nums) // 2
        left = self.sortArray(nums[:mid])
        right = self.sortArray(nums[mid:])

        # Conquista (merge): junta os dois arrays ordenados
        return self.merge(left, right)

    def merge(self, left, right):
        result = []
        i = j = 0

        # Combina os dois arrays ordenadamente
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                result.append(left[i])
                i += 1
            else:
                result.append(right[j])
                j += 1

        # Adiciona o restante dos elementos
        result.extend(left[i:])
        result.extend(right[j:])
        return result
