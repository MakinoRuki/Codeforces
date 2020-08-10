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
#define N 2005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int main() {
	cin>>t;
	for (int cas=1; cas <= t; ++cas) {
		scanf("%d", &n);
		for (int i = n; i >= 1; --i) {
			printf("%d",i);
			if (i > 1) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
