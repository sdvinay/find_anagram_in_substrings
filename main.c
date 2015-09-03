#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define CHAR_MAX 256

// sig is the array to be written to
void compute_signature(char *str, size_t len_str, int *sig)
{
	for (int i = 0; i < CHAR_MAX; i++)
	{
		sig[i] = 0;
	}

	for (int i = 0; i < len_str; i++)
	{
		sig[str[i]]++;
	}
}

void print_signature(int * sig)
{
	for (char c = 'a'; c < 'e'; c++)
	{
		printf("%d",sig[c]);
	}
	printf("\n");
}

int compare_signatures(int * sig1, int * sig2)
{
	for (int i = 0; i < CHAR_MAX; i++)
	{
		if (sig1[i] != sig2[i])
			return 0;
	}
	return 1;
}

int find_anagram(char *a, char *b)
{
	int retVal = -1;


	// these arrays hold the signature of each string
	int char_counts_a[CHAR_MAX];
	int char_counts_current_substr_b[CHAR_MAX];

	size_t len_a = strlen(a);
	size_t len_b = strlen(b);
	if (len_a > len_b)
		return retVal;

	compute_signature(a, len_a, char_counts_a);
	print_signature(char_counts_a);

	for (size_t pos = 0; pos <= (len_b-len_a); pos++)
	{
		compute_signature(b+pos, len_a, char_counts_current_substr_b);
		print_signature(char_counts_current_substr_b);
		if (compare_signatures(char_counts_a, char_counts_current_substr_b))
		{
			retVal = pos;
			break;
		}
	}

	return retVal;
}

int main(int argc, char ** argv)
{
	if (argc > 1)
	{
		int anagram_pos = find_anagram(argv[1], argv[2]);
		int test_val = atoi(argv[3]);
		printf("%s: Expected: %d, Evaluated: %d (%s, %s)\n", (anagram_pos == test_val ? "PASS" : "FAIL"), test_val, anagram_pos, argv[1], argv[2]);
	}
}
