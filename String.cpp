#include <iostream>
#include <exception>
#include "string.h"
#include "myCstring.h"


void String::copy(const String& other) {
	capacity = other.capacity;
	size = other.size;
	data = new (std::nothrow) char[capacity + 1];
	if(data == nullptr){
		throw std::bad_alloc();
	}
	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
	data[size] = '\0';
}

void String::resize() {
	capacity = capacity * 2;
	char* tempData = new (std::nothrow) char[capacity + 1];
	if(tempData == nullptr){
		throw std::bad_alloc();
	}
	for (int i = 0; i < size; i++) {
		tempData[i] = data[i];
	}
	delete[] data;
	data = tempData;
}

void String::addString(const String& other) {
	if (size == capacity) {
		resize();
	}
	if (capacity - size >= other.size) {
		size_t temp = size;
		for (int i = 0; i < other.size; i++) {
			data[temp] = other.data[i];
			++temp;
		}
		size = size + other.size;
		data[size] = '\0';
	}
	else {
		resize();
		addString(other);
	}
}


String::String() {
	size = 0;
	capacity = 8;
	data = new(std::nothrow)char[capacity + 1];
	if(data == nullptr){
		throw std::bad_alloc();
	}
}

String::String(const char arr[]) {
	size = myStrlen(arr);
	capacity = size * 2;
	data = new (std::nothrow) char[capacity + 1];
	if(data == nullptr){
		throw std::bad_alloc();
	}
	myStrCpy(data, (size+1) ,arr);
}

String::String(const String& other) {
	copy(other);
}

String& String::operator=(const String& other) {
	if (this != &other) {
		delete[] data;
		copy(other);
	}
	return *this;
}

String::~String() {
	delete[] data;
}

const char* String::getData()const{
	return data;
}

void String::print()const {
	std::cout << data << std::endl;
}

bool String::operator==(const String& other) const {
	return myStrcmp(data,other.data) == 0;
}

bool String::operator!=(const String& other)const{
	return !(*this == other);
}

void String::push_back(const char& add) {
	if (size == capacity - 1) {
		resize();
	}
	data[size] = add;
	++size;
	data[size] = '\0';
}

void String::pop_back() {
	if(size == 0){
		return;
	}
	data[size-1] = '\0';
	--size;
}

String& String::operator+(const String& other) {
	addString(other);
	return *this;
}

String& String::operator+=(const String& other) {
	addString(other);
	return *this;
}

size_t String::findLength() {
	return size;
}

size_t String::findCapacity() {
	return capacity;
}

const char String::operator[](size_t i) const {
	if (i <= size) {
		return data[i];
	}
	throw std::out_of_range("The index is bigger than the size of the string");
}

char& String::operator[](size_t i) {
	if (i <= size) {
		return data[i];
	}
	throw std::out_of_range("The index is bigger than the size of the string");
}

void String::shrink() {
	capacity = size + 1;
}

void String::erase(){
	delete[] data;
	size = 0;
	data = new(std::nothrow) char[capacity];
	if(data == nullptr){
		throw std::bad_alloc();
	}
}

std::ostream& operator<<(std::ostream& out,const String& string){
	out << string.data;
	return out;
}

std::istream& operator>>(std::istream& in, String& string){
	char temp{};
	if(string.findLength() != 0){
		string.erase();
	}
	while(temp != '\n'){
		temp = in.get();
		if(temp != '\n'){
			string.push_back(temp);
		}
	}
	return in;
}