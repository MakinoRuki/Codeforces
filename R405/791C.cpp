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
#include <random>
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
vector<string> res;
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  cin>>n>>k;
  res.clear();
  for (int i = 1; i <= n-k+1; ++i) {
    string s;
    cin>>s;
    res.push_back(s);
  }
  vector<string> ans(n, "");
  int id;
  for (id = 0; id < n-k+1; ++id) {
    if (res[id] == "YES") {
      break;
    }
  }
  if (id >= n-k+1) {
    for (int i = 0; i < n; ++i) {
      ans[i] = "A";
    }
  } else {
    vector<string> v;
    v.clear();
    for (int j = 0; j < k; ++j) {
      if (j < 26) ans[id+j].push_back('A' + j);
      else {
        ans[id+j].push_back('A'+j-26);
        ans[id+j].push_back('a'+j-26);
      }
      v.push_back(ans[id+j]);
    }
    for (int j = id-1; j >= 0; --j) {
      ans[j] = "A";
    }
    for (int j = id+k; j < n; ++j) {
      if (res[j-k+1] == "YES") {
        int j2;
        for (j2 = 0; j2 < v.size(); ++j2) {
          int j3;
          for (j3 = j-k+1; j3 < j; ++j3) {
            if (ans[j3] == v[j2]) {
              break;
            }
          }
          if (j3 >= j) {
            ans[j] = v[j2];
            break;
          }
        }
      } else {
        ans[j] = ans[j-k+1];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout<<ans[i];
    if (i < n-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
