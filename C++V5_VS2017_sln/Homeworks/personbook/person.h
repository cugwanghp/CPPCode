#pragma once

#include <iostream>
#include <string>
using namespace std;

class person{
public:
    // constructor
	person() = default;
    person(const string& name, const string& address);
    explicit person(istream& in) {read(in);}
	person(const person& p);
    ~person(){}
    
    // get,set methods
    inline string get_name() const {return m_strName;}
    inline string get_address() const {return m_strAddress;}
    void set_name(const string& name) {m_strName=name;}
    void set_address(const string& address) {m_strAddress=address;}
    	
    //IO函数
    istream& read(istream&);
    ostream& write(ostream&) const;
    
private:
    string    m_strName;
    string    m_strAddress;
};

//read, write
istream& operator>>(istream&, person&);
ostream& operator<<(ostream&, const person&);