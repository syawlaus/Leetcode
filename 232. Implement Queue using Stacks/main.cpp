#include <frequently-used-code-snippets.h>

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        // 清空 s2
        clearStack(s2);

        // 把非栈底元素 pop 出来，push 到 s2
        int size = s.size();
        for (int i = 0; i < size - 1; i++) {
            int element = s.top();
            s2.push(element);
            s.pop();
        }

        // 删除栈底元素
        s.pop();

        // 把 s2 元素 push 回 s
        int size2 = s2.size();
        for (int i = 0; i < size2; i++) {
            int element = s2.top();
            s.push(element);
            s2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        // 清空 s2
        clearStack(s2);

        // 把非栈底元素 pop 出来，push 到 s2
        int size = s.size();
        for (int i = 0; i < size - 1; i++) {
            int element = s.top();
            s2.push(element);
            s.pop();
        }

        // 返回栈底元素
        int frontElement = s.top();

        // 把 s2 元素 push 回 s
        int size2 = s2.size();
        for (int i = 0; i < size2; i++) {
            int element = s2.top();
            s.push(element);
            s2.pop();
        }

        return frontElement;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }

private:
    stack<int> s;
    stack<int> s2;

    void clearStack(stack<int>& s) {
        for (int i = 0; i < s.size(); i++) {
            s.pop();
        }
    }
};

int main() {
    Queue q;
    q.push(1);

    int i = q.peek();

    bool isEmpty = q.empty();
}