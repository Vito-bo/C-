//stack��ģ��ʵ��
//��ջ�Ľӿ��п��Կ�����ջʵ����һ�������vector�����ʹ��vector��ȫ����ģ��ʵ��stack��
#include <iostream>
#include <vector>
using namespace std;

namespace Mystack
{
	template<class T>
	class stack
	{
	public:
		stack() {}

		void push(const T& x){
			_c.push_back(x);
		}

		void pop(){
			_c.pop_back();
		}

		T& top()const{
			return _c.back();
		}

		const T& top() const{
			return _c.back();
		}

		size_t size() const{
			return _c.size();
		}

		bool empty()const{
			return _c.empty();
		}

	private:
		vector<T> _c;
	};
}

//queue��ģ��ʵ��
//��Ϊqueue�ӿ��д���ͷɾ��β�壬����listģ��ʵ��queue
#include <list>
namespace Myqueue
{
	template<class T>
	class queue
	{
	public:
		queue(){}

		void push(const T& x){
			_c.push_back(x);
		}

		void pop(){
			_c.pop_front();
		}

		T& back(){
			return _c.front();
		}

		const T& back()const{
			return _c..front();
		}

		T& front(){
			return _c.front();
		}

		size_t size()const{
			return _c.size;
		}

		bool empty()const{
			return _c.empty();
		}
	private:
		list<T> _c;
	};
}