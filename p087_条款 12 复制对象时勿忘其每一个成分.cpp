/*
条款 12 复制对象时勿忘其每一个成分
请记住：
	Copying函数应该确保复制"对象内的所有成员变量"及"所有base class 成分"。
	请不要尝试以某个copying函数实现另一个copying函数。应该将共同机能放进第三个函数中，
并由两个coping函数共同调用。
*/
void logCall(const std::string& funcName); // 制造一个log entry
class Customer {
public:
	Customer(const Customer& rhs);
	Customer& operator=(const Customer& rhs);
private:
	std::string name;
};

Customer::Customer(const Customer& rhs) : name(rhs.name) // 复制rhs的数据
{
	logCall("Customer copy constructor");
}
Customer& Customer::operator=(const Customer& rhs)
{
	logCall("Customer copy assignment operator");
	name = rhs.name; // 复制rhs的数据
	return *this;
}