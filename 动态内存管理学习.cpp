
#include <iostream>
using namespace std;


#if 0
// C++Ϊʲô����ʹ��C�����еĶ�̬�ڴ����ʽ
class Test
{
public:
	Test(int t = 0)
		:_t(t)
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
};
int main()
{
	//Test t1(10);

	// mallocû�е��ù��캯��
	Test* pt = (Test*)malloc(sizeof(Test));
	
	// freeû�е�����������������Դ
	free(pt);
	return 0;
}
#endif



// new  ��  malloc ��C++�еĹؼ��֣�Ҳ���Գ�Ϊ ������
int main()
{
	// ���뵥������
	int* p1 = new int;
	int* p2 = new int(10); //������Ŀռ���г�ʼ��

	int array[10];  // new ֮��ֱ�Ӹ��ľ��Ƕ��������
	// ����һ�������Ŀռ�
	int* p3 = new int[10];
	int* p4 = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	delete p1;
	delete p2;

	delete[] p3;
	delete[] p4;

	return 0;
}

#if 0
class Test
{
public:
	Test(int t = 0)
		:_t(t)
	{
		cout << "Test(int):" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
};

int main()
{   
	// new ����ù��캯��
	Test* pt1 = new Test(10);
	Test* pt2 = (Test*)malloc(sizeof(Test));

	// delete�������������
	delete pt1;
	free(pt2);
	return 0;
}
#endif

#if 0
// �����������Ϳռ��������ͷţ�new/delete  new[]/delete[] malloc/free
// ƥ������ʹ�ã�Ҳ�������κε�����---�Ȳ������Ҳ���ᷢ���ڴ�й©
// ���ǣ�ע��һ��Ҫ�����ո��ַ�ʽʹ��
int main()
{
	int* p1 = (int*)malloc(sizeof(int)* 10);
	int* p2 = (int*)malloc(sizeof(int)* 10);

	delete p1;
	delete[] p2;

	int* p3 = new int;
	int* p4 = new int;

	free(p3);
	delete[] p4;

	// windows�ṩ��һ��api�������������м򵥵��ڴ�й©���
	_CrtDumpMemoryLeaks();

	return 0;
}
#endif
#if 0
class Test
{
public:
	Test(int t = 0)
		:_t(t)
		, _p(new int)
	{
		cout << "Test(int):" << this << endl;
	}

	~Test()
	{
		delete _p;
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
	int* _p;
};

int main()
{
	//Test* p1 = (Test*)malloc(sizeof(Test)* 10);
	//Test* p2 = (Test*)malloc(sizeof(int)* 10);
	Test* p3 = new Test;
	//Test* p4 = new Test[];

	//delete p1;
	//delete[] p2;
	//free(p3);
	//delete[] p4;

	// windows�ṩ��һ��api�������������м򵥵��ڴ�й©���
	_CrtDumpMemoryLeaks();

	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int t = 0)
		:_t(t)
		, _p(new int)
	{
		cout << "Test(int):" << this << endl;
	}

	/*~Test()
	{
		delete _p;
		cout << "~Test()" << this << endl;
	}*/
private:
	int _t;
	int* _p;
};
int main()
{
	Test* pt = new Test[10];
	// �����Զ������ͻ�����Լ��Ĺ��캯�����г�ʼ������������������������
	delete[] pt;

	return 0;
}
#endif

#if 0
// ���� new
void* operator new(size_t size, char* filename, char* funcname, size_t lineNo)
{
	cout << filename << "-" << funcname << "-" << lineNo << ":" << size << endl;
	return malloc(size);
}

#define new new(__FILE__, __FUNCDNAME__, __LINE__)

int main()
{
	int* p = new int;
	delete p;
	return 0;
}
#endif


#if 0
class Test
{
public:
	Test(int t = 0)
		:_t(t)
		, _p(new int)
	{
		cout << "Test(int):" << this << endl;
	}

	~Test()
	{
		delete _p;
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
	int* _p;
};
int main()
{
	// ע�⣺malloc��������Ŀռ䲻�ܽ������Ϊ����
	// ��Ϊ��malloc������ռ��ڼ䲻����ù��캯��
	Test* pt = (Test*)malloc(sizeof(Test));

	// ������Ҫ��ptָ��Ķѿռ���һ������
	// ����ܹ���ptָ��Ŀռ���ִ�й��캯������

	// placement-new ��λnew���ʽ
	// ���Ѿ����ٺõĿռ���ִ�й��캯��
	new(pt)Test(100);

	pt->~Test();
	free(pt);
	return 0;
}
#endif
