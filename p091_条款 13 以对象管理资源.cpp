/*
条款 13 以对象管理资源
请记住：
	为防止资源泄露，请使用RAII对象，它们在构造函数中获得资源并在析构函数中释放资源。
	两个常被使用的RAII classes(RAII: Resource Acquisition Is Initialization 资源取得时机便是初始化时机) 
分别是tr1::shared_ptr和auto_ptr。前者通常是较佳选择，因为其copy行为比较直观。若选择auto_ptr，复制动作会使它(被复制物)指向null。
*/