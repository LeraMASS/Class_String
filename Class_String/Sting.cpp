#include "Sting.hpp"
#include <iostream>
String::String() {
	data = new char[1] { '\0' };
	size = 0;
}

String::String(const char* str) {
	size_t counter{};//счетчик кол-во элементов расположенных в памяти 
	while (*(str + counter++) != '\0');// законченный цикл//пока там не нуль терминатор, цикл будет работать
	// ++counter; можно написать так.
	data = new char[counter];//Выделение памяти, нужного размера
	for (size_t i{}; i < counter; ++i)//{} обозначение 0
		data[i] = str[i];//копирование
	size = counter - 1;
}

String::String(size_t repeats, char sym) : size(repeats) {
	data = new char[repeats + 1];
	for (size_t i = 0; i < repeats; ++i)
		data[i] = sym;// каждый элемент i получает значения элемента который был передан, до repeats;
	data[repeats] = '\0';//нуль терминатор, облегчает работу прогрмме, код, должен быть везде и всегда
}

String::String(const String& other) : size(other.size) {
	data = new char[other.size + 1];
	for (size_t i{}; i < size + 1; ++i)
		data[i] = other.data[i];
}

String::String(String&& other) noexcept : String() {//Вызывается только когда есть объкт из которого копирование существует, ограниченное кол-во времени
	//std::cout << "move-constructor\n"; для проверки перемещения
	std::swap(data, other.data);//обмен полями
	std::swap(size, other.size);//обмен полями
	//throw; команда для вызова ошибки, noexcept - если есть такая команда, то вызов ошибки будет пропущен
}

String::~String() {
	delete[] data;
}

void String::print() const {
	std::cout << data << std::endl;
}

String& String::operator=(const char* str) noexcept {//копируем из параметрического конструктора
	delete[] data;//освобождение памяти
	size_t counter{};
	while (*(str + counter++) != '\0');
	data = new char[counter];
	for (size_t i{}; i < counter; ++i)
		data[i] = str[i];
	size = counter - 1;

	return *this;//зазименнование чтоб вернуть сам объект
}

String& String::operator=(const String& other) {//копируем тело из конструктора копирования
	delete[] data;
	size = other.size;
	data = new char[other.size + 1];
	for (size_t i{}; i < size + 1; ++i)
		data[i] = other.data[i];
	return *this;
}

String& String::operator=(String&& other) {
	std::swap(data, other.data);
	std::swap(size, other.size);
	return *this;
}



String String::operator+(const char* str) const {
	return String();
}
String String::operator+(const String& other) const {
	return String();
}
