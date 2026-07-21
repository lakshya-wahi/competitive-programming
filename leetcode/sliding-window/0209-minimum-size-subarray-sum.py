class Solution(object):
    def minSubArrayLen(self, k, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        l = 0
        r = 0
        currentSum = 0

        minLength = len(nums)

        for num in nums:
            currentSum += num
        if currentSum < k:
            return 0

        currentSum = 0
        while l <= r and r < len(nums):
            currentSum += nums[r]
            while currentSum >= k:
                minLength = min(r - l + 1, minLength)
                currentSum -= nums[l]
                l += 1
            r += 1
        

        return minLength
