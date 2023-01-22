import java.util.Scanner;

public class bitsequalizer {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    for (int k = 1; k <= t; k++) {
      String s1 = sc.next();
      String s2 = sc.next();

      int overallDiff = 0;
      int oneDiff = 0;
      int oneZero = 0;
      int zeroOne = 0;
      int ans;

      for (int i = 0; i < s1.length(); i++) {
        char c1 = s1.charAt(i);
        char c2 = s2.charAt(i);
        if (c1 != c2) {
          overallDiff++;
        }
        if (c1 == '?' && c2 == '1') {
          oneDiff--;
        }
        else if (c1 == '0' && c2 == '1') {
          oneDiff--;
          zeroOne++;
        }
        else if (c1 == '1' && c2 == '0') {
          oneDiff++;
          oneZero++;
        }
      }

      if (oneDiff > 0) {
        ans = -1;
      }
      else {
        ans = overallDiff - Math.min(oneZero, zeroOne);
      }

      System.out.println("Case " + k + ": " + ans);
    }
  }

}
