import java.util.Scanner;

public class rockpaperscissors {

  private static boolean firstPlayerWins(char m1, char m2) {
    return
        (m1 == 'r' && m2 == 's') ||
        (m1 == 's' && m2 == 'p') ||
        (m1 == 'p' && m2 == 'r');
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    while (n != 0) {
      int[] wins = new int[n + 1];
      int[] losses = new int[n + 1];
      int k = sc.nextInt();
      sc.nextLine();
      for (int i = 0; i < (n * (n - 1) * k) / 2; i++) {
        String[] words = sc.nextLine().split(" ");
        int p1 = Integer.parseInt(words[0]);
        char m1 = words[1].charAt(0);
        int p2 = Integer.parseInt(words[2]);
        char m2 = words[3].charAt(0);
        if (!(m1 == m2)) {
          if (firstPlayerWins(m1, m2)) {
            wins[p1]++;
            losses[p2]++;
          } else {
            wins[p2]++;
            losses[p1]++;
          }
        }
      }
      StringBuilder sb = new StringBuilder();
      for (int i = 1; i <= n; i++) {
        double ws = wins[i];
        double ls = losses[i];
        if (ws + ls == 0) {
          sb.append("-\n");
        } else {
          sb.append(String.format("%.3f\n", (ws / (ws + ls))));
        }
      }
      System.out.println(sb);
      n = sc.nextInt();
    }
  }

}
