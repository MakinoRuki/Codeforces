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
#define M 202
#define N 2005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
void rev(int l, int r) {
  while(l < r) {
    swap(a[l], a[r]);
    l++;
    r--;
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    vector<int> ans;
    ans.clear();
    for (int i = n; i >= 1; --i) {
      int id;
      for (id = i; id >= 1; --id) {
        if (a[id] == i) {
          break;
        }
      }
      if (id == i) {
        ans.push_back(0);
      } else {
        ans.push_back(id);
        rev(1, i);
        rev(1, i-id);
        rev(i-id+1, i);
      }
      // for (int j = 1; j <= n; ++j) {
      //   cout<<a[j]<<" ";
      // }
      // cout<<endl;
    }
    for (int i = ans.size()-1; i >= 0; --i) {
      printf("%d", ans[i]);
      if (i > 0) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
