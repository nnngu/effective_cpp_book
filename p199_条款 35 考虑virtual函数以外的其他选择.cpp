/*
条款 35 考虑virtual函数以外的其他选择
请记住：
	virtual函数的替代方案包括NVI手法及Strategy设计模式的多种形式。NVI手法自身是一个特殊形式的
Template Method设计模式。
	将机能从成员函数转移到class外部函数，带来的一个缺点是，非成员函数无法访问class的non-public
成员。
	tr1::funcion对象的行为就像一般函数指针。这样的对象可接纳"与给定之目标签名式(target signature)兼容"
的所有可调用物(callable entities)。
*/