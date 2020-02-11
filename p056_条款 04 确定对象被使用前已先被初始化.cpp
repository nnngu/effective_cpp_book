/*
条款04 确定对象被使用前已先被初始化
*/

// p057 通讯簿的 class
class PhoneNumber {};
class ABEntry {
public:
	ABEntry(const std::string& name, const std::string& address,
			const std::list<PhoneNumber>& phones);
private:
	std::string theName;
	std::string theAddress;
	std::list<PhoneNumber> thePhones;
	int numTimesConsulted;
};
ABEntry::ABEntry(const std::string& name, const std::string& address,
				const std::list<PhoneNumber>& phones)
{
	theName = name;
	theAddress = address;
	thePhones = phones;
	numTimesConsulted = 0; // 这些都是赋值，而不是初始化。
}

// 初始化应该这样写
ABEntry::ABEntry(const std::string& name, const std::string& address,
				const std::list<PhoneNumber>& phones)
:theName(name),
theAddress(address),
thePhones(phones),
numTimesConsulted(0) // 这些都是初始化
{ }

// 假如是无参的构造函数
ABEntry::ABEntry()
:theName(), // 调用 theName 的 default 构造函数
theAddress(),
thePhones(),
numTimesConsulted(0) // 记得将 numTimesConsulted 显式初始化为 0
{ }




















