
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int p[N];
int idx[N];
int calc(string& s, int dt) {
  int cnt=0;
  for (int i = 0; i < n; ++i) {
    int cc = s[i]-'0';
    cc = (cc + dt)%2;
    if (cc == 1) cnt++;
  }
  if ((cnt%2) == dt) {
    return cnt;
  }
  return -1;
}
vector<int> calc2(string& s, int dt) {
  vector<int> ids;
  ids.clear();
  for (int i = 0; i < n; ++i) {
    int cc = s[i]-'0';
    cc = (cc + dt)%2;
    if (cc == 1) ids.push_back(i);
  }
  return ids;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    int res=-1;
    int res0=calc(s, 0);
    int res1=calc(s,1);
    if (res0 < 0 && res1 < 0) {
      puts("-1");
      continue;
    }
    vector<int> ids;
    ids.clear();
    if (res0 >= 0 && res1 >= 0) {
      if (res0 < res1) {
        ids = calc2(s, 0);
        res=res0;
      } else {
        ids = calc2(s, 1);
        res=res1;
      }
    } else {
      if (res0 >=0) ids = calc2(s,0);
      if (res1 >= 0) ids = calc2(s, 1);
      res=max(res0, res1);
    }
    printf("%d\n", res);
    for (auto id : ids) {
      printf("%d ", id+1);
    }
    cout<<endl;
  }
  return 0;
}

