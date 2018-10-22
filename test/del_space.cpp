#include <iostream>
#include <assert.h>

using namespace std;

void del_space(char *str)
{
	assert(str != NULL);
	char *tmp = str;
	while(*str)
	{
		if (*str != ' ')
		{
			*tmp++ = *str;
		}
		str++;
	}
	*tmp = '\0';
}

int main(int argc, char* argv[])
{
	char str[] = " asdfasd asdfasdfass adsfasd ";
	del_space(str);
	cout << str << endl;
	return 0;
}
