B. 只要有任意一个长度为2的pattern出现2次以上。

C. 直接dp。

D. 首先如果存在g|(x+a),g|(y+a)，那么g|(x-y)。对于(x-y)的某个素因子p，只要找出p-x%p(=p-y%p)即可。因此枚举p。