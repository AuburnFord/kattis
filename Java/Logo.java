import java.util.*;

public class Logo{

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        in.nextLine();
        while (cases-- > 0) {
            int instructions = Integer.parseInt(in.nextLine());
            double x = 0;
            double y = 0;
            double degree = 0;
            while (instructions-- > 0) {
                char command = in.next().charAt(0);
                int number = in.nextInt();
                in.nextLine(); // skips to next line, nextInt leaves \n char

                switch (command) {
                    case 'f': x += number * Math.cos(degree);
                              y += number * Math.sin(degree);
                              break;
                    case 'b': x -= number * Math.cos(degree);
                              y -= number * Math.sin(degree);
                              break;
                    case 'l': degree += number * (Math.PI) / 180;
                              break;
                    case 'r': degree -= number * (Math.PI) / 180;
                              break;
                }
            }
            int dist = (int) Math.round(Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2)));
            System.out.println(dist);
        }
    }
}