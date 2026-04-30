#pragma once
template <typename T>
class Stack {
private:
		struct Node {
				T data;
				Node* next;

				Node(const T& val, Node* n = nullptr) : data(val), next(n) {}
		};

		Node* top_node;
		size_t stack_size;

public:
		Stack() : top_node(nullptr), stack_size(0) {}

		~Stack() {
				clear();
		}

		void push(const T& value) {
				top_node = new Node(value, top_node);
				++stack_size;
		}

		void pop() {
				if (top_node) {
						Node* temp = top_node;
						top_node = top_node->next;
						delete temp;
						--stack_size;
				}
		}

		T& top() {
				return top_node->data;
		}

		const T& top() const {
				return top_node->data;
		}

		size_t size() const {
				return stack_size;
		}

		bool empty() const {
				return stack_size == 0;
		}

		void clear() {
				while (top_node) {
						Node* temp = top_node;
						top_node = top_node->next;
						delete temp;
				}
				stack_size = 0;
		}
};

#include "LinkedList.hpp"
template<typename T>
class MyStack {
public:
		void push(const T& value) { m_list.push_front(value); }
		void pop() { m_list.pop_front(); }
		size_t size() { m_list.size(); }
		bool empty() { return m_list.empty(); }
private:
		LinkedList<T>		m_list;
};