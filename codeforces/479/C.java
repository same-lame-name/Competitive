import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.ArrayList; 
import java.util.Collections;
import java.util.Comparator;
import javafx.util.Pair; 


public class Main {
    public static void main(String[] args){
        FastScanner scanner = new FastScanner();
        Integer N = scanner.nextInt();
        Integer current = 0;

        ArrayList<IntegerPair> choices = new ArrayList<IntegerPair>();

        for(int rep = 0; rep < N; ++rep){
            Integer fst = scanner.nextInt();
            Integer sec = scanner.nextInt();

            choices.add(new IntegerPair(fst, sec));
        }

        Collections.sort(choices);
        for(IntegerPair choice : choices){
            if(choice.getSecond() >= current) current = choice.getSecond();
            else current = choice.getFirst();
        }

        System.out.println(current);
        return;
    }

    static class IntegerPair implements Comparable<IntegerPair>{
        Integer first;
        Integer second;

        public IntegerPair(Integer fst, Integer sec){
            this.first = fst;
            this.second = sec;
        }

        public Integer getFirst(){ return this.first; }

        public Integer getSecond(){ return this.second; }

        public int compareTo(IntegerPair other){
            if(!this.first.equals(other.first)) return this.first.compareTo(other.first);
            return this.second.compareTo(other.second);
        }
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
