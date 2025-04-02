#include "Foo.h"

void* Foo::operator new(size_t size)
{
	Foo* p = (Foo*)malloc(size);
	cout << "Foo operator new" << endl;
	return p;
}

void Foo::operator delete(void* pdead, size_t size)
{
	cout << "Foo operator delete" << endl;
	free(pdead);
}

void* Foo::operator new[](size_t size)
{
	Foo* p = (Foo*)malloc(size);
	cout << "Foo operator new[]\n";
	return p;
}

void Foo::operator delete[](void* pdead, size_t size)
{
	cout << "Foo operator delete[]\n";
	free(pdead);
}
