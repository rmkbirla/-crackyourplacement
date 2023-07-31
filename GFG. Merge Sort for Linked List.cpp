class Solution{
  public:
  
    void split(Node* head, Node*& a, Node*& b) {
    if (head == nullptr || head->next == nullptr) {
        a = head;
        b = nullptr;
        return;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    a = head;
    b = slow->next;
    slow->next = nullptr; 
}

Node* merged(Node* a, Node* b) {
    Node* result = nullptr;
    Node* tail = nullptr;

    while (a != nullptr && b != nullptr) {
        Node* smallerNode;
        if (a->data <= b->data) {
            smallerNode = a;
            a = a->next;
        } else {
            smallerNode = b;
            b = b->next;
        }

        if (result == nullptr) {
            result = smallerNode;
            tail = smallerNode;
        } else {
            tail->next = smallerNode;
            tail = smallerNode;
        }
    }

    if (a != nullptr) {
        tail->next = a;
    }

    if (b != nullptr) {
        tail->next = b;
    }

    return result;
}

Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* a;
    Node* b;

    split(head, a, b);

    a = mergeSort(a);
    b = mergeSort(b);

    return merged(a, b);
}
};
