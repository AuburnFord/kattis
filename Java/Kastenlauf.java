import java.util.*;

public class Kastenlauf{

    static Location end;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        while (cases-- > 0) {
           int numStores = in.nextInt();
           Location[] stores = new Location[numStores];
           Location start = new Location(in.nextInt(), in.nextInt());
           for (int i = 0; i < numStores; i++) {
              stores[i] = new Location(in.nextInt(), in.nextInt());
           }
           end = new Location(in.nextInt(), in.nextInt());
           if (start.canReach(end)) {
               System.out.println("happy");
               continue;
           }
           for (Location store : stores) {
               if(end.canReach(store)) {
                   end.neighbors.add(store);
               }
               if(start.canReach(store)) {
                start.neighbors.add(store);
               }
           }
           if (end.neighbors.size() == 0 || start.neighbors.size() == 0) {
               System.out.println("sad");
               continue;
           }
           for (int i = 0; i < numStores; i++) {
              for (int j = 0; j < numStores; j++) {
                  if (i != j && stores[i].canReach(stores[j])) {
                     stores[i].neighbors.add(stores[j]);
                  }
              }
           }

           System.out.println(doDFS(start) ? "happy" : "sad");
        }
    }
    public static boolean doDFS(Location starter) {
        if (end.neighbors.contains(starter)) {
            return true;
        }
        boolean found = false;
        for (Location reachable : starter.neighbors) {
            if (found) break;
            if (!reachable.visited) {
                reachable.visited = true;
                found = doDFS(reachable);
            }
        }
        return found;
    }
}

class Location {
    int x;
    int y;
    boolean visited;
    ArrayList<Location> neighbors = new ArrayList<Location>();

    public Location (int x, int y) {
        this.x = x;
        this.y = y;
        visited = false;
    }

    public boolean canReach(Location target) {
        return (Math.abs(this.x - target.x) + Math.abs(this.y - target.y) <= 1000);
    }
}