#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>

namespace rpn
{

std::vector<std::string> splitBySpace(const std::string& text)
{
	std::vector<std::string> tokens;
	boost::split(tokens, text, [](const auto& it){return it == ' ';});
	return tokens;
}

template<typename T>
T getAndRemove(std::stack<T>& stack)
{
	const T el = stack.top();
	stack.pop();
	return el;
}

template<typename Token, typename BiFunction>
bool isOperator(const std::unordered_map<Token, BiFunction>& operations, const Token& token)
{
	return operations.find(token) != end(operations);
} 

double compute(const std::string& expression)
{
	const std::unordered_map<std::string, std::function<double(double, double)>> operations = {
		{"+", [](const auto& first, const auto& second){return first + second;}},
		{"-", [](const auto& first, const auto& second){return first - second;}},
		{"*", [](const auto& first, const auto& second){return first * second;}},
		{"/", [](const auto& first, const auto& second){return first / second;}}
	};

	const auto tokens = splitBySpace(expression);

	auto value = std::stod(tokens[0]);

	std::stack<double> operands;

	for(auto it = next(begin(tokens)); it != end(tokens); ++it )
	{
		const auto& token = *it;

		if(!isOperator(operations, token))
		{
			operands.push(std::stod(token));
		} 
		else
		{
			if(operands.empty())
			{
				throw std::invalid_argument("Expression: " + expression + " is ill-formed");
			} 
			else
			{
				const auto second = getAndRemove(operands);
				value = operations.at(token)(value, second);
			}
		}
	
	}

	return value;
}

}

int main(int argc, char **argv)
{
	std::cout << rpn::compute(argv[1]) << std::endl;
	return 0;
}
