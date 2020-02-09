class CTextBlock {
public:
	char& operator[](std::size_t position) const // bitwise const 声明，
	{
		return pText[position]; // 但其实不适当.
	}
private:
	char* pText;
};


/*
例如你的 CTextBlock class 有可能高速缓存(cache)文本区块的长度以便应付询问：
*/
class CTextBlock {
public:
	std::size_t length() const;
private:
	char* pText;
	std::size_t textLength;
	bool lengthIsValid;
};
std::size_t CTextBlock::length() const
{
	if(!lengthIsValid) {
		textLength = std::strlen(pText); //错误！在 const 成员函数内不能赋值给 textLength 和 lengthIsValid。
		lengthIsValid = true;
	}
	return textLength;
}


/*
坚持 bitwise const 的办法：
利用 C++的一个与 const 相关的摆动场：mutable(可变的)。
mutable 释放掉 non-static 成员变量的 bitwise const 约束：
*/
class CTextBlock {
public:
	std::size_t length() const;
private:
	char* pText;
	mutable std::size_t textLength; // 这些成员变量可能总是
	mutable bool lengthIsValid; // 会被更改，即使在 const 成员函数内。
};
std::size_t CTextBlock::length() const
{
	if (!lengthIsValid)
	{
		textLength = std::strlen(pText); // 现在，可以这样，
		lengthIsValid = true; // 也可以这样.
	}
	return textLength;
}


















