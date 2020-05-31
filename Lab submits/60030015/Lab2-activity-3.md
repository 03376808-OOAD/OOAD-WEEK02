# การทดลองที่ 2 

## Activity 3 การเขียนโปรแกรมด้วย Win32 API

### วัตถุประสงค์

1. เพื่อให้รู้วิธีการเขียนโปรแกรมบน Windows ด้วยฟังก์ชัน Win32 API
2. เพื่อให้มีความคุ้นเคยกับการใช้เครื่องมือต่างๆ ในการสร้าง Application บน IDE

### ลำดับการทดลอง

1. สร้าง Project ใหม่ ตาม activity ที่ 1
2. คัดลอกไฟล์ .cpp จากการทดลองที่ 2
3. แก้ไข code ในส่วนของการ switch message ให้เป็นดังนี้

``` C++
 ...
 	switch (message) {

 	case WM_PAINT:
 		hdc = BeginPaint (hwnd, &ps);
// 		Ellipse (hdc, 10, 10, 200, 100);
 		EndPaint (hwnd, &ps);
 		return 0;

	case WM_LBUTTONDOWN:
		char str[256];
		POINT pt;   // point of mouse clicked, received via message
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		wsprintf(str,"WM_LBUTTONDOWN\nCo-ordinate are\n (%i, %i)",pt.x,
 			         pt.y);
		MessageBox(hwnd, str, "Left Button Clicked", MB_OK);
		return 0;

	case WM_RBUTTONDOWN:
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		wsprintf(str,"WM_RBUTTONDOWN\nCo-ordinate are\n (%i, %i)",pt.x,
 			         pt.y);
		MessageBox(hwnd, str, "Right Button Clicked", MB_OK);
		return 0;

	case WM_CHAR:
		hdc = GetDC(hwnd);
		TextOut(hdc, 1,1, "  ",3);
		wsprintf(str,"%c",(char) wParam);
		TextOut(hdc, 1,1, str,strlen(str));
		ReleaseDC(hwnd, hdc);
		return 0;

 	case WM_DESTROY:
 		PostQuitMessage (0);
 		return 0;
 	}
...
```

4. กดปุ่ม F5 เพื่อดูผลการทำงานของโปรแกรม  

4.1 ทดลองคลิกเมาส์ปุ่มซ้าย และ ขวา ที่ตำแหน่งต่าง ๆ  
4.2 ทดลองพิมพ์ข้อความทางคียบอร์ด   


## คำถาม

1. ผลการทำงานของโปรแกรมเป็นอย่างไร ให้ cature หน้าจอพร้อมอธิบายการทำงาน
![RBUTTONDOWN](imgs/Anslab3pic1.jpg)
![LEFTBUTTONDOWN](imgs/Anslab3pic2.jpg)
จากโค้ดที่ให้พิมพ์เพิ่มเติม กำหนดให้แก้ไขข้อมูลที่ switch message 
โดยเพิ่ม paint ไว้สำหรับกำหนดขนากของวงกลมหรือรี
LBUTTONDOWN ไว้สำหรับการคลิ๊กเมาส์ข้างซ้ายเพื่อให้แสดงผล WM_LBUTTONDOWN Co-ordinate are(ตำแหน่งที่คลิ๊กเมาส์ข้างซ้าย)
	https://drive.google.com/file/d/11Ay03d_sFNOzsRFzpBtwfqdJWcxsbz3E/view?usp=sharing

RBUTTONDOWN
ไว้สำหรับการคลิ๊กเมาส์ข้างขวาเพื่อให้แสดงผล WM_RBUTTONDOWN Co-ordinate are(ตำแหน่งที่คลิ๊กเมาส์ข้างขวา)
	ttps://drive.google.com/file/d/1nDbG6qC-3BqxJWluiFXFPPvKpS8dxjBZ/view?usp=sharing

CHAR
เป็นตัวที่กำหนดให้แสดงผลเป็นตัวเลขตำแหน่งเมาส์แสดงผลตอนคลิ๊กเมาส
	https://drive.google.com/file/d/1MkYKNfgq_dVgR4pMYNPse9di8Y4cz3b_/view?usp=sharing์์

2. ส่งงานใน repo ตามแนวทางใน activity 1

## Challenges
1. โปรแกรมนี้สามารถพิมพ์อักษรและแสดงได้แค่อักษรเดียว ให้นักศึกษาแก้ไขโปรแกรมให้สามารถพิมพ์ข้อความโดยการรับค่าจากแป้นพิมพ์ได้  
1.1 กำหนดให้รับข้อความได้อย่างน้อย 32 ตัวอักษร  
1.2 เมื่อพิมพ์จนครบ 32 ตัว ให้เลื่อนข้อความไปทางซ้าย โดยตัวสุดท้ายที่พิมพ์เข้าไปจะอยู่ด้านขวาสุดเสมอ  
1.3 ถ้ากดปุ่ม enter จะนำข้อความที่พิมพ์นั้นไปแสดงบน dialog box  
