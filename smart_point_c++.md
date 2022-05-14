PROJECT(HELLO )
SET(SRC_LIST main.cpp)   //SRC_LIST value include   main.cpp
MESSAGE   // KEYWORD  
	SEND_ERROR  SATUS  FATAL_ERROR
ADD_EXECUTABLE(hello $(SRC_LIST)) 


ADD_SUBDIRECTORY(src bin)

INSTALL 

ADD_LIBRARY(hello SHARED )
ADD_LIBRARY(hello STATIC )

SET_TARGET_PROPERTIES

INCLUDE_DIRECTORIES()

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
	sub::lib1
	sub::lib2
	)

ldd 	//check  execute file ".exe" whether link any of file 
objdump -D 

typename decay<T>::type

target_include_directories(hellolib PUBLIC .)

std::valarray

--depth=1

lambda  c++17 auto  

#include <vector>
#include <algorithm>

#include <numeric>  //auto sum

c++20 
 import <generator>
 import  <format>
		co_yield
		format_to(cout,"number is {}", vi);
		
c 	realloc(v,nv+sizeof(int)      free()
c++	v.resize(4);			{}

explicit  
static_cast    //Code Style
reinterpret_cast

=default
=delete
Pig(Pig const &other)      //copy construction function  could copy all of feild
Pig &operator=(Pig const &) = delete;
pig = pig2;

class c {
public:
	c();			
	c(c const& c);		
	c(c&& c);
	c& operator=(c const& c);		
	c& operator=(c&& c);	
	~c();			

};

Pig(){}
Pig(Pig const &other):m_name(other.m_name),
			,m_weight(other.m_weight){}

Pig &operator=(Pig const &other){
		m_name = other.m_name;
		m_weight = other.m_weight;
}

Pig(Pig &&other):m_name(move (other.m_name())
		,m_weight(move(other.m_weight)){}

Pig &operator = (Pig &&other){m_name(move (other.m_name())
		,m_weight(move(other.m_weight));
		return &this;}


////////

	myVector(myVector const&) = delete;
