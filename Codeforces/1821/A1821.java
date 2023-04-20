import java.util.Scanner;

public class A1821 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            long result = 1;
            if (s.charAt(0) == '0') {
                System.out.println(0);
                continue;
            }
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '?') {
                    if (i == 0) {
                        result *= 9;
                    } else {
                        result *= 10;
                    }
                }
            }
            System.out.println(result);


        }
    }
}
