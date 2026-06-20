#include <bits/stdc++.h>
using namespace std;

// Generate all subset sums recursively
void recurrsion(int idx, int end, long long sum,  const vector<long long> &arr, vector<long long> &sums) {
    if (idx == end) {
        sums.push_back(sum);
        return;
    }
    
    recurrsion(idx + 1, end, sum, arr, sums);
    
    recurrsion(idx + 1, end, sum + arr[idx], arr, sums);
}

//Bit mask appproch*****
//combination sum 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int mid = n / 2;
    vector<long long> L(a.begin(), a.begin() + mid);
    vector<long long> R(a.begin() + mid, a.end());

    vector<long long> sumL, sumR;

    recurrsion(0, L.size(), 0, L, sumL);
    recurrsion(0, R.size(), 0, R, sumR);
    sort(sumR.begin() ,sumR.end());
    
    long long ans =0;
    for(long long s:sumL) {
    long long need = x-s;
    ans+= upper_bound(sumR.begin(), sumR.end() , need) - 
    			lower_bound(sumR.begin() , sumR.end() , need);
          
    }

    cout<<ans;

   
}
