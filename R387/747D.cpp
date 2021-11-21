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
#define M 200
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
int tt[N];
int main() {
  cin>>n>>k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &tt[i]);
  }
  vector<pair<int,int>> sg;
  sg.clear();
  int cnt=0;
  for (int i =1 ; i <= n; ++i) {
    if (tt[i] < 0) {
      if (i-1>=1 && tt[i-1] <0) {
        cnt++;
      } else {
        if (i-1>=1 && tt[i-1] >= 0) {
          sg.push_back(make_pair(cnt, 1));
        }
        cnt=1;
      }
    } else {
      if (i-1>=1 && tt[i-1]>=0) {
        cnt++;
      } else {
        if (i-1>=1 && tt[i-1] < 0) {
          sg.push_back(make_pair(cnt, -1));
        }
        cnt=1;
      }
    }
  }
  if (tt[n] >= 0) {
    sg.push_back(make_pair(cnt, 1));
  } else {
    sg.push_back(make_pair(cnt, -1));
  }
  int tot=(int)sg.size();
  if (sg[0].second > 0) {
    tot--;
  }
  ll len = 0;
  for (int i = 0; i < sg.size(); ++i) {
    if (sg[i].second < 0) len += sg[i].first;
  }
  if (len > k) {
    puts("-1");
  } else {
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < sg.size(); ++i) {
      if (sg[i].second > 0) {
        if (i > 0) {
          if (i < sg.size()-1) {
            v1.push_back(sg[i].first);
          } else {
            v2.push_back(sg[i].first);
          }
        }
      }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < v1.size(); ++i) {
      if (len + v1[i] <= k) {
        len += v1[i];
        tot -= 2;
      } else {
         break;
      }
    }
    for (int i = 0; i <v2.size(); ++i) {
      if (len + v2[i] <= k) {
        len += v2[i];
        tot--;
      }
    }
    printf("%d\n", tot);
  }
  return 0;
}
