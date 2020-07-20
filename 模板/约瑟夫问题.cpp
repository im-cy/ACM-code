
//n个人 ， 每 k 个人出局一人
//O(n) 
int josephus(int n, int k)
{
	int res = 0;
	for(int i = 1; i <= n; i ++)
		res = (res + k) % i;
	return res;
}


//O(klogn)
int josephus(int n, int k)
{
	if(n == 1)
		return 0;
	if(k == 1)
		return n - 1;
	if(k > n)
		return (josephus(n - 1, k) + k) % n;  // 线性算法
	int res = josephus(n - n / k, k);
	res -= n % k;
	if(res < 0)
		res += n;  // mod n
	else
		res += res / (k - 1);  // 还原位置
	return res;
}


