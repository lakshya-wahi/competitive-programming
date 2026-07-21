class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        longest = 0
        l = 0
        r = 1

        seen = set()

        if len(s) > 0:
            seen.add(s[0])
            longest = 1

        while r < len(s):
            while s[r] in seen:
                seen.remove(s[l])
                l += 1
            seen.add(s[r])
            longest = max(r - l + 1, longest)
            print(longest)
            r += 1
            print(r)
        
        return longest
                
        
        
