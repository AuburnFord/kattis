import java.util.Scanner;

public class LISDP {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numnum = in.nextInt();
		int arr[] = new int[numnum];
		for (int i = 0; i < numnum; i++) arr[i] = in.nextInt();
		System.out.println("Length of LIS is " + lis(arr,arr.length));
	}	

	static int lis(int[] arr, int n) {
		int lis[] = new int[n]; 
		int i, j, max = 0; 
		
		for ( i = 0; i < n; i++ ) {
			lis[i] = 1; 
		}
		for ( i = 1; i < n; i++ ) {
			for ( j = 0; j < i; j++ ) {
				if ( arr[i] > arr[j] && lis[i] < lis[j] + 1) {
					lis[i] = lis[j] + 1; 
				}
			}
	    }
		for ( i = 0; i < n; i++ ) {
			if ( max < lis[i] ) {
				max = lis[i]; 
			}
    	}
		return max; 
	}

}
