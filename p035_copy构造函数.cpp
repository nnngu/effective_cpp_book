/*
copy 构造函数被用来"以同型对象初始化自我对象"，copy assignment 操作符被用来
"从另一个同型对象中拷贝其值到自我对象"；
*/
class Widget {
public:
	Widget(); // default 构造函数
	Widget(const Widget& rhs); // copy 构造函数
	Widget& operator=(const Widget& rhs); // copy assignment 操作符
	// ...
};
Widget w1; // 调用 default 构造函数
Widget w2(w1); // 调用 copy 构造函数
w1 = w2; // 调用 copy assignment 操作符

/*
"="语法也可用来调用 copy 构造函数
*/
Widget w3 = w2; // 调用 copy 构造函数!














