import java.util.Scanner;

public class aliennumbers {

  public static String translate(String number, String source, String target) {
    long decimal = 0;
    String rev = new StringBuilder().append(number).reverse().toString();
    long digitValue = 1;
    for (Character c : rev.toCharArray()) {
      decimal += source.indexOf(c) * digitValue;
      digitValue *= source.length();
    }
    StringBuilder res = new StringBuilder();
    while (decimal > 0) {
      int rem = (int) decimal % target.length();
      decimal /= target.length();
      res.append(target.charAt(rem));
    }
    return res.reverse().toString();
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    for (int i = 1; i <= n; i++) {
      String number = sc.next();
      String source = sc.next();
      String target = sc.next();
      System.out.println("Case #" + i + ": " + translate(number, source, target));
    }

  }

}