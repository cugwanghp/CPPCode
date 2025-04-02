#include"Snake.h"

Head::Head() {
	m_x = 0;
	m_y = 0;
	m_direction = 1;
	m_speed = 1;
	m_next = new Body(this, nullptr);
}

void Head::eat() {
	Body* new_neck = new Body(this, m_next);
	new_neck->m_x = this->m_x;
	new_neck->m_y = this->m_y;
	m_next->m_last = new_neck;
	m_next = new_neck;
	
}

void Head::move(Map& map) {
	int temp_x = m_x;
	int temp_y = m_y;
	switch (m_direction) {
	case 1:
		m_x += m_speed;
		break;
	case 2:
		m_x -= m_speed;
		break;
	case 3:
		m_y += m_speed;
		break;
	case 4:
		m_y -= m_speed;
		break;
	}
	if (map.m_map[m_x][m_y].m_val == 1) {
		this->eat();
		map.m_map[m_x][m_y].m_val = 0;
	}
	else {
		Body* tail = m_next->findtail();
		while (tail->m_last != nullptr) {
			tail->m_x = tail->m_last->m_x;
			tail->m_y = tail->m_last->m_y;
			tail = tail->m_last;
		}
		m_next->m_x = temp_x;
		m_next->m_y = temp_y;
	}
}