A. 只要有负数delta只会越来越大；否则一定是从g=gcd(a1,a2,...,an)往上加到max{a1, a2, ..., an}。

B. 结果长度不会超过3，直接枚举check。

C. 直接从前往后用map来dp。

D. 观察一下发现，从前往后一个一个添加b中数字，其实这些数字最后都会靠在一起，两边不balance就只要记下往两边添加的数字个数就可以了。

   离散化之后用BIT维护。
