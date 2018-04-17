#include "parser.h"

namespace rpn
{

static std::vector<std::string> splitBySpace(const std::string& text)
{
	std::vector<std::string> tokens;
	boost::split(tokens, text, [](const auto& it){return it == ' ';});
	return tokens;
}

void Parser::addOperation(const std::string& symbol, BinaryOperation operation)
{
	operations[symbol] = operation;
}

Parser::BinaryOperation Parser::getOperation(const std::string& symbol) const
{
	return operations.at(symbol);	
}

bool Parser::isOperator(const std::string& symbol) const
{
	return operations.find(symbol) != end(operations);
} 

double compute(const Parser& parser, const std::string& expression)
{	
	RVStack<double> operands;

	for(const auto& token : splitBySpace(expression))
	{
		if(!parser.isOperator(token))
		{
			operands.push(std::stod(token));
		} 
		else
		{
			if(operands.size() < 2)
			{
				throw std::invalid_argument("Expression: " + expression + " is ill-formed");
			} 
			else
			{
				const auto second = operands.pop();
				const auto first = operands.pop();
				operands.push(parser.getOperation(token)(first, second));				
			}
		}
	
	}
	return operands.pop();
}

}
