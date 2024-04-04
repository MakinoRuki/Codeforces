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
#include <random>
#include <ctime>
#include <list>
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    if (n == 2) {
      printf("! %d %d\n", 0, 1);
      fflush(stdout);
      continue;
    }
    int id1=0, id2=1;
    for (int i = 1; i < n; ++i) {
      printf("? %d %d %d %d\n", id1, id1, id2, id2);
      fflush(stdout);
      string res;
      cin>>res;
      if (res == "<") {
        id1=id2;
      }
      id2=i+1;
    }
    vector<int> ids;
    ids.clear();
    for (int i =0; i < n; ++i) {
      if (i != id1) {
        ids.push_back(i);
      }
    }
    int idmx = id1;
    vector<int> v;
    v.clear();
    v.push_back(ids[0]);
    for (int i = 1; i < ids.size(); ++i) {
      printf("? %d %d %d %d\n", idmx, v.back(), idmx, ids[i]);
      fflush(stdout);
      string res;
      cin>>res;
      if (res == "<") {
        v.clear();
        v.push_back(ids[i]);
      } else if (res == "=") {
        v.push_back(ids[i]);
      }
    }
    int idmn=v[0];
    for (int i = 1; i < v.size(); ++i) {
      printf("? %d %d %d %d\n", idmn, idmn, v[i], v[i]);
      fflush(stdout);
      string res;
      cin>>res;
      if (res == ">") {
        idmn = v[i];
      }
    }
    printf("! %d %d\n", idmn, idmx);
    fflush(stdout);
  }
  return 0;
}
