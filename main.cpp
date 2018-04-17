#include "main.h"

double compute(const std::string& expression)
{
	rpn::Parser parser = rpn::make_parser();
	return rpn::compute(parser, expression);
}

int main(int argc, char **argv)
{
	std::cout << compute(argv[1]) << std::endl;
	return 0;
}
