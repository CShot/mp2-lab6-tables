#pragma once

#include <stdio.h>
#include <tchar.h>
#include <iostream>

using namespace std;

template <class T>

class Stack{
private:
	T *mas;
	int maxsize;
	int pos;
public:
	Stack(int _maxsize = 100){
		maxsize = _maxsize;
		mas = new T[maxsize];
		pos = -1;
	}
	
	~Stack(){
		delete[] mas;
	}
	
	Stack(Stack& st){
		maxsize = st.maxsize;
		mas = new T[maxsize];
		for (int i = 0; i<maxsize; i++)
			mas[i] = st.mas[i];
		pos = st.pos;
	}
	
	Stack& operator = (const Stack& st){
		if (maxsize != st.maxsize){
			maxsize = st.maxsize;
			delete[] mas;
			mas = new T[maxsize];
		}
		for (int i = 0; i<maxsize; i++)
			mas[i] = st.mas[i];
		pos = st.pos;
	}
	
	int full(){
		if (pos == maxsize - 1) return 1;
		return 0;
	}
	
	int empty(){
		return (pos == -1);
	}
	
	void push(T el){
		mas[pos + 1] = el;
		pos++;
	}
	
	T pop(){
		return mas[pos--];
	}
	
	T top(){
		return mas[pos];
	}
	
	void clear(){
		pos = -1;
	}
};