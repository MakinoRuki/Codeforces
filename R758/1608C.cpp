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
#define N 100002
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int s, t;
bool pm[10000];
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    set<int> ss;
    vector<pair<int,int>> rk1, rk2;
    rk1.clear();
    rk2.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      rk1.push_back(make_pair(a[i], i));
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      rk2.push_back(make_pair(b[i], i));
    }
    sort(rk1.begin(), rk1.end());
    reverse(rk1.begin(), rk1.end());
    sort(rk2.begin(), rk2.end());
    reverse(rk2.begin(), rk2.end());
    int i = 0, j = 0;
    int am, bm;
    ss.insert(rk1[i].second);
    am = a[rk1[i].second];
    bm = b[rk1[i].second];
    i++;
    ss.insert(rk2[j].second);
    am = min(am, a[rk2[j].second]);
    bm = min(bm, b[rk2[j].second]);
    j++;
    while(true) {
      int sz1 = (int)ss.size();
      while(i < rk1.size()) {
        int id = rk1[i].second;
        if (a[id] > am || b[id] > bm) {
          ss.insert(id);
          am = min(am, a[id]);
          bm = min(bm, b[id]);
          i++;
        } else {
          break;
        }
      }
      while(j < rk2.size()) {
        int id = rk2[j].second;
        if (a[id] > am || b[id] > bm) {
          ss.insert(id);
          am = min(am, a[id]);
          bm = min(bm, b[id]);
          j++;
        } else {
          break;
        }
      }
      int sz2 = (int)ss.size();
      if (sz2 == sz1 || (i >= rk1.size() && j >= rk2.size())) {
        break;
      }
    }
    string ans="";
    for (int i = 1; i <= n; ++i) {
      if (ss.find(i) != ss.end()) {
        ans += "1";
      } else {
        ans += "0";
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
