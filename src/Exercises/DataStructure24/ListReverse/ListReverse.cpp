#include <iostream>

template <typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode(T x) : val(x), next(nullptr) {}
};

template <typename T>
ListNode<T>* reverseKGroup(ListNode<T>* head, int k) {
    ListNode<T>* current = head;
    int count = 0;
    
    // Check if there are at least k nodes to reverse
    while (current != nullptr && count < k) {
        current = current->next;
        count++;
    }
    
    if (count < k) {
        return head; // Not enough nodes to reverse
    }
    
    // Reverse k nodes
    ListNode<T>* prev = nullptr;
    ListNode<T>* next = nullptr;
    current = head;
    
    for (int i = 0; i < k; i++) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    // Recursively call for the next part of the list
    if (next != nullptr) {
        head->next = reverseKGroup(next, k);
    }
    
    // prev is now the new head of the reversed group
    return prev;
}

// Helper function to print the list
template <typename T>
void printList(ListNode<T>* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array
template <typename T>
ListNode<T>* createList(T arr[], int size) {
    ListNode<T>* head = new ListNode<T>(arr[0]);
    ListNode<T>* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode<T>(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    ListNode<int>* head = createList(arr, 5);
    int k = 2;
    
    std::cout << "Original list: ";
    printList(head);
    
    head = reverseKGroup(head, k);
    
    std::cout << "Reversed list in groups of " << k << ": ";
    printList(head);
    
    return 0;
}
