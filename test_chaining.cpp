#include <iostream.h>
#include <string.h>
using namespace std;

class Container
{
	union
	{
		string str;
		int val;
	};
	bool is_val;

	Container(string str);
	Container(int val);

	Container chain(int val);
	operator string();
};

Container::Container(string str) : str(str), is_val(false)
{

}
Container::Container(int val) : val(val), is_val(true)
{

}

Container Container:chain(int val)
{
	if(this->val > val)
		return Container("Hello");
	else
		return Container(val+1);
}
	
Container chain(int val)
{
	return Container(val);
}

int main()
{
	cout<<chain(2).chain(1)<<endl;
}
