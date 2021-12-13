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
#define N 10000002
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int s, t;
bool pm[10000];
int main() {
  memset(pm, true, sizeof(pm));
  for (int i = 2; i < 10000; ++i) {
    if (pm[i]) {
      for (int j = i * 2; j < 10000; j += i) {
        pm[j] = false;
      }
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<int> ans;
    ans.clear();
    for (int i = 2; i < 10000; ++i) {
      if (ans.size() >= n) {
        break;
      }
      if (pm[i]) {
        ans.push_back(i);
      }
    }
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d", ans[i]);
      if (i < ans.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
