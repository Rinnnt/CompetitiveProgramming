package c1768;

import java.util.Scanner;

public class B {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while (t-- > 0) {
      int n = sc.nextInt();
      int k = sc.nextInt();
      int[] arr = new int[n];
      for (int i = 0; i < n; i++) {
        arr[i] = sc.nextInt();
      }

      int correct = 1;
      for (int i = 0; i < n; i++) {
        if (correct == arr[i]) {
          correct++;
        }
      }

      System.out.println((n - (correct - 1) + k - 1) / k);

    }
  }

}
