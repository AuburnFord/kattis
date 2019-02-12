import java.util.Scanner;
public class CharacterDevelopment {
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int characters = in.nextInt();
        System.out.println((int)Math.pow(2, characters) - characters - 1);
    }
}