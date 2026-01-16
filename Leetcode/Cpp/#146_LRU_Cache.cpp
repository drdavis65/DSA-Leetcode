class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    
    Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        Node* last = tail->prev;
        last->next = node;
        tail->prev = node;
        node->next = tail;
        node->prev = last;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        cache.clear();
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);

        if(cache.size() > cap) {
            Node* lru = head->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
