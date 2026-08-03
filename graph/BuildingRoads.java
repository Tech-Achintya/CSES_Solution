import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
class DisjointSet {
    int[] rank;
    int[] parent;
    public DisjointSet(int n) {
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    public int findPar(int u) {
        if(parent[u] == u) return u;
        return parent[u] = findPar(parent[u]); // path compression
    }
    public void unionByRank(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
}

class pair{
    int first;
    int second;
    public pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
public class BuildingRoads {
    public static void main(String[] args) throws IOException {
       BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bufferedReader.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        List<pair> list = new ArrayList<>();
        DisjointSet disjointSet = new DisjointSet(n+1);
        for(int i=0;i<m;i++) {
            st = new StringTokenizer(bufferedReader.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            list.add(new pair(a, b));
            disjointSet.unionByRank(a,b);
        }
        int notConnectedComponent = 0;
        List<Integer> ans = new ArrayList<>();
        for(int i=1;i<=n;i++){
            if(disjointSet.findPar(i)==i) {
                notConnectedComponent++;
                ans.add(i);
            }
        }
        System.out.println(notConnectedComponent-1);
        for(int i=0;i<notConnectedComponent-1;i++){
            System.out.println(ans.get(i)+ " " + ans.get(i+1));
        }
    }
}