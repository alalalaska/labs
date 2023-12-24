#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

#pragma pack(push, 1)

const BYTE RarSignature[] = { 0x52, 0x61, 0x72, 0x21, 0x1A, 0x07, 0x00 };

typedef struct
{
	WORD header_crc;
	BYTE header_type;
	WORD header_flags;
	WORD header_size;
} RarVolumeHeaderFormat, *PRarVolumeHeaderFormat;

typedef struct
{
	DWORD PackSize;
	DWORD UnpSize;
	BYTE HostOS;
	DWORD FileCRC;
	DWORD FileTime;
	BYTE UnpVer;
	BYTE Method;
	WORD NameSize;
	DWORD FileAttr;

}FILE_HEAD, *PFILE_HEAD;

#pragma pack(pop)

void readRAR(vector<BYTE>& buffer, DWORD fileSize)
{

	int numberOfFiles = 0;
	DWORD fileOffset = sizeof(RarSignature);
	wcout << L"Файлы: " << endl;
	while (fileOffset < fileSize)
        {
		RarVolumeHeaderFormat vh;
		FILE_HEAD fh;
		memcpy(&vh, &buffer[fileOffset], sizeof(vh));
		if (vh.header_type == 0x74)
		{
			numberOfFiles++;
			int ind = fileOffset;
			fileOffset += sizeof(vh);
			memcpy(&fh, &buffer[fileOffset], sizeof(fh));
			fileOffset += sizeof(fh);
			BYTE* filename = new BYTE[fh.NameSize];
			for (int i = 0; i < fh.NameSize; i++)
			{
				filename[i] = buffer[fileOffset];
				cout << filename[i];
				fileOffset++;
			}
			cout << endl;
			delete[] filename;
			fileOffset = ind;
			fileOffset += fh.PackSize + vh.header_size;
		}
		else {
			fileOffset += vh.header_size;
		}

	}
	wcout << L"Всего файлов в архиве: " << numberOfFiles << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	HANDLE fileHandle = CreateFile("Example.rar",
                                GENERIC_READ,
                                0,
                                NULL,
                                OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL,
                                NULL);

	if (fileHandle == INVALID_HANDLE_VALUE)
    {
		wcout << L"Ошибка открытия файла" << endl;
		CloseHandle(fileHandle);
		return -1;
	}
	DWORD fileSize = GetFileSize(fileHandle, NULL);
	vector<BYTE> buffer(fileSize);
	DWORD bytesRead;
	bool readOK = ReadFile(fileHandle, buffer.data(), fileSize, &bytesRead, NULL);
	if (!readOK)
	{
		wcout << L"Ошибка чтения файла" << endl;
		CloseHandle(fileHandle);
		cout << GetLastError();
		return -1;
	}
	CloseHandle(fileHandle);
	readRAR(buffer,fileSize);
	wcout << L"Размер архива: " << fileSize << L" байт";
	return 0;
}
