#pragma once
#include <iostream>
#include <exception>

template <typename T>
class Vector {
	private:
		T* data;
		size_t size;
		size_t capacity;
		void copy(const Vector& other);
		void resize();
		T& at(size_t i)const;
	public:

		// Big 4
		Vector();
		Vector(size_t);
		Vector(const Vector& other);
		Vector& operator=(const Vector& other);
		~Vector();

		// getters for size and capacity
		size_t getSize()const;
		size_t getCapacity()const;

		// operators []
		const T operator[](size_t) const;
		T& operator[](size_t);

		// methods for adding and removing element
		void push_back(const T&);
		void pop_back();

		// method for deleting data
		void pop();
};

template <typename T>
void Vector<T>::copy(const Vector<T>& other) {
	size = other.size;
	capacity = other.capacity;
	data = new(std::nothrow) T[capacity]; // capacity
	if(data == nullptr){
		throw std::bad_alloc();
	}
	for (int i = 0; i < other.size; i++) {
		data[i] = other.data[i];
	}
}

template <typename T>
void Vector<T>::resize() {
	capacity = capacity * 2;
	T* temp = new (std::nothrow) T[capacity];
	if(temp == nullptr){
		throw std::bad_alloc();
	}
	for (int i = 0; i < size; i++) {
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
}

template <typename T>
T& Vector<T>::at(size_t i) const {
	if (i < size){
		return data[i];
	}
	throw std::out_of_range("Index too big to access in vector");
}

template <typename T>
Vector<T>::Vector() {
	size = 0;
	capacity = 8;
	data = new(std::nothrow) T[capacity];
	if(data == nullptr){
		throw std::bad_alloc();
	}
}
template <typename T>
Vector<T>::Vector(size_t addCapacity) {
	size = 0;
	capacity = addCapacity;
	data = new(std::nothrow)T[capacity];
	if(data == nullptr){
		throw std::bad_alloc();
	}
}
template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
	copy(other);
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other) {
		delete[] data;
		copy(other);
	}
	return *this;
}
template <typename T>
Vector<T>::~Vector() {
	delete[] data;
}

template <typename T>
size_t Vector<T>::getSize()const {
	return size;
}

template <typename T>
size_t Vector<T>::getCapacity()const {
	return capacity;
}
template <typename T>
const T Vector<T>::operator[](size_t i) const {
	return at(i);
}
template <typename T>
T& Vector<T>::operator[](size_t i) {
	return at(i);
}
template <typename T>
void Vector<T>::push_back(const T& add) {
	if (size == capacity) {
		resize();
	}
	data[size] = add;
	++size;
}

template <typename T>
void Vector<T>::pop_back(){
	if(size == 0){
		return;
	}
	--size;
}

template <typename T>
void Vector<T>::pop() {
	delete[] data;
	data = new (std::nothrow) T[capacity];
	size = 0;
	if(data == nullptr){
		throw std::bad_alloc();
	}
}