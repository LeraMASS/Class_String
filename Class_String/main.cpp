#include <iostream>
#include "Sting.hpp"



int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	String str1 = "Hello World!";
	str1.print();

	String str2 = str1;
	str2.print();

	String str3 = String (3, '#');




	return 0;
}