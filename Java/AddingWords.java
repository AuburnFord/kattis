import java.util.*;
import java.io.*;

public class AddingWords{

    static HashMap<String, Integer> varVal = new HashMap<String, Integer>();
    static HashMap<Integer, String> valVar = new HashMap<Integer, String>();

   public static void main(String[] args) throws IOException {
      BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
      String temp = in.readLine();
      while (temp != null) {
         String[] arguments = temp.split(" ");
         switch(arguments[0]) {
             case "def": define(arguments);
                break;
             case "calc": calculation(arguments);
                break;
             case "clear": clear();
                break;   
         }
         temp = in.readLine();
      }
   }

   static void define(String[] args) {
      String var = args[1];
      int val = Integer.parseInt(args[2]);
      if (varVal.containsKey(var)) {
         varVal.replace(var, val);
         valVar.replace(val, var);
      } else {
          varVal.put(var, val);
          valVar.put(val, var);
      }
   }

   static void clear() {
      varVal.clear();
      valVar.clear();
   }

   static void calculation(String[] args) {

   }
}