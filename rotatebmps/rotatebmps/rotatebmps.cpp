#pragma pack(2) 
#include <fstream>
#include <iostream>
using namespace std;

typedef short WORD;
typedef int DWORD;
typedef int LONG; 
struct BITMAPFILEHEADER
{
	WORD bfType; // λͼ�ļ������ͣ�����Ϊ��BM��
	DWORD bfSize; // λͼ�ļ��Ĵ�С�����ֽ�Ϊ��λ
	WORD bfReserved1; // λͼ�ļ������֣�����Ϊ0
	WORD bfReserved2; // λͼ�ļ������֣�����Ϊ0
	DWORD bfOffBits; // λͼ���ݵ���ʼλ�ã��������λͼ�ļ�ͷ��ƫ������ʾ�����ֽ�Ϊ��λ
};
struct BITMAPINFOHEADER{
	DWORD biSize; // ���ṹ��ռ���ֽ���
	LONG biWidth; // λͼ�Ŀ�ȣ�������Ϊ��λ
	LONG biHeight; // λͼ�ĸ߶ȣ�������Ϊ��λ
	WORD biPlanes; // Ŀ���豸��ƽ�������壬����Ϊ1
	WORD biBitCount;// ÿ�����������λ����������1(˫ɫ), 4(16ɫ)��8(256ɫ)��24(���ɫ)֮һ
	DWORD biCompression; // λͼѹ�����ͣ������� 0(��ѹ��),1(BI_RLE8ѹ������)��2(BI_RLE4ѹ������)֮һ
	DWORD biSizeImage; // λͼ�Ĵ�С�����ֽ�Ϊ��λ
	LONG biXPelsPerMeter; // λͼˮƽ�ֱ��ʣ�ÿ��������
	LONG biYPelsPerMeter; // λͼ��ֱ�ֱ��ʣ�ÿ��������
	DWORD biClrUsed;// λͼʵ��ʹ�õ���ɫ���е���ɫ��
	DWORD biClrImportant;// λͼ��ʾ��������Ҫ����ɫ��
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