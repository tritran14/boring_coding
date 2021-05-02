import java.awt.*;
import java.io.*;
import java.sql.Array;
import java.util.*;
import java.util.List;

public class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }

        long nextLong() { return Long.parseLong(next()); }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static final int N=300005;
    static final int mod=1000000007;
    static final int INF=1000000009;
    static final int numBit=17;
    static FastReader r=new FastReader();
    static PrintWriter pw = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int n=r.nextInt();
        int []a=new int[n];
        int []dp=new int[n];
        for(int i=0;i<n;++i){
            dp[i]=1;
        }
        for(int i=0;i<n;++i){
            a[i]=r.nextInt();
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(a[i]>a[j]) dp[i]=Math.max(dp[i],dp[j]+1);
            }
        }
//        System.out.print("dp : ");
//        for(int i=0;i<n;++i) System.out.print(dp[i]+" ");
//        System.out.println();
        int ans=1;
        for(int i=0;i<n;++i){
            ans=Math.max(ans,dp[i]);
        }
        pw.print(ans);
        pw.close();
    }
}
