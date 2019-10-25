import java.util.Scanner;

public class BabyBites {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int range =  Integer.parseInt(in.nextLine());
		boolean flag = true;
		for (int i = 1; flag && i <= range; i++) {
			String temp = in.next();
			if (!temp.equals("mumble"))
				if (Integer.parseInt(temp) != i)
					flag = false;
		}
		System.out.println(flag ? "makes sense" : "something is fishy");
	}
}
