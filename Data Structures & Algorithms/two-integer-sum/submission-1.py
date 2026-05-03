class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}

        for i in range(len(nums)):
            y = target - nums[i]

            if y in mp:
                return [mp[y],i] 
            mp[nums[i]] = i