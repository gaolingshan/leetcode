// Implement memcpy
//   Author: 
//   Update: 
#include <iostream>
#include <functional>
#include <bitset>
#include <chrono>
#include <exception>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

/*
just copy, no check of overlap
copy by uint count / 4, pointer += 4 each time
copy by uchar count % 4, pointer += 1 each time
*/
void* memcpy( void* dest, const void* src, size_t count ){
	uint8_t *_dest=(uint8_t*)dest;
	uint8_t *_src=(uint8_t*)(src);
	for(size_t i=0;i<count/sizeof(uint32_t);++i){
		*((uint32_t*)_dest)= *((uint32_t*)_src);		
		_dest+=sizeof(uint32_t);
		_src+=sizeof(uint32_t);
	}
	for(size_t i=0;i<count%sizeof(uint32_t);++i) 
		*(_dest++) = *(_src++);
	return dest;
}

/*
check over lap
1. no overlap, use memcpy
2. [dest,dest_end]
	      [src......src_end]
	copy from src_head
3.	        [dest,dest_end]
	[src......src_end]
	copy from src_end
*/
void* memmove( void* dest, const void* src, std::size_t count ){
	if(count==0) return dest;
	uint8_t *dest_begin=(uint8_t*)dest, *dest_end=dest_begin+count-1;
	uint8_t *src_begin=(uint8_t*)src, *src_end=src_begin+count-1;
	if(dest_end < src_begin || src_end < dest_begin) return memcpy(dest,src,count);
	if(dest_begin <= src_begin)
		for(size_t i=0;i<count;++i) *dest_begin++=*src_begin++;
	else
		for(size_t i=0;i<count;++i) *dest_end--=*src_end--;
	return dest;
}


struct {
  char name[40];
  int age;
} person, person_copy;

int main()
{

/*
	char myname[] = "Pierre de Fermatasdfgh";

	memcpy ( person.name, myname, strlen(myname)+1 );
	person.age = 46;

	memcpy ( &person_copy, &person, sizeof(person) );

	printf ("person_copy: %s, %d \n", person_copy.name, person_copy.age );
*/

/*
    char str[] = "1234567890";
    std::cout << str << '\n';
    std::memmove(str+4, str+3, 3); // copy from [4,5,6] to [5,6.7]
    std::cout << str << '\n';
*/

	char str[] = "memmove can be very useful......";
	memmove (str+20,str+15,11);
	puts (str);

	system("pause");
	return 0;
}