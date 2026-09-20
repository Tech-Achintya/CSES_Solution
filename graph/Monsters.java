import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class triplet {
    int x;
    int y;
    int dist;

    triplet(int x, int y, int dist) {
        this.x = x;
        this.y = y;
        this.dist = dist;
    }
}

class Monsters {

    static boolean isValid(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }

    static String path = "";

    static boolean funct(int x, int y, char[][] grid,
                     int[][] monsterMinPath, String currPath,
                     boolean[][] visited) {

        int n = grid.length;
        int m = grid[0].length;

        Queue<triplet> q = new LinkedList<>();

        q.add(new triplet(x, y, 0));
        visited[x][y] = true;

        char[][] move = new char[n][m];

        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, 1, 0, -1};

        while (!q.isEmpty()) {

            triplet t = q.poll();

            int currX = t.x;
            int currY = t.y;
            int dist = t.dist;

            if (currX == 0 || currY == 0 ||
                currX == n - 1 || currY == m - 1) {

                StringBuilder ans = new StringBuilder();

                int cx = currX;
                int cy = currY;

                while (cx != x || cy != y) {

                    char c = move[cx][cy];
                    ans.append(c);

                    if (c == 'U') cx++;
                    else if (c == 'D') cx--;
                    else if (c == 'L') cy++;
                    else if (c == 'R') cy--;
                }

                path = ans.reverse().toString();
                return true;
            }

            for (int i = 0; i < 4; i++) {

                int newX = currX + dx[i];
                int newY = currY + dy[i];

                if (!isValid(newX, newY, n, m)
                        || visited[newX][newY]
                        || grid[newX][newY] == '#')
                    continue;

                if (monsterMinPath[newX][newY] <= dist + 1)
                    continue;

                visited[newX][newY] = true;

                if (i == 0) move[newX][newY] = 'U';
                else if (i == 1) move[newX][newY] = 'R';
                else if (i == 2) move[newX][newY] = 'D';
                else move[newX][newY] = 'L';

                q.add(new triplet(newX, newY, dist + 1));
            }
        }

        return false;
    }
    public static void main(String[] args) throws Exception {

        BufferedReader br =
                new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);

        char[][] grid = new char[n][m];

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            char[] row = line.toCharArray();
            grid[i] = row;
        }

        int[][] monsterMinPath = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                monsterMinPath[i][j] = (int) 1e9;
            }
        }

        Queue<triplet> q = new LinkedList<>();

        int playerX = -1;
        int playerY = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 'M') {
                    q.add(new triplet(i, j, 0));
                    monsterMinPath[i][j] = 0;
                }

                if (grid[i][j] == 'A') {
                    playerX = i;
                    playerY = j;
                }
            }
        }

        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, 1, 0, -1};

        while (!q.isEmpty()) {

            triplet t = q.poll();

            int x = t.x;
            int y = t.y;
            int dist = t.dist;
            for (int i = 0; i < 4; i++) {

                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < n
                        && newY >= 0 && newY < m
                        && grid[newX][newY] != '#'
                        && monsterMinPath[newX][newY] > dist + 1) {
                    monsterMinPath[newX][newY] = dist + 1;
                    q.add(new triplet(newX, newY, dist + 1));
                }
            }
        }
        boolean[][] visited = new boolean[n][m];
        for(int i=0;i<n;i++){
            Arrays.fill(visited[i],false);
        }
        if (funct(playerX, playerY, grid, monsterMinPath, "",visited)) {
            System.out.println("YES");
            System.out.println(path.length());
            System.out.println(path);
        } else {
            System.out.println("NO");
        }
    }
}