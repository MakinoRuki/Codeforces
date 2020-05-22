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
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int k;
int main() {
  cin>>k;
  bool found=false;
  int i;
  for (i = 1; i*i <= k; ++i) {
    if (k % i == 0) {
      if (i >= 5 && k/i >= 5) {
        found=true;
        break;
      }
    }
  }
  if (!found) {
    cout<<-1<<endl;
  } else {
    int n = i;
    int m = k/i;
    vector<string>mt(n, string(m, ' '));
    vector<char> cs = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        mt[i][j] = cs[(i+j)%5];
      }
    }
    for (int i = 5; i < n; ++i) {
      for (int j = 0; j < 5; ++j) {
        mt[i][j] = cs[j];
      }
    }
    for (int j = 5; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        mt[i][j] = cs[i%5];
      }
    }
    string ans="";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ans.push_back(mt[i][j]);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
