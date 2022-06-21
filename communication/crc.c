#include <stdio.h>

append(int in1_size, char string1[in1_size], int in2_size,
            char string2[in2_size], 
            char out_string[(in1_size+in2_size)])
{
    int in_index = 0, out_index = 0;
    while(string1[index_in] != '\0')
    {
        out_string[out_index] = string1[in_index];
        out_index ++;
        in_index ++;
    }
    in_index = 0;
    while(string2[index_in] != '\0')
    {
        out_string[out_index] = string2[in_index];
        out_index ++;
        in_index ++;
    }
    out_string[out_index] = '\0';
}

int extract(int in_size, int index, char load[in_size], 
            int out_size, char extract[out_size])
{
	for(int i = 0; i < out_size; i++, index++)
	{
		byte[i] = load[index];
		if(load[index] == '\0')
			return ++index;
	}
	byte[out_size] = '\0';
	return index;
}

void get_crc(int in_size, char in_load[in_size], int div_size,
             char divisor[div_size], int crc_size, 
             char crc[crc_size])
{
    int index = 0, rem_size = length(div_size, divisor);
    char load[(in_size+div_size)], rem[rem_size], dividend[rem_size];
    append(in_size, in_load, div_size, divisor, load);
    
    while(load[index] = '\0')
    {
        extract((in_size+div_size), index, load, rem_size, dividend);
        divide(rem_size, dividend, divisor, rem);
        
    }
}

int main(void)
{
    char load[51], divisor[50], crc[50], crc_load[100];
    printf("Enter message: ");
    scanf("%s", &load);
    printf("Enter divisor: ");
    scanf("%s", &divisor);
    get_crc(51, load, 50, divisor, 50, crc);
    append(51, load, 50, crc, crc_load);
    output(100, crc_load);
    return 0;
}
