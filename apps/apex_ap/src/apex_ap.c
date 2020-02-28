/*******************************************************************
 **                                                               **
 **  Copyright(C) 2020 Cepton Technologies. All Rights Reserved.  **
 **  Contact: https://www.cepton.com                              **
 **                                                               **
 *******************************************************************/

#include "sdk.h"
#include "platform_init.h"

int main(void)
{
    platform_init();

    printf("Starting the infinite while loop.\n");
    while (1)
    {
        printf("Apex while loop running.\n");
    }

    return 0;
}
