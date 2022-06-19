#include <stdio.h>

int extract_byte(int in_size, int index, char load[in_size], char byte[9])
{
	for(int i = 0; i < 9; i++, index++)
	{
		byte[i] = load[index];
		if(load[index] == '\0')
			return ++index;
	}
	byte[8] = '\0';
	return index;
}

int str_comp(int size, char string1[size], char string2[size])
{
	int i = 0;
	for(i ; i < size; i++)
		if(string1[i] != string2[i])
			break;
	if(i==size)
		return 1;
	else 
		return 0;
}

void insert(int base_size, int index, char base[base_size], int input_size, char input[input_size])
{
	for(int i = 0; i < input_size; i++, index++)
	{
		base[index] = input[i];
	}
}

void stuff_array(int in_size, char in_load[in_size], int flag_size, char flag[flag_size], 
			   int esc_size, char esc[esc_size], int stuffed_size, char stuffed_load[stuffed_size])
{
	int index_in = 0, index_stuffed = 0;
	char byte[9];
	while(in_load[index_in] != '\0')
	{
		index_in = extract_byte(in_size, index_in, in_load, byte);
		index_in --;
		if(str_comp(9, flag, byte) || str_comp(9, esc, byte))
		{
			insert(stuffed_size, index_stuffed, stuffed_load, 9, esc);
			index_stuffed += 8;
		}
		insert(stuffed_size, index_stuffed, stuffed_load, 9, byte);
		index_stuffed += 8;
	}
	stuffed_load[index_stuffed] = '\0';
}

void destuff_array(int in_size, char in_load[in_size], int flag_size, char flag[flag_size], int 
				   esc_size, char esc[esc_size], int out_size, char out_load[out_size])
{
	int index_in = 0, index_out = 0;
	char byte[9];
	while(in_load[index_in] != '\0')
	{
		index_in = extract_byte(in_size, index_in, in_load, byte);
		index_in --;
		printf("%s\n", byte);
		if(str_comp(9, esc, byte))
		{
			continue;
		}
		insert(out_size, index_out, out_load, 9, byte);
		index_out += 8;
	}
	out_load[index_out] = '\0';
}

void output(int stuffed_size, char stuffed_load[stuffed_size], int destuffed_size,
            char destuffed_load[destuffed_size])
{
	printf("\n%s\n", stuffed_load);
	printf("\n%s\n", destuffed_load);
}

int main(void)
{
	char load[50], stuffed_load[200], destuffed_load[50], flag[9], esc[9];
	printf("Enter payload: ");
	scanf("%s", load);
	printf("Flag: ");
	scanf("%s", flag);
	printf("Escape sequence: ");
	scanf("%s", esc);
	stuff_array(50, load, 9, flag, 9, esc, 200, stuffed_load);
	destuff_array(100, stuffed_load, 9, flag, 9, esc, 50, destuffed_load);
	output(200, stuffed_load, 50, destuffed_load);
	return 0;
}
