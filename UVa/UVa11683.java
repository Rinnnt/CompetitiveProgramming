import java.util.Scanner;

public class UVa11683 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (true) {
      int a = sc.nextInt();
      int c = sc.nextInt();
      if (a == 0 && c == 0) {
        return;
      }

      int cuts = 0;
      int prev = a;
      for (int i = 0; i < c; i++) {
        int x = sc.nextInt();
        if (x < prev) {
          cuts += prev - x;
        }
        prev = x;
      }
      System.out.println(cuts);
    }
  }

}
