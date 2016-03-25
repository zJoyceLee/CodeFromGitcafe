#pragma once
//Current Project
#include "Assistance.hpp"
#include "Node.hpp"

// 链栈类
template<typename T>
class LinkStack {
protected:
//  链栈的数据成员:
	Node<T> * top;							// 栈顶指针

public:
//  链栈的函数成员:
	LinkStack();									// 无参数的构造函数
	virtual ~LinkStack();							// 析构函数
	int GetLength() const;							// 求栈长度
	bool isEmpty() const;							// 判断栈是否为空
	void Clear();									// 将栈清空
	void Traverse(void (*Visit)(const T &)) const ;	// 遍历栈
	Status Push(const T e);					// 入栈
	Status Top(T & e) const;					// 返回栈顶元素
	Status Pop(T & e);						// 出栈
	LinkStack(const LinkStack<T> & s);		// 复制构造函数
	LinkStack<T> & operator =(const LinkStack<T> & s); // 赋值语句重载
};


// 链栈类的实现部分
template<typename T>
LinkStack<T>::LinkStack()
// 操作结果：构造一个空栈表
{
	top = nullptr;
}

template<typename T>
LinkStack<T>::~LinkStack()
// 操作结果：销毁栈
{
	Clear();
}

template <typename T>
int LinkStack<T>::GetLength() const
// 操作结果：返回栈元素个数
{
	int count = 0;		// 计数器
	Node<T> *p;
	for (p = top; p != nullptr; p = p->next)		// 用p依次搜寻每个元素
		count++;		// 统计链栈中结点数
	return count;
}

template<typename T>
bool LinkStack<T>::isEmpty() const
// 操作结果：如栈为空，则返回true，否则返回false
{
	return top == nullptr;
}

template<typename T>
void LinkStack<T>::Clear()
// 操作结果：清空栈
{
	Node<T> *p;
	while (top != nullptr) {
		p = top;
		top = top->next;
		delete p;
	}
}

template <typename T>
void LinkStack<T>::Traverse(void (*Visit)(const T & )) const
// 操作结果：从栈顶到栈底依次对栈的每个元素调用函数(*visit)访问
{
	Node<T> *p;
	for (p = top; p != nullptr; p = p->next)	// 用p依次搜寻当前栈的每个元素
		(*Visit)(p->data);		// 对p所指向的元素调用函数(*visit)访问
}

template<typename T>
Status LinkStack<T>::Push(const T e)
// 操作结果：将元素e追加到栈顶,如成功则返加SUCCESS,否则如动态内存已耗尽
//	将返回OVER_FLOW
{
	Node<T> *p = new Node<T>(e, top);
	if (p == nullptr) 	// 系统内存耗尽
		return OVER_FLOW;
	else	{	// 操作成功
		top = p;
		return SUCCESS;
	}
}

template<typename T>
Status LinkStack<T>::Top(T & e) const
// 操作结果：如栈非空,用e返回栈顶元素,函数返回SUCCESS,否则函数返回UNDER_FLOW
{
	if(isEmpty())	// 栈空
		return UNDER_FLOW;
	else	{	// 栈非空,操作成功
		e = top->data;				// 用e返回栈顶元素
		return SUCCESS;
	}
}

template<typename T>
Status LinkStack<T>::Pop(T & e)
// 操作结果：如栈非空,删除栈顶元素,并用e返回栈顶元素,函数返回SUCCESS,否则
//	函数返回UNDER_FLOW
{
	if (isEmpty())	// 栈空
		return UNDER_FLOW;
	else	{	// 操作成功
		Node<T> *p = top;	// 保留原栈顶
		e = top->data;				// 用e返回栈顶元素
		top = top->next;			// 修改栈顶
		delete p;					// 删除原栈顶结点
		return SUCCESS;
	}
}

template<typename T>
LinkStack<T>::LinkStack(const LinkStack<T> & s)
// 操作结果：由栈s构造新栈--复制构造函数
{
	if (s.isEmpty()) {	// s为空
		top = nullptr;									// 构造一空栈
	} else {	                                    // s非空,复制栈
		top = new Node<T>(s.top->data);	// 生成当前栈项
		Node<T> *q = top;			        // 设置当前栈底指针
		for (Node<T> *p = s.top->next; p != nullptr; p = p->next) {
			q->next = new Node<T>(p->data); // 向栈底追加元素
			q = q->next;					       // 修改栈底指针
		}
	}
}

template<typename T>
LinkStack<T> & LinkStack<T>::operator = (const LinkStack<T> & s)
// 操作结果：将栈s赋值给当前栈--赋值语句重载
{
	if (& s != this) {
		Clear();			// 清空当前栈
   		if (!s.isEmpty()) {	                            // s非空,复制栈
			top = new Node<T>(s.top->data);       // 生成当前栈项
			Node<T> *q = top;			            // 设置当前栈底指针
			for (Node<T> *p = s.top->next; p != nullptr; p = p->next) {
                q->next = new Node<T>(p->data);      // 向栈底追加元素
				q = q->next;			                    // 修改栈底指针
			}
		}
	}
	return *this;
}
