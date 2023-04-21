package c1768;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while (t-- > 0) {
      int n = sc.nextInt();
      int[] arr = new int[n];
      ArrayList<Integer>[] count = new ArrayList[n+1];
      for (int i = 0; i < n + 1; i++) {
        count[i] = new ArrayList<>();
      }
      List<Integer> zeroes = new ArrayList<>();
      for (int i = 0; i < n; i++) {
        arr[i] = sc.nextInt();
        count[arr[i]].add(i);
      }

      int[] p = new int[n];
      int[] q = new int[n];
      boolean fail = false;
      for (int v = 1; v <= n; v++) {
        List<Integer> occurs = count[v];
        if (occurs.size() > 2) {
          fail = true;
          break;
        } else if (occurs.size() == 0) {
          zeroes.add(v);
        } else if (occurs.size() == 1) {
          p[occurs.get(0)] = v;
          q[occurs.get(0)] = v;
        } else if (count[v].size() == 2) {
          if (zeroes.isEmpty()) {
            fail = true;
            break;
          } else {
            int x = zeroes.remove(zeroes.size() - 1);
            p[occurs.get(0)] = v;
            q[occurs.get(0)] = x;
            p[occurs.get(1)] = x;
            q[occurs.get(1)] = v;
          }
        }
      }

      if (fail) {
        System.out.println("NO");
      } else {
        System.out.println("YES");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
          sb.append(p[i]).append(" ");
        }
        System.out.println(sb);
        sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
          sb.append(q[i]).append(" ");
        }
        System.out.println(sb);
      }
    }
  }

}
