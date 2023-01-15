import java.util.Scanner;
import java.lang.Math;

public class UVa11614 {

  /*
  n - number of rows
  x - number of troops
  n(n + 1) / 2 = x
  n^2 + n - 2x = 0
   */
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while (t-- > 0) {
      long n = sc.nextLong();
      int root = (int) Math.floor((-1 + Math.sqrt(1 - (4 * -2 * n))) / (2));
      System.out.println(root);
    }
  }

}
