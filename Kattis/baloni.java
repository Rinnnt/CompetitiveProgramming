import java.util.Scanner;

public class baloni {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] heights = new int[n];
    for (int i = 0; i < n; i++) {
      heights[i] = sc.nextInt();
    }
    boolean[] popped = new boolean[n];
    for (int i = 0; i < n; i++) {
      popped[i] = false;
    }
    int pops = 0;
    int arrows = 0;
    while (pops < n) {
      arrows++;
      Integer h = null;
      int index = 0;
      while (h == null) {
        if (!popped[index]) {
          popped[index] = true;
          pops++;
          h = heights[index] - 1;
        }
        index++;
      }
      while (index < n) {
        if (!popped[index] && heights[index] == h) {
          popped[index] = true;
          pops++;
          h--;
        }
        index++;
      }
    }
    System.out.println(arrows);
  }

}
