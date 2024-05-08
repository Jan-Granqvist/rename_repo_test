#include <iostream>
#include <string>
#include <memory>

class Helper
{
	public:
		explicit Helper(const std::string input)
		: m_string(std::move(input)) {}
		~Helper()
		{
			std::cout << m_string << std::endl;
		}
	private:
		std::string	m_string;
};

int main(int argc, char **argv)
{
	std::unique_ptr<Helper>	helper = std::make_unique<Helper>(std::move("Hello world from helper!!"));
}
