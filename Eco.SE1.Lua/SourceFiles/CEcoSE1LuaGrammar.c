/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoLuaGrammar
 * </сводка>
 *
 * <описание>
 *   Данный файл является описание грамматики
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "CEcoSE1LuaGrammar.h"

/*
 *
 * <сводка>
 *   Функция GetFAForLAOfLua
 * </сводка>
 *
 * <описание>
 *   Функция GetFAForLAOfLua - возвращает конечный автомат для лексического анализа Lua
 * </описание>
 *
 */
IEcoFSM1StateMachine* GetFAForLAOfLua(IEcoFSM1* pIFSM) {
    IEcoFSM1StateMachine* pIFA = 0;
    char_t pszStateName[5] = {0};
    uint32_t index = 0;
    uint32_t y = 0;
    IEcoFSM1Event* pIEvent[256] = {0};
    IEcoFSM1State* pIState[180] = {0};
    char_t pszPunctuators[27] = { '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', ':', ';', '<', '=', '>', '?', '@', '{', '|', '}', '~', 127};
    /* Создаем конечный автомат */
    pIFA = pIFSM->pVTbl->CreateStateMachine(pIFSM, "Lua");
    for (index = 0; index < 180; index++) {
        pszStateName[0] = 'q';
        pszStateName[1] = index/100 + 48;
        if (index >= 100) {
            pszStateName[2] = (index- 100)/10 + 48;
        }
        else {
            pszStateName[2] = index/10 + 48;
        }
        pszStateName[3] = index%10 + 48;
        pIState[index] = pIFA->pVTbl->AddState(pIFA, pszStateName);
    }

    /* Создадим массив событий для алфавита по прядку кодов ASCII таблицы */
    /* Конец файла EOF */
    pIEvent[0] = pIFA->pVTbl->AddEvent(pIFA, "EOF", 0, 0);
    /* Конец строки \r\n */
    pIEvent[10] = pIFA->pVTbl->AddEvent(pIFA, "LF", 10, 0); /* \n */
    pIEvent[13] = pIFA->pVTbl->AddEvent(pIFA, "CR", 13, 0); /* \r */
    /* Пробел и табуляция */
    pIEvent[9] = pIFA->pVTbl->AddEvent(pIFA, "HT", 9, 0);
    pIEvent[32] = pIFA->pVTbl->AddEvent(pIFA, "SP", 32, 0);
    /* Пунктуация */
    pIEvent['!'] = pIFA->pVTbl->AddEvent(pIFA, "!", '!', 0);
    pIEvent['"'] = pIFA->pVTbl->AddEvent(pIFA, "\"", '"', 0);
    pIEvent['#'] = pIFA->pVTbl->AddEvent(pIFA, "#", '#', 0);
    pIEvent['$'] = pIFA->pVTbl->AddEvent(pIFA, "$", '$', 0);
    pIEvent['%'] = pIFA->pVTbl->AddEvent(pIFA, "%", '%', 0);
    pIEvent['&'] = pIFA->pVTbl->AddEvent(pIFA, "&", '&', 0);
    pIEvent['\''] = pIFA->pVTbl->AddEvent(pIFA, "'", '\'', 0);
    pIEvent['('] = pIFA->pVTbl->AddEvent(pIFA, "(", '(', 0);
    pIEvent[')'] = pIFA->pVTbl->AddEvent(pIFA, ")", ')', 0);
    pIEvent['*'] = pIFA->pVTbl->AddEvent(pIFA, "*", '*', 0);
    pIEvent['+'] = pIFA->pVTbl->AddEvent(pIFA, "+", '+', 0);
    pIEvent[','] = pIFA->pVTbl->AddEvent(pIFA, ",", ',', 0);
    pIEvent['-'] = pIFA->pVTbl->AddEvent(pIFA, "-", '-', 0);
    pIEvent['.'] = pIFA->pVTbl->AddEvent(pIFA, ".", '.', 0);
    pIEvent['/'] = pIFA->pVTbl->AddEvent(pIFA, "/", '/', 0);
    /* Диапазон [0-9] */
    pIEvent['0'] = pIFA->pVTbl->AddEvent(pIFA, "0", '0', 0);
    pIEvent['1'] = pIFA->pVTbl->AddEvent(pIFA, "1", '1', 0);
    pIEvent['2'] = pIFA->pVTbl->AddEvent(pIFA, "2", '2', 0);
    pIEvent['3'] = pIFA->pVTbl->AddEvent(pIFA, "3", '3', 0);
    pIEvent['4'] = pIFA->pVTbl->AddEvent(pIFA, "4", '4', 0);
    pIEvent['5'] = pIFA->pVTbl->AddEvent(pIFA, "5", '5', 0);
    pIEvent['6'] = pIFA->pVTbl->AddEvent(pIFA, "6", '6', 0);
    pIEvent['7'] = pIFA->pVTbl->AddEvent(pIFA, "7", '7', 0);
    pIEvent['8'] = pIFA->pVTbl->AddEvent(pIFA, "8", '8', 0);
    pIEvent['9'] = pIFA->pVTbl->AddEvent(pIFA, "9", '9', 0);
    /* Пунктуация */
    pIEvent[':'] = pIFA->pVTbl->AddEvent(pIFA, ":", ':', 0);
    pIEvent[';'] = pIFA->pVTbl->AddEvent(pIFA, ";", ';', 0);
    pIEvent['<'] = pIFA->pVTbl->AddEvent(pIFA, "<", '<', 0);
    pIEvent['='] = pIFA->pVTbl->AddEvent(pIFA, "=", '=', 0);
    pIEvent['>'] = pIFA->pVTbl->AddEvent(pIFA, ">", '>', 0);
    pIEvent['?'] = pIFA->pVTbl->AddEvent(pIFA, "?", '?', 0);
    pIEvent['@'] = pIFA->pVTbl->AddEvent(pIFA, "@", '@', 0);
    /* Диапазон [A-Z] */
    pIEvent['A'] = pIFA->pVTbl->AddEvent(pIFA, "A", 'A', 0);
    pIEvent['B'] = pIFA->pVTbl->AddEvent(pIFA, "B", 'B', 0);
    pIEvent['C'] = pIFA->pVTbl->AddEvent(pIFA, "C", 'C', 0);
    pIEvent['D'] = pIFA->pVTbl->AddEvent(pIFA, "D", 'D', 0);
    pIEvent['E'] = pIFA->pVTbl->AddEvent(pIFA, "E", 'E', 0);
    pIEvent['F'] = pIFA->pVTbl->AddEvent(pIFA, "F", 'F', 0);
    pIEvent['G'] = pIFA->pVTbl->AddEvent(pIFA, "G", 'G', 0);
    pIEvent['H'] = pIFA->pVTbl->AddEvent(pIFA, "H", 'H', 0);
    pIEvent['I'] = pIFA->pVTbl->AddEvent(pIFA, "I", 'I', 0);
    pIEvent['J'] = pIFA->pVTbl->AddEvent(pIFA, "J", 'J', 0);
    pIEvent['K'] = pIFA->pVTbl->AddEvent(pIFA, "K", 'K', 0);
    pIEvent['L'] = pIFA->pVTbl->AddEvent(pIFA, "L", 'L', 0);
    pIEvent['M'] = pIFA->pVTbl->AddEvent(pIFA, "M", 'M', 0);
    pIEvent['N'] = pIFA->pVTbl->AddEvent(pIFA, "N", 'N', 0);
    pIEvent['O'] = pIFA->pVTbl->AddEvent(pIFA, "O", 'O', 0);
    pIEvent['P'] = pIFA->pVTbl->AddEvent(pIFA, "P", 'P', 0);
    pIEvent['Q'] = pIFA->pVTbl->AddEvent(pIFA, "Q", 'Q', 0);
    pIEvent['R'] = pIFA->pVTbl->AddEvent(pIFA, "R", 'R', 0);
    pIEvent['S'] = pIFA->pVTbl->AddEvent(pIFA, "S", 'S', 0);
    pIEvent['T'] = pIFA->pVTbl->AddEvent(pIFA, "T", 'T', 0);
    pIEvent['U'] = pIFA->pVTbl->AddEvent(pIFA, "U", 'U', 0);
    pIEvent['V'] = pIFA->pVTbl->AddEvent(pIFA, "V", 'V', 0);
    pIEvent['W'] = pIFA->pVTbl->AddEvent(pIFA, "W", 'W', 0);
    pIEvent['X'] = pIFA->pVTbl->AddEvent(pIFA, "X", 'X', 0);
    pIEvent['Y'] = pIFA->pVTbl->AddEvent(pIFA, "Y", 'Y', 0);
    pIEvent['Z'] = pIFA->pVTbl->AddEvent(pIFA, "Z", 'Z', 0);
    /* Пунктуация */
    pIEvent['['] = pIFA->pVTbl->AddEvent(pIFA, "[", '[', 0);
    pIEvent['\\'] = pIFA->pVTbl->AddEvent(pIFA, "\\", '\\', 0);
    pIEvent[']'] = pIFA->pVTbl->AddEvent(pIFA, "]", ']', 0);
    pIEvent['^'] = pIFA->pVTbl->AddEvent(pIFA, "^", '^', 0);
    pIEvent['_'] = pIFA->pVTbl->AddEvent(pIFA, "_", '_', 0);
    pIEvent['`'] = pIFA->pVTbl->AddEvent(pIFA, "`", '`', 0);
    /* Диапазон [a-z] */
    pIEvent['a'] = pIFA->pVTbl->AddEvent(pIFA, "a", 'a', 0);
    pIEvent['b'] = pIFA->pVTbl->AddEvent(pIFA, "b", 'b', 0);
    pIEvent['c'] = pIFA->pVTbl->AddEvent(pIFA, "c", 'c', 0);
    pIEvent['d'] = pIFA->pVTbl->AddEvent(pIFA, "d", 'd', 0);
    pIEvent['e'] = pIFA->pVTbl->AddEvent(pIFA, "e", 'e', 0);
    pIEvent['f'] = pIFA->pVTbl->AddEvent(pIFA, "f", 'f', 0);
    pIEvent['g'] = pIFA->pVTbl->AddEvent(pIFA, "g", 'g', 0);
    pIEvent['h'] = pIFA->pVTbl->AddEvent(pIFA, "h", 'h', 0);
    pIEvent['i'] = pIFA->pVTbl->AddEvent(pIFA, "i", 'i', 0);
    pIEvent['j'] = pIFA->pVTbl->AddEvent(pIFA, "j", 'j', 0);
    pIEvent['k'] = pIFA->pVTbl->AddEvent(pIFA, "k", 'k', 0);
    pIEvent['l'] = pIFA->pVTbl->AddEvent(pIFA, "l", 'l', 0);
    pIEvent['m'] = pIFA->pVTbl->AddEvent(pIFA, "m", 'm', 0);
    pIEvent['n'] = pIFA->pVTbl->AddEvent(pIFA, "n", 'n', 0);
    pIEvent['o'] = pIFA->pVTbl->AddEvent(pIFA, "o", 'o', 0);
    pIEvent['p'] = pIFA->pVTbl->AddEvent(pIFA, "p", 'p', 0);
    pIEvent['q'] = pIFA->pVTbl->AddEvent(pIFA, "q", 'q', 0);
    pIEvent['r'] = pIFA->pVTbl->AddEvent(pIFA, "r", 'r', 0);
    pIEvent['s'] = pIFA->pVTbl->AddEvent(pIFA, "s", 's', 0);
    pIEvent['t'] = pIFA->pVTbl->AddEvent(pIFA, "t", 't', 0);
    pIEvent['u'] = pIFA->pVTbl->AddEvent(pIFA, "u", 'u', 0);
    pIEvent['v'] = pIFA->pVTbl->AddEvent(pIFA, "v", 'v', 0);
    pIEvent['w'] = pIFA->pVTbl->AddEvent(pIFA, "w", 'w', 0);
    pIEvent['x'] = pIFA->pVTbl->AddEvent(pIFA, "x", 'x', 0);
    pIEvent['y'] = pIFA->pVTbl->AddEvent(pIFA, "y", 'y', 0);
    pIEvent['z'] = pIFA->pVTbl->AddEvent(pIFA, "z", 'z', 0);
    /* Пунктуация */
    pIEvent['{'] = pIFA->pVTbl->AddEvent(pIFA, "{", '{', 0);
    pIEvent['|'] = pIFA->pVTbl->AddEvent(pIFA, "|", '|', 0);
    pIEvent['}'] = pIFA->pVTbl->AddEvent(pIFA, "}", '}', 0);
    pIEvent['~'] = pIFA->pVTbl->AddEvent(pIFA, "~", '~', 0);
    pIEvent['~'] = pIFA->pVTbl->AddEvent(pIFA, "~", '~', 0);

    /* Устанавливаем начальное состояние автомата */
    pIState[0]->pVTbl->set_Initial(pIState[0], 1);

    /* Устанавливаем акцепторы - токены */
    pIState[68]->pVTbl->set_Final(pIState[68], 1);
    pIState[68]->pVTbl->set_Parameter(pIState[68], "keyword");

    pIState[106]->pVTbl->set_Final(pIState[106], 1);
    pIState[106]->pVTbl->set_Parameter(pIState[106], "multiline-comment");
    pIState[107]->pVTbl->set_Final(pIState[107], 1);
    pIState[107]->pVTbl->set_Parameter(pIState[107], "+");
    pIState[108]->pVTbl->set_Final(pIState[108], 1);
    pIState[108]->pVTbl->set_Parameter(pIState[108], "*");
    pIState[109]->pVTbl->set_Final(pIState[109], 1);
    pIState[109]->pVTbl->set_Parameter(pIState[109], "/");
    pIState[110]->pVTbl->set_Final(pIState[116], 1);
    pIState[110]->pVTbl->set_Parameter(pIState[116], "//");


    pIState[117]->pVTbl->set_Final(pIState[117], 1);
    pIState[117]->pVTbl->set_Parameter(pIState[117], "%");

    pIState[118]->pVTbl->set_Final(pIState[118], 1);
    pIState[118]->pVTbl->set_Parameter(pIState[118], "identifier");
    pIState[119]->pVTbl->set_Final(pIState[119], 1);
    pIState[119]->pVTbl->set_Parameter(pIState[119], "-");
    pIState[120]->pVTbl->set_Final(pIState[120], 1);
    pIState[120]->pVTbl->set_Parameter(pIState[120], "inline-comment");

//    pIState[143]->pVTbl->set_Final(pIState[143], 1);
//    pIState[143]->pVTbl->set_Parameter(pIState[143], "constant");
//    pIState[144]->pVTbl->set_Final(pIState[144], 1);
//    pIState[144]->pVTbl->set_Parameter(pIState[144], "identifier");
//    pIState[145]->pVTbl->set_Final(pIState[145], 1);
//    pIState[145]->pVTbl->set_Parameter(pIState[145], "keyword");
//    pIState[146]->pVTbl->set_Final(pIState[146], 1);
//    pIState[146]->pVTbl->set_Parameter(pIState[146], "string-literal");
//    pIState[147]->pVTbl->set_Final(pIState[147], 1);
//    pIState[147]->pVTbl->set_Parameter(pIState[147], "comment");
    pIState[129]->pVTbl->set_Final(pIState[129], 1);
    pIState[129]->pVTbl->set_Parameter(pIState[129], "new-line");
    pIState[130]->pVTbl->set_Final(pIState[130], 1);
    pIState[130]->pVTbl->set_Parameter(pIState[130], "white-space");
    pIState[131]->pVTbl->set_Final(pIState[131], 1);
    pIState[131]->pVTbl->set_Parameter(pIState[131], "string-literal");
    pIState[132]->pVTbl->set_Final(pIState[132], 1);
    pIState[132]->pVTbl->set_Parameter(pIState[132], "<");
    pIState[133]->pVTbl->set_Final(pIState[133], 1);
    pIState[133]->pVTbl->set_Parameter(pIState[133], "<=");
    pIState[134]->pVTbl->set_Final(pIState[134], 1);
    pIState[134]->pVTbl->set_Parameter(pIState[134],  ">");
    pIState[135]->pVTbl->set_Final(pIState[135], 1);
    pIState[135]->pVTbl->set_Parameter(pIState[135], ">=");
    pIState[136]->pVTbl->set_Final(pIState[136], 1);
    pIState[136]->pVTbl->set_Parameter(pIState[136], ".");
    pIState[137]->pVTbl->set_Final(pIState[137], 1);
    pIState[137]->pVTbl->set_Parameter(pIState[137], "delimiter");
    pIState[138]->pVTbl->set_Final(pIState[138], 1);
    pIState[138]->pVTbl->set_Parameter(pIState[138], "[");
    pIState[139]->pVTbl->set_Final(pIState[139], 1);
    pIState[139]->pVTbl->set_Parameter(pIState[139], "]");
    pIState[140]->pVTbl->set_Final(pIState[140], 1);
    pIState[140]->pVTbl->set_Parameter(pIState[140], "=");
    pIState[141]->pVTbl->set_Final(pIState[141], 1);
    pIState[141]->pVTbl->set_Parameter(pIState[141], "==");
    pIState[142]->pVTbl->set_Final(pIState[142], 1);
    pIState[142]->pVTbl->set_Parameter(pIState[142], "^");
    pIState[148]->pVTbl->set_Final(pIState[143], 1);
    pIState[148]->pVTbl->set_Parameter(pIState[143], "table-start");
    pIState[149]->pVTbl->set_Final(pIState[144], 1);
    pIState[149]->pVTbl->set_Parameter(pIState[144], "table-end");
    pIState[150]->pVTbl->set_Final(pIState[145], 1);
    pIState[150]->pVTbl->set_Parameter(pIState[145], "call-start");
    pIState[151]->pVTbl->set_Final(pIState[146], 1);
    pIState[151]->pVTbl->set_Parameter(pIState[146], "call-end");
    pIState[152]->pVTbl->set_Final(pIState[147], 1);
    pIState[152]->pVTbl->set_Parameter(pIState[147], "integer-constant");

    /* Общая схема переходов нарисована в draw.io */

    /* Создаем переходы для целых чисел */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['0'],  pIState[0],  pIState[2]);

    for (index = '1'; index <= '9'; index++) {
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[0],  pIState[1]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[1],  pIState[1]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[2],  pIState[1]);
    }

    /* Создаем переходы для вещественных чисел */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['.'],  pIState[1],  pIState[3]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['.'],  pIState[2],  pIState[3]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['.'],  pIState[100],  pIState[3]);

    for (index = '0'; index <= '9'; index++) {
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[3],  pIState[3]);
    }

    for (index = 0; index <= 255; index++) {
        if (index >= '0' && index <= '9') {
            continue;
        }
        if (index != '.') {
            pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[2],  pIState[147]);
            pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[1],  pIState[147]);
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[3],  pIState[147]);
    }

    /* Создаем переходы для шестнадцатеричных чисел */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['x'],  pIState[2],  pIState[4]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['X'],  pIState[2],  pIState[4]);

    for (index = '0'; index <= '9'; index++) {
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[4],  pIState[4]);
    }
    for (index = 'A'; index <= 'F'; index++) {
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[4],  pIState[4]);
    }
    for (index = 'a'; index <= 'f'; index++) {
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[4],  pIState[4]);
    }

    /* Создаем переходы для вещественных шестнадцатеричных чисел */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['.'],  pIState[4],  pIState[5]);

    for (index = '0'; index <= '9'; index++) {
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[5],  pIState[5]);
    }
    for (index = 'A'; index <= 'F'; index++) {
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[5],  pIState[5]);
    }
    for (index = 'a'; index <= 'f'; index++) {
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[5],  pIState[5]);
    }

    for (index = 0; index <= 255; index++) {
        if (index >= '0' && index <= '9' ||
            (index >= 'A' && index <= 'F') ||
            (index >= 'a' && index <= 'f')) {
            continue;
        }
        if (index != '.') {
            pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[4],  pIState[147]);
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[5],  pIState[147]);
    }

    /* Создаем переходы для операторов */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['-'],  pIState[0],  pIState[6]);
    for (index = 0; index <= 255; index++) {
        if (index == '-') {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[6],  pIState[119]);
    }

    pIFA->pVTbl->AddTransition(pIFA, pIEvent['+'],  pIState[0],  pIState[8]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['*'],  pIState[0],  pIState[9]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent['/'],  pIState[0],  pIState[10]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['/'],  pIState[10],  pIState[110]);

    for (index = 0; index < 255; index++) {
        if (index != '/') {
            pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[10],  pIState[109]);
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[8],  pIState[107]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[9],  pIState[108]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[110],  pIState[116]);
    }

    pIFA->pVTbl->AddTransition(pIFA, pIEvent['%'],  pIState[0],  pIState[111]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['^'],  pIState[0],  pIState[92]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent['='],  pIState[0],  pIState[90]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['='],  pIState[90],  pIState[91]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent['<'],  pIState[0],  pIState[112]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['='],  pIState[112],  pIState[113]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent['>'],  pIState[0],  pIState[114]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['='],  pIState[114],  pIState[115]);

    for (index = 0; index < 255; index++) {
        if (index != '=') {
            pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[112],  pIState[132]);
            pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[114],  pIState[134]);
            pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[90],  pIState[140]);
        }

        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[111],  pIState[117]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[91],  pIState[141]);

        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[113],  pIState[133]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[115],  pIState[135]);
    }

    /* Создаем переходы для ограничителей */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['{'],  pIState[0],  pIState[93]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['}'],  pIState[0],  pIState[94]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent['('],  pIState[0],  pIState[95]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[')'],  pIState[0],  pIState[96]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[','],  pIState[0],  pIState[97]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[';'],  pIState[0],  pIState[97]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent['['],  pIState[0],  pIState[98]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[']'],  pIState[0],  pIState[99]);

    for (index = 0; index < 255; index++) {
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[92],  pIState[142]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[93],  pIState[143]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[94],  pIState[144]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[95],  pIState[145]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[96],  pIState[146]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[97],  pIState[137]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[98],  pIState[138]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[99],  pIState[139]);
    }

    pIFA->pVTbl->AddTransition(pIFA, pIEvent['.'],  pIState[0],  pIState[100]);
    for (index = 0; index < 255; index++) {
        if (index >= '0' && index <= '9') {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[pszPunctuators[index]],  pIState[100],  pIState[136]);
    }

    /* Создаем переходы для комментариев */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['-'],  pIState[6],  pIState[7]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[10],  pIState[7],  pIState[120]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[13],  pIState[7],  pIState[120]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[10],  pIState[101],  pIState[120]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[13],  pIState[101],  pIState[120]);

    for (index = 0; index <= 255; index++) {
        if (index == '[' || index == 10 || index == 13) {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[7],  pIState[101]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[102],  pIState[101]);
    }
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['['],  pIState[7],  pIState[102]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['['],  pIState[102],  pIState[103]);

    for (index = 0; index <= 255; index++) {
        if (index == ']') {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[103],  pIState[103]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[104],  pIState[103]);
    }
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[']'],  pIState[103],  pIState[104]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[']'],  pIState[104],  pIState[105]);


    /* Создаем переходы для ключевых слов */
    /* and */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['a'],  pIState[0],  pIState[11]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['n'],  pIState[11],  pIState[12]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['d'],  pIState[12],  pIState[13]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[13],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[13],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[13],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[13],  pIState[68]);


    /* or */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['o'],  pIState[0],  pIState[14]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['r'],  pIState[14],  pIState[15]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[15],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[15],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[15],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[15],  pIState[68]);


    /* break */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['b'],  pIState[0],  pIState[16]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['r'],  pIState[16],  pIState[17]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['e'],  pIState[17],  pIState[18]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['a'],  pIState[18],  pIState[19]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['k'],  pIState[19],  pIState[20]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[20],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[20],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[20],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[20],  pIState[68]);

    /* do */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['d'],  pIState[0],  pIState[21]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['o'],  pIState[21],  pIState[22]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[22],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[22],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[22],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[22],  pIState[68]);

    /* end */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['e'],  pIState[0],  pIState[23]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['n'],  pIState[23],  pIState[24]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['d'],  pIState[24],  pIState[25]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[25],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[25],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[25],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[25],  pIState[68]);

    /* else */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['l'],  pIState[23],  pIState[26]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['s'],  pIState[26],  pIState[27]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['e'],  pIState[27],  pIState[28]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[28],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[28],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[28],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[28],  pIState[68]);

    /* elseif */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['i'],  pIState[28],  pIState[29]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['f'],  pIState[29],  pIState[30]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[30],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[30],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[30],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[30],  pIState[68]);

    /* for */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['f'],  pIState[0],  pIState[31]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['o'],  pIState[31],  pIState[32]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['r'],  pIState[32],  pIState[33]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[33],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[33],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[33],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[33],  pIState[68]);

    /* false */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['a'],  pIState[31],  pIState[34]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['l'],  pIState[34],  pIState[35]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['s'],  pIState[35],  pIState[36]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['e'],  pIState[36],  pIState[37]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[37],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[37],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[37],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[37],  pIState[68]);

    /* function */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['u'],  pIState[31],  pIState[38]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['n'],  pIState[38],  pIState[39]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['c'],  pIState[39],  pIState[40]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['t'],  pIState[40],  pIState[41]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['i'],  pIState[41],  pIState[42]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['o'],  pIState[42],  pIState[43]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['n'],  pIState[43],  pIState[44]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[44],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[44],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[44],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[44],  pIState[68]);

    /* goto */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['g'],  pIState[0],  pIState[45]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['o'],  pIState[45],  pIState[46]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['t'],  pIState[46],  pIState[47]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['o'],  pIState[47],  pIState[48]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[48],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[48],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[48],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[48],  pIState[68]);

    /* if */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['i'],  pIState[0],  pIState[49]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['f'],  pIState[49],  pIState[50]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[50],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[50],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[50],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[50],  pIState[68]);

    /* in */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['n'],  pIState[49],  pIState[51]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[51],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[51],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[51],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[51],  pIState[68]);

    /* local */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['l'],  pIState[0],  pIState[52]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['o'],  pIState[52],  pIState[53]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['c'],  pIState[53],  pIState[54]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['a'],  pIState[54],  pIState[55]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['l'],  pIState[55],  pIState[56]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[56],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[56],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[56],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[56],  pIState[68]);

    /* nil */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['n'],  pIState[0],  pIState[57]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['i'],  pIState[57],  pIState[58]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['l'],  pIState[58],  pIState[59]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[59],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[59],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[59],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[59],  pIState[68]);

    /* not */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['o'],  pIState[57],  pIState[60]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['t'],  pIState[60],  pIState[61]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[61],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[61],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[61],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[61],  pIState[68]);

    /* repeat */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['r'],  pIState[0],  pIState[62]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['e'],  pIState[62],  pIState[63]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['p'],  pIState[63],  pIState[64]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['e'],  pIState[64],  pIState[65]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['a'],  pIState[65],  pIState[66]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['t'],  pIState[66],  pIState[67]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[67],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[67],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[67],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[67],  pIState[68]);

    /* return */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['t'],  pIState[63],  pIState[69]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['u'],  pIState[69],  pIState[70]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['r'],  pIState[70],  pIState[71]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['n'],  pIState[71],  pIState[72]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[72],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[72],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[72],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[72],  pIState[68]);

    /* then */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['t'],  pIState[0],  pIState[73]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['h'],  pIState[73],  pIState[74]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['e'],  pIState[74],  pIState[75]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['n'],  pIState[75],  pIState[76]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[76],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[76],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[76],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[76],  pIState[68]);

    /* true */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['r'],  pIState[73],  pIState[77]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['u'],  pIState[77],  pIState[78]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['e'],  pIState[78],  pIState[79]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[79],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[79],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[79],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[79],  pIState[68]);

    /* until */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['u'],  pIState[0],  pIState[80]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['n'],  pIState[80],  pIState[81]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['t'],  pIState[81],  pIState[82]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['i'],  pIState[82],  pIState[83]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['l'],  pIState[83],  pIState[84]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[84],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[84],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[84],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[84],  pIState[68]);

    /* while */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['w'],  pIState[0],  pIState[85]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['h'],  pIState[85],  pIState[86]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['i'],  pIState[86],  pIState[87]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['l'],  pIState[87],  pIState[88]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['e'],  pIState[88],  pIState[89]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[9],  pIState[88],  pIState[89]);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[89],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\t'],  pIState[89],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\n'],  pIState[89],  pIState[68]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\r'],  pIState[89],  pIState[68]);


    /* Создаем переходы для строковых литералов */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['"'],  pIState[0],  pIState[121]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['"'],  pIState[121],  pIState[122]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\''],  pIState[0],  pIState[123]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\''],  pIState[123],  pIState[124]);

    for (index = 0; index <= 255; index++) {
        if (index != '"') {
            pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[121],  pIState[121]);
        }
        if (index != '\'') {
            pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[123],  pIState[123]);
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[124],  pIState[131]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[122],  pIState[131]);
    }

    /* Создаем переходы для новой строки */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[13],  pIState[0],  pIState[126]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[10],  pIState[0],  pIState[127]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[10],  pIState[126],  pIState[127]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[10],  pIState[127],  pIState[129]);

    for (index = 0; index <= 255; index++) {
        if (index == 10) {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[126],  pIState[129]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[127],  pIState[129]);
    }

    /* Создаем переходы для пробелов и табуляции */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[32],  pIState[0],  pIState[128]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[9],  pIState[0],  pIState[128]);
    for (index = 0; index <= 255; index++) {
        if (index == 9 || index == 32) {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[128],  pIState[130]);
    }

    /* Создаем переходы для идентификаторов */
    for (index = 'a'; index <= 'z'; index++) {
        if (!(index == 'a' || index == 'b' || index == 'd' || index == 'e' ||
            index == 'f' || index == 'g' || index == 'i' ||
            index == 'l' || index == 'n' || index == 'o' ||
            index == 'r' || index == 't' ||
            index == 'u' || index == 'w')) {
            pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[0],  pIState[125]);
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[125],  pIState[125]);
    }
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['_'],  pIState[0],  pIState[125]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['_'],  pIState[125],  pIState[125]);


    for (index = 'A'; index <= 'Z'; index++) {
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[0],  pIState[125]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[125],  pIState[125]);

    }
    for (index = '0'; index <= '9'; index++) {
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[125],  pIState[125]);
    }
    for (index = 0; index <= 255; index++) {
        if (index >= 'a' && index <= 'z' || index >= 'A' && index <= 'Z' || index == '_' || index >= '0' && index <= '9') {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[125],  pIState[118]);
    }

    return pIFA;
}


/*
 *
 * <сводка>
 *   Функция GetBNFForSAOfLua
 * </сводка>
 *
 * <описание>
 *   Функция GetBNFForSAOfLua - возвращает контекстно-свободную грамматику в BNF форме для синтаксического анализа Lua
 * </описание>
 *
 * <c0-begin-state> ::= <external-declaration>*

<external-declaration> ::= <function-definition> | <statement>

<specifier-qualifier> ::= "number" | "string" | "boolean" | "table" | "function" | "nil"

<type-name> ::= <specifier-qualifier>

<cast-expression> ::= <unary-expression>  (* not applicable in Lua directly *)

<initializer> ::= <expression>

 */
IEcoBNF1* GetBNFForSAOfLua(IEcoBNF1* pIBNF) {
    /* Интерфейсы для работы с грамматикой */
    IEcoBNF1Rule* pIRule = 0;
    IEcoBNF1Element* pIElement = 0;
    IEcoBNF1Rule* pIOption = 0;
    uint32_t indexSet = 0;
    bool_t bOptFALSE = 0;
    bool_t bOptTRUE = 1;

    /* Beginning */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "c0-begin-state");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "translation-unit", 0, &indexSet);

    /* A.2.1 Expressions */

    /* <primary-expression> ::= <identifier> | <string-literal> | "(" <expression> ")" */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "primary-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "identifier", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "string-literal", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "(", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "expression", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, ")", 0, &indexSet);

    /* <postfix-expression> ::= <primary-expression> <postfix-part>* */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "postfix-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "primary-expression", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, indexSet, "argument-expression-list", 0);

    /* <postfix-part> ::= "[" <expression> "]" | "." <identifier> | "(" [<argument-expression-list>] ")" */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "postfix-part");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "[", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "expression", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "]", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, ".", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "identifier", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "(", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "argument-expression-list", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, ")", 0, &indexSet);

    /* <argument-expression-list> ::= <expression> ("," <expression>)* */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "argument-expression-list");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "expression", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, indexSet, ",", 0);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "expression", 0, &indexSet);

    /* <unary-expression> ::= <unary-operator> <unary-expression> | <postfix-expression> */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "unary-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "unary-operator", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "unary-expression", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "postfix-expression", 0, &indexSet);

    /* <unary-operator> ::= "-" | "not" | "#" | "~" */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "unary-operator");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "-", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "not", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "#", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "~", 0, &indexSet);

    /* <multiplicative-expression> ::= <unary-expression> (<multiplier> <unary-expression>)* */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "multiplicative-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "unary-expression", 0, &indexSet);
    pIOption = pIRule; /* ->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);*/
    pIElement = pIOption->pVTbl->AddAlternative(pIOption, "*", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "unary-expression", 0, &indexSet);

    /* <multiplier> ::= ("*" | "/" | "//" | "%") */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "multiplier");
//    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "*", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "/", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "//", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "%", 0, &indexSet);

    /* <additive-expression> ::= <multiplicative-expression> (<additive-operator> <multiplicative-expression>)* */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "additive-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "multiplicative-expression", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIOption, "+", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "multiplicative-expression", 0, &indexSet);
    /* <additive-operator> ::= "+" | "-" */
//    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "additive-operator");
//    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "+", 0, &indexSet);
//    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "-", 0, &indexSet);

    /* <shift-expression> ::= <additive-expression> (<shift-operator> <additive-expression>)* */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "shift-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "additive-expression", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "shift-operator", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "additive-expression", 0, &indexSet);
    /* <shift-operator> ::= "<<" | ">>" */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "shift-operator");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "<<", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, ">>", 0, &indexSet);

    /* <relational-expression> ::= <additive-expression> (<relational-operator> <additive-expression>)* */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "relational-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "additive-expression", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "relational-operator", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "additive-expression", 0, &indexSet);
    /* <relational-operator> ::= "<" | ">" | "<=" | ">=" */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "relational-operator");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "<", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, ">", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "<=", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, ">=", 0, &indexSet);

    /* <equality-expression> ::= <relational-expression> (<equality-operator> <relational-expression>)* */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "equality-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "relational-expression", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "equality-operator", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "relational-expression", 0, &indexSet);
    /* <equality-operator> ::= "==" | "~=" */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "equality-operator");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "==", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "~=", 0, &indexSet);

    /* <AND-expression> ::= <equality-expression> ("&" <equality-expression>)* */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AND-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "equality-expression", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "&", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "equality-expression", 0, &indexSet);

    /* <exclusive-OR-expression> ::= <AND-expression> ("~" <AND-expression>)* */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "exclusive-OR-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AND-expression", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "~", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "AND-expression", 0, &indexSet);

    /* <inclusive-OR-expression> ::= <exclusive-OR-expression> ("|" <exclusive-OR-expression>)* */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "inclusive-OR-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "exclusive-OR-expression", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "|", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "exclusive-OR-expression", 0, &indexSet);

    /* <logical-AND-expression> ::= <inclusive-OR-expression> ("and" <inclusive-OR-expression>)* */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "logical-AND-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "inclusive-OR-expression", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "and", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "inclusive-OR-expression", 0, &indexSet);

    /* <logical-OR-expression> ::= <logical-AND-expression> ("or" <logical-AND-expression>)* */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "logical-OR-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "logical-AND-expression", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "or", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "logical-AND-expression", 0, &indexSet);

    /* <conditional-expression> ::= <logical-OR-expression> ["if" <expression> "then" <expression> "else" <expression> "end"] */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "conditional-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "logical-OR-expression", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 1, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "if", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "expression", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "then", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "expression", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "else", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "expression", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIOption, "end", 0, &indexSet);

    /* <declaration> ::= "local" <identifier> | <assignment-expression> */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "declaration");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "local", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "identifier", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "assignment-expression", 0, &indexSet);

    /* <assignment-expression> ::= <postfix-expression> "=" <expression> */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "assignment-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "postfix-expression", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "=", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "expression", 0, &indexSet);

    /* <expression> ::= <assignment-expression> | <logical-OR-expression> */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "assignment-expression", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "logical-OR-expression", 0, &indexSet);

    /* <constant-expression> ::= <conditional-expression> */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "constant-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "conditional-expression", 0, &indexSet);

    /* <initializer> ::= <expression> */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "initializer");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "expression", 0, &indexSet);

    /* <statement> ::= <compound-statement> | <expression-statement> | <labeled-statement> | <selection-statement> | <iteration-statement> | <jump-statement> | <function-definition> | <declaration> */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "statement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "compound-statement", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "expression-statement", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "labeled-statement", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "selection-statement", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "iteration-statement", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "jump-statement", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "function-definition", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "declaration", 0, &indexSet);

    /* <compound-statement> ::= "do" <statement>* "end" */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "compound-statement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "do", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "statement", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIOption, "end", 0, &indexSet);

    /* <expression-statement> ::= <expression> [";"] */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "expression-statement");
    pIElement = pIRule->pVTbl->AddAlternative(pIOption, "expression", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 1, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIOption, ";", 0, &indexSet);

    /* <labeled-statement> ::= "::" <identifier> "::" <statement> */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "labeled-statement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "::", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "identifier", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "::", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "statement", 0, &indexSet);

    /* <selection-statement> ::= "if" <expression> "then" <statement>* ("elseif" <expression> "then" <statement>*)* ["else" <statement>*] "end" */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "selection-statement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "if", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "expression", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "then", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "statement", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "elseif", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "expression", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "then", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "statement", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 1, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "else", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "statement", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "end", 0, &indexSet);

    /* <iteration-statement> ::= "while" <expression> "do" <statement>* "end" | "repeat" <statement>* "until" <expression> | "for" <identifier> "=" <expression> "," <expression> ["," <expression>] "do" <statement>* "end" | "for" <identifier> "in" <expression> "do" <statement>* "end" */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "iteration-statement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "while", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "expression", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "do", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "statement", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "end", 0, &indexSet);

    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "repeat", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "statement", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "until", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "expression", 0, &indexSet);

    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "for", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "declaration", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, ",", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "expression", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, ",", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 1, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "expression", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "do", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "statement", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "end", 0, &indexSet);

    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "for", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "declaration", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "in", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "expression", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "do", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "statement", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "end", 0, &indexSet);

    /* <jump-statement> ::= "break" | "return" [<expression> ("," <expression>)*] | "goto" <identifier> */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "jump-statement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "break", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 1, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "return", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 1, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "expression", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, ",", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIRule, "expression", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "goto", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "identifier", 0, &indexSet);

    /* <function-definition> ::= "function" <primary-expression> <function-body> */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "function-definition");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "function", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "primary-expression", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "function-body", 0, &indexSet);

    /* <function-body> ::= "(" [<parameter-list>] ")" <compound-statement> */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "function-body");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "(", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 1, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "parameter-list", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, ")", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, "compound-statement", 0, &indexSet);

    /* <parameter-list> ::= <identifier> ("," <identifier>)* | "... */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "parameter-list");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "identifier", 0, &indexSet);
    pIOption = pIRule->pVTbl->AddOptionalSequence(pIRule, 0, 0, 0, 0, &indexSet);
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, ",", 0, &indexSet);
    pIElement = pIOption->pVTbl->AddConcatenation(pIRule, "identifier", 0, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "...", 0, &indexSet);

    /* <initializer> ::= <expression> */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "initializer");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "expression", 0, &indexSet);

    /* <translation-unit> ::= <statement>* */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "translation-unit");
    pIElement = pIOption->pVTbl->AddAlternative(pIRule, "statement", 0, &indexSet);


    return pIBNF;
}