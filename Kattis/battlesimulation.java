import java.util.Scanner;

public class battlesimulation {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String attacks = sc.next();
    int index = 0;
    StringBuilder ans = new StringBuilder();
    while (index < attacks.length()) {
      if (index < attacks.length() - 2 &&
          attacks.charAt(index) != attacks.charAt(index + 1) &&
          attacks.charAt(index + 1) != attacks.charAt(index + 2) &&
          attacks.charAt(index + 2) != attacks.charAt(index)) {
        ans.append('C');
        index += 3;
      } else {
        if (attacks.charAt(index) == 'R') {
          ans.append('S');
        }
        if (attacks.charAt(index) == 'B') {
          ans.append('K');
        }
        if (attacks.charAt(index) == 'L') {
          ans.append('H');
        }
        index++;
      }
    }

    System.out.println(ans);
  }

}
