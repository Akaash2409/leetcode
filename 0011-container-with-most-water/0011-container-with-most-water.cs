public class Solution {
    public int MaxArea(int[] height) {
        var i = 0;
        var j = height.Length-1;
        var max = 0;
        
        while (i < j) {
            max = Math.Max(max, Math.Min(height[i], height[j]) * (j-i));
            if (height[i] < height[j]) i++;
            else j--;
        }
        
        return max;
    }
}