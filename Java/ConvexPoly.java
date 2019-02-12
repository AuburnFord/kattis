import java.util.*;

public class ConvexPoly{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        for (int t = 0; t < num; t++) {
            int pts = in.nextInt();
            Point first = new Point(in.nextInt(), in.nextInt());
            Point[] points = new Point[pts+1];
            points[0] = first;
            for (int i = 1; i < pts; i++) {
                points[i] = new Point(in.nextInt(), in.nextInt());
            }
            points[pts] = first;
            double area = 0;
            for (int i = 0; i < pts; i++) {
                area += points[i].x * points[i+1].y;
                area -= points[i].y * points[i+1].x;
            }
            System.out.println(area/2);
        }
    }

    static class Point {
        int x;
        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
} 