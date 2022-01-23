#include<thread>
#include<vector>
#include<functional>
#include<iostream>

template<typename T>
concept cons  = requires(T){ 
	std::is_convertible<T,unsigned int>::value;
	std::is_convertible<T,unsigned char>::value;
	std::is_convertible<T,unsigned uint8_t>::value;
	std::is_convertible<T,unsigned uint8_t*>::value;
};

template<cons T>
struct F {
	std::vector<T> v;
	F(std::vector<T> vv) : v{vv} {}
	void operator()() {
		std::cout << "nigger" << v.size();
	}
};

void f(int *x) {
	for(int i=0;i<10000;i++) *x=69;
	std::cout << "first";
}

template<class A, class B> inline constexpr bool convertable_yes = std::is_convertible<A, B>::value;

template<cons T>
void create_thread(T size) {
	std::vector<int> v;
	int x = 0;
	std::thread **t = new std::thread*;
	for(int i=0;i<1;i++) {
	t[i] = new std::thread{std::bind(f, &x)};
	t[i+1] = new std::thread{F<T>(v)}; 
	(*t[i]).join(); // rejoin on deconstruction ?
	(*t[i+1]).join();
	}
}

int main() {
	int d = 0;
	std::thread *t;
	std::cout << std::endl<< d;
	auto ff = []<cons T>(T a) {return typeid(T).name();};
	std::cout << ff(2);
	//sIitd::vector<std::jthread> vv;
	std::cout <<std::is_convertible<int , void>::value;
	std::thread::hardware_concurrency();
	return 0;
}
