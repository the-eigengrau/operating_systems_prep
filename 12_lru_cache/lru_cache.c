typedef struct Node {
    struct Node * next;
    struct Node * previous;
    char * key;
    char * value;
} Node;

typedef struct LRUcache {
    void *hashmap;
    Node * head;
    Node * tail;
    int capacity;
    int current_count;
} LRUcache;

void moveToHead(Node * n, LRUcache * l) {
    (n->head)
}