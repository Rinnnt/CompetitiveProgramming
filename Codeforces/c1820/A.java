package c1820;

import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String line = sc.next();
            if (line.length() == 1) {
                System.out.println((line.charAt(0) == '^') ? 1 : 2);
            }
            else {
                int result = 0;
                if (line.charAt(0) == '_') {
                    result += 1;
                }
                if (line.charAt(line.length() - 1) == '_') {
                    result += 1;
                }
                for (int i = 0; i < line.length() - 1; i++) {
                    if (line.charAt(i) == '_' && line.charAt(i + 1) == '_') {
                        result += 1;
                    }
                }
                System.out.println(result);
            }
        }
    }

}
