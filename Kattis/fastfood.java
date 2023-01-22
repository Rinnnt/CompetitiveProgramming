import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class fastfood {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while (t-- > 0) {
      int n = sc.nextInt();
      int m = sc.nextInt();

      int[] cash = new int[n];
      List<List<Integer>> stickers = new ArrayList<>();
      int[] collected = new int[m];

      for (int i = 0; i < n; i++) {
        int s = sc.nextInt();
        List<Integer> ss = new ArrayList<>();
        for (int j = 0; j < s; j++) {
          ss.add(sc.nextInt());
        }
        stickers.add(ss);
        cash[i] = sc.nextInt();
      }

      for (int i = 0; i < m; i++) {
        collected[i] = sc.nextInt();
      }

      int total = 0;
      for (int x = 0; x < n; x++) {
        int count = Integer.MAX_VALUE;
        for (Integer need : stickers.get(x)) {
          count = Math.min(count, collected[need - 1]);
        }
        total += cash[x] * count;
      }

      System.out.println(total);
    }
  }

}
