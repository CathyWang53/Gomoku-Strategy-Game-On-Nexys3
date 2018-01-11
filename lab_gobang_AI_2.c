#include "xparameters.h"
#include "xgpio.h"
#include "xutil.h"
#include "vga_ip.h"
#include "xps2.h"
#include <xtmrctr.h>
#include <xintc_l.h>
#include "lab_gobang_AI_2.h"
#include "VGADraw.h"
#include "AI.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define Human    1
#define Computer 0
#define Nothing  2

typedef struct node
{
    int x;
    int y;
}POINT;



//====================================================



int board_state[15][15];
POINT board_record[225];

int turn;
int level=2;
int status=PVP;
int step_flag;
int win_flag;
int BackTimes=0;
int maxMoveX, maxMoveY;
volatile int time0=0;
volatile int count=0;
volatile u32 ssBuf;
static const u32 rgfsNumMap[10] = {0x000000C0, 0x000000F9, 0x000000A4,
								0x000000B0, 0x00000099, 0x00000092,
								0x00000082, 0x000000F8, 0x00000080,
								0x00000090};

//������Ϸ
int page=0;//0�ǻ�ӭ���棻1����Ϸ����
int cursor0 = 0;//��ӭ����Ĺ�꣬��Ӧ���������ϡ��Է�������
int money = 0;
int food = 0;
int hp = 5;
int pig = 0;
int grownPig = 0;//����������
int pigs[10] = {0};//ÿֻ���״̬0~6,0��ʾû������6ʱ������ ѭ������
int head=0,tail=0;//ѭ�������ͷβ
int die = 0;//dieΪ1ʱ��Ϸ���������������
int win0 = 0;//winΪ1ʱ��Ϸ����������ʵ����

//====================================================

int CheckWin(int x_pos, int y_pos, int turn)
{
	int i,j,count;
	//ˮƽ
	count=1;
	for (i=x_pos+1, j=y_pos; i<15; i++) {
		if (board_state[i][j]==turn)
			count++;
		else
			break;
	}
	for (i=x_pos-1, j=y_pos; i>=0; i--) {
		if (board_state[i][j]==turn)
			count++;
		else
			break;
    }
	if (count==5)
		return 1;

	//��ֱ
	count=1;
	for (i=x_pos, j=y_pos+1; j<15; j++) {
		if (board_state[i][j]==turn)
			count++;
		else
			break;
	}
	for (i=x_pos, j=y_pos-1; j>=0; j--) {
		if (board_state[i][j]==turn)
			count++;
		else
			break;
	}
	if (count==5)
		return 1;

	//����������
	count=1;
	for (i=x_pos+1,j=y_pos+1; i<15 && j<15; i++,j++) {
		if (board_state[i][j]==turn)
			count++;
		else
			break;
	}
	for (i=x_pos-1,j=y_pos-1; i>=0 && j>=0; i--,j--) {
		if (board_state[i][j]==turn)
			count++;
		else
			break;
	}
	if (count==5)
		return 1;

	//����������
	count=1;
    for (i=x_pos+1,j=y_pos-1; i<15 && j>=0; i++,j--) {
	 	if (board_state[i][j]==turn)
			count++;
		else
			break;
	}
	for (i=x_pos-1,j=y_pos+1; i>=0 && j<15; i--,j++) {
		if (board_state[i][j]==turn)
			count++;
		else
			break;
	}
	if (count==5)
		return 1;

	//no win
	return 0;
}

int CheckBan(int x_pos, int y_pos, int turn)
{
	int i,j,count,lian3,lian4,lian6;

	lian3=0;
	lian4=0;
	lian6=0;

	//ˮƽ
	if (board_state[x_pos+1][y_pos]!= 1-turn && board_state[x_pos-1][y_pos]!= 1-turn){
	count=1;
	if(board_state[x_pos+1][y_pos]==EMPTY){
		for (i=x_pos+2, j=y_pos; i<15; i++) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
		}
		for (i=x_pos-1, j=y_pos; i>=0; i--) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
	    }
		if (count==3)
			++lian3;
		if (count==4)
			++lian4;
	}

	count=1;
	if(board_state[x_pos-1][y_pos]==EMPTY){
		for (i=x_pos+1, j=y_pos; i<15; i++) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
		}
		for (i=x_pos-2, j=y_pos; i>=0; i--) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
    	}
		if (count==3)
			++lian3;
		if (count==4)
			++lian4;
	}

	count=1;
	if(board_state[x_pos-1][y_pos]!=EMPTY&&board_state[x_pos+1][y_pos]!=EMPTY){
		for (i=x_pos+1, j=y_pos; i<15; i++) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
		}
		for (i=x_pos-1, j=y_pos; i>=0; i--) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
    	}
		if (count==3)
			++lian3;
		if (count==4)
			++lian4;
		if (count>5)
			++lian6;
	}
	}//�ж�����������û�ж��ֵ���

	//��ֱ
	if (board_state[x_pos][y_pos +1]!= 1-turn && board_state[x_pos][y_pos-1]!= 1-turn){
	count=1;
	if(board_state[x_pos][y_pos+1]==EMPTY){
		for (i=x_pos, j=y_pos+2; j<15; j++) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
		}
		for (i=x_pos, j=y_pos-1; j>=0; j--) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
	    }
		if (count==3)
			++lian3;
		if (count==4)
			++lian4;
	}

	count=1;
	if(board_state[x_pos][y_pos-1]==EMPTY){
		for (i=x_pos, j=y_pos+1; j<15; j++) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
		}
		for (i=x_pos, j=y_pos-2; j>=0; j--) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
    	}
		if (count==3)
			++lian3;
		if (count==4)
			++lian4;
	}

	count=1;
	if(board_state[x_pos][y_pos+1]!=EMPTY&&board_state[x_pos][y_pos-1]!=EMPTY){
		for (i=x_pos, j=y_pos+1; j<15; j++) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
		}
		for (i=x_pos, j=y_pos-1; j>=0; j--) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
    	}
		if (count==3)
			++lian3;
		if (count==4)
			++lian4;
		if (count>5)
			++lian6;
	}
	}

	//����������
	if (board_state[x_pos-1][y_pos -1]!= 1-turn && board_state[x_pos+1][y_pos+1]!= 1-turn){
	count=1;
	if(board_state[x_pos+1][y_pos+1]==EMPTY){
		for (i=x_pos+2,j=y_pos+2; i<15 && j<15; i++,j++) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
		}
		for (i=x_pos-1,j=y_pos-1; i>=0 && j>=0; i--,j--) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
	    }
		if (count==3)
			++lian3;
		if (count==4)
			++lian4;
	}

	count=1;
	if(board_state[x_pos-1][y_pos-1]==EMPTY){
		for (i=x_pos+1,j=y_pos+1; i<15 && j<15; i++,j++) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
		}
		for (i=x_pos-2,j=y_pos-2; i>=0 && j>=0; i--,j--) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
    	}
		if (count==3)
			++lian3;
		if (count==4)
			++lian4;
	}

	count=1;
	if(board_state[x_pos+1][y_pos+1]!=EMPTY&&board_state[x_pos-1][y_pos-1]!=EMPTY){
		for (i=x_pos+1,j=y_pos+1; i<15 && j<15; i++,j++) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
		}
		for (i=x_pos-1,j=y_pos-1; i>=0 && j>=0; i--,j--) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
    	}
		if (count==3)
			++lian3;
		if (count==4)
			++lian4;
		if (count>5)
			++lian6;
	}
	}

	//����������
	if (board_state[x_pos-1][y_pos +1]!= 1-turn && board_state[x_pos+1][y_pos-1]!= 1-turn){
	count=1;
	if(board_state[x_pos+1][y_pos-1]==EMPTY){
		for (i=x_pos+2,j=y_pos-2; i<15 && j>=0; i++,j--) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
		}
		for (i=x_pos-1,j=y_pos+1; i>=0 && j<15; i--,j++) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
	    }
		if (count==3)
			++lian3;
		if (count==4)
			++lian4;
	}

	count=1;
	if(board_state[x_pos-1][y_pos+1]==EMPTY){
		for (i=x_pos+1,j=y_pos-1; i<15 && j>=0; i++,j--) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
		}
		for (i=x_pos-2,j=y_pos+2; i>=0 && j<15; i--,j++) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
    	}
		if (count==3)
			++lian3;
		if (count==4)
			++lian4;
	}

	count=1;
	if(board_state[x_pos+1][y_pos-1]!=EMPTY&&board_state[x_pos-1][y_pos+1]!=EMPTY){
		for (i=x_pos+1,j=y_pos-1; i<15 && j>=0; i++,j--) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
		}
		for (i=x_pos-1,j=y_pos+1; i>=0 && j<15; i--,j++) {
			if (board_state[i][j]==turn)
				count++;
			else
				break;
    	}
		if (count==3)
			++lian3;
		if (count==4)
			++lian4;
		if (count>5)
			++lian6;
	}
	}

	if (lian3>1) return 1;
	if (lian4>1) return 1;
	if (lian6>0) return 1;

	return 0;
}

void timer_int_handler(void * baseaddr_p) {
	unsigned int csr;
	int num;
    unsigned int MskAnodes;

	csr = XTmrCtr_GetControlStatusReg(XPAR_XPS_TIMER_0_BASEADDR, 0);
    if (csr & XTC_CSR_INT_OCCURED_MASK && win_flag==0) {
	    count++;
	    if (count%2==0) {
	    	MskAnodes=0x00000D00;
	    	num=(TIME_LIMIT-time0)/10;
	    }
	    else {
	    	MskAnodes=0x00000E00;
	    	num=(TIME_LIMIT-time0)%10;
	    }
    	ssBuf = MskAnodes | rgfsNumMap[num];
        Xil_Out32(XPAR_SEVSEG_DISP_12BITS_BASEADDR, ssBuf);
    }
    if (page == 1)
    {
        if (count==200) {//time0���� ������ʱ
            count=0;
            time0++;
            DrawBack(3,9,EMPTY);
            DrawTime(88, EMPTY);
            if (time0>20)
                DrawTime(TIME_LIMIT-time0, CURSOR);//��ʣ10��ʱ���ɫ
            else
                DrawTime(TIME_LIMIT-time0, turn);
        }
        if (time0>TIME_LIMIT) {
            time0=0;
            if (turn==HUMAN_PLAYER) {
                turn=COMPUTER_PLAYER;
                xil_printf("\r\nComputer Player's turn!\r\n");
            }
            else {
                turn=HUMAN_PLAYER;
                xil_printf("\r\nHuman Player's turn!\r\n");
            }
        }
    }
    else
    {
        time0 = 0;
    }
    XTmrCtr_SetControlStatusReg(XPAR_XPS_TIMER_0_BASEADDR, 0, csr);
}

void InitializeGame(int x_cur, int y_cur)
{
	int i,j;
	for (i=0; i<15; i++) {
		for (j=0; j<15; j++) {
		    board_state[i][j]=EMPTY;
		}
	}
	DrawNumber(level,6,18,EMPTY,1);
	DrawWinning(0,1, EMPTY);
	DrawStatus(0, 18, EMPTY,PVP);
	DrawBack(3,9,EMPTY);
	count=0;
	time0=0;
	turn=HUMAN_PLAYER;
	step_flag=0;
	win_flag=0;

	DrawBoard();
	DrawChess(x_cur, y_cur, CURSOR);
	DrawTime(88, EMPTY);
	DrawTime(30, turn);
	DrawStatus(0, 18, COMPUTER_PLAYER,PVP);
	xil_printf("\r\nGame Start!\r\n");

}

void afterGame(int winOrLose)//ÿ����Ϸ������
{
    int i;

    hp-=2;
    if (winOrLose)//Ӯ��
    {
        money += 5;
//        if (money >= 30)
//        {
//            win0 = 1;
//        }
    }
    else money--;

    if (hp<0 || money<0)//��Ҷ���
    {
        die = 1;
    }

    if (food < pig)//�����
    {
        head += (pig-food);//����������ֲ�δ����
        pig = food;//������������
        food = 0;//ʳ��������

    }
    else food-=pig;

    //����
    for (i=head;i<=pig+head;i++)//ѭ������
    {
        pigs[i%10]++;
        if (pigs[i%10] > 5) grownPig++;
    }
}
void buyPig()
{
    if (money >= 2 && pig<10)
    {
        money-=2;
        pig++;
        pigs[tail] = 1;
        tail = (tail + 1) % 10;
        drawFoodNum(pig,food,hp,money,grownPig);

    }
}
void sellPig()
{
    if (pigs[head] > 5)//�Ѿ�������
    {
        money+=12;
        pig--;
        grownPig--;
        pigs[head] = 0;
        head = (head + 1) % 10;
        drawFoodNum(pig,food,hp,money,grownPig);
    }
}

int main (void)
{
   XGpio dip;
   int dip_check;


   static XPs2 Ps2Inst;
   XPs2_Config *ConfigPtr;
   u32 StatusReg;
   u32 BytesReceived;
   u8 RxBuffer;
   int key_count=0;
   int key_count1 = 0;
   int i;

   status=PVP;
   int x_cur=7, y_cur=7, x_pos=0, y_pos=0;

   XGpio_Initialize(&dip, XPAR_DIP_SWITCHES_8BITS_DEVICE_ID);
   XGpio_SetDataDirection(&dip, 1, 0xffffffff);

   ConfigPtr = XPs2_LookupConfig(XPAR_XPS_PS2_0_0_DEVICE_ID);
   XPs2_CfgInitialize(&Ps2Inst, ConfigPtr, ConfigPtr->BaseAddress);

   XIntc_RegisterHandler(XPAR_XPS_INTC_0_BASEADDR,
   		                 XPAR_XPS_INTC_0_XPS_TIMER_0_INTERRUPT_INTR,
                         (XInterruptHandler) timer_int_handler,
                         (void *)XPAR_XPS_TIMER_0_BASEADDR);

   XIntc_MasterEnable(XPAR_XPS_INTC_0_BASEADDR);
   XIntc_EnableIntr(XPAR_XPS_INTC_0_BASEADDR, 0x1);

   XTmrCtr_SetLoadReg(XPAR_XPS_TIMER_0_BASEADDR, 0, 333333);

   XTmrCtr_SetControlStatusReg(XPAR_XPS_TIMER_0_BASEADDR, 0, XTC_CSR_INT_OCCURED_MASK | XTC_CSR_LOAD_MASK );

   XIntc_EnableIntr(XPAR_XPS_TIMER_0_BASEADDR, XPAR_XPS_TIMER_0_INTERRUPT_MASK);

   XTmrCtr_SetControlStatusReg(XPAR_XPS_TIMER_0_BASEADDR, 0, XTC_CSR_ENABLE_TMR_MASK | XTC_CSR_ENABLE_INT_MASK |
     						XTC_CSR_AUTO_RELOAD_MASK | XTC_CSR_DOWN_COUNT_MASK);

   microblaze_enable_interrupts();



   xil_printf("-- Game Starts! --\r\n");
   xil_printf("\r\nHuman Player's turn!\r\n");

   int vga_input;



   //drawFrame();
   //DrawNumber(5,1,1,1);
   drawBuy(cursor0);//��3
   drawFoodNum(pig,food,hp,money,grownPig);//��2
   drawFood(1);//����� ��ɫ
   drawWelcome();

   while (1)
   {
       if (page == 1 && turn==COMPUTER_PLAYER && (status==PVC ||status==CVP )&& win_flag==0) //��������
          {
              if (step_flag==0) {
                  if (x_cur-1<0)
                      x_pos=x_cur+1;
                  else
                      x_pos=x_cur-1;
                      y_pos=y_cur;
                      step_flag=1;
              }
              else {
                  if(level==2||level==3||level == 1)
                  {
                      EvaluateComputerMove(board_state, 0, MIN_INFINITY, MAX_INFINITY, 0, 0);
                      x_pos=maxMoveX;
                      y_pos=maxMoveY;
                      xil_printf("\r\n computer \r\n");
                  }
//                  else
//                  {
//                      everyScore(Computer);
//                      current_pos=best(Computer);
//                      x_pos=current_pos.y;
//                      y_pos=current_pos.x;
//                      xil_printf("\r\n computer \r\n");
//                  }

              }
              xil_printf("\r\n%x, %x\r\n", x_pos, y_pos);

              if(status==CVP)
              DrawChess(x_pos, y_pos, 1-turn);
              else
              DrawChess(x_pos, y_pos, turn);


              board_state[x_pos][y_pos]=COMPUTER_PLAYER;
              board_record[BackTimes].x=x_pos;
              board_record[BackTimes].y=y_pos;
              BackTimes++;

              count=0;
              time0=0;
              if (CheckWin(x_pos, y_pos, turn)) {
                  xil_printf("\r\nComputer Player wins!\r\n");
                  win_flag=1;
                  DrawWinning(0,1, EMPTY);
                  if(status==CVP)
                      DrawWinning(0,1, 1-turn);
                  else
                      DrawWinning(0,1, turn);

                  //money--;
                  afterGame(0);
                  turn=HUMAN_PLAYER;
              }
              else
              {
                  turn=HUMAN_PLAYER;
                  xil_printf("\r\nHuman Player's turn!\r\n");
              }
          }//��������

       else {
        do {//�ȴ���������
            if (turn==COMPUTER_PLAYER && status==PVC && page== 1)
                          break;
                dip_check=XGpio_DiscreteRead(&dip, 1);
                StatusReg = XPs2_GetStatus(&Ps2Inst);
            }while((StatusReg & XPS2_STATUS_RX_FULL) == 0);
        BytesReceived = XPs2_Recv(&Ps2Inst, &RxBuffer, 1);
        key_count = (key_count + 1) % 3;
        if (key_count==0){

        if (win0 == 1) win0++;
        if (die == 1) die++;

        if (die == 0 && win0 == 0){//����ȥ��ʱ��

            if ( RxBuffer==0x21 )//c��
            {
                   page = (page + 1) % 2; //��1���0 �� ��0���1
                   if (page == 1) //����
                   {
                       InitializeGame(x_cur, y_cur);
                       status=PVP;
                   }
                   else //��ʼ�˵�
                   {
                       drawBuy(cursor0);
                       drawFoodNum(pig,food,hp,money,grownPig);
                       //drawFood(1);
                       //drawWin(0,0,2,2);//��ɫ
                   }
                   //break;
            }

       if (page == 0) //���˵�
       {
           if (RxBuffer==0x1D)//�����
           {
               cursor0--;//�������
               if (cursor0 < 0) cursor0 = 4;
               drawBuy(cursor0);

           }
           if (RxBuffer==0x1B)//�����
           {
               cursor0 = (cursor0 + 1) % 5;//�������
               drawBuy(cursor0);

           }

           if  (RxBuffer==0x29)//�ո� ����
           {
               switch (cursor0)
               {
                   case BUY_PIG: buyPig(); break;
                   case SELL_PIG: sellPig(); break;
                   case EAT_MEAL:
                                money--;
                                hp+=5;
                                drawFoodNum(pig,food,hp,money,grownPig);
                                break;
                   case BUY_FOOD:
                                money--;
                                food+=5;
                                drawFoodNum(pig,food,hp,money,grownPig);
                                break;
                  case 4://end game
                                if (money >= 10) win0 = 2;
                                else die = 2;
               }
           }

       }



       if(page == 1 && die == 0 && win0 == 0) //����Ϸ��ҳ��
       {
          if (turn==HUMAN_PLAYER || (turn==COMPUTER_PLAYER && status==PVP)) {
//              do {//�ȴ���������
//                  if (turn==COMPUTER_PLAYER && status==PVC)
//                      break;
//                  dip_check=XGpio_DiscreteRead(&dip, 1);
//                  StatusReg = XPs2_GetStatus(&Ps2Inst);
//              }while((StatusReg & XPS2_STATUS_RX_FULL) == 0);
//              BytesReceived = XPs2_Recv(&Ps2Inst, &RxBuffer, 1);
//              key_count=(key_count+1)%3;
              //if (key_count==0) {
//                  if (RxBuffer==0x21)
//                  {
//                      page = 0;
//                      drawLetter('A',10,10,1,2);//��ʼ������ʼ����
//                      break;
//                  }
//                  if (RxBuffer==0x21 && win_flag==0) {//�ı��Ѷȣ�
//                      DrawNumber(level,6,18,EMPTY);
//
//                      if(level==1)
//                          level=2;
//                      else if(level==2)
//                          level=3;
//                      else
//                          level=1;
//
//                      if(status==PVC )
//                      DrawNumber(level,6,18,0);
//                      else if(status==CVP)
//                      DrawNumber(level,6,18,1);
//                      else
//                      DrawNumber(level,6,18,EMPTY);
//
//                  }
                  if (RxBuffer==0x1D && win_flag==0) {//���������ƶ�wasd ��
                      EraseCursor(x_cur, y_cur);
                      if (y_cur<=0)
                          y_cur=14;
                      else
                          y_cur--;
                      DrawChess(x_cur, y_cur, CURSOR);
                  }
                  if (RxBuffer==0x1B && win_flag==0) {//��
                      EraseCursor(x_cur, y_cur);
                      if (y_cur>=14)
                          y_cur=0;
                      else
                          y_cur++;
                      DrawChess(x_cur, y_cur, CURSOR);
                  }
                  if (RxBuffer==0x1C && win_flag==0) {//��
                      EraseCursor(x_cur, y_cur);
                      if (x_cur<=0)
                          x_cur=14;
                      else
                          x_cur--;
                      DrawChess(x_cur, y_cur, CURSOR);
                  }
                  if (RxBuffer==0x23 && win_flag==0) {//��
                      EraseCursor(x_cur, y_cur);
                      if (x_cur>=14)
                          x_cur=0;
                      else
                          x_cur++;
                      DrawChess(x_cur, y_cur, CURSOR);
                  }

                  if (RxBuffer==0x5A && win_flag==0) {//����
                      DrawBack(3,9,EMPTY);
                      if (board_state[x_cur][y_cur]==EMPTY) {

                          if(status==CVP)
                          DrawChess(x_cur, y_cur, 1-turn);
                          else
                          DrawChess(x_cur, y_cur, turn);

                          board_state[x_cur][y_cur]=turn;
                          board_record[BackTimes].x=x_cur;
                          board_record[BackTimes].y=y_cur;
                          BackTimes++;
                          count=0;
                          time0=0;
                          if (turn==COMPUTER_PLAYER)
                              step_flag=1;
                          if (CheckWin(x_cur,y_cur,turn)==1) {
                              xil_printf("\r\nHuman Player wins!\r\n");
                              win_flag=1;
                              DrawWinning(0, 1, EMPTY);
                              if(status==CVP)
                                  DrawWinning(0, 1, 1-turn);
                              else
                                  DrawWinning(0, 1, turn);

                              if (status==CVP || status==PVC)
                              {
                                  //money+=3;
                                  afterGame(1);
                              }
                          }
                          else if (CheckBan(x_cur,y_cur,turn)==1){
                              xil_printf("\r\nComputer Player wins!\r\n");
                              win_flag=1;
                              DrawWinning(0, 1, EMPTY);
                              if(status==CVP)
                                  DrawWinning(0, 1, turn);
                              else
                                  DrawWinning(0, 1, 1-turn);
                              if (status==CVP || status==PVC)
                              {
                                  //money--;
                                  afterGame(0);
                              }
                          }
                          else {
                              if (turn==HUMAN_PLAYER)
                                  turn=COMPUTER_PLAYER;
                              else
                                  turn=HUMAN_PLAYER;
                              xil_printf("\r\nComputer Player's turn!\r\n");
                          }
                      }
                  }
                  if (RxBuffer==0x29 && turn==HUMAN_PLAYER && win_flag==0) {//change mode �ո�
                      count=0;time0=0;

                      if (status==PVP) {
                          x_cur=7;
                          y_cur=7;
                          for (i=0; i<256; i++) {
                                board_record[i].x=0;
                                board_record[i].y=0;
                                      }
                          InitializeGame(x_cur, y_cur);status=PVP;
                          DrawStatus(0, 18, EMPTY,status);
                          status=PVC;
                          DrawNumber(level,6,18,0,1);
                          DrawStatus(0, 18, COMPUTER_PLAYER,status);
                      }
                      else if(status==PVC) {
                          x_cur=7;
                          y_cur=7;
                          for (i=0; i<256; i++) {
                                board_record[i].x=0;
                                board_record[i].y=0;
                                      }
                          InitializeGame(x_cur, y_cur);status=PVP;
                          DrawStatus(0, 18, EMPTY,status);
                          status=CVP;
                          DrawNumber(level,6,18,1,1);
                          DrawStatus(0, 18, COMPUTER_PLAYER,status);
                          turn=COMPUTER_PLAYER;
                      }
                      else if(status==CVP) {
                          x_cur=7;
                          y_cur=7;
                          for (i=0; i<256; i++) {
                                board_record[i].x=0;
                                board_record[i].y=0;
                                      }
                          InitializeGame(x_cur, y_cur);status=PVP;
                          DrawStatus(0, 18, EMPTY,status);
                          status=PVP;
                          DrawStatus(0, 18, COMPUTER_PLAYER,status);
                      }
                  }
                  if (RxBuffer==0x76) {//�˳���
                      x_cur=7;
                      y_cur=7;
                      for (i=0; i<256; i++) {
                            board_record[i].x=0;
                            board_record[i].y=0;
                                  }
                      InitializeGame(x_cur, y_cur);status=PVP;
                  }
                  if (RxBuffer==0x2D) {//����
                      if(BackTimes>0){
                        BackTimes--;
                        x_cur=board_record[BackTimes].x;
                        y_cur=board_record[BackTimes].y;
                        board_state[x_cur][y_cur]=EMPTY;
                        DrawChess(x_cur,y_cur,EMPTY);
                        turn=1-turn;
                        if(status==PVC)
                        {
                        BackTimes--;
                        x_cur=board_record[BackTimes].x;
                        y_cur=board_record[BackTimes].y;
                        board_state[x_cur][y_cur]=EMPTY;
                        DrawChess(x_cur,y_cur,EMPTY);
                        turn=HUMAN_PLAYER;
                        }
                        DrawBack(3,9,turn);
                                              }
                                              }
              //}
          }


       }//page == 1

   }//die win��Ϊ0

        if (die == 3)
            {
                die = 0;
                drawDie(0,0,0,2);//���ԭ�ȵ���ɫ
                page = 0;//���¿�ʼ��Ϸ
                pig = 0;
                grownPig = 0;
                food = 0;
                hp = 5;
                money = 0;
                cursor0 = 0;
                head = 0;
                tail = 0;
                pigs[head] = 0;

                drawBuy(cursor0);
                drawFoodNum(pig,food,hp,money,grownPig);
                //drawFood(1);//����� ��ɫ

            }
        if (die == 2)
            {
                drawDie(0,0,3,2);
                drawFoodNum(pig,food,hp,money,grownPig);
                die++;
            }

        if (win0 == 3)
            {
                win0 = 0;
                drawWin(0,0,0,2);//���
                page = 0;//���¿�ʼ��Ϸ
                pig = 0;
                grownPig=0;
                food = 0;
                hp = 5;
                money = 0;
                cursor0 = 0;
                head = 0;
                tail = 0;
                pigs[head] = 0;
                drawBuy(cursor0);
                drawFoodNum(pig,food,hp,money,grownPig);
                //drawFood(1);//����� ��ɫ
            }
        if (win0 == 2)
            {
                drawWin(0,0,2,2);//��ɫ
                drawFoodNum(pig,food,hp,money,grownPig);
                win0++;
            }


   }//keycount == 0
   }   //else �ǵ�������
   }//while 1

   return 0;
}


