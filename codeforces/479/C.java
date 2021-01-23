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

        ArrayList<Pair<Integer, Integer>> choices = new ArrayList<Pair<Integer, Integer>>();
        for(int rep = 0; rep < N; ++rep){
            Pair<Integer, Integer> choice = new Pair<Integer, Integer>(scanner.nextInt(), scanner.nextInt());
            choices.add(choice);
        }

        Collections.sort(choices, new choiceComparator());

        for(Pair<Integer, Integer> choice : choices){
            if(choice.getValue() >= current) current = choice.getValue();
            else current = choice.getKey();
        }

        System.out.println(current);
    }

    static class choiceComparator implements Comparator<Pair<Integer, Integer>>{
        public int compare(Pair<Integer, Integer> fst, Pair<Integer, Integer> sec){
            if(fst.getKey().compareTo(sec.getKey()) != 0) return fst.getKey().compareTo(sec.getKey());
            return fst.getValue().compareTo(sec.getValue());
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
