#pragma once
#include <cstring>
#include <iostream>
#include <limits>
#include <cmath>
#include <fstream>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cstdarg>
#include <cassert>

enum Status {SUCCESS, FAIL, UNDER_FLOW, OVER_FLOW,RANGE_ERROR, DUPLICATE_ERROR,
	NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};


#define DEFAULT_SIZE 1000
#define DEFAULT_INFINITY 1000000


char GetChar(std::istream &inStream = std::cin);

template <typename ElemType >
void Swap(ElemType &e1, ElemType &e2);

template<typename ElemType>
void Display(ElemType elem[], int n);

template <typename ElemType>
void Write(const ElemType &e);

class Error;

char GetChar(std::istream & inStream) {
	char ch;
	while ((ch = (inStream).peek()) != EOF

		&& ((ch = (inStream).get()) == ' '

		|| ch == '\t'));

	return ch;
}

#define MAX_ERROR_MESSAGE_LEN 100
class Error {
private:
	char message[MAX_ERROR_MESSAGE_LEN];
public:
	Error(const char *mes = "Ò»°ãÐÔÒì³£!");
	~Error(void) {};
	void Show() const;
};


Error::Error(const char * mes) {
	strcpy(message, mes);
}

void Error::Show() const {
	std::cout << message << std::endl;
}

template <typename ElemType >
void Swap(ElemType & e1, ElemType & e2) {
	ElemType temp;
	temp = e1;	e1 = e2;  e2 = temp;
}

template<typename ElemType>
void Display(ElemType elem[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << elem[i] << "  ";
	}
	std::cout << std::endl;
}

template <typename ElemType>
void Write(const ElemType & e) {
    std::cout << e << "  ";
}
