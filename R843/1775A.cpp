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
#define N 100005
#define M 80
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, q;
int k;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    int id = -1;
    n = (int)s.size();
    if (s[0] == 'a') {
      for (int i = 1; i < n; ++i) {
        if (s[i] == 'b') {
          id = i;
          break;
        }
      }
      if (id < 0) {
        string x = "a";
        string y = "a";
        string z = string(n-2, 'a');
        cout<<x<<" "<<z<<" "<<y<<endl;
      } else {
        if (id == n-1) {
          string x = s.substr(0, n-2);
          string y = "a";
          string z = "b";
          cout<<x<<" "<<y<<" "<<z<<endl;
        } else {
          string x = s.substr(0, id);
          string y = s.substr(id, n-1-id);
          string z =s.substr(n-1, 1);
          cout<<x<<" "<<y<<" "<<z<<endl;
        }
      }
    } else {
      for (int i = 1; i < n; ++i) {
        if (s[i] == 'a') {
          id = i;
          break;
        }
      }
      if (id < 0) {
        string x = "b";
        string y = "b";
        string z = string(n-2, 'b');
        cout<<x<<" "<<z<<" "<<y<<endl;
      } else {
        if (id == n-1) {
          string x = s.substr(0, 1);
          string y = s.substr(1, n-2);
          string z = "a";
          cout<<x<<" "<<y<<" "<<z<<endl;
        } else {
          string x = s.substr(0, id);
          string y = s.substr(id, 1);
          string z =s.substr(id+1, n-1-id);
          cout<<x<<" "<<y<<" "<<z<<endl;
        }
      }
    }
  }
  return 0;
}
