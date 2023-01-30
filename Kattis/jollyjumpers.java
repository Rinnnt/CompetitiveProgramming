import java.util.Scanner;

public class jollyjumpers {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (sc.hasNext()) {
      int n = sc.nextInt();
      int prev = sc.nextInt();
      boolean[] flag = new boolean[n - 1];
      for (int i = 0; i < n - 1; i++) {
        flag[i] = false;
      }
      for (int i = 1; i < n; i++) {
        int next = sc.nextInt();
        if (Math.abs(next - prev) < n && Math.abs(next - prev) > 0) {
          flag[Math.abs(next - prev) - 1] = true;
        }
        prev = next;
      }
      String ans = "Jolly";
      for (int i = 0; i < n - 1; i++) {
        if (!flag[i]) {
          ans = "Not jolly";
        }
      }
      System.out.println(ans);
    }
  }

}
