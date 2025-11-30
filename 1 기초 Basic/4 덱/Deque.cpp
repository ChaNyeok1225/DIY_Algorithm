#include "../2 연결 리스트/List.cpp"

/*
* 4. 덱
*/

template<typename T>
class Deque {
private:
	List<T> storage;

public:
	void push_front(T& value) {
		storage.push_front(value);
	}

	void pop_front() {
		storage.pop_front();
	}

	T& front() {
		return storage.front();
	}

	void push_back(T& value) {
		storage.push_back(value);
	}

	void pop_back() {
		storage.pop_back();
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