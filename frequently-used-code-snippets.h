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
bool containsElementInVector(vector<int>& v,
                             int ele) {
    for (int e : v) {
        if (e == ele) {
            return true;
        }
    }
    return false;
}

// ���ܣ���� ele �� vector
// ������vector, ele
// ���أ�void
void addToVectorUnique(vector<int>& v,
                       int addEle) {
    // ���ǰҪ���ж�û�и�����Ԫ���ظ�
    for (int e : v) {
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
void printVector(vector<int>& v) {
    for (int e : v) {
        cout << e << ' ';
    }
    cout << endl;
}

//********************map*********************
// ���ܣ����� map �� key ���ֵĴ���
// ������map, key
// ���أ�void
void updateKeyCounts(map<int, int>& mapp,
                     int key) {
    map<int, int>::iterator iter = mapp.find(key);

    // �ҵ� key
    if (iter != mapp.end()) {
        (iter->second)++;
    }
    // �Ҳ��� key
    else {
        mapp[key] = 1;
    }
}

// ���ܣ���� <key, val> �� map
// ������map, key, val
// ���أ�void
void addToMap(map<TreeNode*, TreeNode*>& mapParents,
              TreeNode* keyNode,
              TreeNode* valNode) {
    if (keyNode == NULL) {
        return;
    }

    // �Ҳ��� key
    if (mapParents.find(keyNode) == mapParents.end()) {
        mapParents.insert(pair<TreeNode*, TreeNode*>(keyNode, valNode));
    }
}

void addToMap(map<char, int>& mapp,
              char key) {
    map<char, int>::iterator iter = mapp.find(key);

    // �Ҳ��� c���½� <key, val> ��
    if (iter == mapp.end()) {
        mapp[key] = 1;
    }
    // �ҵ� key��val++
    else {
        (iter->second)++;
    }
}

// ���ܣ��ж� map �Ƿ���� key
// ������map, key
// ���أ�bool
bool containsKeyInMap(map<int, int>& mapp,
                      int key) {
    map<int, int>::iterator iter = mapp.find(key);
    return iter != mapp.end();
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