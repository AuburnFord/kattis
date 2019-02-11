import java.util.*;

public class FizzBuzz {
    public static void main(String[]args) {
       Scanner in = new Scanner(System.in);
       int x = in.nextInt();
       int y = in.nextInt();
       int n = in.nextInt();
       for( int t = 1; t <= n; t++) {
          String output = "";
          if( t%x == 0 ) {
             output += "Fizz";
          }
          if( t%y == 0) {
             output += "Buzz";
          }
          if( output.equals("")){
             System.out.println(t);
          }
          else {
              System.out.println(output);
          }
       }
    }
}
// 5%2 -> 1
// if (!(t%x==0) && !(t%y==0)) {
//    System.out.print(t);   
// }
// if (t%x==0) {
//    System.out.print("Fizz");
// }
// if (t%y==0) {
//    System.out.print("Buzz");   
// }
// System.out.println(""); // System.out.print("\n");