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
#define N 52
#define M 1000005
#define inf 1000000000
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int main() {
	cin>>n;
	cout<<n<<endl;
	for (int i = 1; i <= n; ++i) {
		cout<<1;
		if (i < n) cout<<" ";
		else cout<<endl;
	}
  return 0;
}
