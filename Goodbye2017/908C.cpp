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
#define N 1005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
vector<string> mp;
string s;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int x[N];
vector<double> ans;
bool cross(int a1, int b1, int a2, int b2) {
  return a1 <= b2 && b1 >= a2;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   string s;
  //   int tot=0;
  //   for (int i = 0; i < n; ++i) {
  //     if (s[])
  //   }
  // }
  int r;
  cin>>n>>r;
  ans.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x[i]);
  }
  for (int i = 1; i <= n; ++i) {
    int j;
    double rm = (double)r;
    int id = 0;
    for (j = i-1; j >= 1; --j) {
      int d = 4 * r * r - (x[j]-x[i])*(x[j]-x[i]);
      if (d >= 0) {
        if (ans[j-1] + sqrt(d) > rm) {
          rm = ans[j-1] + sqrt(d);
        }
      }
      // if (cross(x[j]-r, x[j]+r, x[i]-r, x[i]+r)) {
      //   if (ans[j-1] > rm) {
      //     rm = ans[j-1];
      //     id = j;
      //   }
      // }
    }
    // if (id == 0) ans.push_back((double)r);
    // else {
    //   int d = 4 * r * r - (x[id]-x[i])*(x[id]-x[i]);
    //   ans.push_back(ans[id-1] + sqrt(d));
    // }
    ans.push_back(rm);
  }
  for (int i = 0; i < ans.size(); ++i) {
    printf("%.10lf", ans[i]);
    if (i < ans.size()-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
