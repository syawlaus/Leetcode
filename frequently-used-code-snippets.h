/**************************************************************************
* includes
*/
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <math.h>
#include <string>


/**************************************************************************
* namespaces
*/
using namespace std;


/**************************************************************************
* defines
*/
// 求数组长度
#define ARRAY_LENGTH(a) (sizeof(a) / sizeof(a[0]))

// 求两个数的较大值
#define MAX_TWO(a, b) (a > b ? a : b)

// 求两个数的较小值
#define MIN_TWO(a, b) (a < b ? a : b)


/**************************************************************************
* consts
*/


/**************************************************************************
* enums
*/


/*************************************************************************
* global variables
*/


/**************************************************************************
* structs
*/
// 单向链表定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 二叉树节点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**************************************************************************
* classes
*     constructors
*     destructors
*     member function declarations
*/


/*************************************************************************
* class member function definitions
*/


/**************************************************************************
* operator overloadings
*/


/*************************************************************************
* function prototypes
*/


/**************************************************************************
* function definitions
*/
//********************list********************
// 功能：打印单向链表
// 参数：链表首节点指针
// 返回：void
void printList(ListNode *head) {
    while (head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

// 功能：把数组转为链表
// 参数：数组，数组长度
// 返回：链表首节点指针
ListNode* convertArrayToList(int* arr, int len) {
    if (len == 0) {
        return NULL;
    }

    // 用 vector 保存所有指针
    vector<ListNode*> nodes;
    for (int i = 0; i < len; i++) {
        ListNode* node = new ListNode(arr[i]);      // 新建 ListNode*
        nodes.push_back(node);
    }

    // 对 vector 所有指针建立 ->next 关系
    for (int i = 0; i < nodes.size() - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    return nodes[0];
}

// 功能：寻找链表中间节点
// 参数：链表首节点指针
// 返回：链表中间节点指针（当链表节点数量为偶数 n 时，返回 mid 为 n/2，而不是 n/2 + 1）
ListNode* findMiddleNode(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != NULL &&
        fast->next != NULL &&
        fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// 功能：反转单向链表
// 参数：链表首节点指针
// 返回：反转链表首节点指针
ListNode* reverseList(ListNode *head) {
    ListNode *reverseHead = NULL;
    ListNode *node = NULL;
    while (head != NULL) {
        ListNode *next = head->next;
        if (next == NULL) {   // 末尾节点 = 反转链表的首节点
            reverseHead = head;
        }
        head->next = node;
        node = head;
        head = next;
    }
    return reverseHead;
}

// 功能：判断链表是否循环链表
// 参数：链表首节点指针
// 返回：bool
bool hasCycle(ListNode *head) {
    if (head == NULL) {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    while (true) {
        // slow  前进一步
        if (slow->next != NULL) {
            slow = slow->next;
        }
        else {
            return false;
        }

        // fast 前进两步
        if (fast->next != NULL) {
            if (fast->next->next != NULL) {
                fast = fast->next->next;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }

        // slow 与 fast 相遇
        if (slow == fast) {
            return true;
        }
    }
}

//*******************vector*******************
// 功能：把数组转换为 vector
// 参数：数组
// 返回：新建的一个 vector
template <class T> vector<T> convertArrayToVector(T *array, int len) {
    vector<T> v;
    for (int i = 0; i < len; i++) {
        v.push_back(array[i]);
    }
    return v;
}

// 功能：判断 vector 是否包含 ele
// 参数：vector, ele
// 返回：bool
template <class T> bool containsElementInVector(vector<T>& v,
                                                T ele) {
    for (T e : v) {
        if (e == ele) {
            return true;
        }
    }
    return false;
}

// 功能：添加 ele 到 vector，且保证 ele 唯一
// 参数：vector, ele
// 返回：void
template <class T> void addToVectorUnique(vector<T>& v,
                                          T addEle) {
    // 添加前要先判断没有跟已有元素重复
    for (T e : v) {
        if (e == addEle) {
            return;
        }
    }
    // 添加到 v
    v.push_back(addEle);
}

// 功能：打印 vector
// 参数：vector
// 返回：void
template <class T> void printVector(vector<T>& v) {
    for (T e : v) {
        cout << e << ' ';
    }
    cout << endl;
}

// 功能：复制 vector
// 参数：vector
// 返回：vector
template <class T> vector<T> copyVector(vector<T>& v) {
    vector<T> copyV;
    for (T e : v) {
        copyV.push_back(e);
    }
    return copyV;
}

//********************map*********************
// 功能：更新 map 中 key 出现的次数
// 参数：map, key
// 返回：void
template <class T> void updateKeyCounts(map<T, int>& mapp,
                                        T key) {
    map<T, int>::iterator iter = mapp.find(key);

    // 找不到 key
    if (iter == mapp.end()) {
        mapp[key] = 1;
    }
    // 找到 key
    else {
        (iter->second)++;
    }
}

// 功能：添加 <key, val> 到 map
// 参数：map, key, val
// 返回：void
template <class Tkey, class Tval> void addToMap(map<Tkey, Tval>& mapp,
                                                Tkey key,
                                                Tval val) {
    if (key == NULL) {
        return;
    }

    map<Tkey, Tval>::iterator iter = mapp.find(key);

    // 找不到 key，添加 <key, val>
    if (iter == mapp.end()) {
        mapp.insert(pair<Tkey, Tval>(key, val));
    }
    // 找到 key，更新 val
    else {
        (iter->second) = val;
    }
}

// 功能：添加 key 到 map，如果 key 已存在，val++
// 参数：map, key
// 返回：void
template <class T> void incrementKeyCountInMap(map<T, int>& mapp,
                                               T key) {
    if (key == NULL) {
        return;
    }

    map<T, int>::iterator iter = mapp.find(key);

    // 找不到 key，添加 <key, val>
    if (iter == mapp.end()) {
        mapp.insert(pair<T, int>(key, 1));
    }
    // 找到 key，val++
    else {
        (iter->second)++;
    }
}

// 功能：判断 map 是否包含 key
// 参数：map, key
// 返回：bool
template <class Tkey, class Tval> bool containsKeyInMap(map<Tkey, Tval>& mapp,
                                                        Tkey key) {
    return mapp.find(key) != mapp.end();
}

template <class Tkey, class Tval> bool containsValueInMap(map<Tkey, Tval>& mapp,
                                                          Tval val) {
    for (map<Tkey, Tval>::iterator iter = mapp.begin(); iter != mapp.end(); iter++) {
        Tval oldVal = iter->second;
        if (val == oldVal) {
            return true;
        }
    }
    return false;
}

//****************binary tree*****************
// 功能：判断一个节点是否叶子
// 参数：TreeNode *node
// 返回：bool
bool isLeafNode(TreeNode *node) {
    return (node->left == NULL && node->right == NULL);
}

// 功能：判断两棵二叉树是否相等
// 参数：两棵二叉树的根节点
// 返回：bool
bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    // 结构不同
    if (p != NULL && q == NULL) {
        return false;
    }
    // 结构不同
    if (p == NULL && q != NULL) {
        return false;
    }
    // 结构相同
    else {      // 即 p != NULL && q != NULL
        // 值不同
        if (p->val != q->val) {
            return false;
        }
        // 值相同
        bool isSameLeft = isSameTree(p->left, q->left);
        bool isSameRight = isSameTree(p->right, q->right);

        if (isSameLeft && isSameRight) {
            return true;
        }
        return false;
    }
}

// 功能：左右反转二叉树
// 参数：根节点
// 返回：根节点
TreeNode* invertTreeInPlace(TreeNode *root) {
    // root 为空结点
    if (root == NULL) {
        return NULL;
    }

    // root 是叶子节点
    if (root->left == NULL &&
        root->right == NULL) {
        return root;
    }

    // 反转左子树
    TreeNode *left = invertTreeInPlace(root->left);

    // 反转右子树
    TreeNode *right = invertTreeInPlace(root->right);

    // 交换左右子结点
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    // 返回根结点
    return root;
}

// 功能：求二叉树最大深度
// 参数：根节点
// 返回：最大深度
int maxDepth(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return MAX_TWO(leftDepth, rightDepth) + 1;
}

// 功能：广度优先遍历二叉树
// 参数：根节点
// 返回：void
void BFS(TreeNode *root) {
    vector<TreeNode *> queue;
    queue.push_back(root);
    int index = 0;
    while (index < queue.size()) {
        TreeNode *node = queue[index];
        index++;
        cout << node->val << ' ';

        if (node->left != NULL)
            queue.push_back(node->left);

        if (node->right != NULL)
            queue.push_back(node->right);
    }
}

//*******************others*******************
// 功能：判断 n 是否奇数
// 参数：n
// 返回：bool
bool isOdd(int n) {
    return (n % 2 != 0);
}

// 功能：判断 c 是否元音字符
// 参数：c
// 返回：bool
bool isVowel(char c) {
    return (c == 'a' || c == 'A' ||
            c == 'e' || c == 'E' ||
            c == 'i' || c == 'I' ||
            c == 'o' || c == 'O' ||
            c == 'u' || c == 'U');
}

// log 对数函数换底公式
double logbase(double n, double base) {
    return log(n) / log(base);
}

// 求两个数的平均值
int average(int low, int high) {
    //return (low + high) / 2;    // 这样会 int 溢出
    return low + (high - low) / 2;
}