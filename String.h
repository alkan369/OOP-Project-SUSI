#pragma once
#include <iostream>

class String {
	private:
		char* data;
		size_t size;
		size_t capacity;
		void copy(const String& other);
		void resize();
		void addString(const String& other);

	public:

		// Big 4
		String();
		String(const char arr[]);
		String(const String& other);
		String& operator=(const String& other);
		~String();

		// getter for data
		const char* getData()const;

		// print method
		void print()const;

		// operator == and !=
		bool operator==(const String& other)const;
		bool operator!=(const String& other)const;

		// methods for adding and removing elements
		void push_back(const char& add);
		void pop_back();

		// operators ++ and +=
		String& operator+(const String& other);
		String& operator+=(const String& other);

		// getters for length and capacity
		size_t findLength();
		size_t findCapacity();

		// operators []
		const char operator[](size_t i)const;
		char& operator[](size_t i);

		// methods to shrink and erase data
		void shrink();
		void erase();

		// operators << and >>
		friend std::ostream& operator<<(std::ostream& out,const String& string);
		friend std::istream& operator>>(std::istream& in, String& string);
};
