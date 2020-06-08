#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 502
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
int t, n;
int a[N], b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    vector<pair<int, int>> rk1;
    vector<pair<int, int>> rk2;
    rk1.clear();
    rk2.clear();
    if (n&1) {
      if (a[(n+1)/2] != b[(n+1)/2]) {
        cout<<"No"<<endl;
        continue;
      }
    }
    for (int i = 1; i <= n/2; ++i) {
      int x = a[i];
      int y = a[n+1-i];
      if (x > y) swap(x,y);
      rk1.push_back(make_pair(x,y));
      x = b[i];
      y = b[n+1-i];
      if (x > y) swap(x,y);
      rk2.push_back(make_pair(x,y));
    }
    sort(rk1.begin(), rk1.end());
    sort(rk2.begin(), rk2.end());
    // for (int i = 0; i < rk1.size(); ++i) {
    //   cout<<"i1="<<i<<endl;
    //   cout<<rk1[i].first<<" "<<rk1[i].second<<endl;
    // }
    // for (int i = 0; i < rk2.size(); ++i) {
    //   cout<<"i2="<<i<<endl;
    //   cout<<rk2[i].first<<" "<<rk2[i].second<<endl;
    // }
    int i;
    for (i = 0; i < rk1.size(); ++i) {
      if ((rk1[i].first != rk2[i].first) || (rk1[i].second != rk2[i].second)) break;
    }
    if (i >= rk1.size()) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  return 0;
}
