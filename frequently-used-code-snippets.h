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
// 参数：链表首元素指针
// 返回：void
void printList(ListNode *head) {
    while (head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
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

//****************binary tree*****************
// 功能：判断一个节点是否叶子
// 参数：TreeNode *node
// 返回：bool
bool isLeafNode(TreeNode *node) {
    return (node->left == NULL && node->right == NULL);
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