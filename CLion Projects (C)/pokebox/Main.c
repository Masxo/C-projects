/*
############################################################
#                                                          #
#             Made by: Leonardo Tórtoro Pereira            #
#                   leonardop@usp.br                       #
#                                                          #
#      “you have something called "determination."         #
#       so as long as you hold on...                       #
#       so as long as you do what's in your heart...       #
#       i believe you can do the right thing.”             #
#                                                          #
#                   'll0MMMMMMMMMMMMMOll'                  #
#                 .OMMMMMMMMMMMMMMMMMMM0l'                 #
#                'OMMMMMMMMMMMMMMMMMMMMMM0'                #
#               '0MMMMMMMMMMMMMMMMMMMMMMMM0'               #
#              '0MMMMMMMMMMMMMMMMMMMMMMMMMM0'              #
#              lMMMMMMMMMMMMMMMMMMMMMMMMMMMMl              #
#              0MMMMMMMMMMMMMMMMMMMMMMMMMMMM0              #
#              MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM              #
#              MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM              #
#              MMMM0lllllOMMMMMMMM0lllll0MMMM              #
#              MM0l'     .OMMMMMM0'     'l0MM              #
#              M0'        lMMMMMMl        '0M              #
#              Ml    'l'  lMMMMMMl  'l'    lM              #
#              Ml    lMl  lMMMMMMl  lMl    lM              #
#              00'   'l' '0M0ll0M0' 'l'   '00              #
#              lM0l'     lMMl  lMMl     'l0Ml              #
#              '0MM0lll''0M0'  '0M0''lll0MM0'              #
#               lMMMM0ll0MMl    lMM0ll0MMMMl               #
#              '0MM000l0MMMl    lMMM0lOO0MMO.              #
#              lMM0'lMMMMMMOllll0MMMMMMl'0MMl              #
#              lM0' 'l0MMMMMMMMMMMMMM0l' '0Ml              #
#              lM0l' 'llllllllllllllll' 'l0Ml              #
#              lMMMl ll              ll lMMMl              #
#              '0MM0'll'l''l''lll''l'll'0MM0'              #
#               lMMM0l'lMllMllMMMllMl'l0MMMl               #
#               '0MMMO''0llMllMMMll0''0MMM0'               #
#                '0MMM0ll''l''lll''ll0MMM0'                #
#                 'l0MMM0llllllllll0MMMOl'                 #
#                   'l0MMMMMMMMMMMMMM0l'                   #
#                     lMMMMMMMMMMMMMMl                     #
#                                                          #
############################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Util.h"
#include "PokeType.h"
#include "Pokemon.h"
#include "PokeBox.h"
#include "PokeDex.h"
#include "SaveManager.h"
#include "Moves.h"
#include "utils.h"

int main()
{
pokebox_t *pokeboxes;
char *line = readline(stdin);
while(line[0] != 0) {
    switch (atoi(line)) {
        case 1:
            break;
        case -1:
            break;
        case 2:
            break;
        case -2:
            break;
        case 3:
            break;
        case 4:
            break;
        case -4:
            break;
        case 5:
            break;
        default:
            printf("errro");
            break;
    }
    free(line);
    line = readline(stdin);
}
}
