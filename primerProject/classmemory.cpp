
#include "stdafx.h"
#include "classmemory.h"

//using namespace std;
int stringbad::num_strings = 0;//这是个坑，静态类成员引用前要加上 类名称：：，并且要在外面初始化
stringbad::stringbad()
{
	len = 0;
	str = new char[len + 1];
	//strcpy_s(str, len, "c++");
	str[0] = '\0';
	stringbad::num_strings++;
	cout << "初始化 " << stringbad::num_strings << endl;
}

stringbad::stringbad(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	//std::strcpy(str, s);
	//std::strncpy(str, s, len);
	strcpy_s(str, len + 1, s);


	stringbad::num_strings++;

	cout << "设置值 " << stringbad::num_strings << endl;
}
stringbad::stringbad(const stringbad & s)//复制构造函数 一个坑 构造函数里用了new 就要写这个函数 也要new
{
	//*this = s;
	len = s.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s.str);

	stringbad::num_strings++;
	cout << "复制值 " << stringbad::num_strings << endl;
}
stringbad::~stringbad()
{
	stringbad::num_strings--;
	cout << "删除时 " << str << " " << stringbad::num_strings << endl;
	delete[] str;
}
int stringbad::howmanay()
{
	return stringbad::num_strings;
}
stringbad & stringbad::operator=(const stringbad & s)
{
	if (this == &s)
		return *this;
	delete[] str;

	this->len = s.len;
	this->str = new char[this->len + 1];
	strcpy_s(this->str, this->len + 1, s.str);
	//this->num_strings++;

	//cout << "赋值1 " << str << " " << stringbad::num_strings << endl;
	return *this;
}

stringbad & stringbad::operator=(const char * ch)
{
	delete[] str;
	this->len = std::strlen(ch);
	this->str = new char[this->len + 1];
	strcpy_s(this->str, this->len + 1, ch);
	//stringbad::num_strings++;

	//cout << "赋值2 " << str << " " << stringbad::num_strings << endl;
	return *this;
}

char & stringbad::operator[](int i)
{
	return this->str[i];
}
const char & stringbad::operator[](int i) const
{
	return this->str[i];
}

bool operator<(const stringbad & a, const stringbad & b)
{
	return (std::strcmp(a.str, b.str) < 0);
}
bool operator>(const stringbad & a, const stringbad & b)
{
	return (std::strcmp(a.str, b.str) > 0);
}
bool operator==(const stringbad & a, const stringbad & b)
{
	return (std::strcmp(a.str, b.str) == 0);
}

std::ostream & operator<<(std::ostream & os, const stringbad & st)
{
	os<< st.str << endl;
	return os;
}
std::istream & operator>>(std::istream & is, stringbad & st)
{
	char temp[stringbad::CINLIM];
	is.get(temp, stringbad::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}
void callme1(stringbad & rs)
{
	cout << "Call1 输出结果 " << rs;
}
void callme2(stringbad rs)
{
	cout << "Call2 输出结果 " << rs;
}

void xiti12()
{
	xiticlassputr();
	class_fifo();
	return;
	stringbad name;
	cout << "Your name is" << endl;
	cin >> name;
	cout << name << ",please enter " << ArSize << " line to quit" << endl;
	cin.clear();
	stringbad sayings[ArSize];
	char temp[Maxlen];
	int i = 0;
	for (i = 0; i < ArSize;i++)
	{
		cout << i + 1 << "：";
		cin.get(temp, Maxlen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;
	if (total > 0)
	{
		cout << "here are you sayings:\n";
		for (i = 0;i <total;i++)
		{
			cout << sayings[i] << endl;
		}

		stringbad * shorttest = &sayings[0];
		stringbad * first = &sayings[0];
		for (i = 0; i < total; i++)
		{
			if (sayings[i].length() < shorttest->length())
				shorttest = &sayings[i];
			if (sayings[i] < *first)
				first = &sayings[i];
		}
		cout << "shorttest ==" << shorttest << endl;
		cout << "first ==" << first << endl;
		srand(time(NULL));
		int choice = rand() % total;
		stringbad * favorite = new stringbad(sayings[choice]);
		cout <<"sayings[choice]==="<< sayings[choice]<< "  choice =="<< choice<<"  favorite ==" << favorite <<"  *favorite =="<< *favorite << endl;
		delete favorite;
	}
	else
		cout << "no much to say" << endl;
	cout << "bye bye \n";
	return;

	stringbad c1, c2;
	c2 = "aabbcc";
	c1 = c2;
	cout << c1 << " " << c2 << endl;

	stringbad s1;
	cin >> s1;
	cout << s1;
	cout << int(stringbad::howmanay());
	return;

	stringbad sb ;
	sb = stringbad("aabbba");

	return;
	stringbad sb1 = { "sb1sb1sb1sb1sb1sb1" };
	stringbad sb2 = { "sb2sb2sb2sb2sb2sb2" };
	stringbad sb3 = { "sb3sb3sb3sb3sb3sb3" };
	stringbad sports = { "sb3sb3sb3sb3sb3sb3" };

	cout << "sb1:" << sb1 << endl;
	cout << "sb2:" << sb2 << endl;
	cout << "sports:" << sports << endl;

	callme1(sb1);
	cout << "sb1:" << sb1 << endl;
	callme2(sb2);
	cout << "sb2:" << sb2 << endl;


	stringbad sport = sb1;
	cout << "sport:" << sport << endl;
	cout << (bool)(sport == sb1) << endl;
	stringbad badsb;
	badsb = sb1;
	cout << "badsb:" << badsb << endl;

	
}


void xiticlassputr()
{
	return;
	char * buffer = new char[BUF];
	JustTesting *pc1, *pc2;
	pc1 = new(buffer) JustTesting;//new 定位符
	pc2 = new JustTesting("heapl", 20);//new 分配内存

	cout << "memory block address:\n" << "buffer:"
		<< (void *)buffer << "  heapl:" << pc2 << endl;
	cout << "memory contents:\n";
	cout << pc1 << ":";
	pc1->show();
	cout << pc2 << ":";
	pc2->show();
	pc1->~JustTesting();
	delete pc2;
	cout << endl;

	JustTesting *pc3, *pc4;
	pc3 = new(buffer + sizeof(JustTesting))JustTesting("bad ideal", 6);
	pc4 = new JustTesting("heap2", 10);
	cout << "memory contents:\n";
	cout << pc3 << ":";
	pc3->show();
	cout << pc4 << ":";
	pc4->show();

	pc3->~JustTesting();
	delete pc4;
	delete[] buffer;

}


int queue::queuecout() const
{
	return 0;
}
bool queue::enqueue(const item &item)
{
	return true;
}
bool queue::dequeue(item &item)
{
	return true;
}
void class_fifo()
{

}