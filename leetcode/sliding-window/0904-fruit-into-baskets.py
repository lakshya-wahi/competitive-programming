class Solution(object):
    def totalFruit(self, fruits):
        """
        :type fruits: List[int]
        :rtype: int
        """
        l = 0
        r = 1

        fruit1 = fruits[l]
        while r < len(fruits) and fruits[r] == fruits[l]:
            r += 1
        if r >= len(fruits):
            return len(fruits)
        fruit2 = fruits[r]

        maxLen = r - l + 1

        while r < len(fruits):
            if (fruits[r] != fruit1) and (fruits[r] != fruit2):
                fruit1 = fruits[r]
                l = r - 1
                fruit2 = fruits[l]
                while l > 0 and fruits[l - 1] == fruit2:
                    l -= 1
            maxLen = max(maxLen, r - l + 1)
            r += 1
        return maxLen
            
