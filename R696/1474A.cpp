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
#include <random>
#define eps 1e-7
#define M 21
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int k;
string b;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cin>>b;
    string a="";
    for (int i = 0; i < n; ++i) {
      if (i == 0) {
        a.push_back('1');
      } else {
        int pre=a[i-1]-'0'+b[i-1]-'0';
        if (b[i]-'0'+1 != pre) {
          a.push_back('1');
        } else {
          a.push_back('0');
        }
      }
    }
    cout<<a<<endl;
  }
  return 0;
}
