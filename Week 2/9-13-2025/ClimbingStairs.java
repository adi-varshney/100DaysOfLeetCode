// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/description/
// Oops, skipped this one problem yesterday... Adding it today!

import java.util.HashMap;

class Solution {
    public int climbStairs(int n) {
        if (n == 1 || n == 2 || n == 3)
            return n;

        HashMap<Integer, Integer> steps = new HashMap<>();

        steps.put(1, 1);
        steps.put(2, 2);
        steps.put(3, 3);

        int i = 4;
        while (i <= n) {
            steps.put(i, steps.get(i - 1) + steps.get(i - 2));

            i++;
        }

        return steps.get(n);
    }
}