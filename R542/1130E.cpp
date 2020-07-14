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
#define N 5002
#define M 1000005
#define inf 1000000000
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int k;
int main() {
	cin>>k;
	k += 2000;
	cout<<2000<<endl;
	for (int i = 1; i <= 2000; ++i) {
		if (i == 1) cout<<-1;
		else {
			cout<<min(k, 1000000);
			k -= min(k, 1000000);
		}
		if (i < 2000) cout<<" ";
		else cout<<endl;
	}
  return 0;
}
