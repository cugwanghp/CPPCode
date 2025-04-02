template<typename T>
struct DListNode {
    T data;
    DListNode<T>* prev;
    DListNode<T>* next;
    DListNode(T val) : data(val), prev(nullptr), next(nullptr);
};

template<typename T>
class LinkedListDeque {
    private:
    DListNode<T>* front; // 头节点
    DListNode<T>* rear; // 尾节点
    int size; // 双向队列的长度
public:
    LinkedListDeque() : front(nullptr), rear(nullptr), size(0) {}
    ~LinkedListDeque() {
        while (front!= nullptr) {
            auto temp = front;
            front = front->next;
            delete temp;
        }
    }
    int size() const{
        return size;
    }
    bool isEmpty() const {
        return size == 0;
    }
    void pushFront(T val) {
        auto node = new DListNode<T>(val);
        if (isEmpty()) {
            front = rear = node;
        } else {
            node->next = front;
            front->prev = node;
            front = node;
        }
        size++;
    }
    void pushBack(T val) {
        auto node = new DListNode<T>(val);
        if (isEmpty()) {
            front = rear = node;
        } else {
            node->prev = rear;
            rear->next = node;
            rear = node;
        }
        size++;
    }
    T popFront() {
        if (isEmpty()) {
            throw out_of_range("deque is empty");
        }
        auto val = front->data;
        auto temp = front;
        front = front->next;
        if (front!= nullptr) {
            front->prev = nullptr;
            } else {
            rear = nullptr;
        }
        delete temp;
        size--;
        return val;
    }
    T popBack() {
        if (isEmpty()) {
            throw out_of_range("deque is empty");
        }
        auto val = rear->data;
        auto temp = rear;
        rear = rear->prev;
        if (rear != nullptr) {
            rear->next = nullptr;
        } else {
            front = nullptr;
        }
        delete temp;
        size--;
        return val;
    }
    T peekFront() {
        if (isEmpty()) {
            throw out_of_range("deque is empty");
        }
        return front->data;
    }
    T peekBack() {
        if (isEmpty()) {
            throw out_of_range("deque is empty");
        }
        return rear->data;
        }
        
};