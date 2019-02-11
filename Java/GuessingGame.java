import java.util.*;

public class GuessingGame{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int highest = 10;
        int lowest = 1;
        int guess = Integer.parseInt(in.nextLine());
        while (guess != 0) {
           String command = in.nextLine();
           switch(command) {
               case "too high": 
                  if (guess <= highest) highest = guess-1;
                  break;
               case "too low":
                  if (guess >= lowest) lowest = guess+1;
                  break;
               case "right on": 
                  System.out.println(guess >= lowest && guess <= highest ? "Stan may be honest" : "Stan is dishonest");
                  highest = 10;
                  lowest = 1;
                  break;
           }
           guess = Integer.parseInt(in.nextLine());
        }
    }
}