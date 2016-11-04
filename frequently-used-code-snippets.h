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
// �����鳤��
#define ARRAY_LENGTH(a) (sizeof(a) / sizeof(a[0]))

// ���������Ľϴ�ֵ
#define MAX_TWO(a, b) (a > b ? a : b)

// ���������Ľ�Сֵ
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
// ����������
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// �������ڵ㶨��
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
// ���ܣ���ӡ��������
// ������������Ԫ��ָ��
// ���أ�void
void printList(ListNode *head) {
    while (head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

//*******************vector*******************
// ���ܣ�������ת��Ϊ vector
// ����������
// ���أ��½���һ�� vector
template <class T> vector<T> convertArrayToVector(T *array, int len) {
    vector<T> v;
    for (int i = 0; i < len; i++) {
        v.push_back(array[i]);
    }
    return v;
}

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

// ���ܣ���� ele �� vector���ұ�֤ ele Ψһ
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
template <class Tkey, class Tval> void addToMap(map<Tkey, Tval>& mapp,
                                                Tkey key,
                                                Tval val) {
    if (key == NULL) {
        return;
    }

    map<Tkey, Tval>::iterator iter = mapp.find(key);

    // �Ҳ��� key����� <key, val>
    if (iter == mapp.end()) {
        mapp.insert(pair<Tkey, Tval>(key, val));
    }
    // �ҵ� key������ val
    else {
        (iter->second) = val;
    }
}

// ���ܣ���� key �� map����� key �Ѵ��ڣ�val++
// ������map, key
// ���أ�void
template <class T> void incrementKeyCountInMap(map<T, int>& mapp,
                                               T key) {
    if (key == NULL) {
        return;
    }

    map<T, int>::iterator iter = mapp.find(key);

    // �Ҳ��� key����� <key, val>
    if (iter == mapp.end()) {
        mapp.insert(pair<T, int>(key, 1));
    }
    // �ҵ� key��val++
    else {
        (iter->second)++;
    }
}

// ���ܣ��ж� map �Ƿ���� key
// ������map, key
// ���أ�bool
template <class Tkey, class Tval> bool containsKeyInMap(map<Tkey, Tval>& mapp,
                                                        Tkey key) {
    return mapp.find(key) != mapp.end();
}

//****************binary tree*****************
// ���ܣ��ж�һ���ڵ��Ƿ�Ҷ��
// ������TreeNode *node
// ���أ�bool
bool isLeafNode(TreeNode *node) {
    return (node->left == NULL && node->right == NULL);
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

// log �����������׹�ʽ
double logbase(double n, double base) {
    return log(n) / log(base);
}