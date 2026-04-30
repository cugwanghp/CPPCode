#pragma once
#include <iostream> // 用于测试输出

template <typename T>
class LinkedList {
private:
		// 链表节点结构
		struct Node {
				T data;
				Node* next;

				Node(const T& val, Node* n = nullptr) : data(val), next(n) {}
		};

		Node* head;    // 链表头节点
		Node* tail;    // 链表尾节点
		size_t count;  // 链表元素计数

public:
		// 构造函数
		LinkedList() : head(nullptr), tail(nullptr), count(0) {}

		// 析构函数
		~LinkedList() {
				clear();
		}

		// 在链表头部添加元素
		void push_front(const T& value) {
				Node* newNode = new Node(value, head);
				head = newNode;
				if (tail == nullptr) {  // 如果链表为空
						tail = head;
				}
				count++;
		}

		// 在链表尾部添加元素
		void push_back(const T& value) {
				Node* newNode = new Node(value);
				if (tail == nullptr) {  // 如果链表为空
						head = tail = newNode;
				}
				else {
						tail->next = newNode;
						tail = newNode;
				}
				count++;
		}

		// 删除链表头部元素
		void pop_front() {
				if (head == nullptr) return;

				Node* temp = head;
				head = head->next;
				delete temp;
				count--;

				if (head == nullptr) {  // 如果删除后链表为空
						tail = nullptr;
				}
		}

		// 删除链表尾部元素
		void pop_back() {
				if (head == nullptr) return;

				if (head == tail) {  // 只有一个元素
						delete head;
						head = tail = nullptr;
				}
				else {
						Node* current = head;
						while (current->next != tail) {
								current = current->next;
						}
						delete tail;
						tail = current;
						tail->next = nullptr;
				}
				count--;
		}

		// 查找元素是否存在
		bool contains(const T& value) const {
				Node* current = head;
				while (current != nullptr) {
						if (current->data == value) {
								return true;
						}
						current = current->next;
				}
				return false;
		}

		// 获取链表大小
		size_t size() const {
				return count;
		}

		// 判断链表是否为空
		bool empty() const {
				return count == 0;
		}

		// 清空链表
		void clear() {
				while (head != nullptr) {
						Node* temp = head;
						head = head->next;
						delete temp;
				}
				tail = nullptr;
				count = 0;
		}

		// 打印链表内容（用于测试）
		void print() const {
				Node* current = head;
				while (current != nullptr) {
						std::cout << current->data;
						if (current->next != nullptr) {
								std::cout << " -> ";
						}
						current = current->next;
				}
				std::cout << std::endl;
		}

		// 迭代器类（简化版）
		class Iterator {
		private:
				Node* current;

		public:
				Iterator(Node* node) : current(node) {}

				Iterator& operator++() {
						current = current->next;
						return *this;
				}

				T& operator*() const {
						return current->data;
				}

				bool operator!=(const Iterator& other) const {
						return current != other.current;
				}
		};

		// 获取开始迭代器
		Iterator begin() const {
				return Iterator(head);
		}

		// 获取结束迭代器
		Iterator end() const {
				return Iterator(nullptr);
		}
};

// 测试代码
int main() {
		LinkedList<int> list;

		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_front(0);

		std::cout << "List contents: ";
		list.print();  // 输出: 0 -> 1 -> 2 -> 3

		std::cout << "Size: " << list.size() << std::endl;  // 输出: 4

		list.pop_front();
		list.pop_back();

		std::cout << "After pop operations: ";
		list.print();  // 输出: 1 -> 2

		std::cout << "Contains 2? " << (list.contains(2) ? "Yes" : "No") << std::endl;  // 输出: Yes

		// 使用迭代器遍历
		std::cout << "Using iterator: ";
		for (auto it = list.begin(); it != list.end(); ++it) {
				std::cout << *it << " ";
		}
		std::cout << std::endl;  // 输出: 1 2

		list.clear();
		std::cout << "After clear, empty? " << (list.empty() ? "Yes" : "No") << std::endl;  // 输出: Yes

		return 0;
}