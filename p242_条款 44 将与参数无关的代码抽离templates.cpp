/*
条款 44 将与参数无关的代码抽离templates
请记住：
	Templates生成多个classes和多个函数，所以任何template代码都不该与某个造成膨胀的
template参数产生相依关系。
	因非类型模板参数(non-type template parameters)而造成的代码膨胀，往往可消除，
做法是以函数参数或class成员变量替换template参数。
	因类型参数(type parameters)而造成的代码膨胀，往往可降低，做法是让带有完全相同
二进制表述(binary representations)的局限类型(instantiation types)共享实现码。
*/
template<typename T>
class SquareMatrixBase {
protected:
	SquareMatrixBase(std::size_t n, T* pMem)
	:size(n), pData(pMem) { }
	void setDataPtr(T* ptr) {pData = ptr;}
private:
	std::size_t size;
	T* pData;
};

template<typename T, std::size_t n>
class SquareMatrix: private SquareMatrixBase<T> {
public:
	SquareMatrix()
	: SquareMatrixBase<T>(n, data) { }
private:
	T data[n*n];
};

// 通过new来分配内存
template<typename T, std::size_t n>
class SquareMatrix: private SquareMatrixBase<T> {
public:
	SquareMatrix()
	: SquareMatrixBase<T>(n, 0),
	pData(new T[n*n])
	{
		this->setDataPtr(pData.get());
	}
private:
	boost::scoped_array<T> pData;
};

