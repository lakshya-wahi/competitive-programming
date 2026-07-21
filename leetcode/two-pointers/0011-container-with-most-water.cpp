class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int largestArea = 0;
        while (left < right) {
            int curArea = min(height[left], height[right]) * (right - left);
            largestArea = max(largestArea, curArea);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return largestArea;
    }
};
