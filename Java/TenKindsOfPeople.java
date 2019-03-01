// 10 Kinds of People
import java.util.*;

public class TenKindsOfPeople {
    static char[][] bMap;
    static int[] unions;
    static int columns;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int rows = in.nextInt();
        columns = in.nextInt();
        in.nextLine();
        bMap = new char[rows][columns];
        for (int i = 0; i < rows; i++) {
            bMap[i] = in.nextLine().toCharArray();
        }
        unions = new int[rows*columns];
        for (int i = 0; i < unions.length; i++) {
            unions[i] = i;
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < columns; c++) {
                if (c != columns - 1) union(r,c,r,c+1);
                if (r != rows - 1) union(r,c,r+1,c);
            }
        }

        int queries = in.nextInt();
        for (int i = 0; i < queries; i++) {
            int r1 = in.nextInt()-1;
            int c1 = in.nextInt()-1;
            int r2 = in.nextInt()-1;
            int c2 = in.nextInt()-1;

            if (bMap[r1][c1] == bMap[r2][c2]) {
                if (find(r1,c1) == find(r2,c2)) {
                    System.out.println((bMap[r1][c1] == '1')? "decimal" : "binary");
                } else System.out.println("neither");
            } else {
                System.out.println("neither");
            }
        }
    }

    // if they are the same character union their parents (this solves cases where a pt is unioned twice)
    static void union(int r1, int c1, int r2, int c2) {
        if (bMap[r1][c1] == bMap[r2][c2]) {
            unions[find(r2,c2)] = find(r1,c1);
        }
    }

    // recursively find and update the parent up the chain
    static int find(int r, int c) {
        // base case, we've reached the parent
        if (unions[r*columns+c] == r*columns+c) {
            return r*columns+c;
        }
        // update and return updated
        unions[r*columns+c] = find(unions[r*columns+c]/columns, unions[r*columns+c]%columns);
        return unions[r*columns+c];
    }
}
