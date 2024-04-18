#include <iostream>
template <typename... Args>
auto foldPrint(Args&&... args)
{
	std::cout << "The number of template arguments is: " << sizeof...(Args) << std::endl; // The number of template arguments is: 4
	std::cout << "The number of function arguments is: " << sizeof...(args) << std::endl; // The number of arguments is: 4

#if _HAS_CXX17
	// C++17折叠表达式对可变函数参数的处理
	std::cout << "The arguments are: " << "Args&&" << std::endl;
	std::stringstream ss;
	//(ss << ... << args) << std::endl; // The arguments are: 12helloc
	//(std::cout << ... << (std::cout << "[" << args, "]")) << std::endl;
	(ss << ... << (ss << "[" << args, "]")) << std::endl; //利用逗号展开 + 函数参数包展开
	return ss;
#endif
}

template <int... Args>
struct SumSquare
{
	using type = SumSquare<Args...>;
	static constexpr int value = (... + (Args * Args));
};

#include <sstream>
template <typename T, typename... Args>
auto print_csv(T&& t, Args&&... args)
{
	std::stringstream ss;
	ss << t << ",";
	if constexpr (sizeof...(args) > 0)
	{
		ss << print_csv(args...).str();
	}
	return ss;
}

// 变长参数模板函数，用于日志记录, c++11 逗号展开
template<typename... Args>
auto logMessage(const Args&... args) {
	std::ostringstream stream;
	using expander = int[];
	//(void)expander { 0, (void(stream << args << ", "), 0)... }; //ok
	(void)expander { (void(stream << args << ", "), 0)... }; //ok
	stream << std::endl;
	//std::cout << stream.str();
	return stream;
}