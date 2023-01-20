import java.util.Scanner;

public class UVa11507 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int l = sc.nextInt();
    String curDir;
    while (l != 0) {
      curDir = "+x";
      for (int i = 1; i < l; i++) {
        String dir = sc.next();
        if (dir.equals("No")) {
          continue;
        }
        switch (curDir) {
          case "+x":
            curDir = dir;
            break;
          case "-x":
            if (dir.charAt(0) == '+') {
              curDir = "-" + dir.charAt(1);
            } else {
              curDir = "+" + dir.charAt(1);
            }
            break;
          case "+y":
          case "-y":
          case "+z":
          case "-z":
            if (dir.charAt(1) == curDir.charAt(1)) {
              if (dir.charAt(0) == curDir.charAt(0)) {
                curDir = "-x";
              } else {
                curDir = "+x";
              }
            }
            break;
        }
      }
      System.out.println(curDir);
      l = sc.nextInt();
    }
  }

}
