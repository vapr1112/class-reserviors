#pragma once
#include <exception>
#include <iostream>

using namespace std;

//���������, �������� �� �����(�����, ������, �������) �������������
class negative_number : public exception
{
private:
	string message;
public:
	negative_number() = delete;

	negative_number(string mes_p) : message{mes_p}{}

	virtual const char* what()const noexcept final { return message.c_str(); }

	virtual ~negative_number() = default;
};

