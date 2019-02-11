import java.util.*;

public class BearZoo{
   public static void main(String[] args) {
      Scanner in = new Scanner(System.in);
      int currentCase = 1;
      while (in.hasNextInt()) {
         TreeMap<String, Integer> zoo = new TreeMap<String, Integer>();
         int numAnimals = in.nextInt();
         if (numAnimals != 0) {
            in.nextLine();
            String animal;
            while (numAnimals-- > 0) {
               animal = in.nextLine();
               animal = animal.split(" ")[animal.split(" ").length - 1].toLowerCase();
               if (zoo.containsKey(animal)) {
                  zoo.put(animal, zoo.get(animal) + 1);
               } else {
                  zoo.put(animal, 1);
               }
            }
            System.out.println("List " + currentCase++ + ": ");
            for (String key : zoo.keySet()) {
               System.out.println(key + " | " + zoo.get(key));
            }
         }
      }
   }
}