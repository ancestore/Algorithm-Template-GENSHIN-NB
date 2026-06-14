#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    char c;
    long long maxnum=0;
    vector<int>num(m+2,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        cin>>c;
        if(c=='F')num[j]++;
        else num[j]=0;
        }
        stack<int>st;
        for(int j=1;j<=m+1;j++){
            while(!st.empty()&&num[st.top()]>num[j]){
                int height=num[st.top()];
                st.pop();
                int width = st.empty() ? j - 1 : j - st.top() - 1;
                maxnum=max(maxnum,(long long)height*width);
            }
            st.push(j);
        }
    }
    cout<<maxnum*3;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}