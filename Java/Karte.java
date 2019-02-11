import java.util.*;

public class Karte {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        HashSet<String> p = new HashSet<String>();
        HashSet<String> k = new HashSet<String>();
        HashSet<String> h = new HashSet<String>();
        HashSet<String> t = new HashSet<String>();
        int bad = 0;
        String cards = in.nextLine();
        if (cards.length() > 156) {
            System.out.println("GRESKA");
        } else {
           for (int i = 0; i < cards.length(); i+=3) {
               String num = cards.substring(i+1, i+3);
               if (cards.charAt(i) == 'P') {
                  if (p.contains(num)) {
                     bad = 1;
                     break;
                  } else {
                     p.add(num);
                  }
               }
               if (cards.charAt(i) == 'K') {
                   if (k.contains(num)) {
                       bad = 1;
                       break;
                   } else {
                       k.add(num);
                   }
               }
               if (cards.charAt(i) == 'H') {
                   if (h.contains(num)) {
                       bad = 1;
                       break;
                   } else {
                       h.add(num);
                   }
               }
               if (cards.charAt(i) == 'T') {
                   if (t.contains(num)) {
                      bad = 1;
                      break;
                   } else {
                      t.add(num);
                   }
               }
           }
           if (bad != 0) {
              System.out.print("GRESKA");
           } else {
               System.out.print(13 - p.size() + " ");
               System.out.print(13 - k.size() + " ");
               System.out.print(13 - h.size() + " ");
               System.out.print(13 - t.size() + " ");
               System.out.println();
           }
        }
    }
}