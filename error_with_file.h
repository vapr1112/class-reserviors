#pragma once
#include <exception>
#include <iostream>

using namespace std;

//проверяет успешно ли открыт и закрыт файл
class error_with_file : public exception
{
private:
	string message;
public:
	error_with_file() = delete;

	error_with_file(string mes_p) : message{ mes_p } {}

	virtual const char* what()const noexcept final { return message.c_str(); }

	virtual ~error_with_file() = default;

};

