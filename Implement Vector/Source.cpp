#include <iostream>
#include <stdexcept>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


/*
reserve()
empty()
operator[], at(int pos)
begin(),end(),front(),back()
push_back(),pop_back()
iterator
*/

template <class T>
class myvector
{
private:
	T* data{ NULL };
	size_t _size{ 0 };
	size_t _capacity{ 0 };
public:
	myvector()
	{
		reserve(16);
	}
	~myvector(){
		delete(data);
	}

	void reserve(size_t new_cap){
		if (new_cap < _capacity) return;
		T* old_ptr = data;
		data = new T[new_cap];
		memcpy(data, old_ptr, _size*sizeof(T));
		delete(old_ptr);
		_capacity = new_cap;
	}

	bool empty() const{
		return _size == 0;
	}

	T& operator [](int idx){
		if (idx >= _size) throw out_of_range("haha");
		return data[idx];
	}
	const T& operator [](int idx) const{
		if (idx >= _size) throw out_of_range("haha");
		return data[idx];
	}

	size_t size() const{
		return _size;
	}

	size_t capacity() const{
		return _capacity;
	}

	void push_back(T val){
		if (_size >= _capacity)
			reserve(2 * _capacity + 1);
		data[_size++] = val;
	}

	void pop_back(){
		if (_size == 0) throw out_of_range("hehe");
		_size--;
	}

	typedef T* iterator;
	typedef const T* const_iterator;

	iterator begin() {
		return &data[0];
	}

	iterator end(){
		return &data[_size];
	}

	T& front(){
		if (_size == 0) throw out_of_range("haha");
		return data[0];
	}

	T& back(){
		if (_size == 0) throw out_of_range("hehe");
		return data[_size - 1];
	}
};

int main() {
	myvector<int> v;
	for (int i = 0; i<100; i++) v.push_back(i);
	for (int i = 0; i<100; i++) cout << v[i] << " "; cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << *v.begin() << endl;
	for (auto it = v.begin(); it != v.end(); it++) cout << *it << " "; cout << endl;
	for (int i = 0; i<99; i++)v.pop_back();
	cout << v.size() << endl;
	cout << v.back() << endl;
	getchar();
	return 0;
}
