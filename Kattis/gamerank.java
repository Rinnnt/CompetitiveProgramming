import java.util.Scanner;

public class gamerank {

  private static int starsOfRank(int rank) {
    if (rank >= 1 && rank <= 10) {
      return 5;
    }
    if (rank >= 11 && rank <= 15) {
      return 4;
    }
    if (rank >= 16 && rank <= 20) {
      return 3;
    }
    if (rank >= 21 && rank <= 25) {
      return 2;
    }
    return -1;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String history = sc.next();
    int rank = 25;
    int stars = 0;
    int consecWins = 0;
    for (Character c : history.toCharArray()) {
      int deltaStars;
      if (c == 'W') {
        consecWins++;
        deltaStars = 1;
        if (rank >= 6 && rank <= 25 && consecWins >= 3) {
          deltaStars++;
        }
        stars += deltaStars;
        if (stars > starsOfRank(rank)) {
          stars -= starsOfRank(rank);
          rank--;
        }
        if (rank == 0) {
          System.out.println("Legend");
          return;
        }
      } else {
        consecWins = 0;
        if (rank >= 1 && rank <= 20) {
          if (stars > 0) {
            stars--;
          } else {
            if (rank < 20) {
              rank++;
              stars = starsOfRank(rank) - 1;
            }
          }
        }
      }
    }
    System.out.println(rank);
  }

}
