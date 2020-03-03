/*
条款 21 必须返回对象时，别妄想返回其reference
请记住：
	绝不要返回 pointer 或 reference 指向一个 local stack 对象，或返回 reference
指向一个 heap-allocated 对象，或返回 pointer 或 reference 指向一个 local static
对象而有可能同时需要多个这样的对象。 条款4已经为"在单线程环境中合理返回reference
指向一个 local static 对象" 提供了一份设计实例。
*/