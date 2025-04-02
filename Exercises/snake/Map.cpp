#include"Snake.h"

Map::Map() {
	m_score = 0;
	Empty empty;
	vector<Snake> column(10, empty);
	vector<vector<Snake>> row(10, column);
	m_map = row;
	
}

void Map::Fill_map(Head* head) {
	m_map[head->m_x][head->m_y] = *head;
	Body* ptr = head->m_next;
	while (ptr != nullptr) {
		m_map[ptr->m_x][ptr->m_y] = *ptr;
		ptr = ptr->m_next;
	}
}