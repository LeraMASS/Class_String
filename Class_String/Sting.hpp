#pragma once


class String { 
private:
	char* data;
	size_t size;

public:
	String();//Конструктор по умолчанию, он пустой
	String(const char* str);//Параметрический конструктор
	String(size_t repeats, char sym);//Параметрический конструктор
	String(const String& other);// конструктор копирования
	String(String&& other) noexcept;// Конструктор перемещения rvalue-reference(&&)-правосторонняя ссылка, move-конструктор, не может быть const
	~String();//Деструктор

	void print() const;//Для проверки

	String& operator=(const char* str);
	String& operator=(const String& other);//Операторо присваивания, равенства
	String& operator=(String&& other) noexcept;
	String operator+(const char* str) const;//Конкотинация
	String operator+(const String& other) const;
};

