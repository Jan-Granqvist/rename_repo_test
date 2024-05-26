#include <iostream>
#include <string>
#include <memory>

class BaseClass
{
	public:
		virtual const std::string &String () const = 0;
};

class Helper : public BaseClass
{
	public:
		explicit Helper(const std::string input)
		: m_string(std::move(input)) {}
		~Helper() {};
		const std::string &String () const override{
			return m_string;
		}
	private:
		std::string	m_string;
};

int main(int argc, char **argv)
{
	std::unique_ptr<BaseClass>	helper = std::make_unique<Helper>(std::move("Hello world from child::Helper!!"));
	std::cout << helper->String() << std::endl;
}
