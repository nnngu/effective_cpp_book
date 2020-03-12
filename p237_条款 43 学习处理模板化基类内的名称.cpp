/*
条款 43 学习处理模板化基类内的名称

*/
class CompanyA {
public:
	void sendCleartext(const std::string& msg);
	void sendEncryted(const std::string& msg);
};
class CompanyB {
public:
	void sendCleartext(const std::string& msg);
	void sendEncryted(const std::string& msg);
};
class MsgInfo {};

template<typename Company>
class MsgSender {
public:
	... // 构造函数、析构函数等等。
	void sendClear(const MsgInfo& info)
	{
		std::string msg;
		Company c;
		c.sendCleartext(msg);
	}
	void sendSecret(const MsgInfo& info)
	{}
};

// -------------------------

class CompanyZ {
public:
	...
	void sendEncryted(const std::string& msg);
	...
};






