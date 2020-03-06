/*
条款 28 避免返回 handles 指向对象内部成分
请记住：
	避免返回handles(包括references、指针、迭代器)指向对象内部。遵守这个条款可增加封装性，
帮助const成员函数的行为像个const，并将发生"虚吊号码牌"(dangling handles)的
可能性将至最低。
*/