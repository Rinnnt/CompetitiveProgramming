import java.util.Scanner;

public class A1 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    while (n-- > 0) {
      String abc = sc.next();
      if (abc.charAt(0) == 'b' && abc.charAt(1) == 'a') {
        System.out.println("b a " + abc.substring(2));
      } else if (abc.charAt(0) == 'a' && abc.charAt(1) == 'a') {
        System.out.println(abc.substring(0, abc.length() - 2) + " " + abc.charAt(abc.length() - 2) + " " + abc.charAt(abc.length() - 1));
      } else {
          System.out.println(abc.charAt(0) + " " + abc.substring(1, abc.length() - 1) + " " + abc.charAt(abc.length() - 1));
      }
    }
  }

}
