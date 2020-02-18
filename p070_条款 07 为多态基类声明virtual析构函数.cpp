/*
条款 07 为多态基类声明virtual析构函数
	polymorphic(带多态性质的)base classes 应该声明一个virtual析构函数。如果class带有
任何virtual函数，它就应该拥有一个virtual析构函数。
	Classes的设计目的如果不是作为base classes使用，或不是为了具备多态性(polymorphically),
就不该声明virtual析构函数。
*/