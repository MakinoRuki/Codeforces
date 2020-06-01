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
#define N 52
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
vector<string> mt;
int main() {
  cin>>t;
  for (int i = 1; i <= t; ++i) {
    scanf("%d", &n);
    mt.clear();
    for (int j = 0; j < n; ++j) {
      string s;
      cin>>s;
      mt.push_back(s);
    }
    bool ok = true;
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (mt[j][k] == '0') continue;
        if (j+1>=n || k+1>=n || mt[j][k+1]=='1' || mt[j+1][k]=='1') {
          continue;
        }
        ok = false;
      }
    }
    if (ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
