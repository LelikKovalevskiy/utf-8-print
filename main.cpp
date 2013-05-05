#include <iostream>
#include <string.h>

using namespace std;
int lengthof(const char *str)
{
    const char *s;
    for (s=str; *s; ++s);
    return(s-str);
} // не нужна.
void print(unsigned char *str,int new_length)// определяет, сколько символов в строке( не все, а только
{                                               // те, которые будут напечатаны)
    int counter=0;
    for(unsigned char *onPrint=str; *onPrint; ++onPrint )
    {
        cout<<*onPrint;
    }
    while(*str)
    {
        if(*str>=0x00 && *str<=0x7F)
        {
            ++str;
        }
        else if(*str>=0xC2 && *str<=0xDF)
        {
            str+=2;
        }
        else if(*str>=0xE0 && *str<=0xEF)
        {
            str+=3;
        }
        else if(*str>=0xF0 && *str<=0xF7)
        {
            str+=4;

        }
         ++counter;
    }
    for(int i=0; i<new_length-counter; ++i)
        cout<<' ';

}

int main()
{
    int length=30;
    unsigned char str1[]="Аa╔╗бbвгd╗дe";
     unsigned char str2[]="Привет, мир!";
     print(str1,length);
    cout<<'|'<<endl;
    print(str2,length);
    cout<<'|'<<endl;



    return 0;


}
