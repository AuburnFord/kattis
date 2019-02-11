import java.io.*;
public class Alphabet{
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        char[] chars = in.readLine().toCharArray();
        int[] lis = new int[chars.length];
        int msf = 0;
        for (int i = 0; i < chars.length; i++) {
            int lsf = 1;
            for (int j = 0; j < i; j++) {
                if (chars[i] > chars[j]) {
                    lsf = Math.max(lsf, lis[j] + 1);
                }
            }
            lis[i] = lsf;
            msf = Math.max(lsf, msf);
        }
        System.out.println((26-msf));
    }
}