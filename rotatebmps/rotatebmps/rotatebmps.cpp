#pragma pack(2) 
#include <fstream>
#include <iostream>
using namespace std;

typedef short WORD;
typedef int DWORD;
typedef int LONG; 
struct BITMAPFILEHEADER
{
	WORD bfType; // 位图文件的类型，必须为“BM”
	DWORD bfSize; // 位图文件的大小，以字节为单位
	WORD bfReserved1; // 位图文件保留字，必须为0
	WORD bfReserved2; // 位图文件保留字，必须为0
	DWORD bfOffBits; // 位图数据的起始位置，以相对于位图文件头的偏移量表示，以字节为单位
};
struct BITMAPINFOHEADER{
	DWORD biSize; // 本结构所占用字节数
	LONG biWidth; // 位图的宽度，以像素为单位
	LONG biHeight; // 位图的高度，以像素为单位
	WORD biPlanes; // 目标设备的平面数不清，必须为1
	WORD biBitCount;// 每个像素所需的位数，必须是1(双色), 4(16色)，8(256色)或24(真彩色)之一
	DWORD biCompression; // 位图压缩类型，必须是 0(不压缩),1(BI_RLE8压缩类型)或2(BI_RLE4压缩类型)之一
	DWORD biSizeImage; // 位图的大小，以字节为单位
	LONG biXPelsPerMeter; // 位图水平分辨率，每米像素数
	LONG biYPelsPerMeter; // 位图垂直分辨率，每米像素数
	DWORD biClrUsed;// 位图实际使用的颜色表中的颜色数
	DWORD biClrImportant;// 位图显示过程中重要的颜色数
};


char picture[3500][3500][4] = {0};

int main(int argc, char* argv[])
{
	if(argc != 3)    // check if i can get the right files
	{
		cout << "File name is missing!" << endl;
		return 0;
	}
	ifstream inFile(argv[1], ios::in|ios::binary);
	if(!inFile) 
	{
		cout << "Cannot open the source File!" << endl;
		return 0;
	}
	ofstream outFile(argv[2], ios::out|ios::binary);
	if(!outFile)
	{
		cout << "Cannot create a new File!" << endl;
		inFile.close();
		return 0;
	}
	BITMAPFILEHEADER a;   // input of the head of the source file
	inFile.seekg(0, ios::beg);
	inFile.read((char*)(&a), sizeof(BITMAPFILEHEADER));
	BITMAPINFOHEADER b;
	inFile.read((char*)(& b), sizeof(BITMAPINFOHEADER));
	if(b.biBitCount == 24) {
		char temp0 = 0;    // input of the picture information 
		int t = 4 - b.biWidth * 3 % 4;
		for(int i = 0; i != b.biHeight; ++i)
		{
			for(int j = 0; j != b.biWidth; ++j)
			{
				for(int k = 0; k != 3; ++k)
				inFile.read((char*) (&picture[i][j][k]), 1);
			}
			if(t != 4)
			{
				for(int s = 0; s < t; ++s)
				{
					inFile.read((char*)(&temp0), 1);
				}
				a.bfSize -= t;
			}
		}
		LONG temp;    // exchange the Height and Width
		temp = b.biHeight;
		b.biHeight = b.biWidth;
		b.biWidth = temp;
		t = 4 - b.biWidth * 3 % 4;           // rotate the picture and output the information
		a.bfSize += t * b.biHeight;
		outFile.seekp(0, ios::beg);
		outFile.write((const char*)(&a), sizeof(BITMAPFILEHEADER));   // output of the head of the bmp file
		outFile.write((const char*)(&b), sizeof(BITMAPINFOHEADER));
		for(int j = b.biHeight - 1; j >= 0; --j)
		{
			for(int i = 0; i != b.biWidth; ++ i)
			{
				for(int k = 0; k != 3; ++k)
					outFile.write ((const char*) (&picture[i][j][k]), 1);
			}
			if(t != 4)
			{
				for(int s = 0; s != t; ++s)
				{
					outFile.write((const char*)(&temp0), 1);
				}

			}
		}
	}
	if(b.biBitCount == 32) {
		char tem[10000] = {0};
		inFile.read(tem, 84);
		for(int i = 0; i != b.biHeight; ++i)
		{
			for(int j = 0; j != b.biWidth; ++j)
			{
				for(int k = 0; k != 4; ++k)
				inFile.read((char*) (&picture[i][j][k]), 1);
			}
		}
		LONG temp;    // exchange the Height and Width
		temp = b.biHeight;
		b.biHeight = b.biWidth;
		b.biWidth = temp;
		outFile.seekp(0, ios::beg);
		outFile.write((const char*)(&a), sizeof(BITMAPFILEHEADER));   // output of the head of the bmp file
		outFile.write((const char*)(& b), sizeof(BITMAPINFOHEADER));
		outFile.write(tem, 84);
		for(int j = b.biHeight - 1; j >= 0; --j)
		{
			for(int i = 0; i != b.biWidth; ++ i)
			{
				for(int k = 0; k != 4; ++k)
					outFile.write ((const char*) (&picture[i][j][k]), 1);
			}
		}
	}
	inFile.close();
	outFile.close();
	return 0;
}