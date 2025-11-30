#include "../2 연결 리스트/List.cpp"

/*
* 3-2. 큐
*/

template<typename T>
class Queue {
private:
	List<T> storage;

public:
	void push(const T& value) {
		storage.push_back(value);
	}

	void pop() {
		storage.pop_front();
	}

	T& front() {
		return storage.front();
	}

	T& back() {
		return storage.back();
	}

	bool empty() const {
		return storage.empty();
	}

	int size() const {
		return storage.size();
	}
};