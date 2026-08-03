
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class DistanceQueries {
    static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        int nextInt() throws IOException {
            int c;
            do {
                c = read();
            } while (c <= ' ');

            int num = 0;

            while (c > ' ') {
                num = num * 10 + (c - '0');
                c = read();
            }

            return num;
        }
    }

    static PrintWriter out = new PrintWriter(System.out);
    static int[] distance;
    static int[] parent;
    static int[][] table;
    static int MAX = 20;

    public static void build(int n){
        table = new int[MAX][n+1];
        table[0] = parent;
        for(int i=1;i<MAX;i++){
            for(int j=1;j<=n;j++){
                int par = table[i-1][j];
                table[i][j] = table[i-1][par];
            }
        }
    }
    public static void main(String[] args) throws IOException {
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        int q = fs.nextInt();
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < n - 1; i++) {
            int u = fs.nextInt();
            int v = fs.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        Queue<Integer> queue = new LinkedList<>();
        distance = new int[n + 1];
        parent = new int[n + 1];
        queue.add(1);
        boolean[] visited = new boolean[n + 1];

        queue.add(1);
        visited[1] = true;
        parent[1] = 0;
        distance[1] = 0;
        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int adjNode : adj.get(node)) {
                if (visited[adjNode]) continue;
                visited[adjNode] = true;
                parent[adjNode] = node;
                distance[adjNode] = distance[node] + 1;
                queue.add(adjNode);
            }
        }
        build(n);
        while (q-- > 0) {
            int nodeA = fs.nextInt();
            int nodeB = fs.nextInt();
            int distRootNodeA = distance[nodeA];
            int distRootNodeB = distance[nodeB];
            int lcaAB = getLCA(nodeA, nodeB);
            int ans = distRootNodeA + distRootNodeB - 2 * distance[lcaAB];
            out.println(ans);
        }
        out.close();
    }
    public static int getLCA(int nodeA,int nodeB) {
        //we assume nodeB is deeper that means distance[b]>distance[a]
        if (distance[nodeA] > distance[nodeB]) {
            int temp = nodeA;
            nodeA = nodeB;
            nodeB = temp;
        }
        // jump directly to the differnce of distance[b]-distance[a] node
        int k = distance[nodeB]-distance[nodeA];
        for(int i = MAX-1;i>=0;i--){
            int mask = 1<<i;
            if((k&mask)>0){
                nodeB = table[i][nodeB];
            }
        }
        if(nodeA==nodeB){
            return nodeA;
        }
        for(int i=MAX-1;i>=0;i--){
            int parNodeA = table[i][nodeA];
            int parNodeB = table[i][nodeB];
            if(parNodeB!=parNodeA){
                nodeA = parNodeA;
                nodeB = parNodeB;
            }
        }
        return parent[nodeA];
    }
}
