/*
条款 17 以独立语句将newed对象置入智能指针
请记住：
	以独立语句将newed对象存储于(置入)智能指针内。如果不这样做，一旦异常被抛出，
有可能导致难以察觉的资源泄露。
*/

// 不建议的写法：
processWidget(std::tr1::shared_ptr<Widget>(new Widget), priority()); // 不建议

// 建议如下写法：
std::tr1::shared_ptr<Widget> pw(new Widget);
processWidget(pw, priority());