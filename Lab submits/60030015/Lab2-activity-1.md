# การทดลองที่ 2 
## Activity 1 การเขียนโปรแกรมด้วย Win32 API


### วัตถุประสงค์
1.	เพื่อให้รู้วิธีการเขียนโปรแกรมบน Windows ด้วยฟังก์ชัน Win32 API
2.	เพื่อให้มีความคุ้นเคยกับการใช้เครื่องมือต่างๆ ในการสร้าง Application บน IDE


### ลำดับการทดลอง
1.	เรียกโปรแกรม Microsoft Visual Studio 2019
2.	สร้าง Project ใหม่  โดยเลือกเมนู File >> New >> Project… (Ctrl+Shift+N) จะปรากฏหน้าต่าง New Project ดังรูปที่ 1

![Picture3.png](Picture3.png)

2.1 เลือก ภาษา : C++, Platform : Windows, Project typ Desktop  
2.2 เลือกชนิด project เป็น Windows Desktop Application
2.3 กด Next

![Picture4.png](Picture4.png)

2.4 ตั้งชื่อโปรเจคตามต้องการ ในที่นี้ตั้งเป็น WIn32_Lab1  
2.5 เลือกตำแหน่งที่ตั้งโปรเจค  
2.6 ในช่อง Solution เลือก Create new solution  
2.7 ในช่อง Solution name ปล่อยไว้ตามที่โปรแกรมกำหนดให้  
2.8 กดปุ่ม create  

Visual studio จะสร้าง application code มาให้ดังรูป

![Picture5.png](Picture5.png)

2.9 ให้ลบ code ออกให้หมด  

3. แก้ไขโค้ด  
3.1 พิมพ์โปรแกรมดังต่อไปนี้ลงในไฟล์ Win32_Lab1.cpp 

``` C++
#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow)
{
	MessageBox(NULL,"Hello World", "Lab1", MB_OK);
	return 0;
}
```
3.2 กด F5 เพื่อ debug โปรแกรม


# คำถาม

1. โปรแกรมสามารถทำงานได้หรือไม่ 
	ตอบ ไม่สามารถทำงานได้
2. ถ้าไม่ได้ แก้ไขอย่างไร
	ตอบ เข้าไปที่ Project-->Properties-->Advance เปลี่ยนค่า character set เป็น  Use Multi-Byte Character Set
	ไปที่ C/C++ --> Precompiled Headers เปลี่ยนค่า Precompiled Header เป็น Not Using Precompiled Headers
# การส่งงาน

1. fork repository นี้ แล้วสร้าง folder ขึ้นในโฟลเดอร์ย่อยที่่ชื่อ ```Lab submits```  
1.1 ตั้งชื่อตามรหัสนักศึกษา ไม่ต้องใส่ชื่อ  
1.2 copy โฟลเดอร์ ใบงานลงใน folder ย่อยที่สร้างขึ้น (ระวัง อย่า move ให้ copy เท่านั้น)  
1.3 อย่าลืมตรวจสอบไฟล์ gitignore ว่าได้ ignore ไฟล์ต่างๆ ที่ visual studio สร้างขึ้น ให้ commit เฉพาะไฟ์ที่นักศึกษาสร้างขึ้นเท่านั้น ดูตัวอย่างไฟล์ gitignore ได้จาก (https://github.com/github/gitignore/blob/master/VisualStudio.gitignore)  
1.4 เมื่อทุกอย่างเรียบร้อย ให้ทำการ Pull request โดยใช้ request message ในรูปแบบ ```stu_id:Lab_no_activity_no``` เช่น ```30xxxxxx: Lab2 Activity 1   ```

## ข้อควรระวัง 
1. การทำ pull request โดยมีไฟล์อยู่นอก folder งานของตนเอง จะทำความเสียหายต่อ repository และอาจทำให้เกิด conflict จนนักศึกษาคนอื่นไม่สามารถส่งงานได้
