#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
int n, k;
int a[N];
int main() {
	cin>>n>>k;
	string s;
	cin>>s;
	string t = s;
	for (int i = 0; i < k; ++i) {
		for (int j = i + k; j < n; j += k) {
			t[j] = s[i];
		}
	}
	bool ok = false;
	if (t >= s) {
		cout<<n<<endl;
		cout<<t<<endl;
	} else {
		int i;
		// 只要看前k位。要么都不变，就直接知道最后结果是什么；
		// 要么找到变化的最高位，必然是变大，最少是+1。然后其余低位全部变成0即可。
		for (i = k-1; i >= 0; --i) {
			if (s[i] < '9') {
				s[i] += 1;
				break;
			}
		}
		for (int j = i+1; j < k; ++j) {
			s[j] = '0';
		}
		for (int i= 0; i < k; ++i) {
			for (int j= i+k; j < n; j += k) {
				s[j] = s[i];
			}
		}
		cout<<n<<endl;
		cout<<s<<endl;
	}
	return 0;
}
