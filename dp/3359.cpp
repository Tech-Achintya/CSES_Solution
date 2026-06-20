#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

// void print(const vector<int>& arr) {
//     for (int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }


vector<string> grid;
vector<string> dp;
string check(string &s1, string &s2) {
    if (s1 < s2) {
        return s1;
    } else {
        return s2;
    }
}

map<pair<int,int>, string> memo;
string recurrence(int i, int j, int n, string s) {
    if(memo.find({i,j})!=memo.end()) return memo[{i,j}];
    s.push_back(grid[i][j]);  

    if (i == n-1 && j == n-1) {
        return s;  
    }

    string down = "~";   
    string right = "~";

    if (i+1 < n) {
        down = recurrence(i+1, j, n, s);
    }
    if (j+1 < n) {
        right = recurrence(i, j+1, n, s);
    }

    return memo[{i,j}] = check(down, right); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<string> temp(n);
    grid = temp;
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    string s ="";
    cout<<recurrence(0,0,n,s);
}