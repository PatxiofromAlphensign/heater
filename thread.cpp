#include<thread>
#include<functional>
#include<vector>
#include<iostream>
#include<initializer_list>

#include<thread.h>

template<typename T>
concept  cons = requires(T a) {
	{a} -> int	;
};

template<cons T>
struct F { 
	//std::vector<T> &v;
	public:
	T d;
	std::vector<T> v;
	F()  = default;	
	F(std::vector<T>& vv, T* v) : d{*(int*)(typeid(T).name())} { }
	F(std::initializer_list<int> c) {this->v = c; }
	void operator()() {}
};
int rec(int base) {
	int i=0;
	if(base>base*2) return base;
	return rec(base+1);
}

void f(std::vector<int>&) {}// {
//}
std::thread **create_thread(int size) {
	std::vector<int>  v;
	int d;
	auto b = std::bind(f, v);
	struct F<int> fn(v, &d); //{v};
	std::thread t1{std::bind(fn)};

	std::thread **t = (std::thread**)malloc(sizeof(std::thread)*size^2);
	for(int i=0;i<size+1; i++) {
		t[i] = new std::thread{std::bind(rec,size)};
		t[i+1] = new std::thread{std::bind(fn)};
	}
	return t;
}

int main() {
	//std::thread **t = create_thread(10);
	struct F<int> fn{1,2,4,5,4,1};
	std::cout << fn.v.size();
	std::cout << compute_high(100);
	//(*t[0]).join();
	return 0;
}
