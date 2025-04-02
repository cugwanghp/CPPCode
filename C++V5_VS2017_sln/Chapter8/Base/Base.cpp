#include "Base.h"

ostream& operator<<(ostream& out, const Base& b)
{
	b.print();
	return out;
}