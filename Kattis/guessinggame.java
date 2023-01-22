import java.util.Scanner;

public class guessinggame {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    boolean[] all = {true, true, true, true, true, true, true, true, true, true};
    boolean[] arr = all.clone();
    int number = Integer.parseInt(sc.nextLine());
    while (number != 0) {
      String line = sc.nextLine();
      if (line.equals("too high")) {
        for (int i = number - 1; i < arr.length; i++) {
          arr[i] = false;
        }
      } else if (line.equals("too low")) {
        for (int i = number - 1; i >= 0; i--) {
          arr[i] = false;
        }
      } else {
        if (arr[number - 1]) {
          System.out.println("Stan may be honest");
        } else {
          System.out.println("Stan is dishonest");
        }
        arr = all.clone();
      }
      number = Integer.parseInt(sc.nextLine());
    }
  }

}
