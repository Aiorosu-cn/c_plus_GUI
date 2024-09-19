/******************头文件包含部分*************/
#include <windows.h>    //windows系统头文件

//测试注释
//播放歌曲
//多媒体设备接口的头文件和库文件
#include <mmsystem.h>
#pragma comment(lib ,"winmm.lib")
//然后需要在显示窗口配置

/******************全局常量定义*************/
#define WND_WIDTH 800
#define WND_HEITHT 600

/***************全局函数声明****************/
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
//主函数
//int __stdcall WinMain()	//最终都是使用这个
//int __WINAPI WinMain()
//int CALLBACK WinMain()
//int APIPRIVATE WinMain()

/***************主函数****************/
int WINAPI WinMain(
	HINSTANCE hInstance,     //当前实例句柄,主函数是WinMain,程序的身份证
	HINSTANCE hPrcInstance,  //先前实例句柄
	LPSTR lpCmdline,         //命令行的指针
	int nShowCmd)            //显示的格式
{
	//实例句柄：用来标志在window系统中每一个程序的身份证
	//有时候一个程序是可以同时打开几个
	//用窗口结构体定义一个具体的窗口出来
	//1.声明并初始化一个窗口对象
	WNDCLASSEX window = { 0 };      //window就是我们需要的一个窗口,WNCLASSEX 是一个结构体
							//sizeof是一个专门计算内存大小的运算符
	window.cbSize = sizeof(WNDCLASSEX);    //窗口在内存中需要的内存大小
	window.cbClsExtra = 0;    //程序的附加内存,现在基本没有什么用
	window.cbWndExtra = 0;    //窗口的附加内存，现在基本没有什么用
	window.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);    //背景的画刷,GetStockObject检索预定义的备用笔和备用刷子的句柄
	window.hInstance = hInstance;     //当前实例句柄
	window.style = CS_HREDRAW | CS_VREDRAW;   //窗口的样式,设置为水平重绘和垂直重绘，通过水平和垂直两个方向来改变窗口的大小
	window.lpszClassName = L"for our dream";  //类名称
	window.hCursor = NULL;   //鼠标的样式，自己定义
	window.hIcon = NULL;     //像标，就是我们的像素图标，窗口左上方的图标
	window.lpszMenuName = NULL;      //菜单
	window.lpfnWndProc = WndProc;    //函数指针，窗口的过程函数,
	
	//设计好的窗口不一定能用，所以需要注册窗口
	//2.注册窗口
	RegisterClassEx(&window);

	//3.创建窗口，其中
	/*
	#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED     | \
	WS_CAPTION        | \
	WS_SYSMENU        | \
	WS_THICKFRAME     | \
	WS_MINIMIZEBOX    | \
	WS_MAXIMIZEBOX)
	竖杠表示或运算，斜杠\表示C语言的换行
	*/

	HWND hwnd =  CreateWindow(L"for our dream",				//窗口类
				 L"超级窗口",					//窗口标题
				 WS_OVERLAPPEDWINDOW,			//窗口风格
				 CW_USEDEFAULT,CW_USEDEFAULT,	//窗口初始位置
				 WND_WIDTH,WND_HEITHT,			//窗口口大小
				 NULL,NULL,hInstance,NULL);

	//4.显示窗口，更新窗口
	ShowWindow(hwnd , nShowCmd);
	UpdateWindow(hwnd);

	//向驱动层发送字符串消息 open the door
	mciSendString(L"open ./res/拂世之剑《倩女幽魂2》.mp3 alias music", 0 ,0 ,0);	//alias 取别名
	mciSendString(L"play music", 0, 0, 0);	//alias 取别名


	//5.让窗口等待用户指令，持续输出不会闪退
	//定义一个消息
	MSG msg = { 0 };
	//循环的条件，什么情况下退出，点击右上角的叉，或者右下角的右键退出，或者alt+f4
	//这些都是一个退出的指令
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
//窗口过程函数 ，针对用户的不同指令做出不同的反应
//比如点击播放（这是一个指令），这个函数根据这个指令去播放音乐
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) 
{
	return DefWindowProc(hwnd, message, wparam, lparam);
}
/*
一个程序一定有资源，那么资源放在哪的？


*/