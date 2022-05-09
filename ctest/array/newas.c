//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>
#include <string.h>

cteststart()
        null(newas(NULL,0));
        arrayp s;

        s = newas("test",10);
        zero(strcmp(atos(s),"test"));
        assert(s->used == strnlen_s("test",5));
        assert(s->bytes == (sizeof(char) * (1 + strnlen_s("test",5))));

        s = newas("test",4);
        zero(strcmp(atos(s),"test"));
        assert(s->used == strnlen_s("test",5));
        assert(s->bytes == (sizeof(char) * (1 + strnlen_s("test",5))));

        s = newas("test",3);
        zero(strcmp(atos(s),"tes"));
        assert(s->used == strnlen_s("tes",5));
        assert(s->bytes == (sizeof(char) * (1 + strnlen_s("tes",5))));

        s = newas("test",1);
        zero(strcmp(atos(s),"t"));
        assert(s->used == strnlen_s("t",5));
        assert(s->bytes == (sizeof(char) * (1 + strnlen_s("t",5))));

        s = newas("test",0);
        zero(strcmp(atos(s),""));
        assert(s->used == strnlen_s("",5));
        assert(s->bytes == (sizeof(char) * (1 + strnlen_s("",5))));
ctestend