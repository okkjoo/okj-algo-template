# okj-algo-template

## 快速排序（递归二分)
```
void qsort(int l, int r){
	int mid = a[l+((r-l)>>1)];
	int i =l,j = r;
	do{
		while(a[i] < mid) i++;//找左半部分比中间数大的数
		while(a[j] > mid) j--;//找右半部分比中间数小的数
		if(i <= j){//如果有一组不满足排序条件（左小右大）
			swap(a[i],a[j]);
			i++;j--;
		}
	}while(i <= j);//=
	if(l<j) qsort(l,j);//递归左半部分
	if(i<r) qsort(i,r);//递归右半部分
}
```

## KMP
###### 当出现字符串不匹配时，可以记录一部分之前已经匹配的文本内容，利用这些信息避免从头再去做匹配。
1. 初始化
2. 处理前后缀不同的情况
3. 处理前后缀相同的情况
```
void kmp(int* next, const string& s){ //前缀表next，要进行查找的字符串
//next[i] 表示 i（包括i）之前最长相等的前后缀长度（其实就是j）
    next[0] = -1; // 前缀表有统一减一的操作，所以j初始化为-1。
    int j = -1;
    //定义两个指针i和j，j指向前缀终止位置（严格来说是终止位置减一的位置），i指向后缀终止位置（与j同理）。
    for(int i = 1; i < s.size(); i++){
        while (j >= 0 && s[i] != s[j + 1]) {// 前后缀不相同了
            j = next[j];// 向前回溯
        }
        if (s[i] == s[j + 1]) {// 找到相同的前后缀
            j++;//同时向后移动i 和j 说明找到了相同的前后缀
        }
        //同时还要将j（前缀的长度）赋给next[i], 因为next[i]要记录相同前后缀的长度。
        next[i] = j;
    }
}
```

## 二叉树
定义：
```
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```
### 深搜前序(中左右)递归遍历:
```
void traversal(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;
    vec.push_back(cur->val);    // 中 ，节点处理
    traversal(cur->left, vec);  // 左
    traversal(cur->right, vec); // 右
}
```

### 深搜前序迭代遍历：
```
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        if (node != NULL) {
            st.pop();
            if (node->right) st.push(node->right);  // 右
            if (node->left) st.push(node->left);    // 左
            st.push(node);                          // 中
            st.push(NULL);                          
        } else {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);            // 节点处理
        }
    }
    return result;
}
```

### 广搜(队列）：
```
vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {// 这一定要固定大小size，因为que.size()在下面的操作中会改变
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);   // 节点处理
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        result.push_back(vec);
    }
    return result;
}
```

### 求深度
```
int getDepth(TreeNode* node) {
    if (node == NULL) return 0;
    return 1 + max(getDepth(node->left), getDepth(node->right));
}
```
### 节点数量
```
int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
```

## 并查集
```
    int father[N];

    // 初始化
    void init() {
        for (int i = 0; i < N; ++i) {
            father[i] = i;
        }
    }
    // 并查集里寻根的过程
    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    // 将v->u 这条边加入并查集
    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return ;
        father[v] = u;
    }
    // 判断 u 和 v是否找到同一个根
    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
```

## 快速幂
例子：a^11 = a^8 + a^2 + a^1;
11 = 1011(二进制)
 
```
long long quickPower(long long b, long long p, long long k){//b的p次方对k取余
	long long ans = 1, base = b;
	while(p > 0){
		if(p & 1) {//只有 b 二进制最后一位是 1 时，b & 1 才会返回 1。
            		ans *= base;
			ans %= k;//优化：每一步都对k取余
        	}    
		base *= base;
		base %= k;//优化：每一步都对k取余
		p>>=1;//右移
	}
	return ans;
}
```
## 线性筛
初始时，假设全部都是素数，当找到一个素数时，显然这个素数乘上另外一个数之后都是合数
把这些合数都筛掉，即算法名字的由来。但仔细分析能发现，这种方法会造成重复筛除合数，影响效率。
比如10，在i=2的时候，k=2*15筛了一次；在i=5，k=5*6 的时候又筛了一次。所以，也就有了快速线性筛法。
```
int vis[MAXN];  
int prime[MAXN];  //prime[j]表示的是第j个素数
//判断是否是一个素数  vis 标记数组 cnt 素数个数  
int cntPrime(){  
    int cnt = 0;      
    for(int i = 2; i < MAXN; i++)  
    {  
        //如果未标记则得到一个素数  
        if(vis[i] == 0){  
            prime[cnt++] = i;  
        }  
        //标记目前得到的素数的i倍为非素数  
        for(int j = 0; j < cnt && prime[j] * i < MAXN; j++)  
        {  
            vis[i * prime[j]] = 1;  
/*
利用了每个合数必有一个最小素因子。每个合数仅被它的最小素因子筛去正好一次。所以为线性时间。
代码中体现在：if(i%prime[j]==0)break;
prime数组 中的素数是递增的,当 i 能整除 prime[j]，那么 i*prime[j+1] 这个合数肯定被 prime[j] 乘以某个数筛掉。
因为i中含有prime[j], prime[j] 比 prime[j+1] 小。接下去的素数同理。所以不用筛下去了。
在满足i%prme[j]==0这个条件之前以及第一次满足改条件时,pr[j]必定是pr[j]*i的最小因子
*/
            if(i % prime[j] == 0){  
                break;  
            }  
        }  
    }  
    return cnt;  
}  
```
