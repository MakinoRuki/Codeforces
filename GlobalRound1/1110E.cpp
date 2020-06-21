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
#define N 100005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n;
int c[N], t[N];
int main() {
  cin>>n;
  vector<int> s1, s2;
  s1.clear();
  s2.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &c[i]);
    if (i>=2) s1.push_back(c[i]-c[i-1]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &t[i]);
    if (i>=2) s2.push_back(t[i]-t[i-1]);
  }
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  int i;
  for (i = 0; i < s1.size(); ++i) {
    if (s1[i] != s2[i]) break;
  }
  if (i >= s1.size() && c[1] == t[1]) {
    cout<<"Yes"<<endl;
  } else {
    cout<<"No"<<endl;
  }
  return 0;
}
