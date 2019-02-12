import java.util.*;
public class T9 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        int cur = 1;
        in.nextLine();
        char last = 'a';
        while (cur <= cases) {
            System.out.print("Case #" + cur + ": ");
            char[] msg = in.nextLine().toCharArray();
            for (int i = 0; i < msg.length; i++) {
                String toPrint = "";
                switch(msg[i]) {
                    case 'c': toPrint+='2';
                    case 'b': toPrint+='2';
                    case 'a': toPrint+='2';
                        break;
                    case 'f': toPrint+='3';
                    case 'e': toPrint+='3';
                    case 'd': toPrint+='3';
                        break;
                    case 'i': toPrint+='4';
                    case 'h': toPrint+='4';
                    case 'g': toPrint+='4';
                        break;
                    case 'l': toPrint+='5';
                    case 'k': toPrint+='5';
                    case 'j': toPrint+='5';
                        break;
                    case 'o': toPrint+='6';
                    case 'n': toPrint+='6';
                    case 'm': toPrint+='6';
                        break;
                    case 's': toPrint+='7';
                    case 'r': toPrint+='7';
                    case 'q': toPrint+='7';
                    case 'p': toPrint+='7';
                        break;
                    case 'v': toPrint+='8';
                    case 'u': toPrint+='8';
                    case 't': toPrint+='8';
                        break;
                    case 'z': toPrint+='9';
                    case 'y': toPrint+='9';
                    case 'x': toPrint+='9';
                    case 'w': toPrint+='9';
                        break;
                    case ' ': toPrint+='0';
                }
                if (toPrint.charAt(0) == last) {
                    System.out.print(" ");
                }
                System.out.print(toPrint);
                last = toPrint.charAt(toPrint.length()-1);
            }
            System.out.println();
            cur++;
        }
    }
}