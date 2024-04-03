class MyHashMap {
private:
    struct Node{
        int val;
        int key;
        Node* next;

    Node(int key, int val) : key(key), val(val), next(nullptr) {}
        
        
    };  
    
    int hash(int key) {
        return key % 1000;
    }
    
public:
    vector<Node*> buckets;
    
    MyHashMap() {
        
        buckets = vector<Node*> (1000, nullptr);    
    }
    
    void put(int key, int value) {
        int index = hash(key);
        Node* newNode = new Node(key, value);

        // Search for the key in the linked list at the bucket index
        Node* curr = buckets[index];
        Node* prev = nullptr;
        while (curr != nullptr) {
            if (curr->key == key) {
                // If the key already exists, update the value and return
                curr->val = value;
                delete newNode; // Free memory allocated for newNode
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        // If the key doesn't exist, append the newNode to the end of the linked list
        if (prev == nullptr) {
            buckets[index] = newNode; // Update bucket's head if it's the first node
        } else {
            prev->next = newNode; // Append newNode to the end of the linked list
        }
    }
    
    int get(int key) {
        int index = hash(key);
        Node* curr = buckets[index];

        // Traverse the linked list in the bucket
        while (curr != nullptr) {
            if (curr->key == key) {
                return curr->val; // Return the value if key is found
            }
            curr = curr->next;
        }
        return -1; // Return -1 if key is not found
    }
    
void remove(int key) {
        int index = hash(key);
        Node* curr = buckets[index];
        Node* prev = nullptr;

        // Search for the node with the given key in the linked list
        while (curr != nullptr) {
            if (curr->key == key) {
                if (prev == nullptr) {
                    buckets[index] = curr->next; // Update bucket's head if removing the first node
                } else {
                    prev->next = curr->next; // Remove the node by updating the previous node's next pointer
                }
                delete curr; // Delete the node
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */