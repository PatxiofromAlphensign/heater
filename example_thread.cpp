#include<vector>
#include<functional>
#include<iostream>
#include<cstdlib>


#include<thread>
#include<t.h>

// uncenessary
template<typename T>
concept c_yesConvertable  = requires(T){ 
	std::is_convertible<T,unsigned int>::value;
	std::is_convertible<T,unsigned char>::value;
	std::is_convertible<T,uint8_t>::value;
	std::is_convertible<T,uint8_t*>::value;
};

template<c_yesConvertable  T>
class F_test {
	std::vector<T> v;
	public:
	F_test(std::vector<T> vv) : v{vv} {}
	static constexpr int val = 1;
	using array_t = std::array<T, val>;
	F_test()  = default;
	void operator()() {
		std::cout << "nigger" << v.size();
	}
	array_t test () const  {
		array_t arr ;
		int local__d =0;
		for(auto i : v) {
			local__d += int{(int)v.size()+i};
			arr = {T{local__d}}; // need assignment members for `array_t`
		}
		return  arr;
	}
	array_t cnst = test();
};

void f(int *x) {
	for(int i=0;i<10000;i++) *x=69;
	std::cout << "first";
}

template<class A, class B> inline constexpr bool convertable_yes = std::is_convertible<A, B>::value;

template<class T>
void create_thread(T size) {
	std::vector<int> v;
	int x = 0;
	std::thread **t = new std::thread*;
	for(int i=0;i<1;i++) {
	t[i] = new std::thread{std::bind(f, &x)};
	t[i+1] = new std::thread{F_test<T>(v)}; 
	t[i+2] = new std::thread{std::bind(compute_high, 10000, 0)}; 
	(*t[i]).join(); // rejoin on deconstruction ?
	(*t[i+1]).join();
	(*t[i+2]).join();
	}
}
namespace std {
	auto is_same_V__ = []<typename T, typename D>(T a, D b){ return std::is_same<T, D>::value;};
	constexpr int val__ = std::is_same<int, char>::value;
};

template<int s>
constexpr int size = s;

//TODO :organize
int main() {
	int d = 0;
	std::vector<int > v;
	int *x = (int*)malloc(sizeof(int{2}));
	std::array<std::thread, size<8>> arr ;//= NULL;
	//
	//for(auto i :  arr); //.join;
	//std::cout <<std::is_convertible<int , void>::value;
	std::cout << std::is_same_V__(1,3);
	std::array<int , std::val__> a;
	create_thread(10);
	F_test<int>().cnst;
	std::thread::hardware_concurrency();
	return 0;
}
