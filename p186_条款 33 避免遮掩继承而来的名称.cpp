/*
条款 33 避免遮掩继承而来的名称
请记住：
	derived classes内的名称会遮掩base classes内的名称。在public继承下从来没有
人希望如此。
	为了让被遮掩的名称再见天日，可使用using声明式或转交函数(forwarding functions)。
*/