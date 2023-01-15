import java.util.Scanner;

public class UVa11559 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (sc.hasNext()) {
      int n = sc.nextInt();
      int b = sc.nextInt();
      int h = sc.nextInt();
      int w = sc.nextInt();

      int minimumCost = Integer.MAX_VALUE;
      for (int i = 0; i < h; i++) {
        int p = sc.nextInt();

        for (int j = 0; j < w; j++) {
          int a = sc.nextInt();
          if (n <= a && (p * n) <= b && (p * n) < minimumCost) {
            minimumCost = p * n;
          }
        }
      }

      System.out.println((minimumCost == Integer.MAX_VALUE) ? "stay home" : minimumCost);
    }
  }

}
