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
#define N 500005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, x, y;
string s;
int main() {
  cin>>n>>x>>y;
  cin>>s;
  reverse(s.begin(), s.end());
  int tot=0;
  for (int i = 0; i < x; ++i) {
    if (i == y && s[i] != '1') tot++;
    else if (i != y && s[i] == '1') tot++;
  }
  cout<<tot<<endl;
  return 0;
}
