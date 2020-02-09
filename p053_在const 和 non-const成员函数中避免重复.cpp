class TextBlock {
public:
	const char& operator[] (std::size_t position) const
	{
		// 边界检验(bounds checking)
		// 日志数据访问(log access data)
		// 检验数据完整性(verify data integrity)
		return text[position];
	}
	char& operator[](std::size_t position)
	{
		// 边界检验(bounds checking)
		// 日志数据访问(log access data)
		// 检验数据完整性(verify data integrity)
		return text[position];
	}
private:
	std::string text;
};


/*
令 non-const operator[]调用其 const 兄弟是一个避免代码重复的安全做法
*/
class TextBlock {
public:
	const char& operator[](std::size_t position) const // 一如既往
	{
		return text[position];
	}
	char& operator[](std::size_t position) // 现在只调用 const op[]
	{
		return 
			const_cast<char&>( // 将 op[]返回值的 const 转除
				static_cast<const TextBlock&>(*this) // 为*this 加上 const
					[position] // 调用 const op[]
			);
	}
};









