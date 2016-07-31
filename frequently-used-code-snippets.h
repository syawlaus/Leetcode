/**************************************************************************
* includes
*/
#include <iostream>
#include <vector>
#include <map>


/**************************************************************************
* namespaces
*/
using namespace std;


/**************************************************************************
* defines
*/
// �����鳤��
#define ARRAY_LENGTH(a) (sizeof(a) / sizeof(a[0]))

// ���������Ľϴ�ֵ
#define MAX_TWO(a, b) (a > b ? a : b)


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
// ����������
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// �������ڵ㶨��
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
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
// ���ܣ���ӡ��������
// ������������Ԫ��ָ��
// ���أ�void
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

//*******************vector*******************
// ���ܣ��ж� vector �Ƿ���� ele
// ������vector, ele
// ���أ�bool
template <class T> bool containsElementInVector(vector<T>& v,
                                                T ele) {
    for (T e : v) {
        if (e == ele) {
            return true;
        }
    }
    return false;
}

// ���ܣ���� ele �� vector
// ������vector, ele
// ���أ�void
template <class T> void addToVectorUnique(vector<T>& v,
                                          T addEle) {
    // ���ǰҪ���ж�û�и�����Ԫ���ظ�
    for (T e : v) {
        if (e == addEle) {
            return;
        }
    }
    // ��ӵ� v
    v.push_back(addEle);
}

// ���ܣ���ӡ vector
// ������vector
// ���أ�void
template <class T> void printVector(vector<T>& v) {
    for (T e : v) {
        cout << e << ' ';
    }
    cout << endl;
}

//********************map*********************
// ���ܣ����� map �� key ���ֵĴ���
// ������map, key
// ���أ�void
template <class T> void updateKeyCounts(map<T, int>& mapp,
                                        T key) {
    map<T, int>::iterator iter = mapp.find(key);

    // �Ҳ��� key
    if (iter == mapp.end()) {
        mapp[key] = 1;
    }
    // �ҵ� key
    else {
        (iter->second)++;
    }
}

// ���ܣ���� <key, val> �� map
// ������map, key, val
// ���أ�void
template <class T> void addToMap(map<T, T>& mapp,
                                 T key,
                                 T val) {
    if (key == NULL) {
        return;
    }

    map<T, T>::iterator iter = mapp.find(key);

    // �Ҳ��� key����� <key, val>
    if (iter == mapp.end()) {
        mapp.insert(pair<T, T>(key, val));
    }
    // �ҵ� key������ val
    else {
        (iter->second) = val;
    }
}

// ���ܣ��ж� map �Ƿ���� key
// ������map, key
// ���أ�bool
template <class T> bool containsKeyInMap(map<T, T>& mapp,
                                         T key) {
    return mapp.find(key) != mapp.end();
}

//****************binary tree*****************
// ���ܣ�BFS ��ӡ������
// ������������ root
// ���أ�void
void printBinaryTree(TreeNode* root) {
}

//*******************others*******************
// ���ܣ��ж� n �Ƿ�����
// ������n
// ���أ�bool
bool isOdd(int n) {
    return (n % 2 != 0);
}

// ���ܣ��ж� c �Ƿ�Ԫ���ַ�
// ������c
// ���أ�bool
bool isVowel(char c) {
    return (c == 'a' || c == 'A' ||
            c == 'e' || c == 'E' ||
            c == 'i' || c == 'I' ||
            c == 'o' || c == 'O' ||
            c == 'u' || c == 'U');
}