#include <iostream>
#include <map>
#include <frequently-used-code-snippets.h>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool> mapp;
        while (head != NULL) {
            if (mapp.find(head) != mapp.end()) {  // head ÒÑ´æÔÚ
                return true;
            }
            mapp[head] = true;
            head = head->next;
        }
        return false;
    }
};

int main() {
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n1;

    Solution sol;

    cout << sol.hasCycle(&n1) << endl;
    cout << hasCycle(&n1) << endl;
}