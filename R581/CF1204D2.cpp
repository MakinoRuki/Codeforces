// 形如10, 1(1010)0这样的string只有一种拼法。
// 所以我们把这样的去掉之后就会剩下000...111。
// 这时候要找出所有没有后缀0的1，这些1没有必要是1。因此可以改成0。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n;
string s;
int main() {
	cin>>s;
	n = s.size();
	int cnt = 0;
	string t = s;
	for (int i = n-1; i >= 0; --i) {
		if (s[i] == '0') cnt--;
		else cnt++;
		if (cnt > 0) {
			t[i] = '0';
			cnt--;
		}
	}
	cout<<t<<endl;
	return 0;
}

// 看每一个1是否可以改成0：对于原先全部选1的方案没有影响；对000...111这种方案有影响。
// 影响在于1变0后0的个数增加，我们希望增加后的000...111长度不要超过原先的全1方案。
// 因此不应该存在任何一个前缀使得#(1)<=#(0)。也就是说只能形如111010这种。因此我们看作括号匹配，就是最后剩下的左括号("1")才可以变为0。
/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n;
string s;
int main() {
	cin>>s;
	n = s.size();
	string t = s;
	vector<int> ids;
	ids.clear();
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			if (!ids.empty()) {
				ids.pop_back();
			}
		} else {
			ids.push_back(i);
		}
	}
	for (int i = 0; i < ids.size(); ++i) {
		t[ids[i]] = '0';
	}
	cout<<t<<endl;
	return 0;
}*/
