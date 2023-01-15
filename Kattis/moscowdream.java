import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class moscowdream {

  public static void main(String[] args) throws IOException {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String line = br.readLine();
    String[] inputs = line.split(" ");

    int a = Integer.parseInt(inputs[0]);
    int b = Integer.parseInt(inputs[1]);
    int c = Integer.parseInt(inputs[2]);
    int n = Integer.parseInt(inputs[3]);

    String res = (a > 0 && b > 0 && c > 0 && (a + b + c) >= n && n >= 3) ? "YES" : "NO";
    System.out.println(res);
  }
}
