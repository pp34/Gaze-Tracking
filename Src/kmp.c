#include "kmp.h"

#define MAX 4

int  str_kmp(const uint8_t A[], const uint8_t a[]){
	uint8_t targtmp[2], texttmp[2];
	int i, j, k;
	int lA,la;
	int next[MAX] = {0};
	lA = pp_strlen(A);
	la = pp_strlen(a);
	
	for (k = 0 ; k < lA; k++)
		targtmp[k] = A[k];
	for (k = 0 ; k < la; k++)
		texttmp[k] = a[k];
	
  for (k = la - 1; k >= 0; k--)
		texttmp[k+1] = texttmp[k];
	for (k = lA - 1; k >= 0; k--)
		targtmp[k+1] = targtmp[k];
	i = 1;
	j = 1;
	while (i <= lA && j <= la)
	{
		if (targtmp[i] == texttmp[j] || j == 0)
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}

	if (j> la)
		return i - j + 1;
	else
		return -1;
}

int pp_match(const uint8_t A[], const uint8_t a[]){
	
//	int i=0;
	int a_len, A_len;
//	int cnt=0;
	
	a_len = pp_numlen(a);
	A_len = pp_numlen(A);
	if(A_len != a_len)	return 0;
	
	if(A[0]==a[0]){
		if(A[1]==a[1])	return 1;
		else						return 0;
	}
	else							return 0;
//	for(i=0; i<a_len; i++){	
//		if(A[i] != a[i])
//			return 0;
//		else{
//			if((++cnt) == 2)	return 1;
//			else 							return 0;
//		}			
//	}
}

void cmd_match(const uint8_t A[]){
	if(pp_match(A, _A1))			CMD_FLAG = 1;						
	else if(pp_match(A, _A2))	CMD_FLAG = 2;	
	else if(pp_match(A, _A3))	CMD_FLAG = 3;	
	else if(pp_match(A, _A4))	CMD_FLAG = 4;	
	else if(pp_match(A, _B1))	CMD_FLAG = 5;	
	else if(pp_match(A, _B2))	CMD_FLAG = 6;	
	else if(pp_match(A, _B3))	CMD_FLAG = 7;	
	else if(pp_match(A, _B4))	CMD_FLAG = 8;	
	else if(pp_match(A, _B5))	CMD_FLAG = 9;	
	else if(pp_match(A, _B6))	CMD_FLAG = 10;	
	else if(pp_match(A, _B7))	CMD_FLAG = 11;	
	else if(pp_match(A, _B8))	CMD_FLAG = 12;		
	else											CMD_FLAG = 0;
}


int pp_strlen(const uint8_t *str){

	if(*str == '\0')
		return 0;
	else 
		return pp_strlen(str+1) +1;
}

int pp_numlen(const uint8_t num[]){
		return sizeof(num) / sizeof(num[0]);
}

uint8_t *pp_numcat(const uint8_t front[], const uint8_t behind[]){

	uint8_t *result;
	int cnt=0;
	uint8_t f_len, b_len;
	
	f_len = pp_strlen(front);
	b_len = pp_strlen(behind);
	
	for(cnt=0; cnt<f_len; cnt++){
		*(result+cnt) = front[cnt];
	}
	for(cnt=f_len; cnt<(f_len+b_len); cnt++){
		*(result+cnt) = behind[cnt];
	}
	return result;
}
	
