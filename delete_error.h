#pragma once
#include <exception>
#include <iostream>

using namespace std;

//проверяет перед удалением элемента, пуст ли массив
class delete_error : public exception
{
private:
	string message;
public:
	delete_error() = delete;

	delete_error(string mes_p) : message{ mes_p } {}

	virtual const char* what()const noexcept final { return message.c_str(); }

	virtual ~delete_error() = default;

};

