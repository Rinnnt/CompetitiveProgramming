import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class bela {

  private static final Map<String, Integer> dominant = new HashMap<>(Map.of("A", 11, "K", 4, "Q", 3, "J", 20, "T", 10, "9", 14, "8", 0, "7", 0));
  private static final Map<String, Integer> nonDominant = new HashMap<>(Map.of("A", 11, "K", 4, "Q", 3, "J", 2, "T", 10, "9", 0, "8", 0, "7", 0));

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int hands = sc.nextInt();
    String d = sc.next();
    int total = 0;
    for (int hand = 0; hand < hands; hand++) {
      for (int i = 0; i < 4; i++) {
        String card = sc.next();
        if (card.charAt(1) == d.charAt(0)) {
          total += dominant.get(String.valueOf(card.charAt(0)));
        }
        else {
          total += nonDominant.get(String.valueOf(card.charAt(0)));
        }
      }
    }
    System.out.println(total);
  }
}
