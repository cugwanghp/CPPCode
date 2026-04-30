#pragma once

template<typename T>
class Array
{
public:
		Array(int size);
		Array(const Array<T>& ary);
		Array(Array<T>&& ary);
		~Array();
		Array& operator=(const Array<T>& ary);
		Array& operator=(Array<T>&& ary);	//

		T& operator[](int index);
		const T& operator[](int index) const;
private:
		T*		m_pdata;		//
		int			m_nsize;		//
};

template<typename T>
Array<T>::Array<T>(int size) : m_nsize(size)
{
		if (m_nsize < 0)	m_nsize = 0;
		m_pdata = new T[m_nsize];
}

template<typename T>
Array<T>::Array<T>(const Array<T>& ary) : m_nsize(ary.m_nsize)
{
		m_pdata = new T[m_nsize];
		for (int i = 0; i < m_nsize; ++i)
				m_pdata[i] = ary.m_pdata[i];
}

template<typename T>
Array<T>::Array<T>(Array<T>&& ary) : m_nsize(ary.m_nsize)
{
		m_pdata = ary.m_pdata;
		ary.m_pdata = nullptr;
		ary.m_nsize = 0;
}

template<typename T>
Array<T>::~Array()
{
		if (m_pdata)
		{
				delete[] m_pdata;
				m_pdata = nullptr;
		}
		m_nsize = 0;
}
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& ary)
{
		if (this != &ary)
		{
				//this->m_pdata
				int*		pdata = new T[ary.m_nsize];
				for (int i = 0; i < ary.m_nsize; ++i)
						pdata[i] = ary.m_pdata[i];
				if (m_pdata)
				{
						delete[] m_pdata;
				}
				m_pdata = pdata;
				m_nsize = ary.m_nsize;
		}
		return *this;
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T>&& ary)
{
		if (this != &ary)
		{
				if (m_pdata) delete[] m_pdata;
				m_pdata = ary.m_pdata;
				m_nsize = ary.m_nsize;
				ary.m_pdata = nullptr;
				ary.m_nsize = 0;
		}
		return *this;
}

template<typename T>
T& Array<T>::operator[](int index)
{
		return m_pdata[index];
}

template<typename T>
const T& Array<T>::operator[](int index) const
{
		return m_pdata[index];
}


template<typename T, int size=10>
class StaticArray {
public:

private:
		T		m_data[size];		//size 定义，常量表达式
		int	m_size;
};


template <typename T>
class Vector {
private:
		T* data;		//数组的首地址
		size_t capacity;		//容量，new T[]
		size_t size;		//数组实际的大小

		void resize(size_t new_capacity) {
				T* new_data = new T[new_capacity];
				for (size_t i = 0; i < size; ++i) {
						new_data[i] = data[i];
				}
				delete[] data;
				data = new_data;
				capacity = new_capacity;
		}

public:
		Vector() : data(nullptr), capacity(0), size(0) {}		//一般构造
		Vector(const Vector<T>& vec);		//复制构造
		Vector(Vector<T>&& vec);		//移动构造
		Vector<T>& operator=(const Vector<T>& vec);//赋值
		Vector<T>& operator=(Vector<T>&& vec);	//移动赋值
		~Vector() {	//析构函数
				if(data) delete[] data;	
		}

		void push_back(const T& value) {
				if (size >= capacity) {
						resize(capacity == 0 ? 1 : capacity * 2);
				}
				data[size++] = value;
		}

		void pop_back() {
				if (size > 0) {
						--size;
				}
		}

		T& operator[](size_t index) {
				return data[index];
		}

		const T& operator[](size_t index) const {
				return data[index];
		}

		size_t get_size() const {
				return size;
		}

		size_t get_capacity() const {
				return capacity;
		}

		bool empty() const {
				return size == 0;
		}

		void clear() {
				size = 0;
		}
};
#include <iostream> // 用于测试输出

template <typename T>
class SinglyLinkedList {
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
		SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

		// 析构函数
		~SinglyLinkedList() {
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
}

