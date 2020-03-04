/*
条款 25 考虑写出一个不抛异常的swap函数
请记住：
	当std::swap 对你的类型效率不高时，提供一个swap成员函数，并确定这个函数不抛出异常。
	如果你提供一个member swap，也该提供一个non-member swap用来调用前者。
对于classes(而非templates)，也请特化std::swap。
	调用swap时应针对std::swap使用using声明式，然后调用swap并且不带任何"命名空间修饰"。
	为"用户定义类型"进行std templates全特化是好的，但千万不要尝试在std内加入某些对std
而言全新的东西。
*/