/*
条款 47 请使用traits classes表现类型信息
请记住：
	Traits classes 使得"类型相关信息"在编译期可用。它们以templates和"templates特化"完成实现。
	整合重载技术(overloading)后，traits classes有可能在编译期对类型执行if...else测试。
*/

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag: public input_iterator_tag {};
struct bidirectional_iterator_tag: public forward_iterator_tag {};
struct random_access_iterator_tag: public bidirectional_iterator_tag {};

// -----------deque迭代器-------------
template<...>
class deque {
public:
	class iterator {
	public:
		typedef random_access_iterator_tag iterator_category;
		...
	};
	...
};

// -----------list迭代器-------------
template<...>
class list {
public:
	class iterator {
	public:
		typedef bidirectional_iterator_tag iterator_category;
		...
	};
	...
};

// --------------重载doAdvance------------------
template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d,
				std::random_access_iterator_tag) 
{
	iter += d;
}

template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d,
				std::bidirectional_iterator_tag)
{
	if (d >= 0)
	{
		while (d--) ++iter;
	}
	else
	{
		while (d++) --iter;
	}
}

template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d,
				std::input_iterator_tag)
{
	if (d<0)
	{
		throw std::out_of_range("Negative distance");
	}
	while (d--) ++iter;
}
