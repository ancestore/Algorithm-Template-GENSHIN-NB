#include <iostream>
using namespace std;

const int MAXN = 10005; // 最大节点数
int val[MAXN], l[MAXN], r[MAXN], cnt = 0;

// 插入操作：返回当前子树的根节点下标
int insert(int p, int v) {
    if (p == 0) { // 如果当前位置为空，创建新节点
        p = ++cnt;
        val[p] = v;
        l[p] = r[p] = 0;
        return p;
    }
    if (v < val[p]) {
        l[p] = insert(l[p], v); // 递归插入左子树
    } else if (v > val[p]) {
        r[p] = insert(r[p], v); // 递归插入右子树
    }
    return p;
}

// 中序遍历：BST的中序遍历结果是升序的
void inorder(int p) {
    if (p == 0) return;
    inorder(l[p]);
    cout << val[p] << " ";
    inorder(r[p]);
}

int main() {
    int root = 0;
    int data[] = {5, 3, 7, 2, 4, 6, 8};
    for (int x : data) root = insert(root, x);
    
    inorder(root); // 输出: 2 3 4 5 6 7 8 
    return 0;
}