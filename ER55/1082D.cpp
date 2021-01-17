#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 502
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int a[N];
int main() {
  cin>>n;
  int cnt = 0;
  vector<int> ids1;
  vector<int> ids2;
  ids1.clear();
  ids2.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] < 2) {
      cnt++;
      ids1.push_back(i);
    } else {
      ids2.push_back(i);
    }
  }
  int res=0;
  vector<pair<int,int>> ans;
  ans.clear();
  if (cnt <= 0) {
    res = n-1;
    for (int i = 1; i < n; ++i) {
      ans.push_back(make_pair(i, i+1));
    }
  } else if (cnt == 1) {
    res = n-1;
    ans.push_back(make_pair(ids1[0], ids2[0]));
    for (int i = 0; i < ids2.size()-1; ++i) {
      ans.push_back(make_pair(ids2[i], ids2[i+1]));
    }
  } else {
    bool ok = true;
    int i = 0;
    int j = 2;
    while(j < ids1.size()) {
      while(i < ids2.size() && a[ids2[i]]<=2) {
        i++;
      }
      if (i >= ids2.size()) {
        ok=false;
        break;
      }
      ans.push_back(make_pair(ids1[j], ids2[i]));
      a[ids2[i]]--;
      j++;
    }
    if (!ok) {
      cout<<"NO"<<endl;
      return 0;
    }
    res = (int)ids2.size()+1;
    for (int i = 0; i < ids2.size()-1; ++i) {
      ans.push_back(make_pair(ids2[i], ids2[i+1]));
    }
    ans.push_back(make_pair(ids1[0], ids2[0]));
    ans.push_back(make_pair(ids1[1], ids2.back()));
  }
  cout<<"YES"<<" "<<res<<endl;
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
