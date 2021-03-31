

#include <iostream>
//#include <deque>

using namespace std;
int compare(const void* a, const void* b);
void binsearch(int* a, int n, int* p, int* q, int T);
void mergesort(int a[], unsigned int n, unsigned int l, unsigned int h);

int b[1000000];
struct node {
	int data;
	node* pred;
	node* succ;
};

class deque {
public:
	deque();
	int front();
	int back();
	void pop_front();
	void pop_back();
	void push_front(int data);
	void push_back(int data);
	bool empty();
private:
	node* header;
	node* tailer;
	unsigned int size;
};




inline deque::deque() {
	header = new node;
	tailer = new node;

	header->data = NULL;
	header->succ = tailer;
	header->pred = nullptr;
	tailer->data = NULL;
	tailer->succ = nullptr;
	tailer->pred = header;
	size = 0;
}

inline int deque::front() {
	if (size)
		return header->succ->data;
	else return NULL;
}
inline int deque::back() {
	if (size)
		return tailer->pred->data;
	else return NULL;

}
void deque::pop_front() {
	header->succ = header->succ->succ;
	delete header->succ->pred;
	header->succ->pred = header;
	size--;
}
void deque::pop_back() {
	tailer->pred = tailer->pred->pred;
	delete tailer->pred->succ;
	tailer->pred->succ = tailer;
	size--;
}
void deque::push_front(int data) {
	node* p = new node;
	p->data = data;
	p->succ = header->succ;
	p->pred = header;
	header->succ->pred = p;
	header->succ = p;
	size++;
}
void deque::push_back(int data) {
	node* p = new node;
	p->data = data;
	p->succ = tailer;
	p->pred = tailer->pred;
	tailer->pred->succ = p;
	tailer->pred = p;
	size++;
}
inline bool deque::empty() {
	if (size)
		return false;
	else return true;
}

int num_confirm[1000000];
int num_days[1000000];
int max_confirm[1000000];


int main()
{
	
	ios_base::sync_with_stdio(false);
	int n;//天数
	cin >> n;
	int i;

	//int* num_confirm = new int[n];
	//int* num_days = new int[n];
	//int* max_confirm = new int[n];
	max_confirm[0] = 0;

	for (i = 0; i < n; i++) {
		cin >> num_confirm[i];
	}
	for (i = 0; i < n; i++) {
		cin >> num_days[i];
	}
	int T;//p, q总数
	cin >> T;
	int* p = new int[T];
	int* q = new int[T];
	for (i = 0; i < T; i++) {
		cin >> p[i] >> q[i];
	}

	deque dq;
	//队列滑动窗口
	//先剔除，再去小
	//第i天，[i-k,i)

	for (i = 1; i < n; i++) {
		while (!dq.empty() && num_confirm[dq.back()] < num_confirm[i - 1])
			dq.pop_back();		
		while (!dq.empty() && dq.front() < (i - num_days[i]))
			dq.pop_front();

		dq.push_back(i - 1);

		//cout << "i: " << i << "  " << dq.front()<< " confirm max:  "<< num_confirm[dq.front()]<< endl;
		max_confirm[i] = num_confirm[dq.front()];
	}
	//qsort(max_confirm, n, sizeof(int), compare);
	mergesort(max_confirm, n, 0, n);
	binsearch(max_confirm, n, p, q, T);
	return 0;
}
void binsearch(int* a, int n, int* p, int* q, int T){
	int cp=0, cq=0;
	for (int k = 0; k < T; k++) {
		if (p[k] >= a[n - 1]) {
			cp = n;
			cq = 0;
		}
		else if (q[k] <= a[0]) {
			cp = 0;
			cq = 0;
		}
		else {
			int l = 0;
			int h = n, m;
			while (l < h) {
				m = (l + h) >> 1;
				p[k]-1 < a[m] ? h = m : l = m + 1;
			}
			cp = l;
			l--;
			h = n;
			while (l < h) {
				m = (l + h) >> 1;
				q[k]-1 < a[m] ? h = m : l = m + 1;
			}
			cq = l - cp;
		}

		cout << cp << " " << cq << endl;
		//cout << count_p[k] << " " << count_q[k] << endl;
	}

}


void mergesort(int a[], unsigned int n, unsigned int l, unsigned int h) {
	if (h - l <= 2) {
		if (a[l] > a[h-1]){
			int tmp = a[l];
			a[l] = a[h-1];
			a[h-1] = tmp;
		}
		return ;
	}
	else{
		int m = (l + h)/2;
		mergesort(a, n, l, m);
		mergesort(a, n, m, h);//左闭右开
		//int* b = new int[m-l];
		int i = 0;
		int j = 0;
		//复制A前缀，实现就地排序
		while(i < m - l){
			b[i] = a[l+i];
			i++;
		}
		//memcpy(&b[0], a + l, m - l);
		i = 0;
		while((l+i)<m && (m+j)<h){
			if(b[i] <= a[m+j]){
				a[l + i + j] = b[i];
				i++;
			}
			else{
				a[l+i+j] = a[m+j];
				j++;
			}			
		}
		if ((m + j) >= h) {//a完,b复制到a末尾
			//memcpy(a + l + i + j, b + i, m - l - i);
			while ((l + i) < m) {
				a[l + i + j] = b[i];
				i++;
			}
		}
		//delete []b;
		return;
	}
}
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}