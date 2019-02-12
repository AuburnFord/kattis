import java.util.Scanner;

public class AmsterdamDist{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int slices = in.nextInt();
        double angle = Math.PI/slices;
        int rings = in.nextInt();
        double rad = in.nextDouble()/rings;

        int x1 = in.nextInt();
        int y1 = in.nextInt();

        int x2 = in.nextInt();
        int y2 = in.nextInt();
        double dist1 = Math.abs(y2-y1)*rad + (Math.abs(x2-x1) * angle * rad * Math.min(y2,y1));
        double dist2 = y2*rad + y1*rad;
        double dist = Math.min(dist1,dist2);
        if (dist != 0) {
            System.out.printf("%.14f\n",dist);
        } else System.out.println(0);

    }
}