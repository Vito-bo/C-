#include <iostream>
using namespace std;

////C++�ļ�IO��
//
////ʹ���ļ�IO�����ı��������Ʒ�ʽ��ʾ��д�����ļ�
//struct ServerInfo
//{
//	char _ip[32];  // ip
//	int _port;     // �˿�
//};
//
//struct ConfigManager
//{
//public:
//	ConfigManager(const char* configfile = "server.config")
//		: _configfile(configfile)
//	{}
//
//	void WriteBin(const ServerInfo& info)
//	{
//		// ����ע��ʹ�ö����Ʒ�ʽ��д
//		ofstream ofs(_configfile, ifstream::in | ifstream::binary);
//		ofs.write((const char*)&info, sizeof(ServerInfo));
//		ofs.close();
//	}
//
//	void ReadBin(ServerInfo& info)
//	{
//		// ����ע��ʹ�ö����Ʒ�ʽ�򿪶�
//		ifstream ifs(_configfile, ifstream::out | ifstream::binary);
//		ifs.read((char*)&info, sizeof(ServerInfo));
//		ifs.close();
//	}
//
//	void WriteText(const ServerInfo& info)
//	{
//		// ����ᷢ��IO��д���α�C�������׾ͼ򵥶��ˣ�
//		// C ���Ե��Ȱ�����itoa��д
//		ofstream ofs(_configfile);
//		ofs << info._ip << endl;
//		ofs << info._port << endl;
//		ofs.close();
//	}
//	void ReadText(ServerInfo& info)
//	{
//		// ����ᷢ��IO�������α�C�������׾ͼ򵥶��ˣ�
//		// C ���Ե��ȶ��ַ�������atoi
//		ifstream ifs(_configfile);
//		ifs >> info._ip;
//		ifs >> info._port;
//		ifs.close();
//	}
//private:
//	string _configfile; // �����ļ�
//};
//int main()
//{
//	ConfigManager cfgMgr;
//	ServerInfo wtinfo;
//	ServerInfo rdinfo;
//	strcpy(wtinfo._ip, "127.0.0.1");
//	wtinfo._port = 80;
//	// �����ƶ�д
//	cfgMgr.WriteBin(wtinfo);
//	cfgMgr.ReadBin(rdinfo);
//	cout << rdinfo._ip << endl;
//	cout << rdinfo._port << endl;
//	// �ı���д
//	cfgMgr.WriteText(wtinfo);
//	cfgMgr.ReadText(rdinfo);
//	cout << rdinfo._ip << endl;
//	cout << rdinfo._port << endl;
//	return 0;
//}
#include<sstream>
int main()
{
	int a = 12345678;
	string sa;
	// ��һ�����α���ת��Ϊ�ַ������洢��string�������
	stringstream s;
	s << a;
	s >> sa;
	// ��stringstream�ײ����string�������ó�"",
	// ������ת��ʱ���Ὣ���ȫ���ۻ��ڵײ�string������
	//s.str("");
	s.clear(); // ���s, ����ջ�ת��ʧ��
	double d = 12.34;
	s << d;
	s >> sa;
	string sValue;
	sValue = s.str(); // str()����������stringsteam�й����string����
	cout << sValue << endl;
	return 0;
}

int main()
{
	stringstream sstream;
	// ������ַ������� sstream ��
	sstream << "first" << " " << "string,";
	sstream << " second string";
	cout << "strResult is: " << sstream.str() << endl;
	// ��� sstream
	sstream.str("");
	sstream << "third string";
	cout << "After clear, strResult is: " << sstream.str() << endl;
	return 0;
}