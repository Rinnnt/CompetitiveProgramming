import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class UVa10071 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String line = br.readLine();
    while (line != null) {
      String[] inputs = line.split(" ");
      int v = Integer.parseInt(inputs[0]);
      int t = Integer.parseInt(inputs[1]);
      System.out.println(2 * v * t);
      line = br.readLine();
    }

  }

}
