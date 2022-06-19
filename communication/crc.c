#include <stdio.h>

void append(int in1_size, char string1[in1_size], int in2_size,
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
}

int extract(int in_size, int index, char load[in_size], 
            int div_size, char extract[div_size])
{
	for(int i = 0; i < div_size; i++, index++)
	{
		byte[i] = load[index];
		if(load[index] == '\0')
			return ++index;
	}
	byte[div_size] = '\0';
	return index;
}

void get_crc(int in_size, char in_load[in_size], int div_size,
             char divisor[div_size], int crc_size, 
             char crc[crc_size])
{
    char load[(in_size+div_size)];
    append(in_size, in_load, div_size, divisor, load);
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
