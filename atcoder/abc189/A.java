import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.Collections;
import java.lang.Math;


public class Main {
    public static void main(String[] args){
        FastScanner scanner = new FastScanner();
        String util = scanner.next();
        if(util.charAt(0) == util.charAt(1) && util.charAt(1) == util.charAt(2)){
            System.out.println("Won\n");
        }else{
            System.out.println("Lost\n");
        }
        return;
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        
        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }
        
        long nextLong() {
            return Long.parseLong(next());
        }
    }

}
