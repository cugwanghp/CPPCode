#include"Snake.h"

//¹¹Ôìº¯Êý
Body::Body(Body* last, Body* next) {
	m_head = nullptr;
	m_last = last;
	m_next = next;
	m_x = 0;
	m_y = 0;
}
Body::Body(Head* head, Body* next) {
	m_head = head;
	m_last = nullptr;
	m_next = next;
	m_x = 0;
	m_y = 0;
}

Body* Body::findtail() {
	if (m_next == nullptr) {
		return this;
	}
	else {
		return m_next->findtail();
	}
}

void Body::add() {

}