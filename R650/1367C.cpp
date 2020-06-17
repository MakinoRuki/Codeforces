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
#define N 50
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, k;
int t;
string s;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>k;
    cin>>s;
    int tot=0;
    vector<pair<int, int>> sg;
    sg.clear();
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        if (i ==0 || s[i-1] == '1') {
          l = i;
          r = i;
        } else {
          r = i;
        }
      } else {
        if (l>=0) {
          if (l > 0) l += k;
          if (r < n-1) r -= k;
          if (l <= r) {
            sg.push_back(make_pair(l, r));
          }
          l = -1, r = -1;
        }
      }
    }
    if (l >= 0) {
      if (l > 0) l += k;
      if (r < n-1) r -= k;
      if (l <= r) {
        sg.push_back(make_pair(l, r));
      }
    }
    for (int i = 0; i < sg.size(); ++i) {
      int len = sg[i].second-sg[i].first+1;
      tot += (len + k) / (k+1);
    }
    cout<<tot<<endl;
  }
  return 0;
}
