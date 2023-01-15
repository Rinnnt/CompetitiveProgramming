import java.util.Scanner;
import java.lang.Math;

public class artichoke {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int p = sc.nextInt();
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    int d = sc.nextInt();
    int n = sc.nextInt();

    double highestPrice = Double.MIN_VALUE;
    double largestDecline = 0;
    for (int i = 1; i <= n; i++) {
      double price = p * (Math.sin(a * i + b) + Math.cos(c * i + d) + 2);
      if (price > highestPrice) {
        highestPrice = price;
      } else {
        if (highestPrice - price > largestDecline) {
          largestDecline = highestPrice - price;
        }
      }
    }

    System.out.println(largestDecline);
  }

}
