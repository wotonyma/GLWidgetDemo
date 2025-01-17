#ifndef MARKEZDDLL_H
#define MARKEZDDLL_H

#pragma region  Return Value

//所有函数都返回一个整形值
#define LMC1_ERR_SUCCESS         0  //成功
#define LMC1_ERR_EZCADRUN        1  //发现EZCAD在运行
#define LMC1_ERR_NOFINDCFGFILE   2  //找不到EZCAD.CFG
#define LMC1_ERR_FAILEDOPEN      3  //打开LMC1失败
#define LMC1_ERR_NODEVICE        4  //没有有效的lmc1设备
#define LMC1_ERR_HARDVER         5  //lmc1版本错误
#define LMC1_ERR_DEVCFG          6  //找不到设备配置文件
#define LMC1_ERR_STOPSIGNAL      7  //报警信号
#define LMC1_ERR_USERSTOP        8  //用户停止
#define LMC1_ERR_UNKNOW          9  //不明错误
#define LMC1_ERR_OUTTIME         10 //超时
#define LMC1_ERR_NOINITIAL       11 //未初始化
#define LMC1_ERR_READFILE        12 //读文件错误
#define LMC1_ERR_OWENWNDNULL     13 //窗口为空
#define LMC1_ERR_NOFINDFONT      14 //找不到指定名称的字体
#define LMC1_ERR_PENNO           15 //错误的笔号
#define LMC1_ERR_NOTTEXT         16 //指定名称的对象不是文本对象
#define LMC1_ERR_SAVEFILE        17 //保存文件失败
#define LMC1_ERR_NOFINDENT           18 //找不到指定对象
#define LMC1_ERR_STATUE        19 //当前状态下不能执行此操作
#define LMC1_ERR_PARAM          20 //参数错误
#define LMC1_ERR_DEVICE         21 //硬件错误

#pragma endregion

#pragma region Device

//初始化lmc1控制卡
//输入参数: strEzCadPath  EzCad软件的执行路径
//          bTestMode = TRUE 表示测试模式  bTestMode = FALSE 表示正常模式，默认TRUE
//          pOwenWnd      表示父窗口对象，如果需要实现停止打标，则系统会从此窗口截取消息 
typedef int(*LMC1_INITIAL)(TCHAR* strEzCadPath,//ezcad的工作目录(经测试类型必须为WCHAR)
	BOOL bTestMode,//是否是测试模式
	HWND hOwenWnd);//父窗口

// 初始化lmc1控制卡
//输入参数: strEzCadPath  EzCad软件的执行路径
//          bTestMode = TRUE 表示测试模式  bTestMode = FALSE 表示正常模式，默认TRUE
typedef int(*LMC1_INITIAL2)(TCHAR* strEzCadPath,//ezcad的工作目录
	BOOL bTestMode);//是否是测试模式

//关闭lmc1控制卡
typedef int(*LMC1_CLOSE)();

//调用设置设备参数的对话框
typedef int(*LMC1_SETDEVCFG)();

//调用设置设备参数的对话框,显示扩展轴参数
typedef int(*LMC1_SETDEVCFG2)(BOOL bAxisShow0, BOOL bAxisShow1);

#pragma endregion

#pragma region LaserMirrs

//控制振镜直接运动到指定坐标
typedef int(*LMC1_GOTOPOS)(double x, double y);

//获取当前振镜的坐标
typedef int(*LMC1_GETCURCOOR)(double& x, double& y);

#pragma endregion

#pragma region Mark

//标刻当前数据库里的所有数据
//输入参数: bFlyMark = TRUE 使能飞动打标  bFlyMark = FALSE 使能飞动打标
//此函数一直等待设备加工完毕后，或者用户停止才返回。即函数结束表示加工结束
typedef int(*LMC1_MARK)(BOOL bFlyMark);

//标刻当前数据库里的指定对象
//输入参数: strEntName 要加工的指定对象的名称
//此函数一直等待设备加工完毕后才返回
typedef int(*LMC1_MARKENTITY)(TCHAR* strEntName);

//飞行标刻当前数据库里的所有数据
//在使用此函数后，软件开始等待飞行硬件信号（IN8/IN9,在飞行界面中设置的），有信号后开始加工
typedef int(*LMC1_MARKFLYBYSTARTSIGNAL)();

//飞动标刻当前数据库里的指定对象
//输入参数: strEntName 飞动打标指定对象的名称
//此函数一直等待设备加工完毕后才返回
typedef int(*LMC1_MARKENTITYFLY)(TCHAR* strEntName);

//标刻指定线段
//输入参数 x1,y1起点坐标，x2y2终点坐标，pen 使用的笔号
typedef int(*LMC1_MARKLINE)(double x1, double y1, double x2, double y2, int pen);

//标刻指定点
//输入参数 x,y点坐标，delay打标时间，pen 使用的笔号
typedef int(*LMC1_MARKPOINT)(double x, double y, double delay, int pen);

//标刻指定的多个点
//输入参数 ptBuf点坐标组；ptBuf[n][0]表示第n个点的x坐标，ptBuf[n][1]表示第n个点的y坐标，dJumpSpeed在点之间的跳转速度，dLaserOnTimeMs点的打标时间，单位ms
typedef int(*LMC1_MARKPOINTBUF2)(double ptBuf[][2], double dJumpSpeed, double dLaserOnTimeMs);

//判断卡正在处于工作状态
typedef int(*LMC1_ISMARKING)();

//强制停止当前标刻							
typedef int(*LMC1_STOPMARK)();

//标刻一次红光显示框
//预览一次全部对象的打标范围,即数据的包围盒
typedef int(*LMC1_REDLIGHTMARK)();

//红光预览当前数据库里面所有数据轮廓一次
//预览轨迹与打标轨迹一致。如果预览圆，轨迹就是一个圆
typedef int(*LMC1_REDLIGHTMARKCONTOUR)();

//红光预览当前数据库里面指定对象
//输入参数 strEntName对象名称;bContour显示的是否是轮廓，true显示轮廓，false显示范围
typedef int(*LMC1_REDLIGHTMARKBYENT)(TCHAR* strEntName, BOOL bContour);

//获取当前的飞行速度
//输入参数: FlySpeed流水线当前速度
//在设备空闲时可查询流水线速度，即加工或红光过程中不可使用
typedef int(*LMC1_GETFLYSPEED)(double& FlySpeed);

#pragma endregion

#pragma region EzdFile

//载入ezd文件，并清除数据库所有对象
//输入参数: strFileName  EzCad文件名称
typedef int(*LMC1_LOADEZDFILE)(TCHAR* strFileName);

//保存当前数据库里所有对象到指定ezd文件里
//输入参数: strFileName ezd文件名称
typedef int(*LMC1_SAVEENTLIBTOFILE)(TCHAR* strFileName);

#pragma endregion

#pragma region Preview

//得到当前数据库里的所有数据的预览图像
//输入参数: hwnd需要显示当前图像的窗口句柄,nBMPWIDTH 需要生成的图像的像素宽度,nBMPHEIGHT需要生成的图像的像素高度
//在程序中调用lmc1_GetPrevBitmap得到当前数据库里的所有对象的预览图像的指针，可以用于更新界面显示
//typedef  CBitmap* (*LMC1_GETPREVBITMAP)(HWND hwnd, int nBMPWIDTH, int nBMPHEIGHT);

//得到当前数据库里的指定对象数据的预览图像
//输入参数: pWnd         预览图像显示到哪个窗口
//          nBMPWIDTH    预览图像的宽度
//          nBMPHEIGHT   预览图像的高度
//          strEntName    指定对象的名称
//typedef  CBitmap* (*LMC1_GETPREVBITMAPBYNAME)(TCHAR* strEntName, HWND hwnd, int nBMPWIDTH, int nBMPHEIGHT);

#pragma endregion

#pragma region Operation Ent

//得到指定对象的最大最小坐标,如果pEntName==NULL表示读取数据库所有对象的最大最小坐标
typedef int(*LMC1_GETENTSIZE)(TCHAR* pEntName,//字符串对象名称
	double& dMinx,//最小x坐标
	double& dMiny,//最小y坐标
	double& dMaxx,//最大x坐标
	double& dMaxy,//最大y坐标
	double& dZ);//对象的z坐标

//移动指定对象相对坐标
typedef int(*LMC1_MOVEENT)(TCHAR* pEntName,//字符串对象名称
	double dMovex,//对象移动x距离
	double dMovey);//对象移动y距离

//缩放指定对象，
typedef int(*LMC1_SCALEENT)(TCHAR* pEntName,//字符串对象名称
	double dCenx,//缩放的X中心
	double dCeny,//缩放的Y中心
	double dScaleX,//缩放的X比例
	double dScaleY);//缩放的Y比例

//镜像指定对象
typedef  int(*LMC1_MIRRORENT)(TCHAR* pEntName,//字符串对象名称
	double dCenx,// 镜像的X中心
	double dCeny,//镜像的Y中心
	BOOL   bMirrorX,//是否X方向镜像，true表示镜像
	BOOL   bMirrorY);//是否Y方向镜像，true表示镜像

//旋转指定对象
typedef  int(*LMC1_ROTATEENT)(TCHAR* pEntName,//字符串对象名称
	double dCenx,//旋转的X中心
	double dCeny,//旋转的Y中心
	double dAngle);//旋转的角度，(逆时针为正，单位为度)

//复制粘贴指定对象，并对新对象命名
//输入参数：PEntName要复制的对象，pNewEntName复制后的对象名称
typedef int(*LMC1_COPYENT)(TCHAR* pEntName, TCHAR* pNewEntName);

//得到当前数据库中的对象总数
//输出参数:  对象总数
typedef  int(*LMC1_GETENTITYCOUNT)();

//得到指定序号的对象名称
//输入参数: nEntityIndex 指定对象的序号(范围: 0 － (lmc1_GetEntityCount()-1))
//输出参数: szEntName 对象的名称
typedef int(*LMC1_GETENTITYNAME)(int nEntityIndex, TCHAR  szEntName[256]);

//设置指定序号的对象名称
typedef int(*LMC1_SETENTITYNAME)(int nEntityIndex, TCHAR* pEntName);

//修改对象名称
typedef int(*LMC1_CHANGEENTNAME)(TCHAR* pEntName, TCHAR* pNewEntName);

//设置旋转变换参数
//输入参数: dCenterX 旋转中心x坐标
//          dCenterY 旋转中心y坐标
//          dRotateAng 旋转角度(弧度值)
typedef void(*LMC1_SETROTATEPARAM)(double dCenterX, double dCenterY, double dRotateAng);

//设置旋转变换参数 不影响数据的显示,只是加工时才对对象进行旋转。
typedef void(*LMC1_SETROTATEMOVEPARAM)( double dMoveX,//X方向移动距离
										double dMoveY,//Y方向移动距离
										double dCenterX, //旋转中心X坐标
										double dCenterY,//旋转中心Y坐标
										double dRotateAng); //旋转角度(弧度值)

//更改当前数据库里的指定文本对象的文本
//输入参数: strTextName     要更改内容的文本对象的名称
//          strTextNew      新的文本内容
typedef int(*LMC1_CHANGETEXTBYNAME)(TCHAR* strTextName, TCHAR* strTextNew);

//得到指定对象的文本
//strTextName     要获取内容的文本对象的名称,szEntText  文本内容
typedef int(*LMC1_GETTEXTBYNAME)(TCHAR* strTextName, TCHAR strText[256]);

//序列号复位为开始序号
//输入参数：PTextName文本对象名称
typedef int(*LMC1_TEXTRESETSN)(TCHAR* pTextName);

//群组2个对象，并设置群组新的对象名称，以及笔号
typedef int(*LMC1_GROUPENT)(TCHAR* pEntName1,//群组对象1名称
							TCHAR* pEntName2,//群组对象2名称
							TCHAR* pEntNameNew,//群组后新对象名称
							int pen);//新对象使用的笔号

//解散群组
//输入参数：pGroupEntName群组对象名称
typedef int(*LMC1_UNGROUPENT)(TCHAR* pGroupEntName);

//群组N个对象，并设置群组新的对象名称，以及笔号
typedef int(*LMC1_GROUPENT2)(TCHAR** strEntNameList,//对象名称列表
							int nEntCount,//群组对象数量
							TCHAR* strGroupName,//群组后对象名
							int nGroupPen);//新对象使用的笔号

//彻底解散群组对象为曲线
typedef int(*LMC1_UNGROUPENT2)(TCHAR* pGroupEntName,//群组对象名称
	                           int nFlag);//标志位，默认=0

//向前移动对象
typedef int(*LMC1_MOVEENTITYBEFORE)(int nMoveEnt, //要移动的对象在对象列表中的位置
	                                int nGoalEnt);//对象要在对象列表中移动到的位置

//向后移动对象
typedef int(*LMC1_MOVEENTITYAFTER)(int nMoveEnt, //要移动的对象在对象列表中的位置
	                               int nGoalEnt);//对象要在对象列表中移动到的位置

//颠倒所有对象在对象列表中的顺序
typedef int(*LMC1_REVERSEALLENTORDER)();

//获取指定位图的参数
typedef int(*LMC1_GETBITMAPENTPARAM)(TCHAR* strEntName,//位图对象名称
	TCHAR   BmpPath[256],//位图对象路径
	int&      nBmpAttrib,//位图参数
	int&      nScanAttrib,//扫描参数
	double&   dBrightness,//亮度设置[-1, 1]
	double&   dContrast,//对比度设置[-1, 1]
	double&   dPointTime,//打点时间设置
	int&   nImportDpi);//DPI

const int BMPSCAN_INVERT = 0x0001;//图像反转
const int BMPSCAN_GRAY = 0x0002;//图像灰度
const int BMPSCAN_LIGHT = 0x0004;//图像亮度
const int BMPSCAN_DITHER = 0x0010;//网点处理
const int BMPSCAN_BIDIR = 0x1000;//双向扫描
const int BMPSCAN_YDIR = 0x2000;//Y向扫描
const int BMPSCAN_DRILL = 0x4000;//打点模式
const int BMPSCAN_POWER = 0x8000;//调整功率
const int BMPATTRIB_DYNFILE = 0x1000;//动态文件
const int BMPATTRIB_IMPORTFIXED_WIDTH = 0x2000;//固定文件输入宽 
const int BMPATTRIB_IMPORTFIXED_HEIGHT = 0x4000;//固定文件输入高
const int BMPATTRIB_IMPORTFIXED_DPI = 0x8000;//固定DPI

//设置指定位图的参数
typedef int(*LMC1_SETBITMAPENTPARAM2)(TCHAR* strEntName,//位图对象名称
									TCHAR*  strBmpPath,//位图对象路径
									int      nBmpAttrib,//位图参数
									int      nScanAttrib,//扫描参数
									double   dBrightness,//亮度设置[-1, 1]
									double   dContrast,//对比度设置[-1, 1]
									double   dPointTime,//打点时间设置
									int      nImportDpi,//dpi
									BOOL bDisableMarkLowGrayPt,//是否使能低灰度值
									int nMinLowGrayPt);//低灰度值


//获取指定文本的字体参数
typedef int(*LMC1_GETTEXTENTPARAM2)(TCHAR* strTextName,//文本名称
	TCHAR sFontName[256],//字体名称
	double&  dCharHeight,//字符高度
	double&  dCharWidth,//字符宽度
	double&  dCharAngle,//字符倾角（弧度值）
	double&  dCharSpace,// 字符间距
	double&  dLineSpace,//行间距
	double&  dSpaceWidth,//空字符宽带
	BOOL&   bEqualCharWidth);//等字符宽度模式

//设置指定文本的字体参数
typedef int(*LMC1_SETTEXTENTPARAM2)(TCHAR* strTextName,//文本名称
									TCHAR* strFontName,//字体名称
									double dCharHeight,//字符高度
									double dCharWidth,//字符宽度
									double dCharAngle,//字符倾角（弧度值）
									double dCharSpace,//字符间距
									double dLineSpace,//行间距
									double dSpaceWidth,//空字符宽带
									BOOL   bEqualCharWidth);//等字符宽度模式

//获取指定文本的字体参数
typedef int(*LMC1_GETTEXTENTPARAM4)(TCHAR* strTextName,//文本名称
									TCHAR sFontName[256],//字体名称
									int&    nTextSpaceMode,//文本间距模式
									double&  dTextSpace,//文本间距距离
									double&  dCharHeight,// 字符高度
									double&  CharWidthRatio,//字符宽度
									double&  dCharAngle,// 字符倾角（弧度值）
									double&  dCharSpace,//字符间距
									double&  dLineSpace,// 行间距
									double&  spaceWidthRatio,//空字符宽带
									int&    nTextAlign,//文本对齐方式
									BOOL&   bBold,//粗体
									BOOL&   bItalic);//斜体

//设置指定文本的字体参数
typedef int(*LMC1_SETTEXTENTPARAM4)(TCHAR* strTextName,//文本名称
									TCHAR* strFontName,//字体名称
									int nTextSpaceMode,//文本间距模式
									double dTextSpace,//文本间距距离
									double dCharHeight,//字符高度
									double CharWidthRatio,//字符宽度
									double dCharAngle,//字符倾角（弧度值）
									double dCharSpace,// 字符间距
									double dLineSpace,//行间距
									double spaceWidthRatio,//空字符宽带
									int nTextAlign,//文本对齐方式
									bool bBold,//粗体
									bool bItalic);//斜体


//删除对象库里指定对象
typedef int(*LMC1_DELETEENT)(TCHAR* pEntName);

//清除对象库里所有数据
typedef int(*LMC1_CLEARENTLIB)();

#pragma endregion

#pragma region AddEnt

//对齐方式时数字代表的意义
//   6 ---  5 --- 4
//   |            |
//   |            |
//   7      8     3
//   |            |
//   |            |
//   0 ---  1 --- 2
//加入新文本到数据库中
typedef int(*LMC1_ADDTEXTTOLIB)(TCHAR* pStr,//要添加的字符串
	TCHAR* pEntName,//字符串对象名称
	double dPosX,//字符串的左下角基点的x坐标
	double dPosY,//字符串的左下角基点的y坐标
	double dPosZ,//字符串对象的z坐标
	int    nAlign,//对齐方式0－8
	double dTextRotateAngle,//字符串绕基点旋转的角度值(弧度值)
	int nPenNo,//对象使用的加工参数
	BOOL bHatchText);//是否填充文本对象

#define CIRTEXTFLAG_REVERSE  	0x0001	//反转
#define CIRTEXTFLAG_UPDOWN  	0x0002	//上下反转 

//添加圆弧文本
typedef int(*LMC1_ADDCIRCLETEXTTOLIB)(TCHAR* pStr,//要添加的字符串
	TCHAR* pEntName,//字符串对象名称
	double dPosX,//文本所在基准圆的x坐标
	double dPosY,//文本所在基准圆的y坐标
	double dPosZ,//字符串对象的z坐标
	int nPenNo,//文本对象使用的笔号
	int bHatchText,//是否填充文本 
	double dCirDiameter,//基准圆直径
	double dCirBaseAngle,//文字基准角度
	BOOL bCirEnableAngleLimit,//是否使能角度限制 
	double dCirAngleLimit, //限制的角度 
	int nCirTextFlag);//文本在圆上的方向

//获得指定圆弧文本对象的参数
typedef int(*LMC1_GETCIRCLETEXTPARAM)(  TCHAR* pEntName,//字符串对象名称
										double& dCenX,//文本所在基准圆的x坐标
										double& dCenY,//文本所在基准圆的y坐标
										double &dCenZ,//字符z坐标
										double& dCirDiameter,//基准圆直径
										double& dCirBaseAngle,//文字基准角度
										BOOL& bCirEnableAngleLimit,//是否使能角度限制 
										double & dCirAngleLimit,//限制的角度 
										int& nCirTextFlag); //文本在圆上的方向

//设置指定圆弧文本对象的参数
typedef int(*LMC1_SETCIRCLETEXTPARAM)(  TCHAR* pEntName,//字符串对象名称
										double dCenX,//文本所在基准圆的x坐标
										double dCenY,//文本所在基准圆的y坐标
										double dCenZ,//字符z坐标
										double dCirDiameter,//基准圆直径 
										double dCirBaseAngle,//文字基准角度
										BOOL bCirEnableAngleLimit,//是否使能角度限制 
										double dCirAngleLimit,//限制的角度 
										int nCirTextFlag);//文本在圆上的方向


//加入指定文件到数据库中
//支持的文件有ezd,dxf,dst,plt,ai,bmp,jpg,tga,png,gif,tiff等
typedef int(*LMC1_ADDFILETOLIB)(TCHAR* pFileName,	//文件名称
	TCHAR* pEntName,//字符串对象名称
	double dPosX, //文件左下角基点x坐标
	double dPosY, //文件左下角基点y坐标
	double dPosZ, //文件z坐标
	int    nAlign,//对齐方式0－8
	double dRatio,//文件缩放比例				  
	int nPenNo,//对象使用的加工参数
	BOOL bHatchFile);//是否填充文件对象 如果是ezd文件或位图文件此参数无效
// 加入曲线到数据库中
typedef int(*LMC1_ADDCIRCLETOLIB)(double ptCenX,//圆心X
	double ptCenY,//圆心Y
	double dRadius,//圆半径
	TCHAR* pEntName,//曲线对象名称
	int nPenNo//曲线对象使用的笔号
	);//曲线是否填充


//加入曲线到数据库中
typedef int(*LMC1_ADDCURVETOLIB)(double ptBuf[][2],//曲线顶点数组
	int  ptNum,//曲线顶点数
	TCHAR* pEntName,//曲线对象名称
	int nPenNo,//曲线对象使用的笔号
	int bHatch);//曲线是否填充

//加入一组点到数据库中
typedef int(*LMC1_ADDCURVETOLIB2)(double* ptBuf,//曲线顶点数组
	int  ptNum,//曲线顶点数
	TCHAR* pEntName,//曲线对象名称
	int nPenNo,//曲线对象使用的笔号
	int bHatch);//曲线是否填充

//加入延时到数据库中
//输入参数：延时时长，单位ms
typedef int(*LMC1_ADDDELAYTOLIB)(double dDelayMs);

//加入输出口到数据库中
typedef int(*lmc1_AddWritePortToLib)(   int nOutPutBit,//输出口的值，0到15
										BOOL bHigh, //是否是高电平
										BOOL bPluse, //是否是脉冲
										double dPulseTimeMs);//脉冲长的，单位ms


#define BARCODETYPE_39      0
#define BARCODETYPE_93      1
#define BARCODETYPE_128A    2
#define BARCODETYPE_128B    3
#define BARCODETYPE_128C    4
#define BARCODETYPE_128OPT  5
#define BARCODETYPE_EAN128A 6
#define BARCODETYPE_EAN128B 7
#define BARCODETYPE_EAN128C 8
#define BARCODETYPE_EAN13   9
#define BARCODETYPE_EAN8    10
#define BARCODETYPE_UPCA    11
#define BARCODETYPE_UPCE    12
#define BARCODETYPE_25      13
#define BARCODETYPE_INTER25 14
#define BARCODETYPE_CODABAR 15
#define BARCODETYPE_PDF417  16
#define BARCODETYPE_DATAMTX 17
#define BARCODETYPE_USERDEF  18
#define BARCODETYPE_QRCODE 19
#define BARCODETYPE_MINIDATAMTX  20




#define BARCODEATTRIB_REVERSE          0x0008 //条码反转
#define BARCODEATTRIB_HUMANREAD        0x1000 //显示人识别字符
#define BARCODEATTRIB_CHECKNUM         0x0004 //需要校验码
#define BARCODEATTRIB_PDF417_SHORTMODE 0x0040 //PDF417为缩短模式
#define BARCODEATTRIB_DATAMTX_DOTMODE  0x0080 //DataMtrix为点模式
#define BARCODEATTRIB_CIRCLEMODE       0x0100 //自定义二维码为圆模式


#define DATAMTX_SIZEMODE_SMALLEST  0
#define DATAMTX_SIZEMODE_10X10     1
#define DATAMTX_SIZEMODE_12X12     2
#define DATAMTX_SIZEMODE_14X14     3
#define DATAMTX_SIZEMODE_16X16     4
#define DATAMTX_SIZEMODE_18X18     5
#define DATAMTX_SIZEMODE_20X20     6
#define DATAMTX_SIZEMODE_22X22     7
#define DATAMTX_SIZEMODE_24X24     8
#define DATAMTX_SIZEMODE_26X26     9
#define DATAMTX_SIZEMODE_32X32     10
#define DATAMTX_SIZEMODE_36X36     11
#define DATAMTX_SIZEMODE_40X40     12
#define DATAMTX_SIZEMODE_44X44     13
#define DATAMTX_SIZEMODE_48X48     14
#define DATAMTX_SIZEMODE_52X52     15
#define DATAMTX_SIZEMODE_64X64     16
#define DATAMTX_SIZEMODE_72X72     17
#define DATAMTX_SIZEMODE_80X80     18
#define DATAMTX_SIZEMODE_88X88     19
#define DATAMTX_SIZEMODE_96X96     20
#define DATAMTX_SIZEMODE_104X104   21
#define DATAMTX_SIZEMODE_120X120   22
#define DATAMTX_SIZEMODE_132X132   23
#define DATAMTX_SIZEMODE_144X144   24
#define DATAMTX_SIZEMODE_8X18     25
#define DATAMTX_SIZEMODE_8X32     26
#define DATAMTX_SIZEMODE_12X26     27
#define DATAMTX_SIZEMODE_12X36     28
#define DATAMTX_SIZEMODE_16X36     29
#define DATAMTX_SIZEMODE_16X48     30

//加入条码到数据库中
typedef int(*LMC1_ADDBARCODETOLIB)(TCHAR* pStr,	//字符串
	TCHAR* pEntName,//字符串对象名称
	double dPosX, //字符左下角基点x坐标
	double dPosY, //字符左下角基点y坐标
	double dPosZ, //字符z坐标
	int    nAlign,//对齐方式0－8
	int    nPenNo,
	int    bHatchText,
	int    nBarcodeType,//条码类型
	WORD   wBarCodeAttrib,//条码属性
	double dHeight,//整个条码的高	
	double dNarrowWidth,//最窄模块宽	
	double dBarWidthScale[4],//条宽比例	(与最窄模块宽相比)
	double dSpaceWidthScale[4],//空宽比例(与最窄模块宽相比)
	double dMidCharSpaceScale,//字符间隔比例(与最窄模块宽相比)
	double dQuietLeftScale,//条码左空白宽度比例(与最窄模块宽相比)
	double dQuietMidScale,//条码中空白宽度比例(与最窄模块宽相比)
	double dQuietRightScale,//条码右空白宽度比例(与最窄模块宽相比)	
	double dQuietTopScale,//条码上空白宽度比例(与最窄模块宽相比)
	double dQuietBottomScale,//条码下空白宽度比例(与最窄模块宽相比)						 
	int    nRow,//二维码行数
	int    nCol,//二维码列数
	int    nCheckLevel,//pdf417错误纠正级别0-8
	int    nSizeMode,//DataMatrix尺寸模式0-30
	double dTextHeight,//人识别字符字体高度
	double dTextWidth,//人识别字符字体宽度
	double dTextOffsetX,//人识别字符X方向偏移
	double dTextOffsetY,//人识别字符Y方向偏移
	double dTextSpace,//人识别字符间距
	double dDiameter,
	TCHAR* pTextFontName);//文本字体名称

//获取条码参数
typedef int(*LMC1_GETBARCODEPARAM)( TCHAR* pEntName,//对象名称
									WORD&wBarCodeAttrib,//条码属性
									int& nSizeMode,//尺寸模式
									int& nCheckLevel,//错误纠正级别
									int& nLangPage,//语言编码页
									double& dDiameter,
									int&nPointTimesN,//点倍数
									double& dBiDirOffset);//双向扫描补偿

//语言编码                   int
//Default                     0
//ANSI(7Bit 1252)             437
//Latin - 1(ISO 8859 - 1)          850
//Japanese(SHIFT - JIS, 932)      932
//Korea(Hangul, 949)           949
//Simple Chinses(GB2312, 936)   936
//Trad chinese(BIG5, 950)       950
//UNICODE(UTF8)            65001

//设置条码参数
typedef int(*LMC1_SETBARCODEPARAM)(TCHAR* pEntName,//对象名称
									WORD  wBarCodeAttrib,//条码属性
									int  nSizeMode,// 尺寸模式
									int  nCheckLevel,//错误纠正级别
									int  nLangPage,//语言编码页
									double  dDiameter,//圆模式直径（矩形模式单元模块高）
									int nPointTimesN,//点倍数
									double  dBiDirOffset);//双向扫描补偿

#pragma endregion

#pragma region IO

// 读lmc1的输入端口
//输入参数: 读入的输入端口的数据
typedef int(*LMC1_READPORT)(WORD& data);

// 读lmc1的输出端口
//输入参数: 读入的输出端口的数据
typedef int(*LMC1_GETOUTPORT)(WORD& data);

// 写lmc1的输出端口
//输入参数: 要写到的输出端口的数据
typedef int(*LMC1_WRITEPORT)(WORD data);

#pragma endregion

#pragma region Hatch


const int HATCHATTRIB_ALLCALC = 0x01;//全部对象整体计算
const int HATCHATTRIB_EDGE = 0x02;//绕边走一次
const int HATCHATTRIB_MINUP = 0x04;//最少起笔
const int HATCHATTRIB_BIDIR = 0x08;//双向填充
const int HATCHATTRIB_LOOP = 0x10;//环行填充
const int HATCHATTRIB_OUT = 0x20;//环行由内向外
const int HATCHATTRIB_AUTOROT = 0x40;//自动角度旋转
const int HATCHATTRIB_AVERAGELINE = 0x80;//自动分布填充线
const int HATCHATTRIB_CROSELINE = 0x400;//交叉填充

typedef int(*LMC1_GETHATCHPARAM3)(bool& bEnableContour,
	int nParamIndex,
	int& bEnableHatch,
	int& nPenNo,
	int& nHatchType,
	bool& bHatchAllCalc,
	bool& bHatchEdge,
	bool& bHatchAverageLine,
	double& dHatchAngle,
	double& dHatchLineDist,
	double& dHatchEdgeDist,
	double& dHatchStartOffset,
	double& dHatchEndOffset,
	double& dHatchLineReduction,//直线缩进
	double& dHatchLoopDist,//环间距
	int& nEdgeLoop,//环数
	bool& nHatchLoopRev,//环形反转
	bool& bHatchAutoRotate,//是否自动旋转角度
	double& dHatchRotateAngle,
	bool& nHatchCross);


typedef int(*LMC1_SETHATCHPARAM3)(BOOL bEnableContour,//使能轮廓本身
	int nParamIndex,//填充参数序号值为1,2,3
	int bEnableHatch,//使能填充
	int nPenNo,//填充参数笔号
	int nHatchType,//填充类型 0单向 1双向 2回形 3弓形 4弓形不反向
	bool bHatchAllCalc,//是否全部对象作为整体一起计算
	bool bHatchEdge,//绕边一次
	bool bHatchAverageLine,//自动平均分布线
	double dHatchAngle,//填充线角度 
	double dHatchLineDist,//填充线间距
	double dHatchEdgeDist,//填充线边距    
	double dHatchStartOffset,//填充线起始偏移距离
	double dHatchEndOffset,//填充线结束偏移距离
	double dHatchLineReduction,//直线缩进
	double dHatchLoopDist,//环间距
	int nEdgeLoop,//环数
	bool nHatchLoopRev,//环形反转
	bool bHatchAutoRotate,//是否自动旋转角度
	double dHatchRotateAngle,//自动旋转角度  
	bool bHatchCross);

typedef int(*LMC1_GETHATCHENTPARAM2)(TCHAR* HatchName,
	bool& bEnableContour,
	int nParamIndex,
	int& bEnableHatch,
	bool&  bContourFirst,
	int& nPenNo,
	int& nHatchType,
	bool& bHatchAllCalc,
	bool& bHatchEdge,
	bool& bHatchAverageLine,
	double& dHatchAngle,
	double& dHatchLineDist,
	double& dHatchEdgeDist,
	double& dHatchStartOffset,
	double& dHatchEndOffset,
	double& dHatchLineReduction,//直线缩进
	double& dHatchLoopDist,//环间距
	int& nEdgeLoop,//环数
	bool& nHatchLoopRev,//环形反转
	bool& bHatchAutoRotate,//是否自动旋转角度
	double& dHatchRotateAngle,
	bool&  bHatchCrossMode,
	int&   dCycCount);


typedef int(*LMC1_SETHATCHENTPARAM2)(TCHAR* HatchName,
	bool bEnableContour,
	int nParamIndex,
	int bEnableHatch,
	bool bContourFirst,
	int nPenNo,
	int nHatchType,
	bool bHatchAllCalc,
	bool bHatchEdge,
	bool bHatchAverageLine,
	double dHatchAngle,
	double dHatchLineDist,
	double dHatchEdgeDist,
	double dHatchStartOffset,
	double dHatchEndOffset,
	double dHatchLineReduction,//直线缩进
	double dHatchLoopDist,//环间距
	int nEdgeLoop,//环数
	bool nHatchLoopRev,//环形反转
	bool bHatchAutoRotate,//是否自动旋转角度
	double dHatchRotateAngle,
	bool    bHatchCrossMode,
	int    dCycCount);

typedef int(*LMC1_HATCHENT)(TCHAR*  strEntName, TCHAR*  strHatchEntName);
typedef int(*LMC1_UNHATCHENT)(TCHAR*  strHatchEntName);

#pragma endregion

#pragma region Font

//获取当前默认的字体参数
typedef int(*LMC1_GETFONTPARAM3)(TCHAR* strFontName,  //字体名称 
								double&   dCharHeight, //字符高度
								double&   dCharWidth, //字体宽度 
								double&   dCharAngle, //字体角度 
								double&   dCharSpace, //字体间距 
								double&   dLineSpace, //行间距
								BOOL&   EqualCharWidth,//空字符宽度
								int&   nTextAlign, //文本对齐方式 
								BOOL&   bBold, //粗体
								BOOL&   bItalic); //斜体

//设置当前默认的字体参数
typedef int(*LMC1_SETFONTPARAM3)(TCHAR* strFontName,  //字体名称 
								double dCharHeight, //字符高度
								double dCharWidth, //字体宽度 
								double dCharAngle, //字体角度 
								double dCharSpace, //字体间距 
								double dLineSpace, //行间距
								BOOL EqualCharWidth,//空字符宽度
								int nTextAlign, //文本对齐方式 
								BOOL bBold, //粗体
								BOOL bItalic );//斜体



							//字体类型属性定义
#define FONTATB_JSF        0x0001        //JczSingle字型
#define FONTATB_TTF        0x0002        //TrueType字型   
#define FONTATB_DMF        0x0004        //DotMatrix字型   
#define FONTATB_BCF        0x0008        //BarCode字型  

							//字型记录
struct lmc1_FontRecord
{
	TCHAR   szFontName[256];     //字体名字	    
	DWORD   dwFontAttrib;       //字体属性
};

typedef int(*LMC1_GETFONTRECORDCOUNT)(int& nFontNum);

//得到当前系统支持的所有字体参数
//输入参数: 无
//输出参数: nFontNum 字体数目
//返回参数: lmc1_FontRecord* 字体记录数组
typedef lmc1_FontRecord* (*LMC1_GETALLFONTRECORD)(int Index, TCHAR*FontName, DWORD & FontAttrib);

#pragma endregion

#pragma region Pen

//得到指定笔号对应的加工参数
typedef int(*LMC1_GETPENPARAM)( int      nPenNo,//要设置的笔号(0-255)					 
								int&      nMarkLoop,//加工次数
								double&   dMarkSpeed,//标刻次数mm/s
								double&   dPowerRatio,//功率百分比(0-100%)	
								double&   dCurrent,//电流A
								int&      nFreq,//频率HZ
								double&      dQPulseWidth,//Q脉冲宽度us	
								int&      nStartTC,//开始延时us
								int&      nLaserOffTC,//激光关闭延时us 
								int&      nEndTC,//结束延时us
								int&      nPolyTC,//拐角延时us   
								double&   dJumpSpeed, //跳转速度mm/s
								int&      nJumpPosTC, //跳转位置延时us
								int&      nJumpDistTC,//跳转距离延时us	
								double&   dEndComp,//末点补偿mm
								double&   dAccDist,//加速距离mm	
								double&   dPointTime,//打点延时 ms						 
								BOOL&     bPulsePointMode,//脉冲点模式 
								int&      nPulseNum,//脉冲点数目
								double&   dFlySpeed);

//得到对应笔号的参数
typedef int(*LMC1_GETPENPARAM2)(int       nPenNo,//要设置的笔号(0-255)						 
								int&      nMarkLoop,//加工次数
								double&   dMarkSpeed,//标刻次数mm/s
								double&   dPowerRatio,//功率百分比(0-100%)	
								double&   dCurrent,//电流A
								int&      nFreq,//频率HZ
								double&      dQPulseWidth,//Q脉冲宽度us	
								int&      nStartTC,//开始延时us
								int&      nLaserOffTC,//激光关闭延时us 
								int&      nEndTC,//结束延时us
								int&      nPolyTC,//拐角延时us   //	
								double&   dJumpSpeed, //跳转速度mm/s
								int&      nJumpPosTC, //跳转位置延时us
								int&      nJumpDistTC,//跳转距离延时us	
								double&   dPointTime,//打点延时 ms		
								int& nSpiWave,//SPI波形
								BOOL&     bWobbleMode,//抖动模式
								double&   bWobbleDiameter,//抖动直径
								double&   bWobbleDist);//抖动间距

//得到对应笔号的参数
typedef int(*LMC1_GETPENPARAM4)(int      nPenNo,//要设置的笔号(0-255)	
	TCHAR   sPenName[256],// 笔名字，默认default
	int&      clr,//笔颜色
	BOOL&      bDisableMark,//是否使能笔号，true关闭笔号不标刻
	BOOL&       bUseDefParam,//是否使用默认值
	int&      nMarkLoop,//加工次数
	double&   dMarkSpeed,//标刻次数mm/s
	double&   dPowerRatio,//功率百分比(0-100%)	
	double&   dCurrent,//电流A
	int&      nFreq,//频率HZ
	double&      dQPulseWidth,//Q脉冲宽度us	
	int&      nStartTC,//开始延时us
	int&      nLaserOffTC,//激光关闭延时us
	int&      nEndTC,//结束延时us
	int&      nPolyTC,//拐角延时us   //	
	double&   dJumpSpeed, //跳转速度mm/s
	int&      nMinJumpDelayTCUs, //最小跳转延时us
	int&      nMaxJumpDelayTCUs,//最大跳转延时us	
	double&   dJumpLengthLimit,//跳转长的极限 		
	double&   dPointTime,//打点时间 ms	
	BOOL&   nSpiSpiContinueMode,//SPI连续模式
	int&      nSpiWave,// SPI波形选择	
	int&      nYagMarkMode,// YAG优化填充模式
	BOOL&   bPulsePointMode,//脉冲点模式
	int&      nPulseNum,// 脉冲点数
	BOOL&   bEnableACCMode,//使能加速模式
	double &   dEndComp,//末点补偿
	double&    dAccDist,//加速距离
	double&    dBreakAngle,//中断角度，角度值
	BOOL&   bWobbleMode,//抖动模式 
	double &   bWobbleDiameter,//抖动直径
	double&    bWobbleDist);//抖动间距


//设置指定笔号对应的加工参数
typedef int(*LMC1_SETPENPARAM)(int      nPenNo,//要设置的笔号(0-255)					 
	int      nMarkLoop,//加工次数
	double   dMarkSpeed,//标刻次数mm/s
	double   dPowerRatio,//功率百分比(0-100%)	
	double   dCurrent,//电流A
	int      nFreq,//频率HZ
	double      dQPulseWidth,//Q脉冲宽度us
	int      nStartTC,//开始延时us
	int      nLaserOffTC,//激光关闭延时us 
	int      nEndTC,//结束延时us
	int      nPolyTC,//拐角延时us   //	
	double   dJumpSpeed, //跳转速度mm/s
	int      nJumpPosTC, //跳转位置延时us
	int      nJumpDistTC,//跳转距离延时us	
	double   dEndComp,//末点补偿mm
	double   dAccDist,//加速距离mm	
	double   dPointTime,//打点延时 ms						 
	BOOL     bPulsePointMode,//脉冲点模式 
	int      nPulseNum,//脉冲点数目
	double   dFlySpeed);//飞行速度==0


//设置指定笔号对应的加工参数
typedef int(*LMC1_SETPENPARAM2)(int      nPenNo,//要设置的笔号(0-255)					 
	int      nMarkLoop,//加工次数
	double   dMarkSpeed,//标刻次数mm/s
	double   dPowerRatio,//功率百分比(0-100%)	
	double   dCurrent,//电流A
	int      nFreq,//频率HZ
	double      dQPulseWidth,//Q脉冲宽度us	
	int      nStartTC,//开始延时us
	int      nLaserOffTC,//激光关闭延时us 
	int      nEndTC,//结束延时us
	int      nPolyTC,//拐角延时us   //	
	double   dJumpSpeed, //跳转速度mm/s
	int      nJumpPosTC, //跳转位置延时us
	int      nJumpDistTC,//跳转距离延时us
	double   dPointTime,//打点延时 ms	
	int      nSpiWave,//SPI激光器波形设置
	BOOL     bWobbleMode,//是否开启抖动功能
	double   bWobbleDiameter,//抖动直径
	double   bWobbleDist);//抖动间距

//设置对应笔号的参数
typedef int(*LMC1_SETPENPARAM4)(int       nPenNo,//要设置的笔号(0-255)	
								TCHAR*  sPenName,// 笔名字，默认default
								int       clr,//笔颜色
								BOOL    bDisableMark,//是否使能笔号，true关闭不标刻
								BOOL        bUseDefParam,//是否使用默认值
								int       nMarkLoop,//加工次数
								double    dMarkSpeed,//标刻次数mm/s
								double    dPowerRatio,//功率百分比(0-100%)	
								double    dCurrent,//电流A
								int       nFreq,//频率HZ
								double    dQPulseWidth,//Q脉冲宽度us	
								int       nStartTC,//开始延时us
								int       nLaserOffTC,//激光关闭延时us
								int       nEndTC,//结束延时us
								int       nPolyTC,//拐角延时us   //	
								double    dJumpSpeed, //跳转速度mm/s
								int&      nMinJumpDelayTCUs, //最小跳转延时us
								int       nMaxJumpDelayTCUs,//最大跳转延时us	
								double    dJumpLengthLimit,//跳转长的极限 		
								double    dPointTime,//打点时间 ms	
								BOOL    nSpiSpiContinueMode,//SPI连续模式
								int       nSpiWave,// SPI波形选择	
								int       nYagMarkMode,// YAG优化填充模式
								BOOL    bPulsePointMode,//脉冲点模式
								int&      nPulseNum,// 脉冲点数
								BOOL    bEnableACCMode,//使能加速模式
								double     dEndComp,//末点补偿
								double     dAccDist,//加速距离
								double     dBreakAngle,//中断角度
								BOOL    bWobbleMode,//抖动模式 
								double     bWobbleDiameter,//抖动直径
								double     bWobbleDist);//抖动间距

#pragma endregion

#pragma region Axis

//复位扩展轴坐标
//输入参数:  bEnAxis0 = 使能轴0  bEnAxis1 = 使能轴1
//在程序中调用扩展轴相关的函数，必须先调用lmc1_Reset来设置使能对应的轴;当扩展轴运动到极限位置时，可以用此函数复位扩展轴坐标。
typedef double(*LMC1_RESET)(BOOL bEnAxis0, BOOL bEnAxis1);

//扩展轴移动到指定坐标位置
//输入参数: axis     扩展轴  0 = 轴0  1 = 轴1
//          GoalPos  坐标位置
//在程序中调用lmc1_AxisMoveTo可以使扩展轴移动到指定坐标位置，扩展轴的运动速度使用设备参数里定义的最大速度。
typedef int(*LMC1_AXISMOVETO)(int axis, double GoalPos);

//扩展轴校正原点
//输入参数: axis     扩展轴  0 = 轴0  1 = 轴1
//在程序中调用lmc1_AxisCorrectOrigin可以使扩展轴自动校正原点。
typedef int(*LMC1_AXISCORRECTORIGIN)(int axis);

//得到扩展轴的当前坐标
//输入参数: axis扩展轴  0 = 轴0  1 = 轴1
typedef double(*LMC1_GETAXISCOOR)(int axis);

//扩展轴移动到指定脉冲坐标位置
//输入参数: axis     扩展轴  0 = 轴0  1 = 轴1
//          nGoalPos  脉冲坐标位置
typedef int(*LMC1_AXISMOVETOPULSE)(int axis, int nGoalPos);

//得到扩展轴的当前脉冲坐标
//输入参数: axis扩展轴  0 = 轴0  1 = 轴1
typedef int(*LMC1_GETAXISCOORPULSE)(int axis);

#pragma endregion

#endif