#ifndef _SEVEN_ZIP_WORKER_H
#define _SEVEN_ZIP_WORKER_H

#include <vector>

class SevenZipWorker {
public:
	static bool compress(const char *in_path, const char *out_file_name); // ��Ŀ¼����ѹ����example: in_path d:\\work\\folder     out_file_name d:\\folder\\folder.7z
	static bool uncompress(const char *in_file_name, const char *out_path);// ��Ŀ¼���н�ѹ����example: in_file_name d:\\folder\\folder.7z     out_path e:\\test
	static void displayFilenames();
	static int getFileNumber();
	static int getFolderNumber();
	~SevenZipWorker(){}
	//��������ļ���
	enum FileType {NOTHING, ARCH, FOLDER};
public:
//private:
	SevenZipWorker();
	static std::vector<std::string> m_allFilename;
	static FileType initDir(const char *dir);
	//����Ŀ¼ dir ���� filespec ָ�����ļ�����(��ʹ�� * �� ��ͨ���) 
	static bool realTraveseDir(const char *dir, const char *filespec);
	static bool traveseDir(const char *dir);
private:
	//��ų�ʼĿ¼�ľ���·������'\'��β  
	static char m_szInitDir[_MAX_PATH];
	//����ļ�������Ŀ¼�ľ���·��
	static char m_folderDir[_MAX_PATH];
	static int m_fileNumber; // �ļ�����
	static int m_folderNumber; // ���ļ�������
};

#endif _SEVEN_ZIP_WORKER_H