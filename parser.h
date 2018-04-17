// parser.h
// @author rvarago
#ifndef PARSER_H_
#define PARSER_H_

#include <algorithm>
#include <functional>
#include <unordered_map>
#include <stdexcept>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>

#include "rvstack.hpp"

namespace rpn
{

// Parse math expressions in the Reverse Polish Notation (RPN)
class Parser
{
public:
	typedef std::function<double(double, double)> BinaryOperation;
	
	void addOperation(const std::string& symbol, BinaryOperation operation);
	BinaryOperation getOperation(const std::string& symbol) const;
	bool isOperator(const std::string& symbol) const;
private:	
	std::unordered_map<std::string, BinaryOperation> operations;
};

double compute(const Parser& parser, const std::string& expression);

}

#endif // PARSER_H_
