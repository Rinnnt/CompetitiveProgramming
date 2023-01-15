import java.util.Scanner;

public class UVa11786 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    sc.nextLine();

    while (t-- > 0) {
      String s = sc.nextLine();
      int water = 0;

      for (int i = 0; i < s.length(); i++) {
        char c = s.charAt(i);

        if (c == '/') {
          int level = 0;
          for (int j = i - 1; j >= 0; j--) {
            char pc = s.charAt(j);
            if (pc == '\\' && level == 0) {
              water += i - j;
              break;
            } else if (pc == '\\') {
              level++;
            } else if (pc == '/'){
              level--;
            }
          }
        }
      }
      System.out.println(water);
    }
  }

}
