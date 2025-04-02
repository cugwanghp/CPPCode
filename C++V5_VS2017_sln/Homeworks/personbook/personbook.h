#include "person.h"
#include <vector>
using namespace std;

class personbook{
public:
	personbook()=default;
	~personbook();
	
	bool add(const person& p);
	bool del(int index);
	bool mod(int index, const person& p);
	void clear();
	void list() const;
private:
	vector<person>	m_vecPersons;
};