#include "xparameters.h"
#include "vga_ip.h"
#include "lab_gobang_AI_2.h"
#include "VGADraw.h"

extern int board_state[15][15];
extern int status;
//extern int status;

void drawPixel(int x_pos, int y_pos, int turn,int page)
{
    int vga_input;
    vga_input=((x_pos)<<24)+((y_pos)<<16)+(page<<8)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
}

void drawLine(int x_pos, int y_pos, int turn,int page)//竖着8个像素
{
    int vga_input;
        vga_input=((x_pos)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos)<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
}

void drawLine2(int x_pos, int y_pos, int turn, int page,int num0,int num1,
               int num2,int num3, int num4, int num5, int num6,int num7)
{
    if (num0) drawPixel(x_pos,y_pos,turn,page);
    if (num1) drawPixel(x_pos,y_pos+1,turn,page);
    if (num2) drawPixel(x_pos,y_pos+2,turn,page);
    if (num3) drawPixel(x_pos,y_pos+3,turn,page);
    if (num4) drawPixel(x_pos,y_pos+4,turn,page);
    if (num5) drawPixel(x_pos,y_pos+5,turn,page);
    if (num6) drawPixel(x_pos,y_pos+6,turn,page);
    if (num7) drawPixel(x_pos,y_pos+7,turn,page);

}

void drawLetter (char letter, int x_pos, int y_pos, int turn,int page)//画字母
{
    int vga_input;
    switch (letter){

    case 'A':
    {
        //左 1列
        vga_input=(x_pos<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //2列
        vga_input=((x_pos+1)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //5列
        vga_input=((x_pos+4)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //6列
        vga_input=((x_pos+5)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //3列
        vga_input=((x_pos+2)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //4列
        vga_input=((x_pos+3)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        break;
    }

    case 'B':
    {
//        //1列
        drawLine(x_pos,y_pos,turn,page);

//        //2列
        drawLine(x_pos+1,y_pos,turn,page);

        //3列
        vga_input=((x_pos+2)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //4列
        vga_input=((x_pos+3)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //5列
        vga_input=((x_pos+4)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //6列
        drawLine2(x_pos+5,y_pos,turn,page,0,1,1,1,1,1,1,0);

        break;
    }

    case 'C':
    {
        //左 1列
        vga_input=(x_pos<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //2列
            drawLine(x_pos+1,y_pos,turn,page);

        //3列
        vga_input=((x_pos+2)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //4列
        vga_input=((x_pos+3)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //5列
        vga_input=((x_pos+4)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //6列
        vga_input=((x_pos+5)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        break;
    }

    case 'D':
    {
        drawLetter('O',x_pos,y_pos,turn,page);
        drawPixel(x_pos,y_pos,turn,page);
        drawPixel(x_pos,y_pos+7,turn,page);

        break;
    }

    case 'E':
    {
        drawLetter('F',x_pos,y_pos,turn,page);
        drawPixel(x_pos+2,y_pos+6,turn,page);
        drawPixel(x_pos+2,y_pos+7,turn,page);
        drawPixel(x_pos+4,y_pos+6,turn,page);
        drawPixel(x_pos+4,y_pos+7,turn,page);
        drawPixel(x_pos+3,y_pos+6,turn,page);
        drawPixel(x_pos+3,y_pos+7,turn,page);
        drawPixel(x_pos+5,y_pos+6,turn,page);
        drawPixel(x_pos+5,y_pos+7,turn,page);
        break;
    }

    case 'F':
    {
//        //1列
        drawLine(x_pos,y_pos,turn,page);

        //2列
          drawLine(x_pos+1,y_pos,turn,page);

        //3列
        vga_input=((x_pos+2)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //4列
        vga_input=((x_pos+3)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //5列
        vga_input=((x_pos+4)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //6列
        vga_input=((x_pos+5)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        break;

    }

    case 'G':
    {
        //左 1列
        vga_input=(x_pos<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //2列
        drawLine(x_pos+1,y_pos,turn,page);

        //3列
        vga_input=((x_pos+2)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //4列
        vga_input=((x_pos+3)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //5列
        vga_input=((x_pos+4)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //6列
        vga_input=((x_pos+5)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        break;
    }

    case 'H':
    {
        drawLine(x_pos,y_pos,turn,page);//1列
        drawLine(x_pos+1,y_pos,turn,page);//2
        drawLine(x_pos+4,y_pos,turn,page);//5
        drawLine(x_pos+5,y_pos,turn,page);//6
        drawLine2(x_pos+2,y_pos,turn,page,0,0,0,1,1,0,0,0);//3
        drawLine2(x_pos+3,y_pos,turn,page,0,0,0,1,1,0,0,0);//4

        break;

    }
    case 'I':
    {
        //2列
        vga_input=((x_pos+1)<<24)+((y_pos+0)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //5列
        vga_input=((x_pos+4)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);


//        //3列
//
//        //4列
        drawLine(x_pos+2,y_pos,turn,page);
        drawLine(x_pos+3,y_pos,turn,page);

        break;
    }

    case 'L':
    {
        drawLine(x_pos+1,y_pos,turn,page);
        drawLine(x_pos+2,y_pos,turn,page);
        drawLine2(x_pos,y_pos,turn,page,1,1,0,0,0,0,1,1);
        drawLine2(x_pos+3,y_pos,turn,page,0,0,0,0,0,0,1,1);
        drawLine2(x_pos+4,y_pos,turn,page,0,0,0,0,0,0,1,1);
        drawLine2(x_pos+5,y_pos,turn,page,0,0,0,0,0,0,1,1);
        break;
    }

    case 'M':
    {
//        //1列
//
//        //2列
//
//        //7列
//
//        //8列
            drawLine(x_pos,y_pos,turn,page);
            drawLine(x_pos+1,y_pos,turn,page);
            drawLine(x_pos+6,y_pos,turn,page);
            drawLine(x_pos+7,y_pos,turn,page);

        //3列
        vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //4列
        vga_input=((x_pos+3)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //5列
        vga_input=((x_pos+4)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+4)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //6列
        vga_input=((x_pos+5)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        break;
    }

    case 'N':
    {
        drawLine(x_pos,y_pos,turn,page);//1列
        drawLine(x_pos+1,y_pos,turn,page);
        drawLine(x_pos+6,y_pos,turn,page);
        drawLine(x_pos+5,y_pos,turn,page);//6

        drawLine2(x_pos+2,y_pos,turn,page,0,1,1,1,1,0,0,0);
        drawLine2(x_pos+3,y_pos,turn,page,0,0,1,1,1,1,0,0);
        drawLine2(x_pos+4,y_pos,turn,page,0,0,0,1,1,1,1,0);
        break;
    }

    case 'O':
    {
        //1列
        drawPixel(x_pos,y_pos+1,turn,page);
        drawPixel(x_pos,y_pos+2,turn,page);
        drawPixel(x_pos,y_pos+3,turn,page);
        drawPixel(x_pos,y_pos+4,turn,page);
        drawPixel(x_pos,y_pos+5,turn,page);
        drawPixel(x_pos,y_pos+6,turn,page);

        //2
        drawLine(x_pos+1,y_pos,turn,page);

        //3列
        drawPixel(x_pos+2,y_pos+0,turn,page);
        drawPixel(x_pos+2,y_pos+1,turn,page);
        drawPixel(x_pos+2,y_pos+6,turn,page);
        drawPixel(x_pos+2,y_pos+7,turn,page);

        //4
        drawPixel(x_pos+3,y_pos+0,turn,page);
        drawPixel(x_pos+3,y_pos+1,turn,page);
        drawPixel(x_pos+3,y_pos+6,turn,page);
        drawPixel(x_pos+3,y_pos+7,turn,page);

        //5
        drawLine(x_pos+4,y_pos,turn,page);

        //6列
        drawPixel(x_pos+5,y_pos+1,turn,page);
        drawPixel(x_pos+5,y_pos+2,turn,page);
        drawPixel(x_pos+5,y_pos+3,turn,page);
        drawPixel(x_pos+5,y_pos+4,turn,page);
        drawPixel(x_pos+5,y_pos+5,turn,page);
        drawPixel(x_pos+5,y_pos+6,turn,page);

        break;

    }

    case 'P':
    {
        //1列
        drawLine(x_pos,y_pos,turn,page);

        //2列
        drawLine(x_pos+1,y_pos,turn,page);

        //3列
        vga_input=((x_pos+2)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //4列
        vga_input=((x_pos+3)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //5列
        drawLine2(x_pos+4,y_pos,turn,page,1,1,1,1,1,1,0,0);

        //6列
        vga_input=((x_pos+5)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        break;
    }

    case 'R':
    {
//        //1列
        drawLine(x_pos,y_pos,turn,page);

//        //2列
            drawLine(x_pos+1,y_pos,turn,page);

        //3列
        vga_input=((x_pos+2)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //4列
        vga_input=((x_pos+3)<<24)+((y_pos)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+3)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        //5列
        drawLine(x_pos+4,y_pos,turn,page);

        //6列
        vga_input=((x_pos+5)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+5)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+6)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+5)<<24)+((y_pos+7)<<16)+(page<<8)+turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        break;
    }

    case 'S':
    {
        drawLine2(x_pos,y_pos,turn,page,0,1,1,1,0,0,1,1);
        drawLine2(x_pos+1,y_pos,turn,page,1,1,1,1,1,0,1,1);
        drawLine2(x_pos+2,y_pos,turn,page,1,1,0,1,1,0,1,1);
        drawLine2(x_pos+3,y_pos,turn,page,1,1,0,1,1,1,1,1);
        drawLine2(x_pos+4,y_pos,turn,page,1,1,0,1,1,1,1,1);
        drawLine2(x_pos+5,y_pos,turn,page,1,1,0,0,1,1,1,0);
        break;
    }

     case 'T':
    {
        drawLine2(x_pos,y_pos,turn,page,1,1,0,0,0,0,0,0);
        drawLine2(x_pos+1,y_pos,turn,page,1,1,0,0,0,0,1,1);
        drawLine(x_pos+2,y_pos,turn,page);
        drawLine(x_pos+3,y_pos,turn,page);
        drawLine2(x_pos+4,y_pos,turn,page,1,1,0,0,0,0,1,1);
        drawLine2(x_pos+5,y_pos,turn,page,1,1,0,0,0,0,0,0);
        break;
    }


    case 'U':
    {
        drawLine2(x_pos,y_pos,turn,page,1,1,1,1,1,1,1,0);
        drawLine2(x_pos+5,y_pos,turn,page,1,1,1,1,1,1,1,0);
        drawLine(x_pos+1,y_pos,turn,page);
        drawLine(x_pos+4,y_pos,turn,page);
        drawLine2(x_pos+2,y_pos,turn,page,0,0,0,0,0,1,1,1);
        drawLine2(x_pos+3,y_pos,turn,page,0,0,0,0,0,1,1,1);
        break;
    }

    case 'W':
    {
        drawLine(x_pos,y_pos,turn,page);
        drawLine(x_pos+1,y_pos,turn,page);
        drawLine(x_pos+6,y_pos,turn,page);
        drawLine(x_pos+7,y_pos,turn,page);
        drawLine2(x_pos+2,y_pos,turn,page,0,0,0,1,1,1,1,0);
        drawLine2(x_pos+3,y_pos,turn,page,0,1,1,1,1,1,0,0);
        drawLine2(x_pos+5,y_pos,turn,page,0,0,0,1,1,1,1,0);
        drawLine2(x_pos+4,y_pos,turn,page,0,1,1,1,1,1,0,0);
        break;
    }

    case 'Y':
    {
        drawLine2(x_pos,y_pos,turn,page,1,1,1,1,1,0,0,0);
        drawLine2(x_pos+1,y_pos,turn,page,1,1,1,1,1,0,0,0);
        drawLine2(x_pos+2,y_pos,turn,page,0,0,0,1,1,1,1,1);
        drawLine2(x_pos+3,y_pos,turn,page,0,0,0,1,1,1,1,1);
        drawLine2(x_pos+4,y_pos,turn,page,1,1,1,1,1,0,0,0);
        drawLine2(x_pos+5,y_pos,turn,page,1,1,1,1,1,0,0,0);
        break;
    }

  }
}

void DrawNumber(int number, int x_pos, int y_pos, int turn, int page)
{
	int vga_input;

	switch (number) {
	    case 0: vga_input=(x_pos<<24)+(y_pos<<16)+(page<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=((x_pos+1)<<24)+(y_pos<<16)+(page<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=((x_pos+2)<<24)+(y_pos<<16)+(page<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=(x_pos<<24)+((y_pos+1)<<16)+(page<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=(x_pos<<24)+((y_pos+2)<<16)+(page<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=(x_pos<<24)+((y_pos+3)<<16)+(page<<8)+turn;
       	        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
       	        vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
       	        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
       	        vga_input=(x_pos<<24)+((y_pos+4)<<16)+(page<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
       	        vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
       	        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
       	        vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
       	        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                break;
	    case 1: vga_input=((x_pos+2)<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                break;
	    case 2: vga_input=(x_pos<<24)+(y_pos<<16)+(page<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=((x_pos+1)<<24)+(y_pos<<16)+(page<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=((x_pos+2)<<24)+(y_pos<<16)+(page<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=(x_pos<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=(x_pos<<24)+((y_pos+3)<<16)+(page<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=(x_pos<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    break;
	    case 3: vga_input=(x_pos<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=(x_pos<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            break;
	    case 4: vga_input=(x_pos<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+1)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            break;
	    case 5: vga_input=(x_pos<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+1)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=(x_pos<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            break;
	    case 6: vga_input=(x_pos<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+1)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+3)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=(x_pos<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            break;
	    case 7: vga_input=(x_pos<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            break;
	    case 8: vga_input=(x_pos<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+1)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+3)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=(x_pos<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            break;
	    case 9: vga_input=(x_pos<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+(y_pos<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+1)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=(x_pos<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(page<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            break;
	}

}

void drawFood(int color)//最左边各种东西的状态
{
    drawLetter('P',1,1,color,2);
    drawLetter('I',8,1,color,2);
    drawLetter('G',15,1,color,2);

    drawLetter('F',1,11,color,2);
    drawLetter('O',8,11,color,2);
    drawLetter('O',15,11,color,2);
    drawLetter('D',22,11,color,2);

    drawLetter('H',1,21,color,2);
    drawLetter('P',8,21,color,2);

    drawLetter('M',1,31,color,2);
    drawLetter('O',10,31,color,2);
    drawLetter('N',17,31,color,2);
    drawLetter('E',25,31,color,2);
    drawLetter('Y',32,31,color,2);

    drawLetter('G',1,41,color,2);
    drawLetter('R',8,41,color,2);
    drawLetter('P',22,41,color,2);
    drawLetter('I',29,41,color,2);
    drawLetter('G',36,41,color,2);

}

void drawBuy(int cursor0)
{
    int color[5] = {1,1,1,1,1};//黑色
    color[cursor0] = 2;//蓝色
    drawLetter('B',70,1,color[0],2);//初始化画开始界面 buy pig
    drawLetter('U',77,1,color[0],2);//初始化画开始界面 buy pig
    drawLetter('Y',84,1,color[0],2);//初始化画开始界面 buy pig
    drawLetter('P',98,1,color[0],2);//初始化画开始界面 buy pig
    drawLetter('I',105,1,color[0],2);//初始化画开始界面 buy pig
    drawLetter('G',112,1,color[0],2);//初始化画开始界面 buy pig

    drawLetter('B',70,11,color[1],2);//buy food
    drawLetter('U',77,11,color[1],2);
    drawLetter('Y',84,11,color[1],2);
    drawLetter('F',98,11,color[1],2);
    drawLetter('O',105,11,color[1],2);
    drawLetter('O',112,11,color[1],2);
    drawLetter('D',119,11,color[1],2);

    drawLetter('E',70,21,color[2],2);//eat meal
    drawLetter('A',77,21,color[2],2);
    drawLetter('T',84,21,color[2],2);
    drawLetter('M',98,21,color[2],2);
    drawLetter('E',107,21,color[2],2);
    drawLetter('A',114,21,color[2],2);
    drawLetter('L',121,21,color[2],2);

    drawLetter('S',70,31,color[3],2);//sell pig
    drawLetter('E',77,31,color[3],2);
    drawLetter('L',84,31,color[3],2);
    drawLetter('L',92,31,color[3],2);
    drawLetter('P',105,31,color[3],2);
    drawLetter('I',112,31,color[3],2);
    drawLetter('G',119,31,color[3],2);

    drawLetter('E',70,41,color[4],2);//end game
    drawLetter('N',77,41,color[4],2);
    drawLetter('D',85,41,color[4],2);
    drawLetter('G',99,41,color[4],2);
    drawLetter('A',106,41,color[4],2);
    drawLetter('M',113,41,color[4],2);
    drawLetter('E',122,41,color[4],2);
}

void drawDie(int x_pos, int y_pos, int color, int page)//"you die"
{
    drawLetter('Y',45,61,color,2);
    drawLetter('O',52,61,color,2);
    drawLetter('U',59,61,color,2);
    drawLetter('D',73,61,color,2);
    drawLetter('I',80,61,color,2);
    drawLetter('E',87,61,color,2);

}

void drawWin(int x_pos, int y_pos, int color, int page)//"you win!"
{
    drawLetter('Y',45,61,color,2);
    drawLetter('O',52,61,color,2);
    drawLetter('U',59,61,color,2);
    drawLetter('W',73,61,color,2);
    drawLetter('I',82,61,color,2);
    drawLetter('N',89,61,color,2);
}

void drawWelcome()
{
    int x,y,color;
    x = 5;
    y = 100;
    color = 1;//黑色
    drawLetter('W',x,y,color,2);
    drawLetter('E',x+9,y,color,2);
    drawLetter('L',x+16,y,color,2);
    drawLetter('L',x+23,y,color,2);
    drawLetter('C',x+30,y,color,2);
    drawLetter('O',x+37,y,color,2);
    drawLetter('M',x+44,y,color,2);
    drawLetter('E',x+53,y,color,2);

    drawLetter('T',x+67,y,color,2);
    drawLetter('O',x+74,y,color,2);

    drawLetter('T',x+88,y,color,2);
    drawLetter('H',x+95,y,color,2);
    drawLetter('E',x+102,y,color,2);

    drawLetter('F',x+116,y,color,2);
    drawLetter('A',x+123,y,color,2);
    drawLetter('R',x+130,y,color,2);
    drawLetter('M',x+137,y,color,2);
}

void DrawNumbers(int number, int x_pos, int y_pos, int turn, int page)//两位数字
{
	int num1, num2,vga_input;

    if (number <0)
    {
        number = -number;//画负号
                vga_input=(x_pos<<24)+(y_pos<<16)+(page<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=((x_pos+1)<<24)+(y_pos<<16)+(page<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=((x_pos+2)<<24)+(y_pos<<16)+(page<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

    }
    else
    {
                vga_input=(x_pos<<24)+(y_pos<<16)+(page<<8)+0;//白色
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=((x_pos+1)<<24)+(y_pos<<16)+(page<<8)+0;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=((x_pos+2)<<24)+(y_pos<<16)+(page<<8)+0;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    }

	num1=number/10;//十位
	num2=number%10;//个位
	DrawNumber(num1, x_pos+4, y_pos, turn,page);
	DrawNumber(num2, x_pos+8, y_pos, turn,page);
}

void drawFoodNum(int pig, int food, int hp, int money,int grownPig)
{
    DrawNumbers(88,   42,1, 0,2);//清除原先的数字
    DrawNumbers(88,   42,11,0,2);
    DrawNumbers(88,   42,21,0,2);
    DrawNumbers(88,   42,31,0,2);
    DrawNumbers(88,   42,41,0,2);

    DrawNumbers(pig,  42,1, 1,2);//画新的数字
    DrawNumbers(food, 42,11,1,2);
    DrawNumbers(hp,   42,21,1,2);
    DrawNumbers(money,42,31,1,2);
    DrawNumbers(grownPig,42,41,1,2);
}




void DrawBoard (void)
{
	int i,j,x_cor,y_cor,type,vga_input;
	for (i=0; i<15; i++) {
		for (j=0; j<15; j++) {
			x_cor=i<<24;
			y_cor=j<<16;

			type=EMPTY;
			vga_input=x_cor+y_cor+(0<<8) + type;
		    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
		}
    }
}

void DrawChess (int x_pos, int y_pos, int turn)
{
	int x_cor,y_cor,type,vga_input;
	type=turn;
	x_cor=x_pos<<24;
	y_cor=y_pos<<16;
	vga_input=x_cor+y_cor+(0<<8)+type;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
}

void EraseCursor (int x_pos, int y_pos)
{
	if ((board_state[x_pos][y_pos]==0 && (status==PVC || status==PVP))||(board_state[x_pos][y_pos]==1 && (status==CVP )))  {
		DrawChess(x_pos,y_pos,0);
	}
	else if ((board_state[x_pos][y_pos]==1 && (status==PVC || status==PVP))||(board_state[x_pos][y_pos]==0 && (status==CVP ))) {
		DrawChess(x_pos,y_pos,1);
	}
	else {
		DrawChess(x_pos,y_pos,2);
	}
}


void DrawTime(int time, int turn)
{
	int num1, num2;

	num1=time/10;
	num2=time%10;
	DrawNumber(num1, 1, 2, turn,1);
	DrawNumber(num2, 5, 2, turn,1);
}

void DrawWinning(int x_pos, int y_pos, int turn)
{
	int vga_input;
	DrawBoard();

    //"w"
    vga_input=((x_pos)<<24)+((y_pos-1)<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos)<<24)+(y_pos<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos)<<24)+((y_pos+1)<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos)<<24)+((y_pos+2)<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+1)<<24)+((y_pos+3)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+2)<<24)+(y_pos<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+3)<<24)+((y_pos+3)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+4)<<24)+((y_pos+2)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+4)<<24)+((y_pos+1)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+4)<<24)+((y_pos)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+4)<<24)+((y_pos-1)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

    //"I"
    vga_input=((x_pos+6)<<24)+((y_pos+4)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+7)<<24)+((y_pos+4)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+8)<<24)+((y_pos+4)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+7)<<24)+((y_pos+5)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+7)<<24)+((y_pos+6)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+7)<<24)+((y_pos+7)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+7)<<24)+((y_pos+8)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+6)<<24)+((y_pos+8)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+8)<<24)+((y_pos+8)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

    //"N"
    vga_input=((x_pos+10)<<24)+((y_pos+9)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+10)<<24)+((y_pos+10)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+10)<<24)+((y_pos+11)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+10)<<24)+((y_pos+12)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+10)<<24)+((y_pos+13)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+11)<<24)+((y_pos+10)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+12)<<24)+((y_pos+11)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+13)<<24)+((y_pos+12)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+14)<<24)+((y_pos+13)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+14)<<24)+((y_pos+12)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+14)<<24)+((y_pos+11)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+14)<<24)+((y_pos+10)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+14)<<24)+((y_pos+9)<<16)+turn;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);


}

void drawP(int x_pos, int y_pos, int turn)
{
    int vga_input;

    vga_input=(x_pos<<24)+(y_pos<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+(y_pos<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+(y_pos<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+2)<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+3)<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+4)<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
}

void drawC(int x_pos, int y_pos, int turn)
{
    int vga_input;
        vga_input=((x_pos+0)<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+1)<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+0)<<24)+((y_pos+2)<<16)+(1<<8)+1-turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+0)<<24)+((y_pos+3)<<16)+(1<<8)+1-turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+0)<<24)+((y_pos+4)<<16)+(1<<8)+1-turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(1<<8)+1-turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(1<<8)+1-turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

}

void DrawStatus(int x_pos, int y_pos, int turn,int status)
{
	int vga_input;

    vga_input=((x_pos+2)<<24)+((y_pos+5)<<16)+(1<<8)+3;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+2)<<24)+((y_pos+6)<<16)+(1<<8)+3;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+3)<<24)+((y_pos+7)<<16)+(1<<8)+3;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+4)<<24)+((y_pos+6)<<16)+(1<<8)+3;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+4)<<24)+((y_pos+5)<<16)+(1<<8)+3;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

    if (status==PVP) {
//        vga_input=(x_pos<<24)+(y_pos<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+1)<<24)+(y_pos<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+2)<<24)+(y_pos<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=(x_pos<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=(x_pos<<24)+((y_pos+2)<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=(x_pos<<24)+((y_pos+3)<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=(x_pos<<24)+((y_pos+4)<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//
//    	vga_input=((x_pos+6)<<24)+((y_pos+5+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+7)<<24)+((y_pos+5+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+8)<<24)+((y_pos+5+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+6)<<24)+((y_pos+6+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+8)<<24)+((y_pos+6+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+6)<<24)+((y_pos+7+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+7)<<24)+((y_pos+7+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+8)<<24)+((y_pos+7+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+6)<<24)+((y_pos+8+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+6)<<24)+((y_pos+9+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        drawP(x_pos,y_pos,turn);
        drawP(x_pos+6,y_pos+6,1-turn);
    }
    else if(status==PVC) {
//        vga_input=(x_pos<<24)+(y_pos<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+1)<<24)+(y_pos<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+2)<<24)+(y_pos<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=(x_pos<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=(x_pos<<24)+((y_pos+2)<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=(x_pos<<24)+((y_pos+3)<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=(x_pos<<24)+((y_pos+4)<<16)+(1<<8)+1-turn;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//
//    	vga_input=((x_pos+6)<<24)+((y_pos+6+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+7)<<24)+((y_pos+6+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+8)<<24)+((y_pos+6+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+6)<<24)+((y_pos+7+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+6)<<24)+((y_pos+8+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+6)<<24)+((y_pos+9+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+7)<<24)+((y_pos+9+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+8)<<24)+((y_pos+9+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        drawP(x_pos,y_pos,turn);
        drawC(x_pos+6,y_pos+6,1-turn);
    }
    else if(status==CVP) {
//    	vga_input=((x_pos+0)<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+1)<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+0)<<24)+((y_pos+2)<<16)+(1<<8)+1-turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+0)<<24)+((y_pos+3)<<16)+(1<<8)+1-turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+0)<<24)+((y_pos+4)<<16)+(1<<8)+1-turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(1<<8)+1-turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(1<<8)+1-turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//
//    	vga_input=((x_pos+6)<<24)+((y_pos+5+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+7)<<24)+((y_pos+5+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+8)<<24)+((y_pos+5+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+6)<<24)+((y_pos+6+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+8)<<24)+((y_pos+6+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+6)<<24)+((y_pos+7+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+7)<<24)+((y_pos+7+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+8)<<24)+((y_pos+7+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+6)<<24)+((y_pos+8+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//    	vga_input=((x_pos+6)<<24)+((y_pos+9+1)<<16)+(1<<8)+turn;
//    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        drawC(x_pos,y_pos,turn);
        drawP(x_pos+6,y_pos+6,1-turn);
    }
    if(turn==EMPTY)
    {
//        vga_input=(x_pos<<24)+(y_pos<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+1)<<24)+(y_pos<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+2)<<24)+(y_pos<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=(x_pos<<24)+((y_pos+1)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=(x_pos<<24)+((y_pos+2)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=(x_pos<<24)+((y_pos+3)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=(x_pos<<24)+((y_pos+4)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+1)<<24)+((y_pos+1)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//
//        vga_input=((x_pos+6)<<24)+((y_pos+5+1)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+7)<<24)+((y_pos+5+1)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+8)<<24)+((y_pos+5+1)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+6)<<24)+((y_pos+6+1)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+8)<<24)+((y_pos+6+1)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+6)<<24)+((y_pos+7+1)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+7)<<24)+((y_pos+7+1)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+8)<<24)+((y_pos+7+1)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+6)<<24)+((y_pos+8+1)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+6)<<24)+((y_pos+9+1)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+7)<<24)+((y_pos+9+1)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+8)<<24)+((y_pos+9+1)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
//        vga_input=((x_pos+7)<<24)+((y_pos+6+1)<<16)+(1<<8)+2;
//        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        drawP(x_pos,y_pos,-1);
        drawP(x_pos+6,y_pos+6,-1);
        drawC(x_pos,y_pos,-1);
        drawC(x_pos+6,y_pos+6,-1);

    }
}


void DrawBack(int x_pos, int y_pos,int turn)
{
	int vga_input;
	vga_input=(x_pos<<24)+(y_pos+2<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+1)<<24)+(y_pos+2<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+2)<<24)+(y_pos+2<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+3)<<24)+(y_pos+2<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+0)<<24)+((y_pos+1+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+3)<<24)+((y_pos+1+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+0)<<24)+((y_pos+2+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+1)<<24)+((y_pos+2+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+2)<<24)+((y_pos+2+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+3)<<24)+((y_pos+2+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+0)<<24)+((y_pos+3+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+2)<<24)+((y_pos+3+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+0)<<24)+((y_pos+4+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+3)<<24)+((y_pos+4+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
}


