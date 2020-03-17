/*
条款 49 了解new-handler的行为
请记住：
	set_new_handler允许客户制定一个函数，在内存分配无法获得满足时被调用。
	Nothrow new是一个颇为局限的工具，因为它只适用于内存分配；后继的构造函数调用还是可能抛出异常。
*/

class NewHandlerHolder {
public:
	explict NewHandlerHolder(std::new_handler nh)
	: handler(nh) {}

	~NewHandlerHolder()
	{std::set_new_handler(handler);}
private:
	std::new_handler handler;
	NewHandlerHolder(const NewHandlerHolder&);
	NewHandlerHolder&
		operator=(const NewHandlerHolder&);
};

void* Widget::operator new(std::size_t size) throw(std::bad_alloc)
{
	NewHandlerHolder h(std::set_new_handler(currentHandler));
	return ::operator new(size);
}

void outOfMem();
Widget::set_new_handler(outOfMem);
Widget* pw1 = new Widget;
std::string* ps = new std::string;
Widget::set_new_handler(0);
Widget* pw2 = new Widget;

// ------------mixin风格的base class--------------

template<typename T>
class NewHandlerSupport {
public:
	static std::new_handler set_new_handler(std::new_handler p) throw();
	static void* operator new(std::size_t size) throw(std::bad_alloc);
	...
private:
	static std::new_handler currentHandler;
};
template<typename T>
std::new_handler
NewHandlerSupport<T>::set_new_handler(std::new_handler p) throw()
{
	std::new_handler oldHandler = currentHandler;
	currentHandler = p;
	return oldHandler;
}
template<typename T>
void* NewHandlerSupport<T>::operator new(std::size_t size)
throw(std::bad_alloc)
{
	NewHandlerHolder h(std::set_new_handler(currentHandler));
	return ::operator new(size);
}

template<typename T>
std::new_handler NewHandlerSupport<T>::currentHandler = 0;