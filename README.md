# 2018IFR_Hero_Vice2.0_YuXin


5.11新增：
拖车检测、自动上下岛安全加速检测：
								拖车：B3口4pin红信号线-PC10，switch第5位，senddata数据帧第二个字节第2位
								上下岛新增：B3口4pin白信号线-PC11，switch第4位，senddata数据帧第二个字节第1位
								主副版协议传输第二个数据字节
								
新增红外需要修改的地方：
1.初始化IO
2.IO数据采集到Switch结构体&结构体更改数量、率可能需要更改
3.Switch结构体传输到Senddata
4.？