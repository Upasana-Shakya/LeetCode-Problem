class Solution(object):
    def countSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res=0
        n=len(nums)

        for i in range(0, n-2):
            if 2*(nums[i]+nums[i+2]) == nums[i+1]:
                res+=1
        return res