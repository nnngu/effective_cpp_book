/*
条款 14 在资源管理类中小心coping行为
请记住：
	复制 RAII 对象必须一并复制它所管理的资源，所以资源的 coping 行为决定
RAII 对象的 coping 行为。
	普遍而常见的 RAII class copying 行为是：抑制 coping、施行引用计数法
(reference counting)。不过其他行为也都可能被实现。
*/