/************************************************
       Big Endian vs Little Endian
**************************************************/
int  i = 1; //4 byte = 32 bit

            1st byte  2nd byte  3rd byte   4th byte
Big Endian    :0000    0000      0000       0001
Little Endian :0001    0000      0000       0000

int main()
{
	int i = 1;
	char *c = (char*)&i;//It will point to 1st Byte
	
	if(*c) cout <<"Little endian";
	else cout <<"Big endian";
	
	return(0);
}
