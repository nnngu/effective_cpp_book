/*
条款 41 了解隐式接口和编译期多态
请记住：
	classes和templates都支持接口(interfaces)和多态(polymorphism)。
	对classes而言接口是显式的(explicit)，以函数签名为中心。多态则是通过virtual函数发生于运行期。
	对template参数而言，接口是隐式的(implicit)，奠基于有效表达式。多态则是通过template具现化
和函数重载解析(function overloading resolution)发生于编译期。
*/

class Widget {
public:
	Widget();
	virtual ~Widget();
	virtual std::size_t size() const;
	virtual void normalize();
	void swap(Widget& other);
};

void doProcessing(Widget& w)
{
	if(w.size() > 10 && w != someNastyWidget) {
		Widget temp(w);
		temp.normalize();
		temp.swap(w);
	}
}

