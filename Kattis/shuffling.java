import java.util.Scanner;

public class shuffling {

  private static int outShuffle(int pos, int n) {
    if (n % 2 == 0) {
      if (pos < n / 2) {
        return pos * 2;
      } else {
        return 1 + ((pos - (n / 2)) * 2);
      }
    }
    else {
      if (pos < n / 2) {
        return pos * 2;
      } else if (pos == n / 2) {
        return n - 1;
      }
      else {
        return 1 + ((pos - (n / 2) - 1) * 2);
      }
    }
  }

  private static int inShuffle(int pos, int n) {
    if (n % 2 == 0) {
      if (pos < n / 2) {
        return 1 + (pos * 2);
      } else {
        return (pos - (n / 2)) * 2;
      }
    }
    else {
      if (pos < n / 2) {
        return 1 + (pos * 2);
      } else if (pos == n / 2) {
        return 0;
      }
      else {
        return (pos - (n / 2)) * 2;
      }
    }

  }

  private static int getMax(int n, String type) {
    int max = 0;
    for (int i = 0; i < n; i++) {
      int count = 1;
      int cur = i;
      if (type.equals("out")) {
        cur = outShuffle(cur, n);
        while (cur != i) {
          cur = outShuffle(cur, n);
          count++;
        }
      } else {
        cur = inShuffle(cur, n);
        while (cur != i) {
          cur = inShuffle(cur, n);
          count++;
        }
      }
      max = Math.max(max, count);
    }
    return max;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String type = sc.next();
    System.out.println(getMax(n, type));
  }

}
