/**
 * YZM2031 - Lab Assignment 1
 * Problem 2: Singly Linked List Implementation
 *
 * Student Name: Ahmet Doruk Güngör
 * Student ID: 24018034
 *
 * Instructions: Implement the TODO sections below
 */

#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    // Constructor
    LinkedList() : head(nullptr), size(0) {}

    // Destructor
    ~LinkedList() {
        Node* freer;
        for (int i = 0;i < size;i++) {
            freer = head->next;
            delete head;
            head = freer;
        }
        // TODO: Free all nodes
        // 1. Traverse the list
        // 2. Delete each node
        // Hint: Save the next pointer before deleting current node

    }

    // Insert at beginning
    void insertFront(int value) {
        Node* newnode = new Node(value);
        newnode->next = head;
        head = newnode;
        size++;
        // TODO: Implement insertFront
        // 1. Create a new node
        // 2. Set new node's next to current head
        // 3. Update head to new node
        // 4. Increment size

    }

    // Insert at end
    void insertBack(int value) {

        Node* newnode = new Node(value);
        if (head == nullptr) {
            head = newnode;
            size++;

        }
        else {
            Node* incrementer = head;

            while (incrementer->next != nullptr) {
                incrementer = incrementer->next;
            }

            incrementer->next = newnode;
            size++;
        }
        // TODO: Implement insertBack
        // 1. Create a new node
        // 2. If list is empty, set head to new node
        // 3. Otherwise, traverse to the last node
        // 4. Set last node's next to new node
        // 5. Increment size

    }

    // Insert at specific position
    void insertAt(int index, int value) {
        Node* incrementer = head;
        Node* placeHolder;
        if (index < 0 || index > size) {
            cout << "Entered Invalid Index" << endl;
        }
        else if (index == 0) {
            insertFront(value);


        }
        else {
            for (int i = 0;i < index - 1;i++) {
                incrementer = incrementer->next;

            }
            placeHolder = incrementer->next;
            Node* newnode = new Node(value);
            incrementer->next = newnode;
            newnode->next = placeHolder;
            size++;





        }
        // TODO: Implement insertAt
        // 1. Validate index (0 <= index <= size)
        // 2. If index is 0, call insertFront
        // 3. Otherwise, traverse to node at index-1
        // 4. Create new node
        // 5. Link new node between current node and next node
        // 6. Increment size

    }

    // Delete first element
    void deleteFront() {
        if (size == 0) {
            cout << "Nothing to Delete Here" << endl;

        }
        else {
            Node* Deleter;
            Deleter = head;
            head = head->next;
            delete Deleter;
            size--;
        }
        // TODO: Implement deleteFront
        // 1. Check if list is empty
        // 2. Save head pointer
        // 3. Move head to next node
        // 4. Delete old head
        // 5. Decrement size

    }

    // Delete last element
    void deleteBack() {
        if (size == 0) {
            cout << "Nothing to Delete Here" << endl;

        }
        else if (head->next == nullptr) {
            delete head;
            head = nullptr;
            size--;
            return;
        }




        else {
            Node* incrementer = head;
            Node* placeHolder;
            while (incrementer->next->next != nullptr) {
                incrementer = incrementer->next;


            }
            placeHolder = incrementer->next;
            incrementer->next = nullptr;
            delete placeHolder;
            size--;

        }
        // TODO: Implement deleteBack
        // 1. Check if list is empty
        // 2. If only one node, delete it and set head to nullptr
        // 3. Otherwise, traverse to second-to-last node
        // 4. Delete last node
        // 5. Set second-to-last node's next to nullptr
        // 6. Decrement size

    }

    // Search for value and return index (-1 if not found)
    int search(int value) {
        Node* incrementer = head;
        int foundFlag = 0;
        int indexCounter = 0;

        while (incrementer != nullptr && foundFlag != 1) {
            if (incrementer->data == value) {
                foundFlag = 1;
                return indexCounter;



            }
            else if (incrementer->data != value) {
                incrementer = incrementer->next;
                indexCounter++;

            }


        }
        if (foundFlag == 0) {
            cout << "Value could not be found" << endl;
            return -1;
        }


        // TODO: Implement search
        // 1. Traverse the list
        // 2. Keep track of index
        // 3. If value found, return index
        // 4. If not found, return -1

          // Placeholder
    }

    // Reverse the list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next_node = nullptr;

        while (current != nullptr) {
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }


        head = prev;

        // TODO: Implement reverse
        // 1. Use three pointers: prev, current, next
        // 2. Initialize prev = nullptr, current = head
        // 3. Traverse the list:
        //    - Save next node
        //    - Reverse current node's pointer
        //    - Move prev and current forward
        // 4. Update head to prev

    }

    // Print all elements
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " → ";
            }
            current = current->next;
        }
        cout << " → nullptr" << endl;
    }

    // Return size
    int getSize() const {
        return size;
    }
};

// Test cases
int main() {
    cout << "=== Testing Linked List ===" << endl << endl;

    LinkedList list;

    // Test 1: Insert operations
    cout << "Test 1: Insert operations" << endl;
    list.insertFront(10);
    list.insertFront(5);
    list.insertBack(20);
    list.insertBack(25);
    cout << "List: ";
    list.print();  // Expected: 5 → 10 → 20 → 25 → nullptr
    cout << "Size: " << list.getSize() << endl;
    cout << endl;

    // Test 2: Insert at position
    cout << "Test 2: Insert 15 at index 2" << endl;
    list.insertAt(2, 15);
    cout << "List: ";
    list.print();  // Expected: 5 → 10 → 15 → 20 → 25 → nullptr
    cout << endl;

    // Test 3: Search
    cout << "Test 3: Search operations" << endl;
    cout << "Index of 15: " << list.search(15) << endl;  // Expected: 2
    cout << "Index of 100: " << list.search(100) << endl;  // Expected: -1
    cout << endl;

    // Test 4: Delete operations
    cout << "Test 4: Delete front" << endl;
    list.deleteFront();
    cout << "List: ";
    list.print();  // Expected: 10 → 15 → 20 → 25 → nullptr
    cout << endl;

    cout << "Test 5: Delete back" << endl;
    list.deleteBack();
    cout << "List: ";
    list.print();  // Expected: 10 → 15 → 20 → nullptr
    cout << endl;

    // Test 6: Reverse
    cout << "Test 6: Reverse list" << endl;
    list.reverse();
    cout << "List: ";
    list.print();  // Expected: 20 → 15 → 10 → nullptr
    cout << endl;

    cout << "=== All tests completed ===" << endl;

    return 0;
}
