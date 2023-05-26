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
#define N 200005
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    int sum=0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') sum++;
      else sum--;
    }
    if (sum != 0) {
      puts("-1");
    } else {
      vector<int> s1, s2;
      s1.clear();
      s2.clear();
      int mx=0;
      for (int i = 0; i < n; ++i) {
        if (s[i] == s[0]) {
          s1.push_back(i);
          a[i] = 1;
          mx=max(mx, 1);
        } else {
          if (s1.empty()) {
            a[i] = 2;
            mx=max(mx, 2);
          } else {
            s1.pop_back();
            a[i] = 1;
            mx=max(mx, 1);
          }
        }
      }
      if (!s1.empty()) {
        while(!s1.empty()) {
          a[s1.back()] = 2;
          mx=max(mx, 2);
          s1.pop_back();
        }
      }
      printf("%d\n", mx);
      for (int i = 0; i < n; ++i) {
        printf("%d", a[i]);
        if (i < n-1) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
