import java.util.*;

public class Datum {
	public static void main(String[]args) {
		Scanner in = new Scanner(System.in);
		int day = in.nextInt();
		int month = in.nextInt();
		String[] days = {"Wednesday","Thursday","Friday","Saturday","Sunday","Monday","Tuesday"};
		switch(month){
			case 12: day+=30;
			case 11: day+=31;
			case 10: day+=30;
			case 9: day+=31;
			case 8: day+=31;
			case 7: day+=30;
			case 6: day+=31;
			case 5: day+=30;
			case 4: day+=31;
			case 3: day+=28;
			case 2: day+=31;
			default: break;	
		}		
		System.out.println(days[day%7]);	
	}
}
