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
//#include <priority_queue>
#define N 102
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
string s;
int main() {
  cin>>n>>s;
  if (n%2) {
    cout<<":("<<endl;
  } else {
    int ln = 0;
    int rn = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') ln++;
      else if (s[i] == ')') rn++;
    }
    if (ln > n/2 || rn > n/2) {
      cout<<":("<<endl;
      return 0;
    }
    int det=0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '?') {
        if (ln<n/2) {
          s[i] = '(';
          ln++;
          det++;
        } else if (rn < n/2) {
          s[i] = ')';
          rn++;
          det--;
        } else {
          ok = false;
        }
      } else if (s[i] == '(') {
        det++;
      } else {
        det--;
      }
      if (i < n-1) {
        if (det<=0) ok =false;
      } else {
        if (det != 0) ok =false;
      }
    }
    if (det) {
      ok = false;
    }
    if (ok) cout<<s<<endl;
    else cout<<":("<<endl;
  }
  return 0;
}
