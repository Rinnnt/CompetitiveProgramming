import java.util.Scanner;

public class vote {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while (t-- > 0) {
      int n = sc.nextInt();
      int max = 0;
      int sum = 0;
      int winner = 0;
      boolean noWinner = true;
      for (int i = 0; i < n; i++) {
        int v = sc.nextInt();
        if (v > max) {
          winner = i + 1;
          max = v;
          noWinner = false;
        } else if (v == max) {
          noWinner = true;
        }
        sum += v;
      }

      if (noWinner) {
        System.out.println("no winner");
      } else {
        if (max > sum / 2) {
          System.out.println("majority winner " + winner);
        } else {
          System.out.println("minority winner " + winner);
        }
      }
    }
  }

}
