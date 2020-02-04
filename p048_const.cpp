/*
const 语法虽然变化多端，但并不莫测高深。如果关键字 const 出现在星号左边，
表示被指物是常量；如果出现在星号右边，表示指针自身是常量；如果出现在星号两边，
表示被指物和指针两者都是常量。
*/


/*
STL 迭代器中 const 的使用
*/
std::vector<int> vec;

const std::vector<int>::iterator iter = vec.begin(); // iter 的作用像个 T* const
*iter = 10; // 没问题，改变 iter 所指物
++iter; // 错误，iter 是 const

std::vector<int>::const_iterator cIter = vec.begin(); // cIter 的作用像个 const T*
*cIter = 10; // 错误！ *cIter 是 const
++cIter; // 没问题，改变 cIter。