import java.util.Scanner;

public class compass {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n1 = sc.nextInt();
    int n2 = sc.nextInt();

    int ans = (n1 <= n2) ? n2 - n1 : n2 - n1 + 360;
    System.out.println(ans <= 180 ? ans : -1 * (360 - ans));
  }

}
