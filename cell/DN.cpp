#include "DN.h"
void DN::check(char type) {
	if(type=='A'||type=='T'||type=='C'||type=='G'){
		return true;
	}else{
		return false;
	}
} 

void DN::init(char type) {
	if(check(type)){
		DN_type = type;
	}
}
