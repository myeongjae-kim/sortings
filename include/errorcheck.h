//
//  errorcheck.h
//
//  Created by Kim, Myeong-jae on 4/29/16.
//  Copyright © 2016 KimMyeong-jae. All rights reserved.
//

#ifndef errorcheck_h
#define errorcheck_h
#include <stdlib.h>

/* Error Checking Macro *
 *
 * ERROR_MSG(msg);
 * MALLOC(pointer, size);
 * CALLOC(pointer, number, size);
 * REALLOC(pointer, size);
 * FREE(pointer);
 * EIF(TRUE);
 *          if TRUE is 0, exit program.
 * EIN(TRUE);
 *          if TRUE is NULL, exit program.
 * FOPEN(fp, filepath, parameter);
 *          if the file cannot be opened, exit program.
 * SWAP(x, y, temp);
 *          swap x and y.
 * ARG_CHECK(number);
 *          if argc != number, print error message and exit program.
 */

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"

#define ERROR_MSG(msg) fprintf(stderr, ANSI_COLOR_RED "\tERROR: "ANSI_COLOR_YELLOW"%s" ANSI_COLOR_RESET, msg)
#define MEM_ERR "INSUFFICIENT MEMORY\n"

#define MALLOC(p,s)\
    do {\
        if( ! ((p) = malloc(s))) {\
            ERROR_MSG(MEM_ERR); \
            exit(EXIT_FAILURE);\
        }\
    }while(0)

#define CALLOC(p,n,s)\
    do {\
        if( ! ((p) = calloc(n, s))) {\
            ERROR_MSG(MEM_ERR); \
            exit(EXIT_FAILURE);\
        }\
    }while(0)

#define REALLOC(p,s)\
    do {\
        p = realloc(p,s);\
        if( !(p)) {\
            ERROR_MSG(MEM_ERR); \
            exit(EXIT_FAILURE);\
        }\
    }while(0)

#define FREE(p)\
    do{\
        if( ! (p) ) {\
            ERROR_MSG("free(): The variable has NULL value. It cannot be free.\n");\
        } else {\
            free(p);\
            p = NULL;\
        }\
    }while(0)
        
#define EIF(TRUE)\
    do{\
        if( ! (TRUE) ) {\
            ERROR_MSG("FALSE FALSE!\n"); \
            exit(EXIT_FAILURE);\
        }\
    }while(0)

#define EIN(TRUE)\
    do {\
        if( ! (TRUE) ) {\
            ERROR_MSG("NULL ADDRESS\n"); \
            exit(EXIT_FAILURE);\
        }\
    }while(0)

#define FOPEN(fp,path,param)\
    do{\
        if (! ( (fp) = fopen((path), (param)))) {\
            ERROR_MSG("FILE OPERNING FAILURE\n");\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
#define SWAP(x,y,temp) ((temp) = (x), (x) = (y), (y) = (temp))

#define ARG_CHECK(number)\
    do{\
        if( (argc) != (number) )\
        {\
            ERROR_MSG("CHECK COMMAND LINE ARGUMENTS.\n");\
            ERROR_MSG("ARGUMENT COUNTER SHOULD BE "); fprintf(stderr, ANSI_COLOR_CYAN "%d.\n"ANSI_COLOR_RESET, number);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
#endif /* errorcheck_h */
