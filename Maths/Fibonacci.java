import java.io.*;

class matrix {
    long a[][] = new long[2][2];

    matrix() {
 
    }
    void markValues(){
        a[0][0] = 1;
        a[0][1] = 1;
        a[1][0] = 1;
        a[1][1] = 0;
    }
}

class Main {
    static long MOD = 1_000_000_007;

    static matrix multiply(matrix m1, matrix m2) {
        matrix res = new matrix();
        res.markValues();
        res.a[0][0] = res.a[0][1] = res.a[1][0] = res.a[1][1] = 0;

        for(int i=0;i<2;i++) {
            for(int j=0;j<2;j++) {
                for(int k=0;k<2;k++) {
                    res.a[i][j] = (res.a[i][j] + (m1.a[i][k] * m2.a[k][j]) % MOD) % MOD;
                }
            }
        }
        return res;
    }

    static matrix binaryExpo(matrix mat, long n) {
        matrix res = new matrix();
        res.markValues();
        while(n > 0) {
            if(n % 2 == 1) {
                res = multiply(res, mat);
            }
            mat = multiply(mat, mat);
            n >>= 1;
        }
        return res;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());

        if(n < 2) {
            System.out.println(n);
            return;
        }
        if(n==2){
            System.out.println(1);
            return;
        }

        matrix mat = new matrix();
        mat.markValues();
        matrix res = binaryExpo(mat, n - 3);

        long ans = (res.a[0][0] + res.a[0][1]) % MOD;
        System.out.println(ans);
    }
}