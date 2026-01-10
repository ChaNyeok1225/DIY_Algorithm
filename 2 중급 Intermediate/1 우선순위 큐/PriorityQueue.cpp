struct PriorityQueue {
	int arr[50005];
	int len = 0;

	bool comp(int a, int b) { // 우선순위 조건
		return a < b;
	}

	void push(int val) {
		int c = (++len);
		int p = c >> 1;

		while (p > 0) {
			if (comp(arr[p], val))
				break;
			arr[c] = arr[p];
			c = p;
			p >>= 1;
		}
		arr[c] = val;
	}

	void pop() {
		int val = arr[len--];
		int p = 1;
		while (true) {
			int c = p << 1;
			if (c > len) break;

			if (c + 1 <= len && comp(arr[c + 1], arr[c])) {
				c++;
			}

			if (comp(val, arr[c]))
				break;
			arr[p] = arr[c];
			p = c;
		}
		arr[p] = val;
	}

	int top() {
		return arr[1];
	}
};