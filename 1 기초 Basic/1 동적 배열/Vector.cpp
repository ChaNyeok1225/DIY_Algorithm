/*
* 1. 동적 배열
*/

template<typename T>
class Vector {
private:
	T* data;
	int capacity;
	int length;
	const static int DEFAULT_CAPACITY = 4;

public:
	Vector(int initCapacity = DEFAULT_CAPACITY)
		: capacity(initCapacity > 0 ? initCapacity : DEFAULT_CAPACITY), length(0) {
		data = new T[capacity];
	}

	~Vector() {
		if (data != nullptr) {
			delete[] data;
		}
	}

	Vector(const Vector& other)
		: capacity(other.capacity), length(other.length) {
		data = new T[capacity];
		for (int i = 0; i < length; i++) {
			data[i] = other.data[i];
		}
	}

	Vector& operator=(const Vector& other) {
		if (this == &other) {
			return *this;
		}

		delete[] data;

		capacity = other.capacity;
		length = other.length;

		data = new T[capacity];
		for (int i = 0; i < length; i++) {
			data[i] = other.data[i];
		}

		return *this;
	}

public:
	void push_back(const T& value) {
		if (length == capacity) {
			int newCapacity = capacity * 2;
			T* newData = new T[newCapacity];

			for (int i = 0; i < length; i++) {
				newData[i] = data[i];
			}

			delete[] data;

			data = newData;
			capacity = newCapacity;
		}
		data[length++] = value;
	}

	void pop_back() {
		if (length > 0) {
			length--;
		}
	}

	T& operator[](int index) {
		return data[index];
	}

	const T& operator[](int index) const {
		return data[index];
	}

	int size() const {
		return length;
	}

	int max_capacity() const {
		return capacity;
	}

	bool empty() const {
		return length == 0;
	}
};