import java.util.Scanner;

public class UVa12643 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (sc.hasNext()) {
      int n = sc.nextInt();
      int i = sc.nextInt();
      int j = sc.nextInt();
      while (true) {
        int mid = (int) Math.pow(2.0, n) / 2;
        if (i <= mid && j <= mid) {
          n--;
        } else if (i > mid && j > mid) {
          i -= mid;
          j -= mid;
          n--;
        } else {
          break;
        }
      }
      System.out.println(n);
    }
  }

}
