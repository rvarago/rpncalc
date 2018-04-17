// stack.hpp
// @author rvarago
#ifndef RVSTACK_HPP_
#define RVSTACK_HPP_

#include <stack>

namespace rpn
{

// Delegates to std::stack<T> but removes when pops
template<typename T>
class RVStack
{
public:
	void push(const T& elem)
	{
		data.push(elem);
	}	
	
	T pop()
	{
		T elem = data.top();
		data.pop();
		return elem;
	}
	
	std::size_t size()
	{
		return data.size();
	}
private:
	std::stack<T> data;
};

}

#endif // RVSTACK_HPP_
