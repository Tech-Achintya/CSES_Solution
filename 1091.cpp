#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> ticket(n);
    set<pair<int,int>> sortedTickets;
    vector<int> ppl(m);
    for(int i=0;i<n;i++){
        cin>>ticket[i];   
        sortedTickets.insert({ticket[i],i});
    }
    for(int i=0;i<m;i++){
        cin>>ppl[i];   
    }
    for(int i=0;i<m;i++){
        auto match = sortedTickets.upper_bound({ppl[i],INT_MAX});
        if(match==sortedTickets.begin()){
            cout<<"-1"<<ln;
        }else{
            match--;
            cout<<(*match).first<<ln;
            sortedTickets.erase(match);
        }
    }

}