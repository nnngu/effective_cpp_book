/*
定义式(definition)的任务是提供编译器一些声明式所遗漏的细节。对对象而言，定义
式是编译器为此对象拨发内存的地点。对 function 或 function template 而言，
定义式提供了代码本体。对 class 或 class template 而言，定义式列出它们
的成员：
*/

int x; // 对象的定义式

std::size_t numDigits(int number) // 函数的定义式
{	// 此函数返回其参数的数字个数，
	std::size_t digitsSoFar = 1; // 例如十位数返回 2，百位数返回 3

	while((number /= 10) != 0) ++digitsSoFar;
	return digitsSoFar;
}

class Widget { // class 的定义式
public:
	Widget();
	~Widget();
	// ...
};

template<typename T> // template 的定义式
class GraphNode {
public:
	GraphNode();
	~GraphNode();
	// ...
};















