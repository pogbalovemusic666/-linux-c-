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







int main()
{
 /*   char hex[10000] = "0080000000";
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







