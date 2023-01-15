import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class UVa13025 {

  public static void main(String[] args) throws ParseException {
    SimpleDateFormat inputFormat = new SimpleDateFormat("dd-MMM-yyyy");
    String dateString = "29-May-2013";
    Date date = inputFormat.parse(dateString);

    SimpleDateFormat outputFormat = new SimpleDateFormat("MMMM d, y EEEE");
    System.out.println(outputFormat.format(date));
  }

}
