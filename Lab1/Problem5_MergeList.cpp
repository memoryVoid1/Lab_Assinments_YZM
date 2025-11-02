/**
 * YZM2031 - Lab Assignment 1
 * Problem 5: Merge Two Sorted Linked Lists
 *
 * Student Name: Ahmet Doruk Güngör
 * Student ID: 24018034
 *
 * Instructions: Implement the TODO sections below
 **/

#include <iostream>
#include <vector>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

/**
 * Merge two sorted linked lists into one sorted list
 *
 * Algorithm approach (choose one):
 *
 * Approach 1 (Iterative):
 * 1. Create a dummy head node
 * 2. Use a tail pointer
 * 3. Compare nodes from both lists
 * 4. Attach smaller node to tail
 * 5. Move pointer in the list where node was taken
 * 6. Attach remaining nodes from non-empty list
 * 7. Return dummy->next
 *
 * Approach 2 (Recursive):
 * 1. Base cases: if list1 is null, return list2; if list2 is null, return list1
 * 2. Compare heads of both lists
 * 3. Attach smaller node and recursively merge rest
 * 4. Return the merged head
 */
Node* mergeSortedLists(Node* list1, Node* list2) {
    Node* movingHead;
    Node* mergeHead;
    Node* list1Increment = list1;
    Node* list2Increment = list2;
    int mergeloopBreaker = 0;
    if (list1 == nullptr && list2 != nullptr) {
        return list2;
    }
    else if (list1 != nullptr && list2 == nullptr) {
        return list1;
    }
    else if (list1 == nullptr && list2 == nullptr) {
        cout << "Both Lists Empty or Failed To Be Read" << endl;
        return nullptr;
    }

    if (list1->data <= list2->data) {
        mergeHead = list1Increment;
        movingHead = mergeHead;
        list1Increment = list1Increment->next;
    }
    else {
        mergeHead = list2Increment;
        movingHead = mergeHead;
        list2Increment = list2Increment->next;

    }
    while (mergeloopBreaker == 0) {
        if (list1Increment == nullptr && list2Increment != nullptr) {
            movingHead->next = list2Increment;
            list2Increment = list2Increment->next;
            movingHead = movingHead->next;
        }
        else if (list2Increment == nullptr && list1Increment != nullptr) {
            movingHead->next = list1Increment;
            list1Increment = list1Increment->next;
            movingHead = movingHead->next;
        }
        else if (list1Increment == nullptr && list2Increment == nullptr) {
            mergeloopBreaker = 1;
        }
        else if (list1Increment->data <= list2Increment->data) {

            movingHead->next = list1Increment;
            list1Increment = list1Increment->next;
            movingHead = movingHead->next;
        }
        else if (list2Increment->data < list1Increment->data) {
            movingHead->next = list2Increment;
            list2Increment = list2Increment->next;
            movingHead = movingHead->next;
        }



    }



    return mergeHead;
}

// ============================================================================
// Helper Functions (Already Implemented - DO NOT MODIFY)
// ============================================================================

// Create a linked list from vector of values
Node* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    Node* head = new Node(values[0]);
    Node* current = head;

    for (size_t i = 1; i < values.size(); i++) {
        current->next = new Node(values[i]);
        current = current->next;
    }

    return head;
}

// Print linked list
void printList(Node* head) {
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

// Delete entire linked list
void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// ============================================================================
// Test Cases
// ============================================================================

int main() {
    cout << "=== Testing Merge Sorted Lists ===" << endl << endl;

    // Test 1: Normal case with equal length lists
    cout << "Test 1: Equal length lists" << endl;
    Node* list1 = createList({ 1, 3, 5, 7 });
    Node* list2 = createList({ 2, 4, 6, 8 });
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    Node* merged = mergeSortedLists(list1, list2);
    cout << "Merged: ";
    printList(merged);
    cout << "Expected: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → nullptr" << endl;
    deleteList(merged);
    cout << endl;

    // Test 2: One empty list
    cout << "Test 2: One empty list" << endl;
    list1 = createList({ 1, 2, 3 });
    list2 = nullptr;
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    merged = mergeSortedLists(list1, list2);
    cout << "Merged: ";
    printList(merged);
    cout << "Expected: 1 → 2 → 3 → nullptr" << endl;
    deleteList(merged);
    cout << endl;

    // Test 3: Lists with different lengths
    cout << "Test 3: Different length lists" << endl;
    list1 = createList({ 1, 5, 9 });
    list2 = createList({ 2, 3, 4, 6, 7, 8 });
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    merged = mergeSortedLists(list1, list2);
    cout << "Merged: ";
    printList(merged);
    cout << "Expected: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9 → nullptr" << endl;
    deleteList(merged);
    cout << endl;

    // Test 4: Both empty lists
    cout << "Test 4: Both empty lists" << endl;
    list1 = nullptr;
    list2 = nullptr;
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    merged = mergeSortedLists(list1, list2);
    cout << "Merged: ";
    printList(merged);
    cout << "Expected: nullptr" << endl;
    deleteList(merged);
    cout << endl;

    // Test 5: Lists with duplicate values
    cout << "Test 5: Lists with duplicate values" << endl;
    list1 = createList({ 1, 3, 5, 5 });
    list2 = createList({ 2, 3, 4, 5 });
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    merged = mergeSortedLists(list1, list2);
    cout << "Merged: ";
    printList(merged);
    cout << "Expected: 1 → 2 → 3 → 3 → 4 → 5 → 5 → 5 → nullptr" << endl;
    deleteList(merged);
    cout << endl;

    cout << "=== All tests completed ===" << endl;

    return 0;
}
