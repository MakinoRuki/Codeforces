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
    string s;
    cin>>s;
    vector<int> v;
    v.clear();
    for (int i = 0; i < n; ++i) {
        if (i == 0 || s[i] != s[i-1]) {
            v.push_back(i);
        }
    }
    int ans=0;
    for (int i = 0; i < v.size(); ++i) {
        if (s[v[i]] == '1') {
            if (i < v.size()-1) {
                ans = v.size()-1-i;
                break;
            }
        }
    }
    printf("%d\n", ans);
  }
  return 0;
}
