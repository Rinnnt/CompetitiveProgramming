package c1821;

import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            for (int i = 0; i < n; i++) {
                b[i] = sc.nextInt();
            }

            int l = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    l = i;
                    break;
                }
            }
            int r = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (a[i] != b[i]) {
                    r = i;
                    break;
                }
            }
            while (l > 0) {
                if (b[l - 1] <= b[l]) {
                    l--;
                } else {
                    break;
                }
            }
            while (r < n - 1) {
                if (b[r + 1] >= b[r]) {
                    r++;
                } else {
                    break;
                }
            }

            System.out.print(l + 1);
            System.out.print(" ");
            System.out.println(r + 1);


        }
    }
}
