struct MyListNode {
    int val;
    MyListNode* next = nullptr;
    MyListNode* prev = nullptr;
    MyListNode(int val) : val(val), next(nullptr), prev(nullptr) {}
};

class MyLinkedList {
    MyListNode* head;
    MyListNode* tail;

public:
    MyLinkedList() {
        head = new MyListNode(-1);
        tail = head;
    }

    int get(int index) {
        MyListNode* curr = head->next;
        int i = 0;
        while (curr && i < index) {
            curr = curr->next;
            i++;
        }
        if (!curr) {
            return -1;
        }
        return curr->val;
    }

    void addAtHead(int val) {
        MyListNode* newNode = new MyListNode(val);
        newNode->next = head->next;
        newNode->prev = head;
        if (head->next) {
            head->next->prev = newNode;
        } else {
            tail = newNode;
        }
        head->next = newNode;
    }

    void addAtTail(int val) {
        MyListNode* newNode = new MyListNode(val);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void addAtIndex(int index, int val) {
        MyListNode* curr = head;
        int i = 0;
        while (curr && i < index) {
            curr = curr->next;
            i++;
        }
        if (!curr) {
            return;
        }
        MyListNode* newNode = new MyListNode(val);
        newNode->next = curr->next;
        newNode->prev = curr;
        if (curr->next) {
            curr->next->prev = newNode;
        } else {
            tail = newNode;
        }
        curr->next = newNode;
    }

    void deleteAtIndex(int index) {
        MyListNode* curr = head;
        int i = 0;
        while (curr && i < index) {
            curr = curr->next;
            i++;
        }
        if (!curr || !curr->next) return;

        MyListNode* toDelete = curr->next;
        curr->next = toDelete->next;
        if (toDelete->next) {
            toDelete->next->prev = curr;
        } else {
            tail = curr;
        }
        delete toDelete;
    }

};
