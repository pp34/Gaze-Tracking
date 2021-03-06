# Gaze-Tracking
STM32 for Gaze Tracking
0、需求：
	
	在软件方案不确定的情况下，完成一个泛用性较好的硬件系统，来外部辅助瞳孔定位和视线跟踪。

1、方法与原理说明
	
	参考方法：包包和李扬的系统设计；
	1、通过外环leds（950nm波长）和内环leds（850nm波长）的交替闪烁，实现明瞳和暗瞳效应；
	2、以下编号D4、D5、D17、D18、D39、D40、D61、D62（详细见PCB板丝印）的led 可以单独点亮，完全能达到《瞳孔-角膜反射原理》的硬件要求。
	
	
	了解了明瞳（bright eye effect）与暗瞳追踪原理，瞳孔角膜反射追踪是可以用明瞳和暗瞳两种技术，两种技术又有各自的光源配置。明瞳追踪，是光源与成像设备在同一条光学路径上；暗瞳追踪，即光源放置在成像设备较远的位置(不在同一条光学路径上)，产生瞳孔比虹膜暗的效果（明显的对比）。
	在使用这两种追踪技术时，瞳孔的检测都会受到不同的因素影响。例如，当使用明瞳追踪时，诸如被试者的年龄和光线环境等因素可能会对眼睛的追踪能力产生影响。被试者的人种也是能够影响明瞳/暗瞳追踪的其他因素之一：对于拉美和高加索人种来说，明瞳追踪的效果较好，但是这种方法经证实不太适合亚洲人种；而对于亚洲人种，暗瞳追踪可提供更好的追踪能力。
	
	bright eye effect亮瞳效应：美国著名的学者Hutchinson在眼睛运动检测专利中提出的，当靠近摄像头光轴的红外光源照射到人脸时，视网膜反射光会使瞳孔显得很亮就是所谓的亮瞳效应，当然眼角膜也会反射光，会在眼球上出现比较小的亮点(glint)。经过试验发现，出现亮瞳孔的亮度主要跟三个因素有关：离摄像头光轴的距离、光源的波长、光照强度。距离摄像头光轴的距离越近，反射光就越多进入摄像头，瞳孔就会显得越亮。人眼瞳孔对近红外光有较高的透射率，而人眼视网膜对不同的波长的光具有不同的反射量，对850 nm的红外光能把90%的入射光反射回去，对950 nm的红外光能把40%的入射光反射回去。
	
	

2、方案选择：

	2.1、光源选择：
		
		因为靠近摄像头轴上的光源选择850 nm的红外光较好，容易产生亮瞳孔，轴外的光源选择950 nm的红外光较好，会出现暗瞳孔。由于外界可见光会影响到亮瞳效应，因此在摄像头上会加上近红外滤光片，考虑到成本和使用效果用830 nm的高通滤光片就可以了。
		
		最后，因为淘宝上不好找950nm波长的红外发射管，改为选择850nm近红外光源LED做内环，950nm近红外光源LED做外环。
		
	2.2、电源模块：
	
		2.2.1、LM2596T-5.0开关电压调节器
		
			考虑到74HC595芯片需要5V供电、单片机需要3.3V供电，以及约80个led，每个使用15~20mA的电流驱动，所以，决定使用LM2596T-5.0开关电压调节器，将锂电池的固定输入12V降压为5V输出，并且最大能输出3A电流，在特定的输入电压和输出负载的条件下，输出电压的误差可以保证在±4%的范围内，振荡频率误差在±15%的范围内；
			附电路图：
			
			
			
		2.2.2、AMS1117-3.3正向低压降稳压器
		
			将5V的固定输入降压到3.3V输出，提供单片机和led的电压。
			附电路图：
			
			
			
		2.2.3、LED驱动
			
			考虑过恒流源的驱动方式，但是鉴于成本和工程时长考虑，选用了较为简单的、基极电压控制的单三极管驱动。
			另外，因为两种方法点亮LED的数目不同，所以配置了单独的和组联的LED。
			附电路图：
			
			
	
		2.2.4、单片机和74HC595
	
			单片机选用STM32F103C8T6，吹；
			为了减少电压控制所要的引脚数量，并且保护单片机不被LED点亮时的瞬间电流冲击，使用了两片74HC5958位串行输入、平行输出的位移缓存器，来起到锁存控制三极管开关和三态缓冲器的作用。
			附电路图：
					
			
			
		
		2.2.5、指示灯
	
			电源指示灯，红色，亮起表示已通电；
			D3、D4分别是外环、内环亮起的指示灯，亮灯表示对应的环被点亮。
			附电路图：
	
					
	
	
	3、成品图
	
	
	
	
	
	4、MATLAB通讯接口
	
		4.1、大概流程：
			
			下位机和PC通过串口通讯，PC通过串口把亮灭灯的指令给到下位机，下位机响应，作出指令的对应动作之后，返回相关的文本信息。
		
		4.2、函数说明：
			
			4.2.1、
				function [s] = Serial_Init(com)
			
				功能：初始化串口参数，打开串口
				输入：com对应串口名字
				返回：串口对象
			
			4.2.2、
				function [ack] = Usart4STM32_Send(ser, str)
			
				功能：发送数据给STM32下位机
				输入：ser被打开的串口对象，str字符串信息
				返回：ack下位机的应答文本
			
			4.2.3、
				function [] = Serial_Close(ser)
			
				功能：关闭串口，删除串口对象
				输入：ser被打开的串口对象
				返回：无
			
			4.2.4、
				function [ack] = AllLedsOff(ser)
			
				功能：传达“灭掉所有的leds”的指令
				输入：ser被打开的串口对象
				返回：ack下位机的应答文本
			
			4.2.5、
				function [ack] = AllLedsOn(ser)
			
				功能：传达“点亮所有的leds”的指令
				输入：ser被打开的串口对象
				返回：ack下位机的应答文本
			
			4.2.6、
				function [ack] = INON(ser)
			
				功能：传达“点亮编号为D4的led”的指令
				输入：ser被打开的串口对象
				返回：ack下位机的应答文本
			
			4.2.7、
				function [ack] = OUTON(ser)
				
				功能：传达“点亮外环的led”的指令
				输入：ser被打开的串口对象
				返回：ack下位机的应答文本
			
			4.2.8、
				function [ack] = D4On(ser)
			
				功能：传达“点亮编号为D4的led”的指令
				输入：ser被打开的串口对象
				返回：ack下位机的应答文本
			
			4.2.9、
				function [ack] = D5On(ser)
			
				功能：传达“点亮编号为D5的led”的指令
				输入：ser被打开的串口对象
				返回：ack下位机的应答文本
			
			4.2.10、
				function [ack] = D17On(ser)
			
				功能：传达“点亮编号为D17的led”的指令
				输入：ser被打开的串口对象
				返回：ack下位机的应答文本
			
			4.2.11、
				function [ack] = D18On(ser)
			
				功能：传达“点亮编号为D18的led”的指令
				输入：ser被打开的串口对象
				返回：ack下位机的应答文本
			
			4.2.12、
				function [ack] = D39On(ser)
			
				功能：传达“点亮编号为D39的led”的指令
				输入：ser被打开的串口对象
				返回：ack下位机的应答文本
			
			4.2.13、
				function [ack] = D40On(ser)
			
				功能：传达“点亮编号为D40的led”的指令
				输入：ser被打开的串口对象
				返回：ack下位机的应答文本
			
			4.2.14、
				function [ack] = D61On(ser)
			
				功能：传达“点亮编号为D61的led”的指令
				输入：ser被打开的串口对象
				返回：ack下位机的应答文本
			
			4.2.15、
				function [ack] = D62On(ser)
			
				功能：传达“点亮编号为D4的led”的指令
				输入：ser被打开的串口对象
				返回：ack下位机的应答文本
			
		注意：
				
			1、返回的文本信息是开发者的串口工具接收的，matlab上不一定会有固定的显示；
			2、建议每次点亮内、外环之前，都执行一次AllLedsOff操作，来达到单独点亮某一环的目的。
			
	
		4.3、步骤示例：
	
			1、打开串口：
		
			插♂入CH340TTL串口USB转接，查找对应COM：
			
			可以看到，USB-SERIAL CH340(COM7)，表示CH340插到了COM7上。
			
			在MATLAB中调用打开串口函数：
				
					ch340 = Serial_Init('COM7');
			
			即可打开串口，进行通讯。
			
			2、PP指令：
			
				通过PP指令函数实现LED亮灭，例如：
				点亮D4： 	D4On(ch340);
				点亮内环：	INON(ch340);
				灭掉所有灯：	AllLedsOff(ch340);
				
			3、整个程序（演示完毕）关闭时，注意关闭串口
			
						Serial_Close(ch340);
			
		
	
	
	
	5、下位机代码实现流程框图
	
	
	
	
	
	
	
	
	
	
	
		
		
	
	


