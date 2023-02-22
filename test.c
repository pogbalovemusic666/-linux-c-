#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define N 100
#include <stdio.h>
#include<string.h>

//#include "math.h"



 void my_itoa(int val, char* buf)
{
    const unsigned int radix = 10;

    char* p;
    unsigned int a;        //every digit
 
    char* b;            //start of the digit char
    char temp;
    unsigned int u;

    p = buf;

    if (val < 0)
    {
        *p++ = '-';
        val = 0 - val;
    }
    u = (unsigned int)val;

    b = p;

    do
    {
        a = u % radix;
        u /= radix;

        *p++ = a + '0';

    } while (u > 0);


    *p-- = 0;

    //swap
    do
    {
        temp = *p;
        *p = *b;
        *b = temp;
        --p;
        ++b;

    } while (b < p);


}










 void my_fcvt(float value, int ndigit, char* aim)
 {


     int b = value;
     char aim1[50];
     my_itoa(b, aim1);
     strcat(aim, aim1, strlen(aim1));
     strcat(aim, ".", 1);


     float c = 0;

     c = value - b;


     for (int i = 0; i < ndigit; i++)
     {

         c = c * 10;
     }
     int d = c;
     if (value < 0)
     {
         d = -d;
     }

     my_itoa(d, aim1);
     strcat(aim, aim1, strlen(aim1));
 }


 int check_sys()
 {
     int i = 1;
     return(*(char*)&i);

 }







void  ll2str(long long value,char* s,  int radix) 
{
    char* p, aux;
    unsigned long long v;
    

    /* Generate the string representation, this method produces
     * an reversed string. */
    v = (value < 0) ? -value : value;
    p = s;
    do {
        *p++ = '0' + (v % radix); // 2 
        v /= radix; // 2
    } while (v);
    if (value < 0) *p++ = '-';

    /* Compute length and add null term. */
  
    *p = '\0';

    /* Reverse the string. */
    p--;
    while (s < p) {
        aux = *s;
        *s = *p;
        *p = aux;
        s++;
        p--;
    }
   
}






















void hextodec_int(char *a ,char* decstr)
{
    int i = 0;
         int re = 0;
    while (a[i])       //当读取到输入的最后一个字符之后，读取到0，跳出循环
    {
        if (a[i] >= '0' && a[i] <= '9') {

            re = re * 16 + a[i] - '0';
        }          //a[i]-'0'利用ASCII码值差值求该位的值
        else if (a[i] >= 'a' && a[i] <= 'f') {

            re = re * 16 + a[i] + 10 - 'a';
        }          //a[i]-'a'利用ASCII码值差值求该位的值
        else if (a[i] >= 'A' && a[i] <= 'F') {

            re = re * 16 + a[i] + 10 - 'A';
        }          //a[i]-'A'利用ASCII码值差值求该位的值
        i++;       //从最高位依次往低一位遍历

    }
        my_itoa(re, decstr);
}












void hextodec_long(char* a, char* decstr)
{
    int i = 0;
    long long int re = 0;
    while (a[i])       //当读取到输入的最后一个字符之后，读取到0，跳出循环
    {
        if (a[i] >= '0' && a[i] <= '9') {

            re = re * 16 + a[i] - '0';
        }          //a[i]-'0'利用ASCII码值差值求该位的值
        else if (a[i] >= 'a' && a[i] <= 'f') {

            re = re * 16 + a[i] + 10 - 'a';
        }          //a[i]-'a'利用ASCII码值差值求该位的值
        else if (a[i] >= 'A' && a[i] <= 'F') {

            re = re * 16 + a[i] + 10 - 'A';
        }          //a[i]-'A'利用ASCII码值差值求该位的值
        i++;       //从最高位依次往低一位遍历

    }
    ll2str(re,decstr,10 );
}



int hextodec(char* a, char* decstr)
{
    int i = 0;
int re = 0;
    while (a[i])       //当读取到输入的最后一个字符之后，读取到0，跳出循环
    {
        if (a[i] >= '0' && a[i] <= '9') {

            re = re * 16 + a[i] - '0';
        }          //a[i]-'0'利用ASCII码值差值求该位的值
        else if (a[i] >= 'a' && a[i] <= 'f') {

            re = re * 16 + a[i] + 10 - 'a';
        }          //a[i]-'a'利用ASCII码值差值求该位的值
        else if (a[i] >= 'A' && a[i] <= 'F') {

            re = re * 16 + a[i] + 10 - 'A';
        }          //a[i]-'A'利用ASCII码值差值求该位的值
        i++;       //从最高位依次往低一位遍历

    }
    return re;
}







void cut(int start,int end,int keep,char*detail,char* chinese,char* source, char* aim)
{
   
    int lenint = end - start + 1;
    int lenstr=strlen(detail);
    strcat(aim, detail);
    strcat(aim,":");

    char p[N] = { 0 };
    strncpy(p, source + start, lenint);
 
    char q[N] = { 0 };
    hextodec_int(p, q);
    strcat(aim,q);
    

}


void transport(char* source, char* aim)
{

    cut(14, 26, 0, "time", "时间", source, aim);
//        DRIVER_ID(676, 682, 0, "driveId", "司机号"),
//cut(472, 478, 1, "barop", "大气压力"),
//        AMBT(176, 182, 1, "ambt", "环境温度"),
//        ALTFAMPS(104, 110, 1, "altFamps", "主发励磁电流"),
//        ENGCMD(328, 334, 0, "engCmd", "柴油机转速命令"),
//        BAT(160, 166, 2, "batteryVoltage", "电池电压"),
//        AFSET(360, 366, 1, "afset", "励磁机温度"),
cut(144, 150, 0, "linkV", "母线电压", source, aim);
//        ENGSPD(248, 254, 0, "engineSpeed", "发动机转速"),
//        POTREF(480, 486, 2, "potref", "10V参考电压"),
//        PTEMP(496, 502, 2, "pTemp", "复合温度"),
//        LINKI(112, 118, 0, "linkI", "母线电流"),
//        GFAULT(456, 462, 0, "gfault", "接地电流"),
//        HPLINK(352, 358, 0, "hpLink", "母线功率"),
//        HPADJ(392, 398, 0, "hpadj", "调整功率"),
//        PAYLD(688, 694, 0, "payLoad", "载重"),
//        PSCMODE(38, 40, 0, "pscMode", "工作模式(电驱系统模式)"),
//        ACCEL_SEL(312, 318, 2, "accelSel", "加速踏板"),
//        RETRD_SEL(320, 326, 2, "retrdSel", "缓行踏板"),
//        DIRECTION(48, 50, 0, "direction", "方向"),
//        TRUCKSPEED(304, 310, 1, "truckSpeed", "卡车速度"),
//        LFRPM(184, 190, 1, "lfrpm", "左前轮速度"),
//        RFRPM(192, 198, 1, "rfrpm", "右前轮速度"),
//        M1RPM(232, 238, 1, "m1rpm", "电机1转速"),
//        M2RPM(240, 246, 1, "m2rpm", "电机2转速"),
//        I1LV(216, 222, 0, "i1lv", "逆变器1电压"),
//        I2LV(224, 230, 0, "i2lv", "逆变器2电压"),
//        RETSPD(168, 174, 1, "retspd", "缓行控制速度"),
//        TQCMD1(336, 342, 0, "tqcmd1", "力矩命令1"),
//        TQCMD2(344, 350, 0, "tqcmd2", "力矩命令2"),
//        TRQFB1(200, 206, 0, "trqfb1", "力矩反馈1"),
//        TRQFB2(208, 214, 0, "trqfb2", "力矩反馈2"),
//        //    PWR1(632,638,0,"model1", "逆变器1模式"),
//
        cut(36, 36, 0, "model1", "逆变器1模式", source, aim);
//        MODEL2(38, 38, 0, "model2", "逆变器2模式"),
//        ALTFVOLTS(136, 142, 1, "altfVolts", "主发励磁电机"),
//        ALTFPOS(464, 470, 1, "altFieldPlusEndVolts", "主发励磁正端电压"),
//
//        VOLTS_24P(416, 422, 2, "+24V", "+24V"),
//        VOLTS_24N(424, 430, 2, "-24V", "-24V"),
//        VOLTS_15P(432, 438, 2, "+15V", "+15V"),
//        VOLTS_15N(440, 446, 2, "-15V", "-15V"),
//        VOLTS_5P(448, 454, 2, "+5V", "+5V"),
//
//        B1_VOLTS(504, 510, 1, "b1Volts", "鼓风机电压"),
//        B1_AMPS(608, 614, 1, "b1Amps", "鼓风机1电流"),
//        B2_AMPS(616, 622, 1, "b2Amps", "鼓风机2电流"),
//        //    FDIODEINT(466,472,1,"fdiodeint", "主整流二极管故障"),
//        CPUBOARDTEMP(752, 758, 1, "CPUBoardTemp", "cpu温度"),
//        ALTERNATOR(592, 598, 1, "alterNator", "主发电机"),
//        RECTIDIODEJUNCT(600, 606, 1, "rectiDiodeJunct", "主整流二极管"),
//        CHOPPERMODULE(576, 582, 1, "chopperModule", "斩波器相模块"),
//        CHOPPERDIODE(584, 590, 1, "chopperDidoe", "斩波器二极管"),
//        LEFTMOTORSTATOR(520, 526, 1, "leftMotoStator", "电机1定子"),
//        LEFTMOTORROTOR(536, 542, 1, "leftMotoRotor", "电机2定子"),
//        RIGHTMOTORSTATOR(512, 518, 1, "rightMotoStator", "电机1转子"),
//        RIGHTMOTORROTOR(528, 534, 1, "rightMotoRotor", "电机2转子"),
//        LEFTINVERTERMODULE(544, 550, 1, "leftInverterModule", "逆变器1相模块"),
//        LEFTINVERTERDIODE(560, 566, 1, "leftInverterDidoe", "逆变器1二极管"),
//        RIGHTINVERTERMODULE(552, 558, 1, "rightInverterModule", "逆变器2相模块"),
//        RIGHTNVERTERDIODE(568, 574, 1, "rightInverterDidoe", "逆变器2二极管"),
//        //01:KEYSW 08:PS-UN 10:ENGKILL
//        INPUT_1(54, 56, 1, "inpu_1", "输入量1"),
//        //04:PRKBRKFB 10:ENGWARN
//        INPUT_2(62, 64, 1, "inpu_2", "输入量2"),
//        //01:WARM-UP 02:INV1DID 04:INV2DID 10:RESET-DO 20:OVERPAYLD 40:BRKTSTREQ 80:AXLEP
//        INPUT_3(66, 68, 1, "inpu_3", "输入量3"),
//        //01:SPDLIM 02:FORREQ 04:REVREQ 08:ACCINH 10:RSC 40:ENGKILL 80:DATAST
//        INPUT_4(58, 60, 1, "inpu_4", "输入量4"),
//        //01:CPSFB 02:CNTRLP 04:GFFB 20:PSOK 40:ESI1 80:ESI2
//        INPUT_5(50, 52, 1, "inpu_5", "输入量5"),
//        //08:GFNCO 40:BRAKEON 80:OEMACCIN
//        INPUT_6(52, 54, 1, "inpu_6", "输入量6"),
//        //01:WheelLocK 08:LAMPTEST 10:ENGSTRTREQ
//        INPUT_7(70, 72, 1, "inpu_7", "输入量7"),
//        //01:LOADBRK 04:RESETSW 10:BODYDWN 20:FULLPAYLD
//        INPUT_8(60, 62, 1, "inpu_8", "输入量8"),
//        //01:RP1 02:RP2 20:GFR 40:GF
//        INPUT_9(76, 78, 1, "inpu_9", "输入量9"),
//        //04:SYSRUN 40:CMCTL 80:SCR3
//        INPUT_10(78, 80, 1, "inpu_10", "输入量10"),
//        //01:CPRL 08:AFSE 40:REVT 80:FORT
//        INPUT_11(74, 76, 1, "inpu_11", "输入量11"),
//        //01:SPD1 02:SPD2 04:REVERSE
//        INPUT_12(88, 90, 1, "inpu_12", "输入量12"),
//        //01:NORETARD 02:NOPROPEL 04:SPDLIMIT 10:WSLIDE1 20:WSLIDE2 40:WSPIN1 80:WSPIN2
//        INPUT_13(82, 84, 1, "inpu_13", "输入量13"),
//        //01:INV1DIS 02:INV2DIS 04:ENG_RP
//        INPUT_14(80, 82, 1, "inpu_14", "输入量14"),
//        //01:LMPOK 80:RTRDCONT
//        INPUT_15(84, 86, 1, "inpu_15", "输入量15"),
//        //08:PROPINH
//        INPUT_16(68, 70, 1, "inpu_16", "输入量16"),
//
}







int main()
{
 /*   char hex[10000] = "008100B701551217010A1511235800010101011040004000012708090002100000800008008FE30408082205013300010005003DB8754200000000CD14DF3F5E061644991E4C4100D2B7440000A0402067DC4171141A4218F9AA4100000000000000000050CAC50000C8C500C0B74400C0B744F500BB4449A6B9441D71AE4400000000D194423FE256C9400000000046A457C5AD142D42FD4C934101000000223E4E3F0000AF4471F2BDC571F2BDC500005FC50F11E04190C2304290C2304200000000000000000000203B2E202041C0CAC241E770C2C11A1C7341802C72C100F0A240002D82429951E241BB7A69419D3B1F41000020421F07FD4163D1A743F852E642D458EC4262AED3429E6DD9420000D8410000D841000000420000F84100002842000004426B96504200000000B6A03E430000000080473B440000E1C40000DDC41D71AE4400000000000000000000ED136CE98048000000000000A041000000000000000000D82E40003C8C40AFE74A3F5D391F41000000420000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    char decstr[10000] = {0};*/
  //  hextodec_long(hex,decstr);

  //cut(1, 3, 0, "time","时间",hex, decstr);
/*    transport(hex, decstr);


    printf("%s\n", decstr);   */  
  

  //  printf("%f", 3.14);

    //string_to_float(char* string, float* data);




 //   char a[10] = "4048f5c3";

 //   char b[10] = { 0 };
 //  int c= hextodec(a, b);
 //  float f = 0;

 //  memcpy(&f, &c, 4);
 //  printf("%f\n", f);

 //   //int ret = check_sys();
 //   //if (ret == 1)
 //   //{
 //   //    printf("小端\n");
 //   //}else
 //   //{
 //   //printf("大端\n");}
 //  // float d = 3.14;
 //  char p[5];
 //p=  fcvt(f,2,1,0);

 //
 //  printf("%s", p);

 /*   float a = 3.145926;
    int b = a;
    float c = a - b;
    c = c * 100;
    int d = c;
    printf("%f\n", a);
    printf("%d\n", b);
    printf("%f\n", c);
    printf("%d\n", d);*/


    char out[100] = {0};
    float a = -3.145926;
    my_fcvt(a, 3, out);
    int b = a;
    //printf("%d", b);
    printf("%s", out);







}







