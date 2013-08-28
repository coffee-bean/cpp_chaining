#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Container
{
private:
	string str;
	int val;
	bool is_string;

public:
	Container(string str);
	Container(int val);

	Container chain(int val);
	operator string();
};

Container::Container(string str) : str(str), is_string(true)
{

}

Container::Container(int val) : val(val), is_string(false)
{

}

Container Container::chain(int val)
{
	assert(!is_string);
	if(this->val > val)
	{
		return Container("Hello");
	}
	else
	{
		return Container(val+1);
	}
}

Container::operator string()
{
	assert(is_string);
	return str;	
}
	
Container chain(int val)
{
	return Container(val);
}

void foo(string str)
{
	cout<<str<<endl;
}

int main()
{
	foo(chain(2).chain(1));
}
