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
#include <stack>
#include <bitset>
#define N 500005
#define M 325
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    vector<int> ids;
    ids.clear();
    int cnt=0;
    for (int i = 0; i < 2*n; ++i) {
      if (s[i] == '1') cnt++;
    }
    if (cnt%2) {
      puts("-1");
      continue;
    }
    int cur=1;
    for (int i = 0; i < 2*n; i += 2) {
      if (s[i] == s[i+1]) continue;
      if (s[i]-'0' == cur) {
        ids.push_back(i+1);
      } else {
        ids.push_back(i+2);
      }
      cur = !cur;
    }
    printf("%d", (int)ids.size());
    if (!ids.empty()) {
      for (int i = 0; i < ids.size(); ++i) {
        printf(" %d", ids[i]);
      }
    }
    cout<<endl;
    for (int i = 1; i <= 2*n; i += 2) {
      printf("%d ", i);
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

