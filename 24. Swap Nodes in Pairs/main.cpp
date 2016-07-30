#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        // 在 head 前面加一个 traverseHead，用来循环时更新 head 的前一个节点
        ListNode tempNode(INIT_VAL);
        ListNode* traverseHead = &tempNode;
        traverseHead->next = head;

        // 用来保存最终结果链表的首元素
        ListNode* retHead = traverseHead;

        while (head != NULL) {
            ListNode* first = head;
            ListNode* second = head->next;
            ListNode* third = NULL;
            if (second != NULL) {
                third = second->next;

                // 原来：traverseHead -> first -> second -> third
                // 任务 ：traverseHead -> second -> first -> third
                traverseHead->next = second;
                second->next = first;
                first->next = third;

                // second -> first (= traverseHead)
                traverseHead = first;

                // head 后移一位（因为 first = head，现在 first 后移了一位，所以 head 只需要再后移一位即可）
                head = head->next;
            }
            else {      // 到达末节点
                break;
            }
        }

        // 返回 head
        return retHead->next;
    }

private:
    const int INIT_VAL = -1;
};

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

ListNode* convertArrayToList() {
    // 把 arr 转为 list，方便测试
    int arr[] = { 1, 2, 3, 4, 5 };
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "arr len = " << len << endl;

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

int main() {
    Solution sol;
    ListNode* head = convertArrayToList();
    printList(sol.swapPairs(head));
}