import java.util.Scanner;

public class B1820 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            long max = 0;
            long cur = 0;
            boolean zero = false;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '1') {
                    cur += 1;
                }
                else {
                    zero = true;
                    max = Math.max(cur, max);
                    cur = 0;
                }
            }
            max = Math.max(cur, max);

            if (!zero) {
                System.out.println(max * max);
                continue;
            }
            if (max == 0) {
                System.out.println(0);
                continue;
            }

            long start = 0;
            long end = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '1') {
                    start += 1;
                }
                else {
                    break;
                }
            }
            for (int i = s.length() - 1; i >= 0; i--) {
                if (s.charAt(i) == '1') {
                    end += 1;
                }
                else {
                    break;
                }
            }
            max = Math.max(start + end, max);

            long result = 0;
            for (int i = 1; i <= max; i++) {
                result = Math.max(i * (max - i + 1), result);
            }
            System.out.println(result);
        }
    }
}
