#include<thread>
#include<functional>
#include<vector>
#include<iostream>
#include<initializer_list>
#include<ranges>

#include<t.h>


template<typename T>
struct F { //std::vector<T> &v;
	std::vector<T> v;
	public:
	T d;
	typedef std::initializer_list<int> init_int; F()  = default;	
	F(std::vector<T>& vv, T* v) : d{*(int*)(typeid(T).name())} { }
	F(init_int c) {
		this->v = c; 
		const char* name =typeid(init_int::value_type).name();
		init_int::iterator iter;
		
	} 
	typedef init_int::size_type size_type;
	struct F operator()() {
		return *this;	
	}
};
int rec(int base, int i=0) {
	if(i>base) return base;
	return rec(base, i+1);
}

void f(std::vector<int>&) {}// {
//}

auto ret_t(struct F<int> *f) {
	std::vector<int> v ;
	int d = 0;
	f = new struct F<int>(v, &d);
	return f;
}
std::jthread **create_jthread(int size) noexcept  { //undefined behaviour
	std::vector<int>  v;
	int d;
	auto b = std::bind(f, v);
	struct F<int> fn(v, &d); //{v};
	std::jthread t1{std::bind(fn)};
	std::jthread **t = (std::jthread**)malloc(sizeof(std::jthread)*size^2);
	for(int i=0;i<size+2; i++) {
		//t[i] = new std::thread{std::bind(rec,size)};
		//t[i+1] = new std::thread{std::bind(fn)};
		t[i+2] = new std::jthread{std::bind(compute_high, size,0)};
		(*t[i+2]).join();
	}
	return t;
}
template<typename T>
T _create_thread(T size) noexcept { //does not include the struct F impl
	if(size>10) return 0;
	std::thread **t = new std::thread*;
	std::thread **t1 = new std::thread*;
	for(int i=0;i<size+1;i++) { t[i] = new std::thread{std::bind(compute_high, 100,0)};
				//t1[i] = new std::thread{std::bind(rec, 100, 0)};
	 			(*t[i]).join();
	 			//(*t1[i]).join(); //double free || malloc() corruption  
				}
	free(t);
	return 1;
} 
template<typename T>
void free_a(T &a) noexcept {
	for(int i=0;i<200;i++)free(a[i])	;
}
template<class T>
std::ranges::iterator_t<std::vector<T>> ranged_vector() noexcept {
	std::ranges::iterator_t<std::vector<T>> range_iter = {};
	std::array<int, 2> v; 
	for(auto i : v);
	for(auto i : range_iter) range_iter.push_back(2);
}
int main() {
	//std::thread **t = create_jthread(10);
	//for(int i=0;i<200;i++)(*t[i]).join();
	//free_a(t);
	int x = _create_thread(10);
	//std::cout << x << " ";
	rec(10);
	struct F<int> fn{1,2,4,5,4,1};
	struct F<int> *fnn;
	std::cout <<std::move(fn()).v.size();
	//std::cout << fn.v.size();
	//struct F<int> f = std::bind(*fnn)();
	struct F<int> *ret = ret_t(&fn);
	struct F<int> fn_ = std::bind((*ret))();
	//std::thread t1{std::bind(f)};
	//t1.join();
	const long unsigned int d_u = (const long unsigned int)compute_high(100);
	using namespace std;
	std::array<int, 4> v{2,2,1,2}; 
	std::cout << v.size();

	for(int i : v) {
		while(i < 100) {
			//std::cout << "2";
			i++;
		}
	}
	return 0;
}
