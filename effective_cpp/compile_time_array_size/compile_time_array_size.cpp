#include <iostream>
#include <array>

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
	return N;
}

int main(int argc, char** argv)
{
	const char name[] = "My name is Zhonghua Xi";	

	std::cout<<"size of name = "<<arraySize(name)<<std::endl;

	std::array<char, arraySize(name)> new_name;

	std::cout<<"size of new_name = "<<new_name.size()<<std::endl;	


	return 0;
}