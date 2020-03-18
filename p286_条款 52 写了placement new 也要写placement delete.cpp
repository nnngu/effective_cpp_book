/*
条款 52 写了placement new 也要写placement delete
请记住：
	当你写一个placement operator new，请确定也写出了对应的placement operator delete。
如果没有这样做，你的程序可能会发生隐晦而时断时续的内存泄漏。
	当你声明placement new 和placement delete，请确定不要无意识(非故意)地遮掩了它们的
正常版本。
*/