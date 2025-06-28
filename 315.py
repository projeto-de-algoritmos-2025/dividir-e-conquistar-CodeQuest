class Solution:
    def countSmaller(self, nums):
        result = [0] * len(nums)  # Armazena a contagem final
        enum = list(enumerate(nums))  # Guarda os índices originais

        def sort(enum):
            if len(enum) <= 1:
                return enum

            # Divide
            mid = len(enum) // 2
            left = sort(enum[:mid])
            right = sort(enum[mid:])

            # Conquista e conta elementos menores à direita
            merged = []
            i = j = 0
            while i < len(left) or j < len(right):
                if j == len(right) or (i < len(left) and left[i][1] <= right[j][1]):
                    result[left[i][0]] += j  # Soma quantos da direita já foram usados
                    merged.append(left[i])
                    i += 1
                else:
                    merged.append(right[j])
                    j += 1
            return merged

        sort(enum)
        return result
