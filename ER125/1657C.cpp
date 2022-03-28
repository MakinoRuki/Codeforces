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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    int i = 0;
    int tot=0;
    while(i < s.size()) {
      if (i + 1 >= s.size()) {
        break;
      }
      if (s[i] == '(') {
        i += 2;
        tot++;
      } else {
        if (s[i + 1] == ')') {
          i += 2;
          tot++;
        } else {
          int j = i+1;
          while(j < s.size() && s[j] != ')') {
            j++;
          }
          if (j >= s.size()) {
            break;
          } else {
            tot++;
            i = j+1;
          }
        }
      }
    }
    printf("%d %d\n", tot, (int)s.size() - i);
  }
  return 0;
}
