/*
数组 滑动窗口

给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组[numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。
如果不存在符合条件的子数组，返回 0 。
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = nums.size();
        int result = INT_MAX; // 初始化结果为最大值
        int slow = 0, fast = 0; // 滑动窗口的左右指针
        int sum = 0;

        while (fast < length) {
            sum += nums[fast];
            while (sum >= target) {
                result = min(result, fast - slow + 1);
                sum -= nums[slow++];
            }
            fast++;
        }

        return (result != INT_MAX) ? result : 0;
    }
};