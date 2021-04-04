# okj-algo-template


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
