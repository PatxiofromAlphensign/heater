#include<ranges>
#include<functional>
#include<vector>
#include<cstdlib>
#include<string>
#include<iostream>

#include<thread.h>

template<typename T>
struct F {
	using point = T*;
	using ref = T&;
	using iter_t = std::ranges::iterator_t<std::vector<int>>;

	F() = default;
	F(std::vector<int> &v);
	T rec(T base) {
		char *name_t = (char*)typeid(T).name();
		std::string *s = (std::string*)&name_t;
		//(*s)._M_length(10);
		if(base>10)  return base;
		base =  rec(base+1)*2;
		return 1-base;
	}
	void operator()(int &x) {
		T x_ = this->rec(x);
		x=x_;
	}
};

template<>
F<int>::F(std::vector<int> &v) { }
//template<typename T>
//T type_pointer_rec(T a, int base=0) {
//	if(base>1) return a;
//	return type_pointer_rec<T*>(&a, base+1);
//}
//

int large_vector(int size,int base) {
	if(base>size) return base;
	std::vector<int> v;
	for(int i=0;i<size;i++) {
		v.push_back((1-base) - v.size());
	}
	base = large_vector(size, base+1);
	return (int)1 -base;
}

