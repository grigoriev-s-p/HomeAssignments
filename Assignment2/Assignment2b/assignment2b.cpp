/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * Assignment 2b
*/
#include"assignment2b.h"

#include<iostream>
#include<string>
void myproject::solution(){
    	std::string s;
        bool isFraction = false;
	float fractionDiv = 10.0f;
	std::getline(std::cin,s);
	float* stack = new float[size(s)];
	float* top = stack - 1;
	bool flag=false;
	for (size_t i = 0; i < size(s); i++)
	{
		switch (s[i]) {
		case ' ':
			flag = false;
			break;
		float ans;
		case '+':
			ans = *top;
			top--;
			ans += *top;
			*top = ans;
			flag = false;
			break;
		case '-':
			if (i != size(s)-1) {
				if (s[i + 1] != ' ') {
					top++;
					*top = -float(s[i+1] - '0');
					i += 1;
					flag = true;
					break;
				}
				else {
					ans = *top;
					top--;
					ans *= -1;
					ans += *top;
					*top = ans;
					flag = false;
					break;
				}
			}
			else {
				ans = *top;
				top--;
				ans *= -1;
				ans += *top;
				*top = ans;
				flag = false;
				break;
			}
		case '*':
			ans = *top;
			top--;
			ans *= *top;
			*top = ans;
			flag = false;
			break;
		case '/':
			ans = *top;
			top--;
			ans = 1 / ans;
			ans *= *top;
			*top = ans;
			flag = false;
			break;
		default:
			if (!flag) {
				top++;
				*top = 0.0f;
				flag = true;
				isFraction = false;
				fractionDiv = 10.0f;
			}
			if (s[i] == '.') {
				isFraction = true;
				break;
			}
			if (!isFraction) {
				*top = (*top) * 10 + float(s[i] - '0');
			}
			else {
				*top = *top + float(s[i] - '0') / fractionDiv;
				fractionDiv *= 10.0f;
			}
			break;
		}
	}
	if (top == stack) {
		std::cout << *top;
	}
	else {
		std::cout << "wrong format";
	}
	delete[] stack;
}


