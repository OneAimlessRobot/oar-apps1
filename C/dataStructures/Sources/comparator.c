#include "../Includes/preprocessor.h"
#include "../Includes/comparator.h"

int compare(void* mem1,void* mem2,u_int64_t sizeIsTheSame){


	return memcmp(mem1,mem2,sizeIsTheSame);


}
