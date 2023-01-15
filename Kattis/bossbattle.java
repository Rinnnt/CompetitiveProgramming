import java.util.Scanner;

public class bossbattle {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    System.out.println((n <= 3) ? 1 : (n - 2));
  }

}
