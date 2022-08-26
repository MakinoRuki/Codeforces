#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
bool used[N];
int query4(int x1, int x2, int x3, int x4) {
  printf("? %d %d\n", x1, x3);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  if (res == 1) {
    printf("? %d %d\n", x1, x4);
    fflush(stdout);
    scanf("%d", &res);
    if (res == 1) return x1;
    else return x4;
  } else if (res == 2) {
    printf("? %d %d\n", x2, x3);
    fflush(stdout);
    scanf("%d", &res);
    if (res == 1) return x2;
    else return x3;
  } else {
    printf("? %d %d\n", x2, x4);
    fflush(stdout);
    scanf("%d", &res);
    if (res == 1) return x2;
    else return x4;
  }
}
int query(vector<int> v) {
  if (v.size()== 2) {
    printf("? %d %d\n", v[0], v[1]);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    if (res == 1) return v[0];
    else if (res == 2) return v[1];
    else return 0;
  }
  if (v.size() == 4) {
    return query4(v[0], v[1], v[2], v[3]);
  }
  vector<int> v2;
  v2.clear();
  for (int i = 0; i < v.size(); i += 4) {
    if (i + 2 < v.size()) {
      v2.push_back(query4(v[i], v[i+1], v[i+2], v[i+3]));
    } else {
      printf("? %d %d\n", v[i], v[i+1]);
      fflush(stdout);
      int res;
      scanf("%d", &res);
      if (res==1) v2.push_back(v[i]);
      else v2.push_back(v[i+1]);
    }
  }
  return query(v2);
//   if (nn == 3) {
//     int w1 = query(dt, nn-1);
//     int w2 = query(dt + (1<<(nn-1)), nn-1);
//     printf("? %d %d\n", w1, w2);
//     fflush(stdout);
//     int res;
//     scanf("%d", &res);
//     if (res == 1) return w1;
//     else return w2;
//   }
//   int w1 = query(dt, nn-2);
//   int w2 = query(dt+(1<<(nn-2)), nn-2);
//   int w3 = query(dt + (1<<(nn-1)), nn-2);
//   int w4 = query(dt + (1<<(nn-1)) + (1<<(nn-2)), nn-2);
//   printf("? %d %d\n", w1, w3);
//   fflush(stdout);
//   int res;
//   scanf("%d", &res);
//   if (res == 1) {
//     printf("? %d %d\n", w1, w4);
//     fflush(stdout);
//     scanf("%d", &res);
//     if (res == 1) return w1;
//     else return w4;
//   } else if (res== 2) {
//     printf("? %d %d\n", w2, w3);
//     fflush(stdout);
//     scanf("%d", &res);
//     if (res == 1) return w2;
//     else return w3;
//   } else {
//     printf("? %d %d\n", w2, w4);
//     fflush(stdout);
//     scanf("%d", &res);
//     if (res == 1) return w2;
//     else return w4;
//   }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<int> v;
    for (int i = 1; i <= (1<<n); ++i) {
      v.push_back(i);
    }
    int w = query(v);
    printf("! %d\n", w);
    fflush(stdout);
  }
  return 0;
}
