/*
* 2. 연결 리스트 
*/

template<typename T>
class List {
private:
	struct Node {
		T data;
		Node* prev;
		Node* next;

		Node(const T& d = T(), Node* p = nullptr, Node* n = nullptr)
			:data(d), prev(p), next(n) { }
	};

	Node* head;
	Node* tail;
	int length;

public:
	List() : length(0) {
		head = new Node();
		tail = new Node();

		head->next = tail;
		tail->prev = head;
	}

	~List() {
		Node* current = head->next;
		Node* nextNode;

		while (current != tail) {
			nextNode = current->next;
			delete current;
			current = nextNode;
		}
		delete head;
		delete tail;
	}

	void insert(Node* p, const T& value) {
		Node* newNode = new Node(value, p->prev, p);
		p->prev->next = newNode;
		p->prev = newNode;
		length++;
	}

	void erase(Node* p) {
		if (p == head || p == tail)
			return;
		
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		length--;
	}

	void push_back(const T& value) {
		insert(tail, value);
	}

	void push_front(const T& value) {
		insert(head->next, value);
	}

	void pop_back() {
		if (!empty()) {
			erase(tail->prev);
		}
	}

	void pop_front() {
		if (!empty()) {
			erase(head->next);
		}
	}

	T& front() {
		return head->next->data;
	}

	T& back() {
		return tail->prev->data;
	}

	bool empty() const {
		return length == 0;
	}

	int size() const {
		return length;
	}
};