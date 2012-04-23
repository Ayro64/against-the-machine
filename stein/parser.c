#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "map.h"
#include "parser.h"

void parseTextFile(char *path)
{
    int i,j;
    int fileDes = open(path, O_RDONLY);
    char readReturn = ' ';

    do
    {
        i = 1;
        j = read(fileDes, &readReturn, 1);
        char a = readReturn;
        readReturn = ' ';
        buffer = malloc(NB_MAX_CHAR);
        if(j==-1)
        {
            printf("Invalid File Name.\n");
            break;
        }
        while(j != 0 && readReturn != '\n')
        {
            j = read(fileDes, &readReturn, 1);
            if (j != 0)
                buffer[i++] = readReturn;
        }
        treatLine(a);
        free(buffer);
    }while(j != 0);
    close(fileDes);
}

void treatLine(char a)
{
    int param1=0, param2=0, param3=0;
    switch(a)
    {
        case('R'):
            for(;*buffer != ' ';++buffer){}
            buffer++;
            for(;*buffer != '\n';buffer++)
            {
                param1 = param1*10 + (*buffer-48);
            }
            g = create_graph(param1);
            break;
        case('M'):
            for(;*buffer != ' ';++buffer){}
            buffer++;
            for(;*buffer != ' ';buffer++)
            {
                param1 = param1*10 + (*buffer - 48);
            }
            buffer++;
            for(;*buffer != '\n';buffer++)
            {
                param2 = param2*10 + (*buffer - 48);
            }
            g->lsom[param1-1]->cost = -param2;
            break;
        case('B'):
            for(;*buffer != ' ';++buffer){}
            buffer++;
            for(;*buffer != ' ';buffer++)
            {
                param1 = param1*10 + (*buffer - 48);
            }
            buffer++;
            for(;*buffer != '\n';buffer++)
            {
                param2 = param2*10 + (*buffer - 48);
            }
            g->lsom[param1-1]->cost = param2;
            break;
        case('D'):
            for(;*buffer != ' ';++buffer){}
            buffer++;
            for(;*buffer != '\n';buffer++)
            {
                param1 = param1*10 + (*buffer-48);
            }
            g->lsom[param1-1]->cost = -10000;
            break;
        case('A'):
            for(;*buffer != ' ' && *buffer != '\n';++buffer){}
            if(*buffer != '\n')
            {
                buffer++;
                for(;*buffer != ' ';buffer++)
                {
                    param1 = param1*10 + (*buffer - 48);
                }
                buffer++;
                for(;*buffer != ' ';buffer++)
                {
                    param2 = param2*10 + (*buffer - 48);
                }
                buffer++;
                for(;*buffer && *buffer != '\n';buffer++)
                {
                    param3 = param3*10 + (*buffer - 48);
                }
                add_arc(g, param1-1, param3-1, -param2);
            }
            break;
        default:
            break;
    }
}
