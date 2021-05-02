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

    static List<Pair> []v=new List[N];

    public static class Pair implements Comparable<Pair>{
        int x,y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public void setX(int x) {
            this.x = x;
        }

        public int getY() {
            return y;
        }

        public void setY(int y) {
            this.y = y;
        }

        @Override
        public int compareTo(Pair o) {
            if(this.x<o.getX()) return -1;
            else if(this.x>o.getX()) return 1;
            return 0;
        }
    }

    static int []dist=new int[N];

    public static void dijkstra(int beg){
        for(int i=0;i<N;++i) dist[i]=INF;
        PriorityQueue<Pair> PQ=new PriorityQueue<>();
        dist[beg]=0;
        PQ.add(new Pair(0,beg));
        while(!PQ.isEmpty()){
            Pair u=PQ.peek();
            PQ.poll();
            int now=u.getY();
            int d=u.getX();
            if(d!=dist[now]) continue;
            for(Pair next:v[now]){
                int vv=next.getX();
                int uv= next.getY();
                if(dist[vv]>d+uv){
                    dist[vv]=d+uv;
                    PQ.add(new Pair(dist[vv],vv));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        int n=r.nextInt();
        int m=r.nextInt();
        for(int i=0;i<n;++i) v[i]=new ArrayList<>();
        for(int i=0;i<m;++i){
            int x=r.nextInt();
            int y=r.nextInt();
            int w=r.nextInt();
            --x;
            --y;
            v[x].add(new Pair(y,w));
        }
        int s=r.nextInt();
        int t= r.nextInt();
        --s;
        --t;
        dijkstra(s);
        int ans=dist[t];
        if(ans==INF) ans=-1;
        pw.print(ans);
        pw.close();
    }
}
