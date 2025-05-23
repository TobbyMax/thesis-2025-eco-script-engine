/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoLexicalAnalyzer1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IEcoMemoryManager1.h"
#include "IEcoInterfaceBus1.h"
#include "IdEcoFSM1.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"
#include "IdEcoData1.h"
#include "IdEcoStack1.h"
#include "IdEcoDictionary1.h"
#include "IdEcoLog1.h"
#include "IEcoLog1FileAffiliate.h"
#include "IdEcoBNF1.h"
#include "IdEcoRL1.h"
#include "IdEcoLexicalAnalyzer1.h"
#include "IdEcoGlushkov1.h"
#include "IdEcoObserver1.h"
#include "CEcoGlushkov1Sink.h"
#include "CEcoScanner1Sink.h"
#include "IdEcoDateTime1.h"
#include "EcoC89Grammar.h"

/* Прототипы функций */
bool_t Test_00_01(/* in */ IEcoLog1* pILog, /* in */ IEcoString1* pIStr, /* in */ IEcoFSM1* pIFSM, /* in */ IEcoLexicalAnalyzer1* pILexer, /* in */ IEcoObserver1* pIObserver, /* in */ IEcoLexicalAnalyzer1Events* pIScannerSink);
bool_t Test_00_02(/* in */ IEcoLog1* pILog, /* in */ IEcoString1* pIStr, /* in */ IEcoFSM1* pIFSM, /* in */ IEcoLexicalAnalyzer1* pILexer, /* in */ IEcoObserver1* pIObserver, /* in */ IEcoLexicalAnalyzer1Events* pIScannerSink);


bool_t OutputDiagnosticInfoOfFA(/* in */ bool_t bOutTransition, /* in */ IEcoLog1* pILog, /* in */ IEcoString1* pIStr, /* in */ IEcoFSM1StateMachine* pIFA);
//bool_t OutputDiagnosticInfoOfRG(/* in */ bool_t bOutTransition, /* in */ IEcoLog1* pILog, /* in */ IEcoString1* pIStr, /* in */ IEcoRE1Grammar* pIRG);
bool_t OutputDiagnosticInfoOfScannerStep(/* in */ IEcoLog1* pILog, /* in */ IEcoString1* pIStr, /* in */ IEcoLexicalAnalyzer1Token* pIToken);
IEcoFSM1StateMachine* GetFAForLA(/* in */ IEcoFSM1* pIFSM);
IEcoFSM1StateMachine* GetFAForLA2(/* in */ IEcoFSM1* pIFSM);
int16_t ECOCALLMETHOD RecognitionIndividualToken(/* in */ uchar_t Symbol,
        /* in */ char_t* Lexem,
        /* in */ uint32_t Line,
        /* in */ uint32_t Column,
        /* in */ char_t* Source,
        /* in */ uint32_t Position,
        /* in */ uint32_t Length,
        /* out */ int32_t* Type,
        /* in | out */ char_t** Description,
        /* out */ uint16_t* Flag);
//IEcoRE1Grammar* GetRGForLA(/* in */ IEcoRE1* pIRE);

/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    /* Указатель на интерфейс работы со строкой */
    IEcoString1* pIStr = 0;
    /* Указатель на интерфейс журнала */
    IEcoLog1* pILog = 0;
    IEcoLog1FileAffiliate* pIFileAffiliate = 0;
    /* Указатель на интерфейс работы с нотацией */
    IEcoBNF1* pIBNF = 0;
    IEcoBNF1Rule* pIRule = 0;
    IEcoBNF1Element* pIElement = 0;
    IEcoRL1* pIRL = 0;
    IEcoGlushkov1* pIGlushkov = 0;
    IEcoGlushkov1Events* pIGlushkovSink = 0;
    IEcoObserver1* pIObserver = 0;
    //IEcoRE1Grammar* pIRG = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoLexicalAnalyzer1* pILexer = 0;
    IEcoLexicalAnalyzer1Scanner* pIScanner = 0;
    IEcoLexicalAnalyzer1Token* pIToken = 0;
    IEcoLexicalAnalyzer1Events* pIScannerSink = 0;
    //IEcoRE1NonTerminal* pIStart = 0;
    //IEcoRE1NonTerminal* pIComment = 0;
    IEcoFSM1* pIFSM = 0;
    IEcoFSM1StateMachine* pIFA = 0;

    char_t pszName[5] = {0};
    uint32_t index = 0;
    IEcoFSM1Event* pIEvent[256] = {0};
    IEcoFSM1State* pIState[16] = {0};
    IEcoFSM1State* pIState0 = 0;
    //IEcoRE1NonTerminal* pINonTerminal[16] = {0};
    char_t* new_line = "break";
    char_t* keyword = "(case)v(char)v(const)";
    char_t* white_space = "svt";
    char_t* arr_R[2];
    uint32_t i = 0;

    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem, (void **)&pISys);
        if (result != 0 && pISys == 0) {
            /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

#ifdef ECO_LIB
    /* Регистрация статического компонента для работы с SLR (Simple Left to Right Parser) алгоритмом */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLexicalAnalyzer1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_7D1E60DAB7EA4837A79D537781F94437);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoList1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_53884AFC93C448ECAA929C8D3A562281);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы со словарем */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoDictionary1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_2912A7C7E0B84B4D9BFE9500EF4667D3);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы с конечным автоматом */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoFSM1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_5E7C610CB846447DB59A3C5A2C4F446F);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы с регулярной грамматикой */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoRL1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_9D51655E6B8542EDB7D0CC7C9980D749);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы со строкой */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoString1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_84CC0A7DBABD44EEBE749C9A8312D37E);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы с журналом */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLog1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_97322B6765B74342BBCE38798A0B40B5);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы со стеком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoStack1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_18129B1DCF9248D9A7787F9206E2D6DC);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы со таблицами */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoData1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_5A0F0DD57E6448EC9EE0E5D67572B47E);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы с нотацией */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoBNF1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_323DD55E33D040FA98068E2FCB1CBD49);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы с наблюдателем */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoObserver1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_2A1A9CF60C724209A401543FF529E3B9);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы с алгоритмом Глушкова */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoGlushkov1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_E0644366CFB740138E6B487D333B12BA);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы с датой и вреенем */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoDateTime1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_5B2BA17BEA704527BC708F88568FE115);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#endif

    /* Получение интерфейса для работы со строкой */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (void**) &pIStr);
    if (result != 0 || pIStr == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса для работы с журналированием данных */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1, (void**) &pILog);
    if (result != 0 || pILog == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1FileAffiliate, (void**) &pIFileAffiliate);
    if (result != 0 || pIFileAffiliate == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }
    pILog->pVTbl->AddAffiliate(pILog, (IEcoLog1Affiliate*)pIFileAffiliate);
    pIFileAffiliate->pVTbl->Release(pIFileAffiliate);

    /* Получение тестируемого интерфейса */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLexicalAnalyzer1, 0, &IID_IEcoLexicalAnalyzer1, (void**) &pILexer);
    if (result != 0 || pILexer == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Создаем подписчика на события работы сканера */
    result = createCEcoScanner1Sink((IEcoUnknown*)pISys, 0, pILog, &pIScannerSink);
    if (result != 0 && pIScannerSink == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса для работы с конечным автоматом */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoFSM1, 0, &IID_IEcoFSM1, (void **)&pIFSM);
    if (result != 0 || pIFSM == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoRL1, 0, &IID_IEcoRL1, (void**) &pIRL);
    if (result != 0 && pIRL == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса работы с алгоритмом Глушкова */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoGlushkov1, 0, &IID_IEcoGlushkov1, (void**) &pIGlushkov);
    if (result != 0 && pIGlushkov == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }
    /* Настраиваем параметры */
    pIGlushkov->pVTbl->set_EscapeCharacter(pIGlushkov, '\\');
    pIGlushkov->pVTbl->set_DisjunctionCharacter(pIGlushkov, 'v');
    pIGlushkov->pVTbl->set_GroupBrakets(pIGlushkov, '(', ')');
    pIGlushkov->pVTbl->set_IterationBrakets(pIGlushkov, '{', '}');

    /* Создаем подписчика на события работы алгоритма */
    result = createCEcoGlushkov1Sink((IEcoUnknown*)pISys, 0, pILog, &pIGlushkovSink);
    if (result != 0 && pIGlushkovSink == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Запрашиваем интерфейс наблюдателя (опционально - может не поддерживаться в зависимости от реализации) */
    result = pIGlushkov->pVTbl->QueryInterface(pIGlushkov, &IID_IEcoObserver1, (void**) &pIObserver);
    /* Если поддерживается, то подключаем наблюдателя */
    if (result == 0 && pIObserver != 0) {
        pIObserver->pVTbl->Attach(pIObserver, &IID_IEcoGlushkov1Events, (IEcoUnknown*)pIGlushkovSink);
    }


    /* Вывод начальной информации */
    pILog->pVTbl->Info(pILog, "Start Test Lexical Analyzer");
    pILog->pVTbl->Info(pILog, " ");

    Test_00_01(pILog, pIStr, pIFSM, pILexer, pIObserver, pIScannerSink);



    Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение интерфейса для работы с конечным автоматом */
    if (pIFSM != 0) {
        pIFSM->pVTbl->Release(pIFSM);
    }

    /* Освобождение интерфейса для работы с регулярной грамматикой */
    if (pIRL != 0) {
        pIRL->pVTbl->Release(pIRL);
    }

    /* Освобождение интерфейса для работы с журналом */
    if (pILog != 0) {
        pILog->pVTbl->Release(pILog);
    }

    /* Освобождение интерфейса работы со строкой */
    if (pIStr != 0) {
        pIStr->pVTbl->Release(pIStr);
    }

    /* Освобождение тестируемого интерфейса */
    if (pILexer != 0) {
        pILexer->pVTbl->Release(pILexer);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

/*
 *
 * <сводка>
 *   Функция Test_00_01
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
bool_t Test_00_01(/* in */ IEcoLog1* pILog, /* in */ IEcoString1* pIStr, /* in */ IEcoFSM1* pIFSM, /* in */ IEcoLexicalAnalyzer1* pILexer, /* in */ IEcoObserver1* pIObserver, /* in */ IEcoLexicalAnalyzer1Events* pIScannerSink) {
    int16_t result = -1;
    IEcoLexicalAnalyzer1Scanner* pIScanner = 0;
    IEcoFSM1StateMachine* pIFA = 0;
    IEcoLexicalAnalyzer1Token* pIToken = 0;


    /******************************** ВАРИАНТ 1 : Задание правил с помошъю конечного автомата *******************************/

    pILog->pVTbl->Info(pILog, "Example 1 (C89 comments) - Finite Automata");
    pILog->pVTbl->Info(pILog, " ");
    pILog->pVTbl->Info(pILog, " ");
    pILog->pVTbl->Info(pILog, "->(q0)--- / --->(q1)--------------- * --->(q5)--- * --->(q8)--- / --->(q9)--- [A-Za-zА-Яа-я/0-9_ \\t\\r\\n] --->((q10))  -  comment");
    pILog->pVTbl->Info(pILog, "      \\               \\                    ^__|             |                                           /");
    pILog->pVTbl->Info(pILog, "       \\               \\                   |________________|                                          /");
    pILog->pVTbl->Info(pILog, "        \\               \\               [A-Za-zА-Яа-я]                                                /");
    pILog->pVTbl->Info(pILog, "         \\               \\              [/0-9_ \\t\\r\\n]                                               /");
    pILog->pVTbl->Info(pILog, "          \\               \\                                                                         /");
    pILog->pVTbl->Info(pILog, "           \\               \\                                                                       /");
    pILog->pVTbl->Info(pILog, "            \\               \\                                                                     /");
    pILog->pVTbl->Info(pILog, "             \\                ------- / -->(q6)------------------------- \\r\\n -------------------");
    pILog->pVTbl->Info(pILog, "              \\                           ^__|");
    pILog->pVTbl->Info(pILog, "               \\                         [A-Za-zА-Яа-я]");
    pILog->pVTbl->Info(pILog, "                \\                        [/0-9_ \\t]");
    pILog->pVTbl->Info(pILog, "                 \\ ");
    pILog->pVTbl->Info(pILog, "                  -------- \\r -->(q2)--- \\n --->(q7)------------ [A-Za-zА-Яа-я/0-9_ \\t\\r\\n] ----------->((q11))  -  new-line");
    pILog->pVTbl->Info(pILog, "                   \\                        / ");
    pILog->pVTbl->Info(pILog, "                    --------- \\n ----------");
    pILog->pVTbl->Info(pILog, "                     \\ ");
    pILog->pVTbl->Info(pILog, "                      -------- \\t ---->(q3)--------------------- [A-Za-zА-Яа-я/0-9_ \\t\\r\\n] ------------>((q12))  -  white-space");
    pILog->pVTbl->Info(pILog, "                       \\ ");
    pILog->pVTbl->Info(pILog, "                        -------- / ---->(q4)--------------------------- \\r\\n ----------------------------->((q13))  -  backslash");
    pILog->pVTbl->Info(pILog, "                        \\ ");
    pILog->pVTbl->Info(pILog, "                         -------- [A-Za-zА-Яа-я0-9_ ]---->(q14)---------- \\r\\n \\t / \\------------------->((q15))  -  unknown");
    pILog->pVTbl->Info(pILog, " ");

    /* Строим конечный автомат для комментариев языка Си */
//    pIFA = GetFAForLA(pIFSM);
    pIFA = GetFAForLA2(pIFSM);

    /* Вывод диагностической/отладочной информации */
    OutputDiagnosticInfoOfFA(0, pILog, pIStr, pIFA);

    /* Создание интерфейса лексического разбора согласно заданным правилам на конечном автомате */
    /* В качестве исходного файла для анализа используем этот код */
    pIScanner = pILexer->pVTbl->new_FileScannerByFA(pILexer, pIFA, "C:\\Dev\\Eco.Toolchain\\Eco.Framework\\Eco.LexicalAnalyzer1\\UnitTestFiles\\SourceFiles\\test.c");
    /* Освобождение */
    pIFA->pVTbl->Release(pIFA);

    /* Запрашиваем интерфейс наблюдателя (опционально - может не поддерживаться в зависимости от реализации) */
    result = pIScanner->pVTbl->QueryInterface(pIScanner, &IID_IEcoObserver1, (void**) &pIObserver);
    /* Если поддерживается, то подключаем наблюдателя */
    if (result == 0 && pIObserver != 0) {
        pIObserver->pVTbl->Attach(pIObserver, &IID_IEcoLexicalAnalyzer1Events, (IEcoUnknown*)pIScannerSink);
    }

    if ( pIScanner != 0) {
        /* Основной цикл чтения и обработки входной последовательности */
        while (1) {
            /* Лексический анализ */
            pIToken = pIScanner->pVTbl->Scan(pIScanner);
            if (pIToken == 0) {
                /* Выход - входная последовательность закончилась */
                break;
            }
            /* Вывод диагностической/отладочной информации */
            OutputDiagnosticInfoOfScannerStep(pILog, pIStr, pIToken);
            /* Токен обработан - освобождение */
            pIToken->pVTbl->Release(pIToken);
        }

        /* Освобождение */
        pIScanner->pVTbl->Release(pIScanner);
        pIScanner = 0;
    }

    /* Если поддерживается, то отключаем наблюдателя */
    if (pIObserver != 0) {
        pIObserver->pVTbl->Detach(pIObserver, &IID_IEcoLexicalAnalyzer1Events, (IEcoUnknown*)pIScannerSink);
    }
    return 1;
}


/*
 *
 * <сводка>
 *   Функция Test_00_02
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
bool_t Test_00_02(/* in */ IEcoLog1* pILog, /* in */ IEcoString1* pIStr, /* in */ IEcoFSM1* pIFSM, /* in */ IEcoLexicalAnalyzer1* pILexer, /* in */ IEcoObserver1* pIObserver, /* in */ IEcoLexicalAnalyzer1Events* pIScannerSink) {
    int16_t result = -1;
    IEcoLexicalAnalyzer1Scanner* pIScanner = 0;
    IEcoFSM1StateMachine* pIFA = 0;
    IEcoLexicalAnalyzer1Token* pIToken = 0;


    /******************************** ВАРИАНТ 1 : Задание правил с помошъю конечного автомата *******************************/

    pILog->pVTbl->Info(pILog, "Example 1 (C89 comments) - Finite Automata");
    pILog->pVTbl->Info(pILog, " ");
    pILog->pVTbl->Info(pILog, " ");
    pILog->pVTbl->Info(pILog, "->(q0)--- / --->(q1)--------------- * --->(q5)--- * --->(q8)--- / --->(q9)--- [A-Za-zА-Яа-я/0-9_ \\t\\r\\n] --->((q10))  -  comment");
    pILog->pVTbl->Info(pILog, "      \\               \\                    ^__|             |                                           /");
    pILog->pVTbl->Info(pILog, "       \\               \\                   |________________|                                          /");
    pILog->pVTbl->Info(pILog, "        \\               \\               [A-Za-zА-Яа-я]                                                /");
    pILog->pVTbl->Info(pILog, "         \\               \\              [/0-9_ \\t\\r\\n]                                               /");
    pILog->pVTbl->Info(pILog, "          \\               \\                                                                         /");
    pILog->pVTbl->Info(pILog, "           \\               \\                                                                       /");
    pILog->pVTbl->Info(pILog, "            \\               \\                                                                     /");
    pILog->pVTbl->Info(pILog, "             \\                ------- / -->(q6)------------------------- \\r\\n -------------------");
    pILog->pVTbl->Info(pILog, "              \\                           ^__|");
    pILog->pVTbl->Info(pILog, "               \\                         [A-Za-zА-Яа-я]");
    pILog->pVTbl->Info(pILog, "                \\                        [/0-9_ \\t]");
    pILog->pVTbl->Info(pILog, "                 \\ ");
    pILog->pVTbl->Info(pILog, "                  -------- \\r -->(q2)--- \\n --->(q7)------------ [A-Za-zА-Яа-я/0-9_ \\t\\r\\n] ----------->((q11))  -  new-line");
    pILog->pVTbl->Info(pILog, "                   \\                        / ");
    pILog->pVTbl->Info(pILog, "                    --------- \\n ----------");
    pILog->pVTbl->Info(pILog, "                     \\ ");
    pILog->pVTbl->Info(pILog, "                      -------- \\t ---->(q3)--------------------- [A-Za-zА-Яа-я/0-9_ \\t\\r\\n] ------------>((q12))  -  white-space");
    pILog->pVTbl->Info(pILog, "                       \\ ");
    pILog->pVTbl->Info(pILog, "                        -------- / ---->(q4)--------------------------- \\r\\n ----------------------------->((q13))  -  backslash");
    pILog->pVTbl->Info(pILog, "                        \\ ");
    pILog->pVTbl->Info(pILog, "                         -------- [A-Za-zА-Яа-я0-9_ ]---->(q14)---------- \\r\\n \\t / \\------------------->((q15))  -  unknown");
    pILog->pVTbl->Info(pILog, " ");

    /* Строим конечный автомат для комментариев языка Си */
    //pIFA = GetFAForLA(pIFSM);
    pIFA = GetFAForLAOfC89(pIFSM);

    ///* Вывод диагностической/отладочной информации */
    OutputDiagnosticInfoOfFA(0, pILog, pIStr, pIFA);

    /* Создание интерфейса лексического разбора согласно заданным правилам на конечном автомате */
    /* В качестве исходного файла для анализа используем этот код */
    pIScanner = pILexer->pVTbl->new_FileScannerByFA(pILexer, pIFA, "..\\..\\..\\UnitTestFiles\\SourceFiles\\test.c");
    /* Освобождение */
    pIFA->pVTbl->Release(pIFA);

    /* Запрашиваем интерфейс наблюдателя (опционально - может не поддерживаться в зависимости от реализации) */
    result = pIScanner->pVTbl->QueryInterface(pIScanner, &IID_IEcoObserver1, (void**) &pIObserver);
    /* Если поддерживается, то подключаем наблюдателя */
    if (result == 0 && pIObserver != 0) {
        pIObserver->pVTbl->Attach(pIObserver, &IID_IEcoLexicalAnalyzer1Events, (IEcoUnknown*)pIScannerSink);
    }

    if ( pIScanner != 0) {
        /* Основной цикл чтения и обработки входной последовательности */
        while (1) {
            /* Лексический анализ */
            pIToken = pIScanner->pVTbl->Scan(pIScanner);
            if (pIToken == 0) {
                /* Выход - входная последовательность закончилась */
                break;
            }
            /* Вывод диагностической/отладочной информации */
            OutputDiagnosticInfoOfScannerStep(pILog, pIStr, pIToken);
            /* Токен обработан - освобождение */
            pIToken->pVTbl->Release(pIToken);
        }

        /* Освобождение */
        pIScanner->pVTbl->Release(pIScanner);
        pIScanner = 0;
    }

    /* Если поддерживается, то отключаем наблюдателя */
    if (pIObserver != 0) {
        pIObserver->pVTbl->Detach(pIObserver, &IID_IEcoLexicalAnalyzer1Events, (IEcoUnknown*)pIScannerSink);
    }

    /******************************** ВАРИАНТ 2 : Задание правил с помошъю регулярной грамматики *******************************/

    pILog->pVTbl->Info(pILog, "Example 2 (C89 comments) - Regular Grammar");
    pILog->pVTbl->Info(pILog, " ");
    pILog->pVTbl->Info(pILog, " ");

    /* Формируем правила регулярной грамматики для комментариев языка Си */
    //pIRG = GetRGForLA(pIRE);

    /* Вывод диагностической/отладочной информации */
    //OutputDiagnosticInfoOfRG(0, pILog, pIStr, pIRG);

    /* Преобразуем регулярную грамматику в недетерминированный конечный автомат */
    //result = pIRE->ConversionRGToFA(pIRE, pIRG, &pIFA);

    /* Вывод диагностической/отладочной информации */
    //OutputDiagnosticInfoOfFA(0, pILog, pIStr, pIFA);

    /* Создание интерфейса лексического разбора согласно заданным правилам на конечном автомате */
    /* В качестве исходного файла для анализа используем этот код */
    //pIScanner = pILexer->pVTbl->new_FileScannerByFA(pILexer, pIFA, "..\\..\\..\\UnitTestFiles\\SourceFiles\\EcoLexicalAnalyzer1.c");

    /* Основной цикл чтения и обработки входной последовательности */
    //while (1) {
    //    /* Лексический анализ */
    //    pIToken = pIScanner->pVTbl->Scan(pIScanner);
    //    if (pIToken == 0) {
    //        /* Выход - входная последовательность закончилась */
    //        break;
    //    }
    //    /* Вывод диагностической/отладочной информации */
    //    OutputDiagnosticInfoOfScannerStep(pILog, pIStr, pIToken);
    //    /* Токен обработан - освобождение */
    //    pIToken->pVTbl->Release(pIToken);
    //}

    /* Освобождение */
    //pIScanner->pVTbl->Release(pIScanner);
    //pIFA->pVTbl->Release(pIFA);
    //pIRG->pVTbl->Release(pIRG);

    /******************************** ВАРИАНТ 3 : Задание правил с помошъю регулярных выражений ********************************/

    pILog->pVTbl->Info(pILog, "Example 3 (C89 comments) - Regular Expression");
    pILog->pVTbl->Info(pILog, " ");
    pILog->pVTbl->Info(pILog, " ");
    //arr_R[0] = pIGlushkov->pVTbl->PrepareRegular(pIGlushkov, keyword);
    //arr_R[1] = pIGlushkov->pVTbl->PrepareRegular(pIGlushkov, white_space);
    //pILog->pVTbl->InfoFormat(pILog, "R1 = %s", arr_R[0]);
    //pILog->pVTbl->InfoFormat(pILog, "R2 = %s", arr_R[1]);
    //result = pIGlushkov->pVTbl->ConstructionFA(pIGlushkov, arr_R, 1, &pIFA);
    //pIState0 = (IEcoFSM1State*)pIFA->pVTbl->get_States(pIFA)->pVTbl->Item(pIFA->pVTbl->get_States(pIFA), 0);
    //pIState0->pVTbl->set_Initial(pIState0, 1);

    /* Вывод диагностической/отладочной информации */
    //OutputDiagnosticInfoOfFA(0, pILog, pIStr, pIFA);

    /* Создание интерфейса лексического разбора согласно заданным правилам на конечном автомате */
    /* В качестве исходного файла для анализа используем этот код */
    //pIScanner = pILexer->pVTbl->new_FileScannerByFA(pILexer, pIFA, "..\\..\\..\\UnitTestFiles\\SourceFiles\\test.c");

    //if ( pIScanner != 0) {
    //    /* Основной цикл чтения и обработки входной последовательности */
    //    while (1) {
    //        /* Лексический анализ */
    //        pIToken = pIScanner->pVTbl->Scan(pIScanner);
    //        if (pIToken == 0) {
    //            /* Выход - входная последовательность закончилась */
    //            break;
    //        }
    //        /* Вывод диагностической/отладочной информации */
    //        OutputDiagnosticInfoOfScannerStep(pILog, pIStr, pIToken);
    //        /* Токен обработан - освобождение */
    //        pIToken->pVTbl->Release(pIToken);
    //    }

    //    /* Освобождение */
    //    pIScanner->pVTbl->Release(pIScanner);
    //    pIScanner = 0;
    //}


    /******************************** ВАРИАНТ 4 : Задание правил с помошъю Формы Бэкуса-Наура **********************************/
    /******************************************** для регулярной грамматики подмножества контекстно-свободных ******************/

    pILog->pVTbl->Info(pILog, "Example 4 (C89 comments) - BNF (Сontext-free Grammar)");
    pILog->pVTbl->Info(pILog, " ");
    pILog->pVTbl->Info(pILog, " ");

    /******************************** ВАРИАНТ 5 : Непосредственная реализация с помощью функции ********************************/

    pILog->pVTbl->Info(pILog, "Example 5 (C89 comments) - Direct Implementation (callback function)");
    pILog->pVTbl->Info(pILog, " ");
    pILog->pVTbl->Info(pILog, " ");

    /* Создание интерфейса лексического разбора согласно правилам непосредственной реализации */
    /* В качестве исходного файла для анализа используем этот код */
    // pIScanner = pILexer->pVTbl->new_FileScannerByDirectImpl(pILexer, RecognitionIndividualToken, "..\\..\\..\\UnitTestFiles\\SourceFiles\\test.c");

    ///* Запрашиваем интерфейс наблюдателя (опционально - может не поддерживаться в зависимости от реализации) */
    //result = pIScanner->pVTbl->QueryInterface(pIScanner, &IID_IEcoObserver1, (void**) &pIObserver);
    ///* Если поддерживается, то подключаем наблюдателя */
    //if (result == 0 && pIObserver != 0) {
    //    pIObserver->pVTbl->Attach(pIObserver, &IID_IEcoLexicalAnalyzer1Events, (IEcoUnknown*)pIScannerSink);
    //}

    //if ( pIScanner != 0) {
    //    /* Основной цикл чтения и обработки входной последовательности */
    //    while (1) {
    //        /* Лексический анализ */
    //        pIToken = pIScanner->pVTbl->Scan(pIScanner);
    //        if (pIToken == 0) {
    //            /* Выход - входная последовательность закончилась */
    //            break;
    //        }
    //        /* Вывод диагностической/отладочной информации */
    //        OutputDiagnosticInfoOfScannerStep(pILog, pIStr, pIToken);
    //        /* Токен обработан - освобождение */
    //        pIToken->pVTbl->Release(pIToken);
    //    }

    //    /* Освобождение */
    //    pIScanner->pVTbl->Release(pIScanner);
    //    pIScanner = 0;
    //}

    ///* Если поддерживается, то отключаем наблюдателя */
    //if (pIObserver != 0) {
    //    pIObserver->pVTbl->Detach(pIObserver, &IID_IEcoLexicalAnalyzer1Events, (IEcoUnknown*)pIScannerSink);
    //}

}


/*
 *
 * <сводка>
 *   Функция OutputDiagnosticInfoOfFA
 * </сводка>
 *
 * <описание>
 *   Функция OutputDiagnosticInfoOfFA - Вывод диагностической информации конечного автомата
 * </описание>
 *
 */
bool_t OutputDiagnosticInfoOfFA(/* in */ bool_t bOutTransition, /* in */ IEcoLog1* pILog, /* in */ IEcoString1* pIStr, /* in */ IEcoFSM1StateMachine* pIFA) {
    bool_t bResult = 0;
    IEcoFSM1Transition* pITransition = 0;
    IEcoFSM1State* pISource = 0;
    IEcoFSM1State* pITarget = 0;
    IEcoFSM1Event* pIEvent = 0;
    IEcoList1* pITransitions = 0;
    IEcoList1* pIColumns = 0;
    IEcoList1* pIRows = 0;
    uint32_t index = 0;
    char_t* Line = 0;
    IEcoFSM1State* pIState = 0;
    IEcoFSM1State* pIStateTarget = 0;
    IEcoList1* pIEvents = 0;
    IEcoFSM1Event* pITempEvent = 0;
    IEcoFSM1State* pISourceState = 0;
    uint32_t indexEvent = 0;
    uint32_t indexTransition = 0;
    IEcoData1Table* pITransitionTable = 0;
    IEcoData1Column* pIColumn = 0;
    IEcoData1Row* pIRow = 0;
    uint32_t indexColumn = 0;
    uint32_t indexRow = 0;
    uint32_t countAlign = 0;
    char_t* Headers = 0;
    char_t* intStr = 0;

    if (pIFA != 0) {
        pILog->pVTbl->InfoFormat(pILog, "Finite Automata Name = %s", pIFA->pVTbl->get_Name(pIFA));
        /* Вывод переходов конечного автомата */
        if (bOutTransition) {
            pILog->pVTbl->Info(pILog, "Transitions :");
            pITransitions = pIFA->pVTbl->get_Transitions(pIFA);
            for(index = 0; index < pITransitions->pVTbl->Count(pITransitions); index++) {
                pITransition = (IEcoFSM1Transition*)pITransitions->pVTbl->Item(pITransitions, index);
                pIEvent = pITransition->pVTbl->get_Event(pITransition);
                pISource = pITransition->pVTbl->get_Source(pITransition);
                pITarget = pITransition->pVTbl->get_Target(pITransition);
                Line = 0;
                Line = pIStr->pVTbl->Append(pIStr, Line, "Transition - [");
                Line = pIStr->pVTbl->Append(pIStr, Line, pIStr->pVTbl->ConvertIntToString(pIStr, pITransition->pVTbl->get_Id(pITransition)));
                Line = pIStr->pVTbl->Append(pIStr, Line, "]: ");
                if (pISource->pVTbl->IsInitial(pISource)) {
                    Line = pIStr->pVTbl->Append(pIStr, Line, "->");
                }
                if (pISource->pVTbl->IsFinal(pISource)) {
                    Line = pIStr->pVTbl->Append(pIStr, Line, "(");
                }
                Line = pIStr->pVTbl->Append(pIStr, Line, "(");
                Line = pIStr->pVTbl->Append(pIStr, Line, pISource->pVTbl->get_Name(pISource));
                if (pISource->pVTbl->IsFinal(pISource)) {
                    Line = pIStr->pVTbl->Append(pIStr, Line, ")");
                }
                Line = pIStr->pVTbl->Append(pIStr, Line, ") -- ");
                Line = pIStr->pVTbl->Append(pIStr, Line, pIEvent->pVTbl->get_Name(pIEvent));
                Line = pIStr->pVTbl->Append(pIStr, Line, " --> (");
                if (pITarget->pVTbl->IsFinal(pITarget)) {
                    Line = pIStr->pVTbl->Append(pIStr, Line, "(");
                }
                Line = pIStr->pVTbl->Append(pIStr, Line, pITarget->pVTbl->get_Name(pITarget));
                Line = pIStr->pVTbl->Append(pIStr, Line, ")");
                if (pITarget->pVTbl->IsFinal(pITarget)) {
                    Line = pIStr->pVTbl->Append(pIStr, Line, ")  -  ");
                    Line = pIStr->pVTbl->Append(pIStr, Line, (char_t*)pITarget->pVTbl->get_Parameter(pITarget));
                }

                pILog->pVTbl->Info(pILog, Line);
                pIStr->pVTbl->Free(pIStr, Line);
                Line = 0;
            }
        }
        /* Вывод управляющей таблицы */
        pITransitionTable = pIFA->pVTbl->get_TransitionTable(pIFA);
        if (pITransitionTable != 0) {
            Headers = 0;
            Line = 0;
            pIColumns = pITransitionTable->pVTbl->get_Columns(pITransitionTable);
            pIRows = pITransitionTable->pVTbl->get_Rows(pITransitionTable);
            pILog->pVTbl->InfoFormat(pILog, "Table [%s]", pITransitionTable->pVTbl->get_Name(pITransitionTable));
            Line = pIStr->pVTbl->Append(pIStr, Line, "+--------+");
            Headers = pIStr->pVTbl->Append(pIStr, Headers, "| S \\ E  |");
            for (indexColumn = 0; indexColumn < pIColumns->pVTbl->Count(pIColumns); indexColumn++) {
                pIColumn = (IEcoData1Column*)pIColumns->pVTbl->Item(pIColumns, indexColumn);
                Line = pIStr->pVTbl->Append(pIStr, Line, "--");
                Headers = pIStr->pVTbl->Append(pIStr, Headers, "  ");
                Headers = pIStr->pVTbl->Append(pIStr, Headers, pIColumn->pVTbl->get_Name(pIColumn));
                countAlign = pIStr->pVTbl->RetrieveSize(pIStr, pIColumn->pVTbl->get_Name(pIColumn));
                if (countAlign == 3) {
                    Headers = pIStr->pVTbl->Append(pIStr, Headers, " |");
                }
                else if (countAlign == 2) {
                    Headers = pIStr->pVTbl->Append(pIStr, Headers, "  |");
                }
                else {
                    Headers = pIStr->pVTbl->Append(pIStr, Headers, "   |");
                }
                Line = pIStr->pVTbl->Append(pIStr, Line, "----+");
            }
            pILog->pVTbl->InfoFormat(pILog, "%s", Line);
            pILog->pVTbl->InfoFormat(pILog, "%s", Headers);
            pILog->pVTbl->InfoFormat(pILog, "%s", Line);
            pIStr->pVTbl->Free(pIStr, Headers);
            Headers = 0;

            for (indexRow = 0; indexRow < pIRows->pVTbl->Count(pIRows); indexRow++) {
                Headers = pIStr->pVTbl->Append(pIStr, Headers, "|");
                pIRow = (IEcoData1Row*)pIRows->pVTbl->Item(pIRows, indexRow);
                Headers = pIStr->pVTbl->Append(pIStr, Headers, "   ");
                intStr = pIStr->pVTbl->ConvertIntToString(pIStr, indexRow);
                Headers = pIStr->pVTbl->Append(pIStr, Headers, intStr);
                pIStr->pVTbl->Free(pIStr, intStr);
                intStr = 0;
                countAlign = pIStr->pVTbl->RetrieveSize(pIStr, Headers);
                if (countAlign == 7) {
                    Headers = pIStr->pVTbl->Append(pIStr, Headers, "  |");
                }
                else if (countAlign == 6) {
                    Headers = pIStr->pVTbl->Append(pIStr, Headers, "   |");
                }
                else {
                    Headers = pIStr->pVTbl->Append(pIStr, Headers, "    |");
                }
                for (indexColumn = 0; indexColumn < pIColumns->pVTbl->Count(pIColumns); indexColumn++) {
                    if (pIRow->pVTbl->IsNullByIndex(pIRow, indexColumn)) {
                        Headers = pIStr->pVTbl->Append(pIStr, Headers, "      |");
                    } else {
                        Headers = pIStr->pVTbl->Append(pIStr, Headers, " ");
                        Headers = pIStr->pVTbl->Append(pIStr, Headers, (char_t*)pIRow->pVTbl->get_ItemByIndex(pIRow, indexColumn));
                        Headers = pIStr->pVTbl->Append(pIStr, Headers, " |");
                    }
                }
                pILog->pVTbl->InfoFormat(pILog, "%s", Headers);
                pILog->pVTbl->InfoFormat(pILog, "%s", Line);
                pIStr->pVTbl->Free(pIStr, Headers);
                Headers = 0;
            }
            pIStr->pVTbl->Free(pIStr, Line);
            Line = 0;
        }

    }
    return bResult;
}

/*
 *
 * <сводка>
 *   Функция OutputDiagnosticInfoOfRG
 * </сводка>
 *
 * <описание>
 *   Функция OutputDiagnosticInfoOfRG - Вывод диагностической информации регулярной грамматики
 * </описание>
 *
 */
//bool_t OutputDiagnosticInfoOfRG(/* in */ bool_t bOutTransition, /* in */ IEcoLog1* pILog, /* in */ IEcoString1* pIStr, /* in */ IEcoRE1Grammar* pIRG) {
//    bool_t bResult = 0;
//IEcoRE1NonTerminal* pILHS = 0;
//IEcoRE1NonTerminal* pINonTerminal = 0;
//IEcoRE1Rule* pIRule = 0;
//IEcoList1* pIRuleSet = 0;
//char_t pTerminal[2] = {0};
//uint32_t index = 0;
//bool_t bRight = 0;

///* Вывод всех правил регулярной грамматики */
//pILog->pVTbl->InfoFormat(pILog, "Regular Grammar - [%s][%d]:", pIRG->get_Name(pIRG), pIRG->get_Id(pIRG));
//bRight = pIRG->IsRightLinearGrammar(pIRG);
//pIRuleSet = pIRG->get_RuleSet(pIRG);
//for(index = 0; index < pIRuleSet->Count(pIRuleSet); index++) {
//    pIRule = (IEcoRE1Rule*)pIRuleSet->Item(pIRuleSet, index);
//    pILHS = pIRule->get_LHS(pIRule);
//    pTerminal[0]= pIRule->get_Terminal(pIRule);
//    pINonTerminal = pIRule->get_NonTerminal(pIRule);
//    if (bRight) {
//        if (pINonTerminal != 0) {
//            pILog->pVTbl->InfoFormat(pILog, "Rule - [%d]: %s -> %s%s", pIRule->get_Id(pIRule), pILHS->get_Name(pILHS), pTerminal, pINonTerminal->get_Name(pINonTerminal));
//        }
//        else {
//            pILog->pVTbl->InfoFormat(pILog, "Rule - [%d]: %s -> %s", pIRule->get_Id(pIRule), pILHS->get_Name(pILHS), pTerminal);
//        }
//    }
//    else {
//        if (pINonTerminal != 0) {
//            pILog->pVTbl->InfoFormat(pILog, "Rule - [%d]: %s -> %s%s", pIRule->get_Id(pIRule), pILHS->get_Name(pILHS), pINonTerminal->get_Name(pINonTerminal), pTerminal);
//        }
//        else {
//            pILog->pVTbl->InfoFormat(pILog, "Rule - [%d]: %s -> %s", pIRule->get_Id(pIRule), pILHS->get_Name(pILHS), pTerminal);
//        }
//    }
//}
//    return bResult;
//}

/*
 *
 * <сводка>
 *   Функция OutputDiagnosticInfoOfScannerStep
 * </сводка>
 *
 * <описание>
 *   Функция OutputDiagnosticInfoOfScannerStep - Вывод диагностической информации шага лексического анализа
 * </описание>
 *
 */
bool_t OutputDiagnosticInfoOfScannerStep(/* in */ IEcoLog1* pILog, /* in */ IEcoString1* pIStr, /* in */ IEcoLexicalAnalyzer1Token* pIToken) {
    bool_t bResult = 0;
    if (pIToken != 0) {
        printf("******************************** C89 SCANNER STEP ******************************\n");
        printf("Token Type = %d, Lexem = %s, Description = %s\n", pIToken->pVTbl->get_Type(pIToken), pIToken->pVTbl->get_Lexeme(pIToken), pIToken->pVTbl->get_Description(pIToken));
        printf("Token Line = %d, Column = %d\n", pIToken->pVTbl->get_Line(pIToken), pIToken->pVTbl->get_Column(pIToken));
        printf("Token Source = %s, Position = %d, Length = %d\n", pIToken->pVTbl->get_Source(pIToken), pIToken->pVTbl->get_Position(pIToken), pIToken->pVTbl->get_Length(pIToken));


        pILog->pVTbl->InfoFormat(pILog, "****************************** C89 SCANNER STEP ******************************");
        pILog->pVTbl->InfoFormat(pILog, "Token Type = %d, Lexem = %s, Description = %s", pIToken->pVTbl->get_Type(pIToken), pIToken->pVTbl->get_Lexeme(pIToken), pIToken->pVTbl->get_Description(pIToken));
        pILog->pVTbl->InfoFormat(pILog, "Token Line = %d, Column = %d", pIToken->pVTbl->get_Line(pIToken), pIToken->pVTbl->get_Column(pIToken));
        pILog->pVTbl->InfoFormat(pILog, "Token Source = %s, Position = %d, Length = %d", pIToken->pVTbl->get_Source(pIToken), pIToken->pVTbl->get_Position(pIToken), pIToken->pVTbl->get_Length(pIToken));
    }
    return bResult;
}

/*
 *
 * <сводка>
 *   Функция GetFAForLA
 * </сводка>
 *
 * <описание>
 *   Функция GetFAForLA - возвращает конечный автомат для лексического анализа
 * </описание>
 *
 */
IEcoFSM1StateMachine* GetFAForLA(/* in */ IEcoFSM1* pIFSM) {
    IEcoFSM1StateMachine* pIFA = 0;
    char_t pszName[5] = {0};
    uint32_t index = 0;
    IEcoFSM1Event* pIEvent[256] = {0};
    IEcoFSM1State* pIState[16] = {0};

    /* Создаем конечный автомат */
    pIFA = pIFSM->pVTbl->CreateStateMachine(pIFSM, "C89 comment");
    for (index = 0; index < 16; index++) {
        pszName[0] = 'q';
        pszName[1] = index/100 + 48;
        if (index > 100) {
            pszName[2] = (index- 100)/10 + 48;
        }
        else {
            pszName[2] = index/10 + 48;
        }
        pszName[3] = index%10 + 48;
        pIState[index] = pIFA->pVTbl->AddState(pIFA, pszName);
    }

    /* Создадим массив событий для алфавита по прядку кодов ASCII таблицы */
    pIEvent[0] = pIFA->pVTbl->AddEvent(pIFA, "NUL", 0, 0);
    pIEvent[1] = pIFA->pVTbl->AddEvent(pIFA, "SOH", 1, 0);
    pIEvent[2] = pIFA->pVTbl->AddEvent(pIFA, "STX", 2, 0);
    pIEvent[3] = pIFA->pVTbl->AddEvent(pIFA, "ETX", 3, 0);
    pIEvent[4] = pIFA->pVTbl->AddEvent(pIFA, "EOT", 4, 0);
    pIEvent[5] = pIFA->pVTbl->AddEvent(pIFA, "ENQ", 5, 0);
    pIEvent[6] = pIFA->pVTbl->AddEvent(pIFA, "ACK", 6, 0);
    pIEvent[7] = pIFA->pVTbl->AddEvent(pIFA, "BEL", 7, 0);
    pIEvent[8] = pIFA->pVTbl->AddEvent(pIFA, "BS", 8, 0);
    pIEvent[9] = pIFA->pVTbl->AddEvent(pIFA, "HT", 9, 0);
    pIEvent[10] = pIFA->pVTbl->AddEvent(pIFA, "LF", 10, 0);
    pIEvent[11] = pIFA->pVTbl->AddEvent(pIFA, "VT", 11, 0);
    pIEvent[12] = pIFA->pVTbl->AddEvent(pIFA, "FF", 12, 0);
    pIEvent[13] = pIFA->pVTbl->AddEvent(pIFA, "CR", 13, 0);
    pIEvent[14] = pIFA->pVTbl->AddEvent(pIFA, "SO", 14, 0);
    pIEvent[15] = pIFA->pVTbl->AddEvent(pIFA, "SI", 15, 0);
    pIEvent[16] = pIFA->pVTbl->AddEvent(pIFA, "DLE", 16, 0);
    pIEvent[17] = pIFA->pVTbl->AddEvent(pIFA, "DC1", 17, 0);
    pIEvent[18] = pIFA->pVTbl->AddEvent(pIFA, "DC2", 18, 0);
    pIEvent[19] = pIFA->pVTbl->AddEvent(pIFA, "DC3", 19, 0);
    pIEvent[20] = pIFA->pVTbl->AddEvent(pIFA, "DC4", 20, 0);
    pIEvent[21] = pIFA->pVTbl->AddEvent(pIFA, "NAK", 21, 0);
    pIEvent[22] = pIFA->pVTbl->AddEvent(pIFA, "SYN", 22, 0);
    pIEvent[23] = pIFA->pVTbl->AddEvent(pIFA, "ETB", 23, 0);
    pIEvent[24] = pIFA->pVTbl->AddEvent(pIFA, "CAN", 24, 0);
    pIEvent[25] = pIFA->pVTbl->AddEvent(pIFA, "EM", 25, 0);
    pIEvent[26] = pIFA->pVTbl->AddEvent(pIFA, "SUB", 26, 0);
    pIEvent[27] = pIFA->pVTbl->AddEvent(pIFA, "ESC", 27, 0);
    pIEvent[28] = pIFA->pVTbl->AddEvent(pIFA, "FS", 28, 0);
    pIEvent[29] = pIFA->pVTbl->AddEvent(pIFA, "GS", 29, 0);
    pIEvent[30] = pIFA->pVTbl->AddEvent(pIFA, "RS", 30, 0);
    pIEvent[31] = pIFA->pVTbl->AddEvent(pIFA, "US", 31, 0);
    pIEvent[32] = pIFA->pVTbl->AddEvent(pIFA, "SP", 32, 0);

    for (index = 33; index < 256; index++) {
        pszName[0] = index;
        pszName[1] = 0;
        /* Для любого события можно переназначить отображаемое имя */
        /* ... */
        pIEvent[index] = pIFA->pVTbl->AddEvent(pIFA, pszName, index, 0);
    }

    /* Пример для задания пустого (эпсилон) события */
    //pIEvent[0] = pIFA->AddEvent(pIFA, "epsilon", 0, 1);

    /* Устанавливаем начальное состояние автомата */
    pIState[0]->pVTbl->set_Initial(pIState[0], 1);

    /* Устанавливаем акцепторы - токены */
    pIState[10]->pVTbl->set_Parameter(pIState[10], "comment");
    pIState[10]->pVTbl->set_Final(pIState[10], 1);
    pIState[11]->pVTbl->set_Parameter(pIState[11], "new-line");
    pIState[11]->pVTbl->set_Final(pIState[11], 1);
    pIState[12]->pVTbl->set_Parameter(pIState[12], "white-space");
    pIState[12]->pVTbl->set_Final(pIState[12], 1);
    pIState[13]->pVTbl->set_Parameter(pIState[13], "backslash");
    pIState[13]->pVTbl->set_Final(pIState[13], 1);
    pIState[15]->pVTbl->set_Parameter(pIState[15], "unknown");
    pIState[15]->pVTbl->set_Final(pIState[15], 1);

    /* Создаем переходы для комментариев */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['/'],  pIState[0],  pIState[1]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['*'],  pIState[1],  pIState[5]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['/'],  pIState[1],  pIState[6]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['*'],  pIState[5],  pIState[8]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['/'],  pIState[8],  pIState[9]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[13],  pIState[6],  pIState[10]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[10],  pIState[6],  pIState[10]);
    for (index = 0; index <= 255; index++) {
        if (index == 13 || index == 10) {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[6],  pIState[6]);
    }
    for (index = 0; index <= 255; index++) {
        if (index == '*') {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[5],  pIState[5]);
    }
    for (index = 0; index <= 255; index++) {
        if (index == '/') {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[8],  pIState[5]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[1],  pIState[14]);
    }
    for (index = 0; index <= 255; index++) {
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[9],  pIState[10]);
    }

    /* Создаем переходы для новой строки */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[13],  pIState[0],  pIState[2]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[13],  pIState[2],  pIState[2]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[10],  pIState[0],  pIState[7]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[10],  pIState[2],  pIState[7]);
    for (index = 0; index <= 255; index++) {
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[7],  pIState[11]);
    }

    /* Создаем переходы для пробелов и табуляции */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[32],  pIState[0],  pIState[3]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[9],  pIState[0],  pIState[3]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[32],  pIState[3],  pIState[3]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[9],  pIState[3],  pIState[3]);
    for (index = 0; index <= 255; index++) {
        if (index == 9 || index == 32) {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[3],  pIState[12]);
    }

    /* Создаем переходы для продолжения строки */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\\'],  pIState[0],  pIState[4]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[13],  pIState[4],  pIState[13]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[10],  pIState[4],  pIState[13]);

    /* Создаем переходы для необрабатываемых лексем */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[9],  pIState[14],  pIState[15]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[10],  pIState[14],  pIState[15]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[13],  pIState[14],  pIState[15]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[' '],  pIState[14],  pIState[15]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['\\'],  pIState[14],  pIState[15]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['/'],  pIState[14],  pIState[15]);
    for (index = 0; index <= 255; index++) {
        if (index == 9 || index == 10 || index == 13 || index == ' ' || index == '\\' || index == '/') {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[0],  pIState[14]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[14],  pIState[14]);
    }

    return pIFA;
}

#define CASE 0
#define HT 1
#define LF 2
#define CR 3
#define SLASH 4
#define STAR 5
#define LETTERS 6
#define SP 7
#define BACKSLASH 8
#define UNKNOWN 9
#define CONTROL 10
/*
 *
 * <сводка>
 *   Функция GetFAForLA2
 * </сводка>
 *
 * <описание>
 *   Функция GetFAForLA2 - возвращает конечный автомат для лексического анализа
 * </описание>
 *
 */
IEcoFSM1StateMachine* GetFAForLA2(/* in */ IEcoFSM1* pIFSM) {
    IEcoFSM1StateMachine* pIFA = 0;
    IEcoFL1Alphabet* pIAlphabet = 0;
    IEcoFL1SymbolSet* pISymbolSet = 0;
    char_t pszName[5] = {0};
    uint32_t index = 0;
    IEcoFSM1Event* pIEvent[11] = {0};
    IEcoFSM1State* pIState[18] = {0};

    /* Создаем конечный автомат */
    pIFA = pIFSM->pVTbl->CreateStateMachine(pIFSM, "C89 comment");
    for (index = 0; index < 18; index++) {
        pszName[0] = 'q';
        pszName[1] = index/100 + 48;
        if (index > 100) {
            pszName[2] = (index- 100)/10 + 48;
        }
        else {
            pszName[2] = index/10 + 48;
        }
        pszName[3] = index%10 + 48;
        pIState[index] = pIFA->pVTbl->AddState(pIFA, pszName);
    }

    /* Создадим массив событий для алфавита по прядку кодов ASCII таблицы */
    pIEvent[0] = pIFA->pVTbl->AddEvent(pIFA, "case", 4, 0);
    pISymbolSet = pIEvent[0]->pVTbl->AddSymbolSet(pIEvent[0], "case");
    pISymbolSet->pVTbl->set_Length(pISymbolSet, 0x07);
    pISymbolSet->pVTbl->set_Align(pISymbolSet, 0x00);
    pISymbolSet->pVTbl->set_Word(pISymbolSet, (byte_t*)"case", 0x04);
    pISymbolSet->pVTbl->set_WordFailedState(pISymbolSet, pIState[15]);

    pIEvent[10] = pIFA->pVTbl->AddEvent(pIFA, "CE", 1, 0);
    pISymbolSet = pIEvent[10]->pVTbl->AddSymbolSet(pIEvent[10], "control");
    pISymbolSet->pVTbl->AddSymbolRange(pISymbolSet, 0, 8, &index);
    pISymbolSet->pVTbl->AddSymbolRange(pISymbolSet, 11, 12, &index);
    pISymbolSet->pVTbl->AddSymbolRange(pISymbolSet, 14, 31, &index);
    pIEvent[1] = pIFA->pVTbl->AddEvent(pIFA, "HT", 9, 0);
    pIEvent[2] = pIFA->pVTbl->AddEvent(pIFA, "LF", 10, 0);
    pIEvent[3] = pIFA->pVTbl->AddEvent(pIFA, "CR", 13, 0);
    pIEvent[4] = pIFA->pVTbl->AddEvent(pIFA, "/", '/', 0);
    pIEvent[5] = pIFA->pVTbl->AddEvent(pIFA, "*", '*', 0);
    pIEvent[6] = pIFA->pVTbl->AddEvent(pIFA, "LE", 2, 0);
    pISymbolSet = pIEvent[6]->pVTbl->AddSymbolSet(pIEvent[6], "letters");
    pISymbolSet->pVTbl->AddSymbolRange(pISymbolSet, 'A', 'Z', &index);
    pISymbolSet->pVTbl->AddSymbolRange(pISymbolSet, 'a', 'z', &index);
    pISymbolSet->pVTbl->AddSymbolRange(pISymbolSet, '_', '_', &index);
    pISymbolSet = pIEvent[6]->pVTbl->AddSymbolSet(pIEvent[6], "digits");
    pISymbolSet->pVTbl->AddSymbolRange(pISymbolSet, '0', '9', &index);
    pIEvent[7] = pIFA->pVTbl->AddEvent(pIFA, "SP", 32, 0);
    pIEvent[8] = pIFA->pVTbl->AddEvent(pIFA, "\\", '\\', 0);
    pIEvent[9] = pIFA->pVTbl->AddEvent(pIFA, "UNK", 3, 0);
    pISymbolSet = pIEvent[6]->pVTbl->AddSymbolSet(pIEvent[6], "unknown");
    pISymbolSet->pVTbl->set_Complement(pISymbolSet, 1);
    pISymbolSet->pVTbl->AddSymbolRange(pISymbolSet, 'A', 'Z', &index);
    pISymbolSet->pVTbl->AddSymbolRange(pISymbolSet, 'a', 'z', &index);
    pISymbolSet->pVTbl->AddSymbolRange(pISymbolSet, '_', '_', &index);
    pISymbolSet->pVTbl->AddSymbolRange(pISymbolSet, 0, 32, &index);
    pISymbolSet->pVTbl->AddSymbolRange(pISymbolSet, '/', '/', &index);
    pISymbolSet->pVTbl->AddSymbolRange(pISymbolSet, '\\', '\\', &index);
    pISymbolSet->pVTbl->AddSymbolRange(pISymbolSet, '*', '*', &index);

    /* Устанавливаем начальное состояние автомата */
    pIState[0]->pVTbl->set_Initial(pIState[0], 1);

    /* Устанавливаем акцепторы - токены */
    pIState[10]->pVTbl->set_Parameter(pIState[10], "comment");
    pIState[10]->pVTbl->set_Final(pIState[10], 1);
    pIState[11]->pVTbl->set_Parameter(pIState[11], "new-line");
    pIState[11]->pVTbl->set_Final(pIState[11], 1);
    pIState[12]->pVTbl->set_Parameter(pIState[12], "white-space");
    pIState[12]->pVTbl->set_Final(pIState[12], 1);
    pIState[13]->pVTbl->set_Parameter(pIState[13], "backslash");
    pIState[13]->pVTbl->set_Final(pIState[13], 1);
    pIState[15]->pVTbl->set_Parameter(pIState[15], "unknown");
    pIState[15]->pVTbl->set_Final(pIState[15], 1);
    pIState[17]->pVTbl->set_Parameter(pIState[17], "case");
    pIState[17]->pVTbl->set_Final(pIState[17], 1);

    pIFA->pVTbl->AddTransition(pIFA, pIEvent[CASE],  pIState[0],  pIState[16]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[SP],  pIState[16],  pIState[17]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[HT],  pIState[16],  pIState[17]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[CR],  pIState[16],  pIState[17]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[LF],  pIState[16],  pIState[17]);

    /* Создаем переходы для комментариев */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[SLASH],  pIState[0],  pIState[1]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[STAR],  pIState[1],  pIState[5]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[SLASH],  pIState[1],  pIState[6]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[STAR],  pIState[5],  pIState[8]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[SLASH],  pIState[8],  pIState[9]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[CR],  pIState[6],  pIState[10]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[LF],  pIState[6],  pIState[10]);

    for (index = 0; index < 11; index++) {
        if (index == CR || index == LF) {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[6],  pIState[6]);
    }

    for (index = 0; index < 11; index++) {
        if (index == STAR) {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[5],  pIState[5]);
    }

    for (index = 0; index < 11; index++) {
        if (index == SLASH) {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index], pIState[8], pIState[5]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index], pIState[1], pIState[14]);
    }

    for (index = 0; index < 11; index++) {
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index], pIState[9],  pIState[10]);
    }

    /* Создаем переходы для новой строки */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[CR],  pIState[0],  pIState[2]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[CR],  pIState[2],  pIState[2]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[LF],  pIState[0],  pIState[7]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[LF],  pIState[2],  pIState[7]);
    for (index = 0; index < 11; index++) {
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[7],  pIState[11]);
    }

    /* Создаем переходы для пробелов и табуляции */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[SP],  pIState[0],  pIState[3]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[HT],  pIState[0],  pIState[3]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[SP],  pIState[3],  pIState[3]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[HT],  pIState[3],  pIState[3]);

    for (index = 0; index < 11; index++) {
        if (index == SP || index == HT) {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[3],  pIState[12]);
    }

    /* Создаем переходы для продолжения строки */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[BACKSLASH],  pIState[0],  pIState[4]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[CR],  pIState[4],  pIState[13]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[LF],  pIState[4],  pIState[13]);

    /* Создаем переходы для необрабатываемых лексем */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[HT],  pIState[14],  pIState[15]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[LF],  pIState[14],  pIState[15]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[CR],  pIState[14],  pIState[15]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[SP],  pIState[14],  pIState[15]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[BACKSLASH],  pIState[14],  pIState[15]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[SLASH],  pIState[14],  pIState[15]);

    for (index = 0; index < 11; index++) {
        if (index == HT || index == LF || index == CR || index == SP || index == BACKSLASH || index == SLASH) {
            continue;
        }
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[0],  pIState[14]);
        pIFA->pVTbl->AddTransition(pIFA, pIEvent[index],  pIState[14],  pIState[14]);
    }

    return pIFA;
}

/*
 *
 * <сводка>
 *   Функция GetRGForLA
 * </сводка>
 *
 * <описание>
 *   Функция GetRGForLA - возвращает регулярную грамматику для лексического анализа
 * </описание>
 *
 */
//IEcoRE1Grammar* GetRGForLA(/* in */ IEcoRE1* pIRE) {
//    IEcoRE1Grammar* pIRegularGrammar = 0;
//IEcoRE1Rule* pIRule = 0;
//IEcoRE1NonTerminal* pINT[14] = {0};
//uint32_t index = 0;
//char_t pszName[5] = {0};

///* Получение интерфейса для левосторонней регулярной грамматики */
//pIRegularGrammar = pIRE->CreateRegularGrammar(pIRE, "RG - Comment", 0);

//for (index = 0; index < 14; index++) {
//    pszName[0] = 'q';
//    pszName[1] = index/100 + 48;
//    if (index > 100) {
//        pszName[2] = (index- 100)/10 + 48;
//    }
//    else {
//        pszName[2] = index/10 + 48;
//    }
//    pszName[3] = index%10 + 48;
//    if (index == 13) {
//        /* Создаем нетерминальный стартовый символ */
//        pINT[index] = pIRegularGrammar->new_NonTerminal(pIRegularGrammar, pszName, 1);
//        /* Для регулярной грамматики является конечным состоянием */
//        pINT[index]->set_Description(pINT[index], "token");
//    }
//    else if (index == 5) {
//        /* Создаем нетерминальный символ для комментария */
//        pINT[index] = pIRegularGrammar->new_NonTerminal(pIRegularGrammar, pszName, 0);
//        pINT[index]->set_Description(pINT[index], "comment");
//    }
//    else if (index == 7) {
//        /* Создаем нетерминальный символ для новой строки */
//        pINT[index] = pIRegularGrammar->new_NonTerminal(pIRegularGrammar, pszName, 0);
//        pINT[index]->set_Description(pINT[index], "new-line");
//    }
//    else if (index == 8) {
//        /* Создаем нетерминальный символ для пробелов */
//        pINT[index] = pIRegularGrammar->new_NonTerminal(pIRegularGrammar, pszName, 0);
//        pINT[index]->set_Description(pINT[index], "white-space");
//    }
//    else if (index == 10) {
//        /* Создаем нетерминальный символ для продолжения строки */
//        pINT[index] = pIRegularGrammar->new_NonTerminal(pIRegularGrammar, pszName, 0);
//        pINT[index]->set_Description(pINT[index], "backslash");
//    }
//    else if (index == 12) {
//        /* Создаем нетерминальный символ для осталных */
//        pINT[index] = pIRegularGrammar->new_NonTerminal(pIRegularGrammar, pszName, 0);
//        pINT[index]->set_Description(pINT[index], "unknown");
//    }
//    else {
//        pINT[index] = pIRegularGrammar->new_NonTerminal(pIRegularGrammar, pszName, 0);
//    }
//}

///* Формируем правила описывающие множество  */
//for (index = 0; index < 256; index++) {
//    /* правла:  q013->q005 [0-9a-zA-Z\r\n\sp\t] */
//    pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[13], index, 0, pINT[5]);
//    /* правла:  q013->q007 [0-9a-zA-Z\r\n\sp\t] */
//    pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[13], index, 0, pINT[7]);
//    /* правла:  q013->q008 [0-9a-zA-Z\r\n\sp\t] */
//    pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[13], index, 0, pINT[8]);
//    /* правла:  q013->q010 [0-9a-zA-Z\r\n\sp\t] */
//    pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[13], index, 0, pINT[10]);
//    /* правла:  q013->q012 [0-9a-zA-Z\r\n\sp\t] */
//    pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[13], index, 0, pINT[12]);
//}

///* правла:  q005->q004 /  */
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[5], '/', 0, pINT[4]);

///* правла:  q005->q003 [\r\n]  */
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[5], 10, 0, pINT[3]);
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[5], 13, 0, pINT[3]);


///* правла:  q004->q002*  */
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[4], '*', 0, pINT[2]);

///* правла:  q002->q004 [0-9a-zA-Z\r\n\sp\t]  */
//for (index = 0; index < 256; index++) {
//    if (index == '/') {
//        continue;
//    }
//    pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[2], index, 0, pINT[4]);
//}
///* правла:  q002->q002 [0-9a-zA-Z\r\n\sp\t]  */
//for (index = 0; index < 256; index++) {
//    if (index == '*') {
//        continue;
//    }
//    pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[2], index, 0, pINT[2]);
//}

///* правла:  q002->q001 *  */
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[2], '*', 0, pINT[1]);

///* правла:  q003->q001 /  */
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[3], '/', 0, pINT[1]);

///* правла:  q003->q003  [0-9a-zA-Z\sp\t]  */
//for (index = 0; index < 256; index++) {
//    if (index == 10 || index == 13) {
//        continue;
//    }
//    pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[3], index, 0, pINT[3]);
//}

///* правла:  q001-> /  */
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[1], '/', 0, 0);

///* правла:  q001->q011  [0-9a-zA-Z\sp\t]  */
//for (index = 0; index < 256; index++) {
//    if (index == '*' || index == '/') {
//        continue;
//    }
//    pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[11], index, 0, pINT[1]);
//}

///* правла:  q006-> \r  */
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[6], 13, 0, 0);

///* правла:  q007->q006 \n  */
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[7], 10, 0, pINT[6]);

///* правла:  q007-> \n  */
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[7], 10, 0, 0);

///* правла:  q008-> [\sp\t] */
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[8], 9, 0, 0);
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[8], 32, 0, 0);
///* правла:  q008-> q008 [\sp\t] */
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[8], 9, 0, pINT[8]);
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[8], 32, 0, pINT[8]);

///* правла:  q009-> \  */
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[9], '\\', 0, 0);

///* правла:  q0010->q009 [\r\n]  */
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[10], 10, 0, pINT[9]);
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[10], 13, 0, pINT[9]);

///* правла:  q011->q009  [0-9a-zA-Z\sp\t]  */
//for (index = 0; index < 256; index++) {
//    if (index == 10 || index == 13) {
//        continue;
//    }
//    pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[11], index, 0, pINT[9]);
//}

///* правла:  q0012->q011 [\r\n\sp\t\/]  */
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[12], 10, 0, pINT[11]);
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[12], 13, 0, pINT[11]);
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[12], 9, 0, pINT[11]);
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[12], 32, 0, pINT[11]);
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[12], '\\', 0, pINT[11]);
//pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[12], '/', 0, pINT[11]);

///* правла:  q011->[0-9a-zA-Z]  */
//for (index = 0; index < 256; index++) {
//    if (index == 10 || index == 13 || index == 9 || index == 32 || index == '\\' || index == '/') {
//        continue;
//    }
//    pIRule = pIRegularGrammar->AddRule(pIRegularGrammar, 0, pINT[11], index, 0, 0);
//}

//    return pIRegularGrammar;
//}

int16_t ECOCALLMETHOD RecognitionIndividualToken(/* in */ uchar_t Symbol,
        /* in */ char_t* Lexem,
        /* in */ uint32_t Line,
        /* in */ uint32_t Column,
        /* in */ char_t* Source,
        /* in */ uint32_t Position,
        /* in */ uint32_t Length,
        /* out */ int32_t* Type,
        /* in | out */ char_t** Description,
        /* out */ uint16_t* Flag) {
    int16_t result = 0;

    return result;
}
