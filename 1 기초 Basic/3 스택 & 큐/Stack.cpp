#include "../1 동적 배열/Vector.cpp"

/*
* 3-1. 스택
*/

template<typename T>
class Stack {
private:
	Vector<T> storage;

public:
	void push(const T& value) {
		storage.push_back(value);
	}

	void pop() {
		storage.pop_back();
	}

	T& top() {
		return storage[storage.size() - 1];
	}

	const T& top() const {
		return storage[storage.size() - 1];
	}

	bool empty() const {
		return storage.empty();
	}

	int size() const {
		return storage.size();
	}
};