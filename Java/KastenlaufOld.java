import java.util.*;

public class KastenlaufOld{
   
    static int numStores;
    static Location home;
    static Location[] stores;
    static Location dest;
   
   public static void main(String[] args) {
      Scanner in = new Scanner(System.in);
      int cases = in.nextInt();
      while (cases > 0) {
         numStores = in.nextInt();
         home = new Location(in.nextInt(), in.nextInt());
         stores = new Location[numStores];
         for (int i = 0; i < numStores; i++) {
            stores[i] = new Location(in.nextInt(), in.nextInt());
         }
         dest = new Location(in.nextInt(), in.nextInt());
         boolean found = doDFS(home);
 
         //Calculations
         //check if dest in range
         //check if store is in range
         //mark store visited, update range
         //repeat

         if (found) {
            System.out.println("happy");
         }
         else {
            System.out.println("sad");
         }



         cases--;
      }
   }
   
   public static boolean doDFS(Location current) {
      boolean foundIt = false;
      current.visited = true;
      if (current.canReach(dest)) {
         foundIt = true;
      }
      int index = 0;
      while (!foundIt && index < numStores) {
         if (!stores[index].visited && current.canReach(stores[index])) {
            foundIt = doDFS(stores[index]);
         }
         index++;
        }
      return foundIt;
   }
}
class Location {
   int[] location = new int[2];
   boolean visited;

   public Location(int x, int y) {
      location[0] = x;
      location[1] = y;
      visited = false;
   }

   public int getXLocation() {
      return location[0];
   }

   public int getYLocation() {
      return location[1];
   }

   public boolean canReach(Location target) {
      if (Math.abs(target.getXLocation() - this.getXLocation()) + Math.abs(target.getYLocation() - this.getYLocation()) <= 1000) {
         return true;
      }
      
      return false;
   }
}