#技术应用原因
#一些老旧的设备的SDK为win-x86，而新程序的arch为win-x64
#希望能将两个程序揉合在一起，一键启动，一键停止。
#之前由于32位SDK写过进程外COM组件,在同一台机上运行良好，可是局域网跨机调用始终有问题。
#这次改用tcp RPC方式来调用32位SDK的方法，此方式简单易于调试。

#一键启动简单, 直接使用CreateProcess启动32位子进程即可
#避坑: 如果参数不设置lpCurrentDirectory, 子进程的默认当前目录为父进程的当前目录

#一键停止有很多坑, 主要用Windows消息机制来实现的
#坑1: 根据网上的说法使用PostMessage向子进程发送消息，使用EnumWindows()枚举所有顶级窗口。
      由于我创建的子进程是一个控制台程序，始终无法找到子进程的HWND[其实未创建任何窗口,自然找不到]。
	  原因: 需要用在创建子进程时设置dwCreationFlag: CREATE_NEW_CONSOLE.
	  这样子进程会生成一个新的控制台,能获取控制台的HWND.
	  
#坑2: 如果子进程就是没有窗口呢(比如子进程是控制台程序并且CMake使用WIN32标志隐藏了控制台，又比如上述在创建时就没有使用新的控制台)
	  [注意] 当窗口被hide时也无法获取HWND
	  此时PostMessage & SendMessage就无法使用了。
	  应该使用PostThreadMessage向子进程发送消息。参数中的线程id为创建进程中PROCESS_INFORMATION的dwThreadId[猜测此Id为子进程主线程Id]
	  
	  
然后子进程可以使用GetMessage来获取一次消息(所以是在事件循环中接受消息处理);
由于我的子进程是基于Qt的一个程序
可以继承QAbstractNativeEventFilter，然后安装事件过滤器app.installNativeEventFilter(&eventFilter);