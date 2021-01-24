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
        int k = scanner.nextInt();
        String N = scanner.next(); 
        int L = N.length(), total = 0, current = 0;
        int count[] = new int[15];

        for(int idx = 0; idx < N.length(); ++idx){
            count[N.charAt(idx) - '0']++;
            current += N.charAt(idx) - '0';
        }

        for(int digit = 0, avail, req, take; digit < 10 && current < k; ++digit){
            avail = count[digit];
            req = (k - current + 8 - digit) / (9 - digit);
            take = Math.min(avail, req);

            total += take;
            current += take * (9 - digit);
        }

        System.out.println(total);
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
