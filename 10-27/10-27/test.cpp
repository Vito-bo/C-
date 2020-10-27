
#include<iostream>
using namespace std;

#if 0
//C++ΪʲôҪ�������һ�׶�̬�ڴ����ķ�ʽ
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
	Test t1(100);//����ù��캯��
	//malloc�����������ù��캯��
	Test* pt = (Test*)malloc(sizeof(Test));

	free(pt);
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int t = 0)
		: _t(t)
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
	Test* pt1 = new Test(100);//����ù��캯��
	Test* pt2 = (Test*)malloc(sizeof(Test));

	delete pt1;//�������������
	free(pt2);
	return 0;
}


int main()
{
	//���뵥�����͵Ŀռ�
	int* p1 = new int;
	int* p2 = new int(10); //������Ŀռ���г�ʼ��

	int arr[10];

	//����һ�������Ŀռ�
	int* p3 = new int[10];
	int* p4 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};//������������ռ���г�ʼ��

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;
	return 0;
}
#endif

#if 0
//�����������Ϳռ��������ͷ�
int main()
{
	int* p1 = (int*)malloc(sizeof(int)* 10);
	int* p2 = (int*)malloc(sizeof(int)* 10);

	int* p3 = new int;
	int* p4 = new int;

	int* p5 = new int[10];
	int* p6 = new int[10];

	delete p1;
	delete[] p2;

	free(p3);
	delete[] p4;

	free(p5);
	delete p6;

	// windows�ṩ��һ��api�������������м򵥵��ڴ�й©���
	//_CrtDumpMemoryLeaks();
	return 0;
}

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
		cout << "~Test()" << this << endl;
	}
private:
	int _t;
	int* _p;
};

int main()
{
	Test* p1 = (Test*)malloc(sizeof(Test)* 10);
	Test* p2 = (Test*)malloc(sizeof(Test)* 10);
	Test* p3 = new Test;
	Test* p4 = new Test;
	Test* p5 = new Test[10];
	Test* p6 = new Test[10];

	delete p1;
	delete[] p2;

	free(p3);
	delete[] p4;

	free(p5);
	delete p6;

	// windows�ṩ��һ��api�������������м򵥵��ڴ�й©���
	//_CrtDumpMemoryLeaks();
	return 0;
}
#endif

#if 0
void* operator new(size_t size, char* filename, char* funcname, size_t lineNo)
{
	cout << filename << "-" << funcname << "-" << lineNo << ":" << size << endl;
	return malloc(size);
}


#define new new(__FILE__, __FUNCDNAME__,__LINE__)
int main()
{
	int* p = new int;

	delete p;
	return 0;
}
#endif

class Test
{
public:
	Test(int t = 0)
		: _t(t)
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









