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
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, q;
int a[N];
int main() {
  cin>>n;
  int ones = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] == 1) ones++;
  }
  vector<int> ans;
  ans.clear();
  if (ones == 0) {
    for (int i = 1; i <= n; ++i) {
      ans.push_back(a[i]);
    }
  } else if (ones <= 2) {
    if (n-ones>0) {
      ans.push_back(2);
    }
    ans.push_back(1);
    for (int i  = 1; i <= n-ones-1; ++i) {
      ans.push_back(2);
    }
    for (int i = 1; i <= ones-1; ++i) {
      ans.push_back(1);
    }
  } else {
    for (int i = 1; i <= 3; ++i) {
      ans.push_back(1);
    }
    for (int i = 1; i<=n-ones; ++i) {
      ans.push_back(2);
    }
    for (int i = 1; i <= ones-3; ++i) {
      ans.push_back(1);
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d", ans[i-1]);
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
