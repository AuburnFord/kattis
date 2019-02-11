import java.util.*;
import java.math.BigInteger;

public class Anagram{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		while(in.hasNextLine()){
			BigInteger poss = new BigInteger("1");
			HashMap<Character, Integer> chars = new HashMap<Character,Integer>();
			String word = in.nextLine();
			poss = poss.multiply(fact(word.length()));
			for(int i = 0; i < word.length(); i++){
				char k = word.charAt(i);
				if(!chars.containsKey(k)) chars.put(k,0);
				chars.put(k,chars.get(k)+1);
			}	
			for(char k : chars.keySet()) {
				poss = poss.divide(fact(chars.get(k)));
			}
			System.out.println(poss);
		}
	}
	
	public static BigInteger fact(int n) {
		BigInteger out = new BigInteger("1");
		if(n == 0 || n == 1) {
			return BigInteger.ONE;	
		}
		out = out.multiply(new BigInteger("" + n));
		out = out.multiply(fact(n-1));
		return out;
	}
}
