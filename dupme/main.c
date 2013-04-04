#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const int buff = 512;

int i_want_atoi(char* why)
    {
        int temp = 0, i = 0;
        while(why[i] >= '0' && why[i] <= '9')
            {
                temp = temp * 10 + why[i] - 48;
                i++;
            }
        return temp;
    }

int main(int argc, char* argv[])
    {
        int k = i_want_atoi(argv[1]), flag1 = 1, flag2 = 1, temp_pointer = 0, i = 0;
        /*char *temp = (char *) malloc(k + 1), *buffer = (char *) malloc(buff);*/
        /*дико странное поведение, если первая строка не влезает*/
        /*ее она обрабатывает криво, а вот все последующие почемуто нормально*/
        /*вариант, который ниже, работает прекрастно*/
        char temp[k + 1], buffer[buff];
        while (flag1 == 1)
            {
                int hmr = read(0, buffer, buff), i = 0;
                while (i < hmr)
                    {
                        temp[temp_pointer++] = buffer[i++];
                        if (temp_pointer <= k + 1 && temp[temp_pointer - 1] == '\n' && flag2 == 1)
                            {
                                write(1, temp, temp_pointer);
                                write(1, temp, temp_pointer);
                                temp[temp_pointer - 1] = 'a';
                                temp_pointer = 0;
                            }
                        if (temp_pointer == k + 1 && temp[temp_pointer - 1] != '\n')
                            {
                                flag2 = 0;
                                temp_pointer = 0;
                            }
                        if (flag2 == 0 && temp[temp_pointer - 1] == '\n')
                            {
                                flag2 = 1;
                                temp_pointer = 0;
                            }
                    }
                if (hmr < buff)
                    flag1 = 0;
            }
        return 0;
    }
