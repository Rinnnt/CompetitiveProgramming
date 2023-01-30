import java.util.Scanner;

public class wertyu {

  public static final String keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    while (sc.hasNext()) {
      String line = sc.next();
      StringBuilder res = new StringBuilder();
      for (Character c : line.toCharArray()) {
        if (Character.isSpaceChar(c)) {
          res.append(c);
        } else {
          res.append(keyboard.charAt(keyboard.indexOf(c) - 1));
        }
      }
      System.out.print(res);
      System.out.print(" ");
    }
  }

}
