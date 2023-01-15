import java.util.Scanner;

public class peasoup {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    while (n-- > 0) {
      int k = sc.nextInt();
      sc.nextLine();
      String name = sc.nextLine();
      boolean pancakes = false;
      boolean peaSoup = false;
      for (int i = 0; i < k; i++) {
        String s = sc.nextLine();
        if (s.equals("pancakes")) {
          pancakes = true;
          if (peaSoup) {
            System.out.println(name);
            return;
          }
        } else if (s.equals("pea soup")) {
          peaSoup = true;
          if (pancakes) {
            System.out.println(name);
            return;
          }
        }
      }
    }
    System.out.println("Anywhere is fine I guess");
  }

}
