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

    public static int binaSearch(List<Integer> a,int val){
        int n=a.size();
        if(val>a.get(n-1)){
            return -1;
        }
        int low=0,high=n-1;
        while(low<high){
            int mid=(low+high)>>1;
            if(a.get(mid)==val){
                return -2;
            }
            if(a.get(mid)<val){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }

    public static void main(String[] args) throws IOException {
        int n=r.nextInt();
        int []a=new int[n];
        List<Integer> list=new ArrayList<>();
        for(int i=0;i<n;++i){
            a[i]=r.nextInt();
        }
        for(int i=0;i<n;++i){
            if(list.isEmpty()){
                list.add(a[i]);
                continue;
            }
            int pos=binaSearch(list,a[i]);
            if(pos==-2) continue;
            if(pos==-1) list.add(a[i]);
            else list.set(pos,a[i]);
        }
//        System.out.println(list);
        pw.print(list.size());
        pw.close();
    }
}
