/*
条款 31 将文件间的编译依存关系降至最低
请记住：
	支持"编译依存性最小化"的一般构想是：相依于声明式，不要相依于定义式。
基于此构想的两个手段是Handle classes和Interface classes。
	程序库头文件应该以"完全且仅有声明式"(full and declaration-only forms)的形式存在。
这种做法不论是否涉及templates都适用。
*/