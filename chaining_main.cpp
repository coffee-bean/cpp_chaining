#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
using namespace std;

class Container
{
private:
	string m_str;
	int m_val;
	bool m_is_string;

public:
	Container(string m_str);
	Container(int m_val);

	Container chain(int m_val);
	operator string();
};

Container::Container(string str) : m_str(str), m_is_string(true)
{

}

Container::Container(int val) : m_val(val), m_is_string(false)
{

}

Container Container::chain(int val)
{
	assert(!m_is_string);
	if(m_val > val)
	{
		stringstream ss;
		ss<<"VAL: "<<m_val + val;
		return Container(ss.str());
	}
	else
	{
		return Container(m_val + val);
	}
}

Container::operator string()
{
	assert(m_is_string);
	return m_str;	
}
	
Container chain(int m_val)
{
	return Container(m_val);
}

void foo(string str)
{
	cout<<str<<endl;
}

int main()
{
	foo(chain(2).chain(5).chain(9).chain(1));
}
