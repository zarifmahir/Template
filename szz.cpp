#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define int long long
struct mice{
  int s;
  int x; 
  int y; 
  
};
double dist(int x1, int y1, int x2, int y2){
  return sqrt(((x1-x2)*(x1-x2))+ ((y1-y2)*(y1-y2)));
}
void solve(){
  int n; cin>>n;
  vector<mice> m;
  m.push_back({0,0,0});
  for(int i=1; i<=n; i++){
    int x, y, s;
    cin>>x>>y>>s;
    m.push_back({s, x, y});
  }
  sort(m.begin(), m.end());
  double dis[n+1];
  dis[1] = dist(0,0, m[1].x, m[1].y);
  for(int i=2; i<=n; i++){
      dis[i] = dist(m[i-1].x, m[i-1].y, m[i].x, m[i].y);
  }
  int cnt =0;
  while(cnt!=n){
    
  }


}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int t; cin>>t;
  while(t--) solve();
}
