/******************ͷ�ļ���������*************/
#include <windows.h>    //windowsϵͳͷ�ļ�

//����ע��
//���Ÿ���
//��ý���豸�ӿڵ�ͷ�ļ��Ϳ��ļ�
#include <mmsystem.h>
#pragma comment(lib ,"winmm.lib")
//Ȼ����Ҫ����ʾ��������

/******************ȫ�ֳ�������*************/
#define WND_WIDTH 800
#define WND_HEITHT 600

/***************ȫ�ֺ�������****************/
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
//������
//int __stdcall WinMain()	//���ն���ʹ�����
//int __WINAPI WinMain()
//int CALLBACK WinMain()
//int APIPRIVATE WinMain()

/***************������****************/
int WINAPI WinMain(
	HINSTANCE hInstance,     //��ǰʵ�����,��������WinMain,��������֤
	HINSTANCE hPrcInstance,  //��ǰʵ�����
	LPSTR lpCmdline,         //�����е�ָ��
	int nShowCmd)            //��ʾ�ĸ�ʽ
{
	//ʵ�������������־��windowϵͳ��ÿһ����������֤
	//��ʱ��һ�������ǿ���ͬʱ�򿪼���
	//�ô��ڽṹ�嶨��һ������Ĵ��ڳ���
	//1.��������ʼ��һ�����ڶ���
	WNDCLASSEX window = { 0 };      //window����������Ҫ��һ������,WNCLASSEX ��һ���ṹ��
							//sizeof��һ��ר�ż����ڴ��С�������
	window.cbSize = sizeof(WNDCLASSEX);    //�������ڴ�����Ҫ���ڴ��С
	window.cbClsExtra = 0;    //����ĸ����ڴ�,���ڻ���û��ʲô��
	window.cbWndExtra = 0;    //���ڵĸ����ڴ棬���ڻ���û��ʲô��
	window.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);    //�����Ļ�ˢ,GetStockObject����Ԥ����ı��ñʺͱ���ˢ�ӵľ��
	window.hInstance = hInstance;     //��ǰʵ�����
	window.style = CS_HREDRAW | CS_VREDRAW;   //���ڵ���ʽ,����Ϊˮƽ�ػ�ʹ�ֱ�ػ棬ͨ��ˮƽ�ʹ�ֱ�����������ı䴰�ڵĴ�С
	window.lpszClassName = L"for our dream";  //������
	window.hCursor = NULL;   //������ʽ���Լ�����
	window.hIcon = NULL;     //��꣬�������ǵ�����ͼ�꣬�������Ϸ���ͼ��
	window.lpszMenuName = NULL;      //�˵�
	window.lpfnWndProc = WndProc;    //����ָ�룬���ڵĹ��̺���,
	
	//��ƺõĴ��ڲ�һ�����ã�������Ҫע�ᴰ��
	//2.ע�ᴰ��
	RegisterClassEx(&window);

	//3.�������ڣ�����
	/*
	#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED     | \
	WS_CAPTION        | \
	WS_SYSMENU        | \
	WS_THICKFRAME     | \
	WS_MINIMIZEBOX    | \
	WS_MAXIMIZEBOX)
	���ܱ�ʾ�����㣬б��\��ʾC���ԵĻ���
	*/

	HWND hwnd =  CreateWindow(L"for our dream",				//������
				 L"��������",					//���ڱ���
				 WS_OVERLAPPEDWINDOW,			//���ڷ��
				 CW_USEDEFAULT,CW_USEDEFAULT,	//���ڳ�ʼλ��
				 WND_WIDTH,WND_HEITHT,			//���ڿڴ�С
				 NULL,NULL,hInstance,NULL);

	//4.��ʾ���ڣ����´���
	ShowWindow(hwnd , nShowCmd);
	UpdateWindow(hwnd);

	//�������㷢���ַ�����Ϣ open the door
	mciSendString(L"open ./res/����֮����ٻŮ�Ļ�2��.mp3 alias music", 0 ,0 ,0);	//alias ȡ����
	mciSendString(L"play music", 0, 0, 0);	//alias ȡ����


	//5.�ô��ڵȴ��û�ָ����������������
	//����һ����Ϣ
	MSG msg = { 0 };
	//ѭ����������ʲô������˳���������ϽǵĲ棬�������½ǵ��Ҽ��˳�������alt+f4
	//��Щ����һ���˳���ָ��
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}
//���ڹ��̺��� ������û��Ĳ�ָͬ��������ͬ�ķ�Ӧ
//���������ţ�����һ��ָ�����������������ָ��ȥ��������
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) 
{
	return DefWindowProc(hwnd, message, wparam, lparam);
}
/*
һ������һ������Դ����ô��Դ�����ĵģ�


*/