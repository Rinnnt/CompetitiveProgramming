import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class C1821 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            List<Integer> ops = new ArrayList<>();
            for (int i = 0; i < 26; i++) {

                int max = 0;
                int cur = 0;
                for (int j = 0; j < s.length(); j++) {
                    if (s.charAt(j) != Character.toChars(97 + i)[0]) {
                        cur += 1;
                    }
                    else {
                        max = Math.max(cur, max);
                        cur = 0;
                    }
                }
                max = Math.max(cur, max);
                if (max > 0) {
                    ops.add(((int) (Math.log(max) / Math.log(2))) + 1);
                }
                else {
                    ops.add(0);
                }
            }
            int result = 99999999;
            for (int x : ops) {
                result = Math.min(x, result);
            }
            System.out.println(result);
        }
    }
}
