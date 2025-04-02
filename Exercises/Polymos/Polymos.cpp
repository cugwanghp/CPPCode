#include <iostream>
#include <string>

int abs(int a)
{
    return (a>0 ? a : -a);
}

double abs(double a)
{
    return (a>0.0 ? a : -a);
}

class Person{
public:
    Person(const std::string& name, int age) : m_name(name), m_age(age) {}
    void print() const;
protected:
    std::string m_name;
    int         m_age;
};

class Player : public Person
{
public:
    Player(const std::string& name, int age, double score);
    void print() const;
    void game();

protected:
    double  m_score;
};

void Person::print() const
{
    std::cout << m_name << ", " << m_age;
}

Player::Player(const std::string& name, int age, double score) :
    Person(name, age), m_score(score)
{}

void Player::print() const
{
    std::cout << m_name << ", " << m_age << ", " << m_score;
}

void Player::game()
{
    m_score++;
}

int main()
{
    Person  p1(std::string("Zhang"), 18);
    Player  p2(std::string("Lee"), 20, 25.0);

    Person* ptr = &p1;  //ok
    ptr->print();
    std::cout << std::endl;

    ptr = &p2;  // ok?
    ptr->print();
//    ptr->game();    // ok?
//    std::cout << std::endl;

    return 0;

    int     a;
    double  b;

    std::cin >> a >> b;
    std::cout << abs(a) << std::endl;   //a-int, abs(int)
    std::cout << abs(b) << std::endl;   //b-double, abs(double)

    return 0;
}