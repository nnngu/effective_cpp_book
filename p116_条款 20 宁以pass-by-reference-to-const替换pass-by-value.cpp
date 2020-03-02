/*
条款 20 宁以pass-by-reference-to-const替换pass-by-value
请记住：
	尽量以pass-by-reference-to-const替换pass-by-value。前者通常比较高效，
并可避免切割问题(slicing problem)。
	以上规则并不适用于内置类型，以及STL的迭代器和函数对象。对它们而言，
pass-by-value往往比较适当。
*/