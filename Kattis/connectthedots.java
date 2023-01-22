import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class connectthedots {

  private static void connect(Map<Integer, Character> connected, int p1, int p2) {
    if (p1 > p2) {
      connect(connected, p2, p1);
      return;
    }

    if (p1 / 100 == p2 / 100) {
      for (int i = p1 + 1; i < p2; i++) {
        if (!connected.containsKey(i)) {
          connected.put(i, '-');
        }
        if (connected.get(i) == '|') {
          connected.put(i, '+');
        }
      }
    } else {
      for (int i = p1 + 100; i < p2; i += 100) {
        if (!connected.containsKey(i)) {
          connected.put(i, '|');
        }
        if (connected.get(i) == '-') {
          connected.put(i, '+');
        }
      }

    }

  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    Pattern pattern = Pattern.compile("[0-9a-zA-Z]");
    Map<Integer, Character> connected = new HashMap<>();
    int height = 0;
    int width = 0;
    int[] connect = new int[62];
    int connectSize = 0;
    while (sc.hasNextLine()) {

      String line = sc.nextLine();
      if (line.isEmpty()) {
        for (int idx = 1; idx <= connectSize; idx++) {
          connect(connected, connect[idx], connect[idx - 1]);
        }
        for (int i = 0; i < height; i++) {
          char[] row = new char[width];
          for (int j = 0; j < width; j++) {
            row[j] = connected.getOrDefault(i * 100 + j, '.');
          }
          System.out.println(row);
        }
        System.out.println();
        height = 0;
        connectSize = 0;
        connected.clear();
      } else {
        Matcher matcher = pattern.matcher(line);
        while (matcher.find()) {
          char match = matcher.group().charAt(0);
          int index = matcher.start();
          connected.put(height * 100 + index, match);

          int idx = -1;
          if (Character.isDigit(match)) {
            idx = Character.getNumericValue(match);
          } else if (Character.isAlphabetic(match) && Character.isLowerCase(match)) {
            idx = match - 'a' + 10;
          } else if (Character.isAlphabetic(match) && Character.isUpperCase(match)) {
            idx = match - 'A' + 36;
          }
          connect[idx] = height * 100 + index;
          connectSize = Math.max(connectSize, idx);
        }

        width = line.length();
        height++;
      }
    }
    for (int idx = 1; idx <= connectSize; idx++) {
      connect(connected, connect[idx], connect[idx - 1]);
    }
    for (int i = 0; i < height; i++) {
      char[] row = new char[width];
      for (int j = 0; j < width; j++) {
        row[j] = connected.getOrDefault(i * 100 + j, '.');
      }
      System.out.println(row);
    }
    System.out.println();
  }
}

