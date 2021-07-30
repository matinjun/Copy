#include <iostream>
#include <stack>
#include <list>
#include <cstring>
#include "Folder.h"
#include "Message.h"
#include "ShareStack.h"

class Test {
public:
	void testFolder() const;
	void testVect() const;
	void testStack() const;
};

namespace mtjStack {
	bool isIoTrue(char str[], int n);
	bool isCentrosymmetric(std::list<char >&);
}

int main() {
	Test test;
#if 0
	for (;;) {
		test.testVect();
		if (std::cin.eof()) break;
	}
#endif
	test.testStack();
	return 0;
}

void Test::testFolder() const
{
	Folder f1, f2;
	Message m1(std::string("hello Neo!")), m2(std::string("Hi, Mtj!"));
	m1.save(f1);
	m2.save(f1); m2.save(f2);
	Message m3(m1);
	Folder f3(f2);
	f3 = f1;
	f3 = f3;

	swap(m1, m2);
	swap(f1, f2);

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;
	std::cout << m1 << std::endl;
	std::cout << m2 << std::endl;
	std::cout << m3 << std::endl;
}

void Test::testVect() const
{
	double a[3], b[3];
	double c[3];
	double& x1 = a[0], & y1 = a[1], & z1 = a[2];
	double& x2 = b[0], & y2 = b[1], & z2 = b[2];
	std::cout << "plz input vec(a): ";
	std::cin >> x1 >> y1 >> z1;
	std::cout << "plz input vec(b): ";
	std::cin >> x2 >> y2 >> z2;
	c[0] = y1 * z2 - z1 * y2;
	c[1] = x2 * z1 - x1 * z2;
	c[2] = x1 * y2 - x2 * y1;

	std::cout << "vec(a) x vec(b) = " 
		<< c[0] << ", " << c[1] << ", " << c[2] << std::endl;
}

void Test::testStack() const
{
	char str[] = "IIIOOIOO";
	int len = strlen(str);
	std::cout << str << " is " ;
	if (mtjStack::isIoTrue(str, len))
		std::cout << "true";
	else
		std::cout << "false";
	std::cout << std::endl;
	std::cout << "====================" << std::endl;

	// =============================================
	std::list<char> lst;
	std::string tmpstr = "xxyxyxx";
	lst.assign(tmpstr.begin(), tmpstr.end());
	std::cout << tmpstr << " is ";
	if (mtjStack::isCentrosymmetric(lst))
		std::cout << "Centrosymmetric";
	else
		std::cout << "not Centrosymmetric";
	std::cout << std::endl;

}

namespace mtjStack {
	bool isIoTrue(char str[], int n)
	{
		int Icount = 0, Ocount = 0;
		for (int i = 0; i < n; ++i) {
			switch (str[i]) {
			case 'I':
				++Icount;
				break;
			default:
				++Ocount;
			}
			if (Icount < Ocount) return false;
		}
		return true;
	}

	bool isCentrosymmetric(std::list<char>& lst) {

		ShareStack stck;
		for (auto ch : lst) {
			stck.push(0, ch);
		}
		for (auto ch : lst) {
			char data;
			stck.pop(0, data);
			if (data != ch) return false;
		}
		return true;
	}
}
