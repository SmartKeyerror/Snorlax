
#include <unordered_map>

using namespace std;

struct Node {
    Node *prev, *next;
    int key, value;
    Node() : prev(nullptr), next(nullptr), value(0) {}
    Node(int _key, int _value) : prev(nullptr), next(nullptr), key(_key), value(_value) {}
};


class LinkedList {
private:
    Node *dummyHead;
    Node *dummyTail;
public:
    LinkedList() {
        dummyHead = new Node();
        dummyTail = new Node();

        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    // 获取链表的尾部节点
    Node *getTail() {
        return dummyTail->prev == dummyHead ? nullptr : dummyTail->prev;
    }

    // 删除链表中的节点 (但不释放内存)
    void deleteNode(Node *node) {
        // 断开原有连接
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = nullptr;
        node->prev = nullptr;
    }

    // 将节点插入至链表头
    void insertHead(Node *node) {
        node->prev = dummyHead;
        node->next = dummyHead->next;

        dummyHead->next = node;
        node->next->prev = node;
    }
};


class LRUCache {
private:
    int capacity;
    unordered_map<int, Node *> cache;
    LinkedList linkedList;
private:
    // 创建一个新的缓存项
    void addRecently(int key, int value) {
        Node *node = new Node(key, value);
        linkedList.insertHead(node);
        cache[key] = node;
    }

    // 将一个缓存项变为最近使用的
    void moveRecently(int key) {
        Node *node = cache[key];
        linkedList.deleteNode(node);
        linkedList.insertHead(node);
    }

    // 删除最久没有使用的缓存项
    void deleteCache() {
        Node *node = linkedList.getTail();
        linkedList.deleteNode(node);
        cache.erase(node->key);
    }

public:
    LRUCache(int _capacity) : capacity(_capacity) {}

    int get(int key) {
        auto find = cache.find(key);

        // 若 key 不存在，则返回 -1
        if (find == cache.end()) return -1;
        else {
            moveRecently(key);
            return find->second->value;
        }
    }
    
    void put(int key, int value) {
        auto find = cache.find(key);

        // key 不存在
        if (find == cache.end()) {
            addRecently(key, value);

            if (cache.size() > capacity) deleteCache();
        } 
        else {
            Node *node = find->second;
            node->value = value;
            moveRecently(key);
        }
    }
};
