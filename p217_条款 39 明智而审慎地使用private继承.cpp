/*
条款 39 明智而审慎地使用private继承
请记住：
	Private继承意味is-implemented-in-terms of(根据某物实现出)。它通常比复合(composition)
的级别低。但是当derived class需要访问protected base class的成员，或需要重新定义继承而来的
virtual函数时，这么设计是合理的。
	和复合(composition)不同，private继承可以造成empty base最优化。这对致力于"对象尺寸最小化"
的程序库开发者而言，可能很重要。
*/