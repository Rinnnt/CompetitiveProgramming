import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class basicprogramming1 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int t = sc.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }

    switch (t) {
      case 1 :
        System.out.println(7);
        break;
      case 2 :
        if (a[0] == a[1]) {
          System.out.println("Equal");
        } else {
          System.out.println((a[0] < a[1]) ? "Smaller" : "Bigger");
        }
        break;
      case 3 :
        int[] na = new int[3];
        na = Arrays.copyOfRange(a, 0, 3);
        Arrays.sort(na);
        System.out.println(na[1]);
        break;
      case 4 :
        long sum = 0;
        for (int x : a) {
          sum += (long) x;
        }
        System.out.println(sum);
        break;
      case 5 :
        long sum1 = 0;
        for (int x : a) {
          if (x % 2 == 0) {
            sum1 += (long) x;
          }
        }
        System.out.println(sum1);
        break;
      case 6 :
        char[] chars = new char[n];
        for (int i = 0; i < n; i++) {
          chars[i] = (char) ((a[i] % 26) + 97);
        }
        System.out.println(new String(chars));
        break;
      case 7 :
        Set<Integer> visited = new HashSet<>(List.of(0));
        int index = 0;
        while (true) {
          index = a[index];
          if (index < 0 || index >= n) {
            System.out.println("Out");
            return;
          }
          if (index == n - 1) {
            System.out.println("Done");
            return;
          }
          if (visited.contains(index)) {
            System.out.println("Cyclic");
            return;
          }
          visited.add(index);
        }
    }
  }

}
