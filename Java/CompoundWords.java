import java.util.*;

public class CompoundWords {
    public static void main(String[] args) {
        HashSet<String> words = new HashSet<String>();
        TreeSet<String> unique = new TreeSet<String>();
        Scanner in = new Scanner(System.in);

        while (in.hasNext()) {
            words.add(in.next());
        }

        for (String s : words) {
            for (String s2: words) {
                if (!s.equals(s2)) {
                    unique.add(s+s2);
                }
            }
        }
        for (String s : unique) {
            System.out.println(s);
        }
    }
}