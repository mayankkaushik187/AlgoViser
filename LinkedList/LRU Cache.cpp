//aise code likh ek bhi agar job nhi mili na toh laanat hai 
class LRUCache {
    public:
        class node {
            public:
                int key;
            int val;
            node * next;
            node * prev;
            node(int key_, int val_) {
                key = key_;
                val = val_;
            }
        };
    node * head = new node(-1, -1);
    node * tail = new node(-1, -1);

    unordered_map < int, node * > mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    void addnode(node * to_be_added) {
        node * prevheadnext = head -> next;
        to_be_added -> next = prevheadnext;
        to_be_added -> prev = head;
        prevheadnext -> prev = to_be_added;
        head -> next = to_be_added;
    }
    void deletenode(node * to_be_deleted) {
        node * deleteprev = to_be_deleted -> prev;
        node * deletenext = to_be_deleted -> next;

        deleteprev -> next = deletenext;
        deletenext -> prev = deleteprev;

    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            node * resnode = mp[key];
            int res = resnode -> val;
            mp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mp[key] = head -> next;

            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            node * existingNode = mp[key];
            mp.erase(key);
            deletenode(existingNode);
        }
        if (mp.size() == cap) {
            mp.erase(tail -> prev -> key);
            deletenode(tail -> prev);
        }
        addnode(new node(key, value));

        mp[key] = head -> next;
    }
};
