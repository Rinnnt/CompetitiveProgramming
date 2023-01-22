import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class chess {

  private static List<int[]> reaches(int[] p) {
    int[][] dirs = {
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1},
    };
    List<int[]> reach = new ArrayList<>();
    for (int i = 0; i < 4; i++) {
      int[] cur = p.clone();
      while (true) {
        cur[0] += dirs[i][0];
        cur[1] += dirs[i][1];
        if (cur[0] >= 0 && cur[0] < 8 && cur[1] > 0 && cur[1] <= 8) {
          reach.add(cur.clone());
        } else {
          break;
        }
      }
    }
    return reach;
  }

  private static String pointToString(int[] p) {
    return ((char) ('A' + p[0]) + " " + p[1]);
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    uphere:
    while (t-- > 0) {
      int[] p1 = new int[2];
      int[] p2 = new int[2];
      p1[0] = sc.next().charAt(0) - 'A';
      p1[1] = sc.nextInt();
      p2[0] = sc.next().charAt(0) - 'A';
      p2[1] = sc.nextInt();
      if ((p1[0] + p1[1]) % 2 != (p2[0] + p2[1]) % 2) {
        System.out.println("Impossible");
      } else if (Arrays.equals(p1, p2)) {
        System.out.println("0 " + pointToString(p1));
      } else {
        var p1Reach = reaches(p1);
        var p2Reach = reaches(p2);
        for (int[] r : p1Reach) {
          if (Arrays.equals(r, p2)) {
            System.out.println("1 " + pointToString(p1) + " " + pointToString(p2));
            continue uphere;
          }
        }
        for (int[] r : p1Reach) {
          for (int[] r2 : p2Reach) {
            if (Arrays.equals(r, r2)) {
              System.out.println("2 " + pointToString(p1) + " " + pointToString(r) + " " + pointToString(p2));
              continue uphere;
            }
          }
        }
      }
    }
  }

}
