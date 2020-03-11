/*
条款 37 绝不重新定义继承而来的缺省参数值
请记住：
	绝对不要重新定义一个继承而来的缺省参数值，因为缺省参数值都是静态绑定，而virtual函数--你唯一
应该覆写的东西--却是动态绑定。
*/

class Shape {
public:
	enum ShapeColor {Red, Green, Blue};
	virtual void draw(ShapeColor color = Red) const = 0;
};

class Rectangle:public Shape {
public:
	virtual void draw(ShapeColor color = Green) const;
};

class Circle:public Shape {
public:
	virtual void draw(ShapeColor color) const;
};

//-----------------------------------------

class Shape {
public:
	enum ShapeColor {Red, Green, Blue};
	virtual void draw(ShapeColor color = Red) const = 0;
};

class Rectangle:public Shape {
public:
	virtual void draw(ShapeColor color = Red) const;
};

// ---------------------------------

class Shape {
public:
	enum ShapeColor {Red, Green, Blue};
	void draw(ShapeColor color = Red) const
	{
		doDraw(color);
	}
private:
	virtual void doRraw(ShapeColor color) const = 0;
};

class Rectangle:public Shape {
public:
	//...
private:
	virtual void doDraw(ShapeColor color) const;
};