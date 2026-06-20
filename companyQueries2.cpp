#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 200005;
const long long LOG = 20;

long long up[MAXN][LOG];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        cin >> up[i][0];
    }

    up[1][0] = 0; // root has no parent

    // Precompute 2^j ancestors
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j-1] != 0)
                up[i][j] = up[ up[i][j-1] ][j-1];
            else
                up[i][j] = 0;
        }
    }

    // Process queries
    while (q--) {
        int node1,node2;
        cin>>node1>>node2;
        for(int i =0;i<LOG;i++){
            if(up[node1][i]==up[node2][i]){
                long long ans = up[node1][i];
                cout<<ans<<" "<<endl;
                break;
            }
        }
    }

    return 0;
}
