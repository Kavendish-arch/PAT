#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define lineLength 100

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct
{
	int iData;
	char cChar;
	char cChar2;
}Data;

int main(int argc, char** argv) {
	FILE* file;
	
	//打开方式：
	// r 以只读方式打开，文件必须已经存在
	// r+ 以读写方式打开，文件必须存在
	// rb+ 以读写方式打开，文件是二进制文件，文件必须存在
	// rt+ 以读写方式打开，文件是文本文件 ，文件必须存在
	// w 以写的方式打开，如果文件原来存在内容，此时将被清空覆盖，如果不存在，新建文件
	// w+ 以读写方式打开，如果文件原来存在内容，此时将被清空覆盖，如果不存在，新建文件
	// a 以附加方式打开，如果文件原理存在内容，把新内容附加到源文件的尾部，不过不存在，新建文件
	// a+ 以附加方式可读写打开，如果文件原理存在内容，把新内容附加到源文件的尾部，不过不存在，新建文件
	// wb
	// wb+
	// wt+
	// ab+
	// at+
	
	// write text
//	char buffer1[lineLength] = "Hello world!\r\n";
//	char buffer2[lineLength] = "Line2: aaaaaa bbbbb\r\n";
//	
//	file = fopen(".\\a.txt", "wt+");
//	
//	if(file == NULL)
//	{
//		printf("open file a.txt failed\n");
//	}
//	else
//	{
//		printf("open file a.txt successfully\n");
		
		// int fprintf(File *f, const char* format, ...);
		// fprintf(file, "%s", buffer1);
		// fprintf(file, "%s", buffer2);
//	}
	
	
	// read text
//	char buffer[lineLength];
//	file = fopen(".\\a.txt", "rt+");
//	
//	if(file == NULL)
//	{
//		printf("open file a.txt failed.\n");
//	}
//	else
//	{
//		printf("open file a.txt successfully.\n");
//		
//		// int fscanf( FILE *f, const char* format, ...);
//		while(fscanf(file, "%s", buffer) != EOF)
//		{
//			printf("%s:%d\n", buffer, ftell(file));
//		}
//	}

	Data a, b, c;
	
	a.iData = 53;
	a.cChar = 'a';
	a.cChar2 = 'd';
	
	b.iData = 56;
	b.cChar = 'c';
	b.cChar2 = 'e';
	
	file = fopen(".\\c.b", "ab+");
	
	if(file == NULL)
	{
		printf("open file c.b failed.\n");
	}
	else
	{
		// fwrite((void*) p, int size, int count, FILE* f)
		if(fwrite(&a, sizeof(Data), 1, file) != 1)
		{
			printf("write in error!\n");
		}
		
		if(fwrite(&b, sizeof(Data), 1, file) != 1)
		{
			printf("write in error!\n");
		}
	}
	
	// int fseek(FILE* f, long offset, int origin)
	// origin:
	// 		SEEK_SET 开头，SEEK_CUR 当前位置， SEEK_END 结尾开始 
	
	fseek(file, sizeof(Data), SEEK_SET);
	
	// fread((void*) p, int size, int count, FILE* f)
	fread(&c, sizeof(Data), 1, file);
	
	printf("%d.%c.%c\n", c.iData, c.cChar, c.cChar2); 
	
	fclose(file);
	
	return 0;
}
