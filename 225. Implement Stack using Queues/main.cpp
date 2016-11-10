#include <frequently-used-code-snippets.h>

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        queue.push_back(x);
        topElement = x;
    }

    // Removes the element on top of the stack.
    void pop() {
        // 记录除栈顶的其它元素
        popQueue.clear();
        for (int i = 0; i < queue.size() - 1; i++) {
            popQueue.push_back(queue[i]);
        }

        // 恢复除栈顶的其它元素
        queue.clear();
        for (int i = 0; i < popQueue.size(); i++) {
            queue.push_back(popQueue[i]);
        }
        
        // 更新 topElement
        if (queue.size() > 0) {
            topElement = queue[queue.size() - 1];
        }
        else {
            topElement = UNDEFINED;
        }
    }

    // Get the top element.
    int top() {
        return topElement;
    }

    // Return whether the stack is empty.
    bool empty() {
        return queue.empty();
    }

private:
    vector<int> queue;
    vector<int> popQueue;
    int topElement;
    const int UNDEFINED = -1;
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.empty() << endl;
}