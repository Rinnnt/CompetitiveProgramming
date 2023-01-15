import java.util.Scanner;
import java.lang.Math;

public class UVa11547 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while (t-- > 0) {
      int n = sc.nextInt();
      int res = Math.abs(((n * 567 / 9 + 7492) * 235 / 47 - 498) / 10) % 10;
      System.out.println(res);
    }
  }

}
