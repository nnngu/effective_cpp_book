/*
条款 24 若所有参数皆需类型转换，请为此采用non-member函数
请记住：
	如果你需要为某个函数的所有参数(包括被this指针所指的那个隐喻参数)进行类型转换，
那么这个函数必须是个non-member。
*/

class Rational {
public:
	Rational(int numerator = 0, int denominator = 1);
	const Rational operator* (const Rational& rhs) const;
};

// ---------正确的做法如下-----------
class Rational {
	... // 不包括operator*
};
const Rational operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.numerator() * rhs.numerator(),
					lhs.denominator() * lhs.denominator());
}
Rational oneFourth(1,4);
Rational result;
result = oneFourth * 2; //没问题
result = 2 * oneFourth; // 也没问题
