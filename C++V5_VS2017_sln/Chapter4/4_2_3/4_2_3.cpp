
int main()
{
	Something s1{ 1, 2.4 }; // calls Something(int, double)
	Something s2{ 1 }; // calls Something(int, double)
	Something s3{}; // calls Something(int, double)

	Something s4{ 2.4 }; // will not compile, as there's no constructor to handle Something(double)

	return 0;
}