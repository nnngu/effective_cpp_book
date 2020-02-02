class A {
public:
	A(); // default 构造函数
};

class B {
public:
	explicit B(int x = 0, bool b = true); // default 构造函数
}

class C {
public:
	explicit C(int x); // 不是 default 构造函数
};

/*
	上述的 classes B 和 C 的构造函数都被声明为 explicit，这可阻止它们被用来
执行隐式类型转换(implicit type conversions)，但它们仍可被用来进行显式类型转换
(explicit type conversions)。
*/

void doSomething(B bObject); // 函数，接受一个类型为 B 的对象

B bObj1; // 一个类型为 B 的对象
doSomething(bObj1); // 没问题，传递一个 B 给 doSomething 函数
B bObj2(28); // 没问题，根据 int28 建立一个 B
			 // (函数的 bool 参数缺省为 true)
doSomething(28); // 错误！doSomething() 函数应该接受一个 B 对象，
				 // 不是一个 int，而 int 至 B 之间并没有隐式转换
doSomething(B(28)); // 没问题，使用 B 构造函数将 int 显示转换
					// (也就是转型，cast)为一个 B 以促成此一调用.
					// (条款 27 对转型谈的更多)

/*
被声明为 explicit 的构造函数通常比其 non-explici 兄弟更受欢迎，因为它们禁止
编译器执行非预期(往往也不被期望)的类型转换。除非我有一个好理由允许构造函数被用于
隐式类型转换，否则我会把它声明为 explicit。我鼓励你遵循相同的政策。
*/






















