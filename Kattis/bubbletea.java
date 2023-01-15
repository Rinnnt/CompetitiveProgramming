import java.util.Scanner;

public class bubbletea {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    Integer[] teaPrices = new Integer[n];
    for (int i = 0; i < n; i++) {
      teaPrices[i] = sc.nextInt();
    }

    int m = sc.nextInt();
    Integer[] toppingPrices = new Integer[m];
    for (int i = 0; i < m; i++) {
      toppingPrices[i] = sc.nextInt();
    }

    int leastPrice = Integer.MAX_VALUE;
    for (int i = 0; i < n; i++) {
      int k = sc.nextInt();
      for (int j = 0; j < k; j++) {
        int toppingIndex = sc.nextInt() - 1;
        if (teaPrices[i] + toppingPrices[toppingIndex] < leastPrice) {
          leastPrice = teaPrices[i] + toppingPrices[toppingIndex];
        }
      }
    }

    int budget = sc.nextInt();
    int students = (budget / leastPrice - 1);
    System.out.println(Math.max(students, 0));
  }

}
