#include <bits/stdc++.h>
using namespace std;
#define mod 114514
#define base 250
#define ll long long
int ans=0;
vector<string>num[mod+2];
void gethash(string s){
    ll x=1;
    for(int i=0;s[i];i++){
        x=(x*base*222+s[i])%mod;
    }
    for(int i=0;i<num[x].size();i++){
        if(num[x][i]==s) {
            return;
        }
    }
    num[x].push_back(s);
    ans++;
}
void solve(){
    int n;
    cin>>n;
    int cnt;
    while(n--){
        string tmp;
        cin>>tmp;
        gethash(tmp);
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}