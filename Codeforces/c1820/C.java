package c1820;

import java.util.*;

public class C {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            Map<Integer, Integer> count = new HashMap<>();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                nums[i] = x;
                count.put(x, count.getOrDefault(x, 0) + 1);
            }

            int mex = 0;
            while (count.containsKey(mex)) {
                mex++;
            }

            boolean possible = false;
            if (count.containsKey(mex + 1)) {
                boolean replacing = false;
                possible = true;
                for (int i = 0; i < nums.length; i++) {
                    if (nums[i] == mex + 1) {
                        replacing = true;
                    }
                    if (replacing) {
                        if (count.get(nums[i]) == 1) {
                            if (nums[i] < mex + 1) {
                                possible = false;
                                break;
                            }
                            if (nums[i] == mex + 1) {
                                break;
                            }
                        }
                        count.put(nums[i], count.get(nums[i]) - 1);
                    }
                }
            } else {
                for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
                    if (entry.getKey() < mex + 1 && entry.getValue() > 1) {
                        possible = true;
                        break;
                    }
                    if (entry.getKey() > mex + 1) {
                        possible = true;
                        break;
                    }
                }
            }

            if (possible) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}
