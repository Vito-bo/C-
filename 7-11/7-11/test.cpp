//ÿ��һ��7-11
//1.����������
#include <iostream>
#include <cmath>
//long long�������ؼ���ƴ�����ģ��������ܲ����㣬������һ��
typedef long long _sint64;
//�������������
class RationalNumber{
	bool m_infinate; //�������Ϊ��
	bool m_negative; //������
	_sint64 m_numerator; //���ӣ��������
	_sint64 m_denominator; //��ĸ
	_sint64 m_integer; //��������
	_sint64 m_numeratorAll; //��¼�����������ķ��ӣ������������
	_sint64 calcGCD(_sint64 a, _sint64 b); //�����Լ���ĺ���
public:
	RationalNumber(_sint64 numerator, _sint64 denominator); //���캯��
	RationalNumber operator+(RationalNumber const& o) const; //������������
	RationalNumber operator-(RationalNumber const& o) const;
	RationalNumber operator*(RationalNumber const& o) const;
	RationalNumber operator/(RationalNumber const& o) const;
	//��������������
	friend std::ostream &operator<<(std::ostream &os, RationalNumber const& o);
};
//��������ÿ��������ʵ��
_sint64 RationalNumber::calcGCD(_sint64 a, _sint64 b)
{
	if (b == 0)
	{
		return a;
	}
	//շת�����
	return calcGCD(b, a % b);
}
RationalNumber::RationalNumber(_sint64 numerator, _sint64 denominator)
{
	m_negative = false;
	m_infinate = false;
	//�����ĸΪ������
	if (denominator == 0)
	{
		m_infinate = true;
		return;
	}
	//��������д������Ϊ��ͨ�����������й�������У��п��ܳ��ַ��ӷ�ĸ��Ϊ���������
	if (numerator < 0)
	{
		m_negative = !m_negative;
	}
	if (denominator < 0)
	{
		m_negative = !m_negative;
	}
	//�������������ӡ���ĸ�����з�ĸҪ������������㣬���Բ����Ǹ��ģ���absȡ����ֵ������Ҫ����ԭֵ
	m_integer = numerator / denominator;
	m_numerator = numerator - m_integer * denominator;
	m_denominator = abs(denominator);
	//Լ�֣�ע�⴫���Ӻ����ķ��ӱ��������ģ���ĸ���洦�����
	if (m_numerator)
	{
		_sint64 maxtmp = calcGCD(abs(m_numerator), m_denominator);
		if (maxtmp)
		{
			m_numerator /= maxtmp;
			m_denominator /= maxtmp;
		}
	}
	//����Լ�ֺ�ٷ�����ķ��ӣ���Ϊ���������ǲ���Ҫ�������ֵģ����Ա����üٷ����ķ����㡣
	m_numeratorAll = m_numerator + m_integer * m_denominator;
}
//����Ϊ�����ļӼ��˳���ͳͳʹ��m_numeratorAll���ٷ����ķ��ӣ��������㡣
RationalNumber RationalNumber::operator+(RationalNumber const& o) const
{
	_sint64 numerator = (m_numeratorAll * o.m_denominator) +
		(o.m_numeratorAll * m_denominator);
	_sint64 denominator = m_denominator * o.m_denominator;
	return RationalNumber(numerator, denominator);
}
RationalNumber RationalNumber::operator-(RationalNumber const& o) const
{
	_sint64 numerator = (m_numeratorAll * o.m_denominator) -
		(o.m_numeratorAll * m_denominator);
	_sint64 denominator = m_denominator * o.m_denominator;
	return RationalNumber(numerator, denominator);
}
RationalNumber RationalNumber::operator*(RationalNumber const& o) const
{
	_sint64 numerator = m_numeratorAll * o.m_numeratorAll;
	_sint64 denominator = m_denominator * o.m_denominator;
	return RationalNumber(numerator, denominator);
}
RationalNumber RationalNumber::operator/(RationalNumber const& o) const
{
	_sint64 numerator = m_numeratorAll * o.m_denominator;
	_sint64 denominator = m_denominator * o.m_numeratorAll;
	return RationalNumber(numerator, denominator);
}
std::ostream &operator<<(std::ostream &os, RationalNumber const& o)
{
	//��ĸΪ0������Ͳ��ü�����
	if (o.m_infinate)
	{
		os << "Inf";
		return os;
	}
	//�����ͷ���Ϊ0�Ǹɴ����0��
	if (o.m_numerator == 0 && o.m_integer == 0)
	{
		os << "0";
		return os;
	}
	//������ӡ���ź͸���
	if (o.m_negative)
	{
		os << "(-";
	}
	//�������ʹ�����
	if (o.m_integer)
	{
		os << abs(o.m_integer);
		if (o.m_numerator) //����С�����оʹ���ո����
		{
			os << " ";
		}
	}
	//�з����ʹ��������ĸ�Ѿ�abs���ˣ�������Բ���
	if (o.m_numerator)
	{
		os << abs(o.m_numerator) << '/' << o.m_denominator;
	}
	//�����ĺ�������
	if (o.m_negative)
	{
		os << ")";
	}
	return os;
}
int main()
{
	_sint64 n1, d1, n2, d2;
	scanf("%lld/%lld %lld/%lld", &n1, &d1, &n2, &d2);
	RationalNumber rn1(n1, d1), rn2(n2, d2);
	//����+����ʹ�ú���ʱ��
	std::cout << rn1 << " + " << rn2 << " = " << rn1 + rn2 << '\n';
	std::cout << rn1 << " - " << rn2 << " = " << rn1 - rn2 << '\n';
	std::cout << rn1 << " * " << rn2 << " = " << rn1 * rn2 << '\n';
	std::cout << rn1 << " / " << rn2 << " = " << rn1 / rn2 << '\n';
	return 0;
}
//2.ǰ��ͺ���
#include <string>
#include <tuple>
#include <list>
#include <cstdio>
// ��n�Ľ׳�
long long factorial(int n)
{
	long long r = 1;
	for (int i = 1; i <= n; i++)
	{
		r *= i;
	}
	return r;
}
// �� n, m ����� C(n, m)
// ���� C(n, m) == C(n, n - m) ���ص㣬�������׵�
long long combination(int n, int m)
{
	int max = m > (n - m) ? m : (n - m);
	long long numerator = 1;
	for (int i = max + 1; i <= n; i++)
	{
		numerator *= i;
	}
	return numerator / factorial(n - max);
}
// ���������ͣ������� typedef ����
using PrePost = std::tuple<std::string, std::string>;
// ����һ������ǰ��+��������������ע�͵�ԭ��
// ��ÿ��������ǰ��+�����зֳ���
std::list<PrePost> splitSubTrees(std::string const& pre, std::string const& post)
{
	std::list<PrePost> list{};
	size_t preIdx = 1;
	size_t lastPost = 0;
	while (preIdx < pre.size())
	{
		char rootValue = pre[preIdx];
		size_t postIdx = post.find(rootValue);
		int countOfNode = postIdx - lastPost + 1;
		list.emplace_back(std::make_tuple(
			pre.substr(preIdx, countOfNode),
			post.substr(lastPost, countOfNode)
			)
			);
		preIdx += countOfNode;
		lastPost += countOfNode;
	}
	return list;
}
// �ݹ�����ÿһ��Ŀ����ԣ�ֱ������ֻʣһ������������
long long calculateNumOfPossibilities(int m,
	std::string const& pre,
	std::string const& post)
{
	if (pre.size() == 0 || pre.size() == 1) {
		return 1;
	}
	std::list<PrePost> subTrees = splitSubTrees(pre, post);
	long long result = combination(m, subTrees.size());
	for (PrePost const& prePost : subTrees)
	{
		result *= calculateNumOfPossibilities(m,
			std::get<0>(prePost),
			std::get<1>(prePost));
	}
	return result;
}

int main()
{
	int m;
	char pre[30];
	char post[30];
	while (scanf("%d %s %s", &m, pre, post) != EOF)
	{
		printf("%lld\n", calculateNumOfPossibilities(m, pre, post));
	}
	return 0;
}
