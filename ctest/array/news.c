//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>
#include <string.h>

cteststart()
        array_p s = array_news(NULL, 0);
        null(s);
        array_del(s);

        s = array_news("test", 10);
        zero(strcmp(atos(s),"test"));
        assert(s->used == strnlen_s("test",5));
        assert(s->bytes == (sizeof(char) * (1 + strnlen_s("test",5))));
        array_del(s);

        s = array_news("test", 4);
        zero(strcmp(atos(s),"test"));
        assert(s->used == strnlen_s("test",5));
        assert(s->bytes == (sizeof(char) * (1 + strnlen_s("test",5))));
        array_del(s);

        s = array_news("test", 3);
        zero(strcmp(atos(s),"tes"));
        assert(s->used == strnlen_s("tes",5));
        assert(s->bytes == (sizeof(char) * (1 + strnlen_s("tes",5))));
        array_del(s);

        s = array_news("test", 1);
        zero(strcmp(atos(s),"t"));
        assert(s->used == strnlen_s("t",5));
        assert(s->bytes == (sizeof(char) * (1 + strnlen_s("t",5))));
        array_del(s);

        s = array_news("test", 0);
        zero(strcmp(atos(s),""));
        assert(s->used == strnlen_s("",5));
        assert(s->bytes == (sizeof(char) * (1 + strnlen_s("",5))));
        array_del(s);
ctestend