import java.util.Scanner;

public class UVa12157 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t  = sc.nextInt();
    for (int i = 1; i <= t; i++) {
      int n = sc.nextInt();
      int milePrice = 0;
      int juicePrice = 0;
      while (n-- > 0) {
        int price = sc.nextInt();
        milePrice += 10 * ((price / 30) + 1);
        juicePrice += 15 * ((price / 60) + 1);
      }
      if (milePrice == juicePrice) {
        System.out.println("Case " + i + ": Mile Juice " + milePrice);
      } else if (milePrice < juicePrice) {
        System.out.println("Case " + i + ": Mile " + milePrice);
      } else {
        System.out.println("Case " + i + ": Juice " + juicePrice);
      }
    }
  }

}
