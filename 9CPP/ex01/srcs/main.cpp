#include <iostream>
#include <string>
#include <stack>

class InvalidOperationException : public std::exception {
  public:
	virtual const char* what() const throw();
};
const char* InvalidOperationException::what() const throw() {
	return "Error";
}

bool isSign(char ch) {
	if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
		return true;
	else
		return false;
}

void checkSyntax(std::string& operation) {
	size_t numbers = 0;
	size_t sign = 0;

	for (size_t i = 0; i < operation.size(); i++)
	{
		if (i % 2 && operation[i] != ' ') {
			throw InvalidOperationException();
		} else if (i % 2 == 0 && (!isdigit(operation[i]) && !isSign(operation[i]))) {
			throw InvalidOperationException();
		} else if (isSign(operation[i]) && i < 4) {
			throw InvalidOperationException();
		} else if (isSign(operation[i])) {
			sign++;
		} else if (isdigit(operation[i])) {
			numbers++;
		}
	}

	if (numbers < 2 || numbers - 1 != sign)
		throw InvalidOperationException();
}

int doMath(std::stack<int>& stack, char sign) {
	int first_nbr = stack.top();
	stack.pop();
	int second_nbr = stack.top();
	stack.pop();
	switch (sign)
	{
	  case '-':
		return second_nbr - first_nbr;

	  case '+':
		return second_nbr + first_nbr;

	  case '*':
		return second_nbr * first_nbr;

	  case '/':
		return second_nbr / first_nbr;
	}

	return 0;
}

void rpn(std::string& operation) {
	std::stack<int> stack;

	for (size_t i = 0; i < operation.size(); i += 2)
	{
		if (!isSign(operation[i])) {
			stack.push(operation[i] - '0');
		} else {
			stack.push(doMath(stack, operation[i]));
		}
	}
	std::cout << stack.top() << std::endl;
}

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		std::cerr << "Invalid argument number" << std::endl;
		return 1;
	}

	std::string operation(argv[1]);
	try
	{
		checkSyntax(operation);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	rpn(operation);

	return 0;
}
