class Node {
     
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};


class LRUCache {
    
private:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,0);
        tail = new Node(-1,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            add(node);
            return node->val;
        }
        return -1;
    }
    
    void remove(Node* node) {
        if(!node)   return;
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    
    void add(Node* node) {
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            node->val = value;
            add(node);
            cache[key] = node;
        }
        else {
            if(cache.size() == capacity) {
                cache.erase(head->next->key);
                remove(head->next);  
            }
            Node* node = new Node(key,value);
            cache[key] = node;
            add(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
