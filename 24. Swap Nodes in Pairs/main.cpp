#include <frequently-used-code-snippets.h>
using namespace std;

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

int main() {
    // 测试一
    Solution sol;
    int arr1[] = { 1 };
    ListNode* list1 = convertArrayToList(arr1, ARRAY_LENGTH(arr1));
    printList(sol.swapPairs(list1));

    // 测试二
    int arr2[] = { 1, 2, 3, 4 };
    ListNode* list2 = convertArrayToList(arr2, ARRAY_LENGTH(arr2));
    printList(sol.swapPairs(list2));

    // 测试三
    int arr3[] = { 1, 2, 3, 4, 5 };
    ListNode* list3 = convertArrayToList(arr3, ARRAY_LENGTH(arr3));
    printList(sol.swapPairs(list3));
}