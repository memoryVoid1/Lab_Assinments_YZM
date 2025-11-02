#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStacks {
private:
    stack<int> stack1;  // For enqueue operations
    stack<int> stack2;  // For dequeue operations

    // Helper function to transfer elements from stack1 to stack2
    void transfer(int value) {
        switch (value) {
        case 1:
            while (stack1.empty() != true) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            break;
        case 2:
            while (stack2.empty() != true) {
                stack1.push(stack2.top());
                stack2.pop();
            }
            break;
        }
        // TODO: Transfer all elements from stack1 to stack2
        // This reverses the order, giving us FIFO behavior
    }

public:
    QueueUsingStacks() {
        stack1;
        stack2;
        // Constructor - stacks are automatically initialized
    }

    void enqueue(int value) {
        transfer(2);
        stack1.push(value);
        transfer(1);
        // TODO: Add element to queue
        // Hint: Which stack should you push to?
    }

    int dequeue() {
        int dequeuedValue = stack2.top();
        stack2.pop();
        return dequeuedValue;
        // TODO: Remove and return front element
        // Hint: When should you call transfer()?

    }

    int front() {
        // TODO: Return front element without removing it
        return stack2.top();
    }

    bool isEmpty() {
        if (stack1.empty() == true && stack2.empty() == true) {
            return true;
        }
        else if (stack2.empty() != true && stack1.empty() == true) {
            return false;

        }
        else {
            cout << "Critical Error" << endl;
            return false;
        }
    }
};

int main() {
    cout << "=== Problem 2: Implement Queue using Two Stacks ===" << endl;

    QueueUsingStacks q;

    // Test 1: Basic enqueue and dequeue
    cout << "\nTest 1 - Basic operations:" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "After enqueuing 10, 20, 30:" << endl;
    cout << "  Dequeue: " << q.dequeue() << endl;  // Expected: 10
    cout << "  Dequeue: " << q.dequeue() << endl;  // Expected: 20

    // Test 2: Mixed operations
    cout << "\nTest 2 - Mixed operations:" << endl;
    q.enqueue(40);
    q.enqueue(50);

    cout << "After enqueuing 40, 50:" << endl;
    cout << "  Front: " << q.front() << endl;      // Expected: 30
    cout << "  Dequeue: " << q.dequeue() << endl;  // Expected: 30
    cout << "  Dequeue: " << q.dequeue() << endl;  // Expected: 40
    cout << "  Dequeue: " << q.dequeue() << endl;  // Expected: 50

    cout << "  Is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;  // Expected: Yes

    // Test 3: Enqueue after emptying
    cout << "\nTest 3 - Enqueue after emptying:" << endl;
    q.enqueue(100);
    q.enqueue(200);
    cout << "After enqueuing 100, 200:" << endl;
    cout << "  Front: " << q.front() << endl;       // Expected: 100
    cout << "  Dequeue: " << q.dequeue() << endl;   // Expected: 100
    cout << "  Front: " << q.front() << endl;       // Expected: 200

    return 0;
}