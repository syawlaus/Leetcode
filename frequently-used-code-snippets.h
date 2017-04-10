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
// �����������׽ڵ�ָ��
// ���أ�void
void printList(ListNode *head) {
    while (head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

// ���ܣ�������תΪ����
// ���������飬���鳤��
// ���أ������׽ڵ�ָ��
ListNode* convertArrayToList(int* arr, int len) {
    if (len == 0) {
        return NULL;
    }

    // �� vector ��������ָ��
    vector<ListNode*> nodes;
    for (int i = 0; i < len; i++) {
        ListNode* node = new ListNode(arr[i]);      // �½� ListNode*
        nodes.push_back(node);
    }

    // �� vector ����ָ�뽨�� ->next ��ϵ
    for (int i = 0; i < nodes.size() - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    return nodes[0];
}

// ���ܣ�Ѱ�������м�ڵ�
// �����������׽ڵ�ָ��
// ���أ������м�ڵ�ָ�루������ڵ�����Ϊż�� n ʱ������ mid Ϊ n/2�������� n/2 + 1��
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

// ���ܣ���ת��������
// �����������׽ڵ�ָ��
// ���أ���ת�����׽ڵ�ָ��
ListNode* reverseList(ListNode *head) {
    ListNode *reverseHead = NULL;
    ListNode *node = NULL;
    while (head != NULL) {
        ListNode *next = head->next;
        if (next == NULL) {   // ĩβ�ڵ� = ��ת������׽ڵ�
            reverseHead = head;
        }
        head->next = node;
        node = head;
        head = next;
    }
    return reverseHead;
}

// ���ܣ��ж������Ƿ�ѭ������
// �����������׽ڵ�ָ��
// ���أ�bool
bool hasCycle(ListNode *head) {
    if (head == NULL) {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    while (true) {
        // slow  ǰ��һ��
        if (slow->next != NULL) {
            slow = slow->next;
        }
        else {
            return false;
        }

        // fast ǰ������
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

        // slow �� fast ����
        if (slow == fast) {
            return true;
        }
    }
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

// ���ܣ����� vector
// ������vector
// ���أ�vector
template <class T> vector<T> copyVector(vector<T>& v) {
    vector<T> copyV;
    for (T e : v) {
        copyV.push_back(e);
    }
    return copyV;
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
// ���ܣ��ж�һ���ڵ��Ƿ�Ҷ��
// ������TreeNode *node
// ���أ�bool
bool isLeafNode(TreeNode *node) {
    return (node->left == NULL && node->right == NULL);
}

// ���ܣ��ж����ö������Ƿ����
// ���������ö������ĸ��ڵ�
// ���أ�bool
bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    // �ṹ��ͬ
    if (p != NULL && q == NULL) {
        return false;
    }
    // �ṹ��ͬ
    if (p == NULL && q != NULL) {
        return false;
    }
    // �ṹ��ͬ
    else {      // �� p != NULL && q != NULL
        // ֵ��ͬ
        if (p->val != q->val) {
            return false;
        }
        // ֵ��ͬ
        bool isSameLeft = isSameTree(p->left, q->left);
        bool isSameRight = isSameTree(p->right, q->right);

        if (isSameLeft && isSameRight) {
            return true;
        }
        return false;
    }
}

// ���ܣ����ҷ�ת������
// ���������ڵ�
// ���أ����ڵ�
TreeNode* invertTreeInPlace(TreeNode *root) {
    // root Ϊ�ս��
    if (root == NULL) {
        return NULL;
    }

    // root ��Ҷ�ӽڵ�
    if (root->left == NULL &&
        root->right == NULL) {
        return root;
    }

    // ��ת������
    TreeNode *left = invertTreeInPlace(root->left);

    // ��ת������
    TreeNode *right = invertTreeInPlace(root->right);

    // ���������ӽ��
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    // ���ظ����
    return root;
}

// ���ܣ��������������
// ���������ڵ�
// ���أ�������
int maxDepth(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return MAX_TWO(leftDepth, rightDepth) + 1;
}

// ���ܣ�������ȱ���������
// ���������ڵ�
// ���أ�void
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

// ����������ƽ��ֵ
int average(int low, int high) {
    //return (low + high) / 2;    // ������ int ���
    return low + (high - low) / 2;
}