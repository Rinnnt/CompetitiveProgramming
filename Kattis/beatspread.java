import java.util.Scanner;

public class beatspread {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    while (n-- > 0) {
      int s = sc.nextInt();
      int d = sc.nextInt();
      if ((s + d) % 2 == 1) {
        System.out.println("impossible");
      } else {
        int ans1 = (s + d) / 2;
        int ans2 = s - ans1;
        if (ans1 < 0 || ans2 < 0) {
          System.out.println("impossible");
        } else {
          System.out.println(ans1 + " " + ans2);
        }
      }

    }
  }

}
