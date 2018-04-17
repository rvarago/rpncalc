#include "parser_builder.h"

namespace rpn
{

Parser make_parser()
{
	const std::unordered_map<std::string, Parser::BinaryOperation> operations = {
		{"+", [](const auto& first, const auto& second){return first + second;}},
		{"-", [](const auto& first, const auto& second){return first - second;}},
		{"*", [](const auto& first, const auto& second){return first * second;}},
		{"/", [](const auto& first, const auto& second){return first / second;}},
		{"^", [](const auto& first, const auto& second){return std::pow(first, second);}}
	};

	Parser parser;

	for(const auto& operation : operations)
	{
		parser.addOperation(operation.first, operation.second);
	}

	return parser;
}

}
