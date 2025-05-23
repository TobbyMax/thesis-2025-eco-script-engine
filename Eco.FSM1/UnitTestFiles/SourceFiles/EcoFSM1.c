/*
 * <кодировка символов>
 *   Cyrillic (Windows) - Codepage 1251
 * </кодировка символов>
 *
 * <сводка>
 *   EcoFSM1
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
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IEcoLog1FileAffiliate.h"
#include "IdEcoFSM1.h"
#include "IdEcoList1.h"
#include "IdEcoString1.h"
#include "IdEcoLog1.h"
#include "IdEcoData1.h"
#include "IdEcoDateTime1.h"

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
    IEcoString1* pIString = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoFSM1* pIFSM = 0;
    IEcoFSM1StateMachine* pIStateMachine = 0;
    IEcoFSM1State* pIState = 0;
    IEcoFSM1Transition* pITransition = 0;
    IEcoFSM1Event* pIEvent = 0;
    IEcoFSM1Event* pIEventWithSymbolSet = 0;
    IEcoMemoryManager1* pIMemMgr = 0;
    /* Указатель на интерфейс работы с журналом */
    IEcoLog1* pILog = 0;
    IEcoLog1FileAffiliate* pIFileAffiliate = 0;
    IEcoData1Table* pITransitionTable = 0;
    IEcoFSM1EventProcessing* pIEventProcessing = 0;
    IEcoList1* pIColumns = 0;
    IEcoList1* pIRows = 0;
    IEcoData1* pIData = 0;
    IEcoData1Column* pIColumn = 0;
    IEcoData1Row* pIRow = 0;
    uint32_t index = 0;
    uint32_t indexColumn = 0;
    uint32_t indexRow = 0;
    char_t* Line = 0;
    char_t* Headers = 0;
    char_t* ptrStr = 0;

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
    /* Регистрация статического компонента для работы с конечным автоматом */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoFSM1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_5E7C610CB846447DB59A3C5A2C4F446F);
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
    /* Регистрация статического компонента для работы с таблицами */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoData1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_5A0F0DD57E6448EC9EE0E5D67572B47E);
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

    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса для работы со строкой */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (void**) &pIString);
    if (result != 0|| pIString == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса для работы с журналом */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1, (void**) &pILog);
    if (result != 0|| pILog == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1FileAffiliate, (void**) &pIFileAffiliate);
    if (result != 0|| pIFileAffiliate == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }
    pILog->pVTbl->AddAffiliate(pILog, (IEcoLog1Affiliate*)pIFileAffiliate);
    pIFileAffiliate->pVTbl->Release(pIFileAffiliate);

    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoData1, 0, &IID_IEcoData1, (voidptr_t*) &pIData);
    if (result != 0 && pIData == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoFSM1, 0, &IID_IEcoFSM1, (void**) &pIFSM);
    if (result != 0 && pIFSM == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Вызов функции создания машины состояний */
    pIStateMachine = pIFSM->pVTbl->CreateStateMachine(pIFSM, "A");

    /* Проверка */
    if (pIStateMachine != 0) {
        IEcoFL1Alphabet* pIAlphabet = 0;

        IEcoFL1SymbolSet* pISymbolSet = 0;
        IEcoFL1SymbolSet* pISymbolSetInt = 0;
        IEcoFL1SymbolSet* pISymbolSetWord = 0;



        /* Вызов функции создания алфавита */

        pIAlphabet = pIStateMachine->pVTbl->AddAlphabet(pIStateMachine, "sigma");

        /* Вызов функции создания набора символов алфавита */
        pISymbolSet = pIAlphabet->pVTbl->AddSymbolSet(pIAlphabet, "ASCII");
        /* Зададим длину символов алфавита равную 7 бит */
        pISymbolSet->pVTbl->set_Length(pISymbolSet, 0x07);
        /* Зададим выравнивание равное 8 бит (значение по умолчанию 8 бит), так как минимально адресуемой единицей памяти является 8-битный байт */
        pISymbolSet->pVTbl->set_Align(pISymbolSet, 0x08);
        /* Зададим набор символов алфавита с помощью диапазона кодов */
        result = pISymbolSet->pVTbl->AddSymbolRange(pISymbolSet, 0x01, 0x7F, 0);

        pISymbolSetInt = pIAlphabet->pVTbl->AddSymbolSet(pIAlphabet, "int");
        pISymbolSetInt->pVTbl->set_Length(pISymbolSetInt, 0x07);
        pISymbolSetInt->pVTbl->set_Align(pISymbolSetInt, 0x00);
        result = pISymbolSetInt->pVTbl->AddSymbol(pISymbolSetInt, (byte_t*)"i", 0x07, 0, 0);
        result = pISymbolSetInt->pVTbl->AddSymbol(pISymbolSetInt, (byte_t*)"n", 0x07, 0, 0);
        result = pISymbolSetInt->pVTbl->AddSymbol(pISymbolSetInt, (byte_t*)"t", 0x07, 0, 0);

        pISymbolSetWord = pIAlphabet->pVTbl->AddSymbolSet(pIAlphabet, "word");
        pISymbolSetWord->pVTbl->set_Length(pISymbolSetWord, 0x07);
        pISymbolSetWord->pVTbl->set_Align(pISymbolSetWord, 0x00);
        result = pISymbolSetWord->pVTbl->set_Word(pISymbolSetWord, (byte_t*)"word", 0x04);

        /* Добавление состояний и событий */
        pIState = pIStateMachine->pVTbl->AddState(pIStateMachine, "0");
        pIState->pVTbl->set_Initial(pIState, 1);
        pIStateMachine->pVTbl->AddEvent(pIStateMachine, "(", 0, 0);
        pIStateMachine->pVTbl->AddEvent(pIStateMachine, "x", 1, 0);
        pIStateMachine->pVTbl->AddEvent(pIStateMachine, "S", 2, 0);
        pIState = pIStateMachine->pVTbl->AddState(pIStateMachine, "1");
        pIStateMachine->pVTbl->AddEvent(pIStateMachine, "$", 3, 0);
        pIState = pIStateMachine->pVTbl->AddState(pIStateMachine, "2");
        pIStateMachine->pVTbl->AddEvent(pIStateMachine, "L", 4, 0);
        pIState = pIStateMachine->pVTbl->AddState(pIStateMachine, "3");
        pIState = pIStateMachine->pVTbl->AddState(pIStateMachine, "4");
        pIStateMachine->pVTbl->AddEvent(pIStateMachine, ",", 6, 0);
        pIEvent = pIStateMachine->pVTbl->AddEvent(pIStateMachine, ")", 7, 0);
        pIEventWithSymbolSet = pIStateMachine->pVTbl->AddEvent(pIStateMachine, "int", 8, 0);
        pIEventWithSymbolSet->pVTbl->AddExistingSymbolSet(pIEventWithSymbolSet, pIAlphabet->pVTbl->get_SymbolSet(pIAlphabet, 1));
        pIEventWithSymbolSet = pIStateMachine->pVTbl->AddEvent(pIStateMachine, "word", 9, 0);
        pIEventWithSymbolSet->pVTbl->AddExistingSymbolSet(pIEventWithSymbolSet, pIAlphabet->pVTbl->get_SymbolSet(pIAlphabet, 2));
        pIEventWithSymbolSet = pIStateMachine->pVTbl->AddEvent(pIStateMachine, "ASCII", 10, 0);
        pIEventWithSymbolSet->pVTbl->AddExistingSymbolSet(pIEventWithSymbolSet, pIAlphabet->pVTbl->get_SymbolSet(pIAlphabet, 0));


        pIState = pIStateMachine->pVTbl->AddState(pIStateMachine, "5");
        pIState = pIStateMachine->pVTbl->AddState(pIStateMachine, "6");
        pIState = pIStateMachine->pVTbl->AddState(pIStateMachine, "7");
        pIState = pIStateMachine->pVTbl->AddState(pIStateMachine, "8");
        pIState = pIStateMachine->pVTbl->AddState(pIStateMachine, "9");
        pIState = pIStateMachine->pVTbl->AddState(pIStateMachine, "10");
        pIState = pIStateMachine->pVTbl->AddState(pIStateMachine, "11");
        pIState = pIStateMachine->pVTbl->AddState(pIStateMachine, "12");
        pIAlphabet->pVTbl->get_SymbolSet(pIAlphabet, 2)->pVTbl->set_WordFailedState(pIAlphabet->pVTbl->get_SymbolSet(pIAlphabet, 2), pIState);
        /* Добавление переходов */
        pITransition = pIStateMachine->pVTbl->AddTransitionById(pIStateMachine, 0, 0, 2);
        pITransition = pIStateMachine->pVTbl->AddTransitionById(pIStateMachine, 1, 0, 0);
        pITransition = pIStateMachine->pVTbl->AddTransitionById(pIStateMachine, 2, 0, 3);

        pITransition = pIStateMachine->pVTbl->AddTransitionById(pIStateMachine, 1, 2, 1);
        pITransition = pIStateMachine->pVTbl->AddTransitionById(pIStateMachine, 2, 2, 6);
        pITransition = pIStateMachine->pVTbl->AddTransitionById(pIStateMachine, 4, 2, 4);

        pITransition = pIStateMachine->pVTbl->AddTransitionById(pIStateMachine, 5, 4, 7);
        pITransition = pIStateMachine->pVTbl->AddTransitionById(pIStateMachine, 6, 4, 5);

        pITransition = pIStateMachine->pVTbl->AddTransitionById(pIStateMachine, 7, 6, 8);
        pITransition = pIStateMachine->pVTbl->AddTransitionById(pIStateMachine, 0, 7, 2);
        pITransition = pIStateMachine->pVTbl->AddTransitionById(pIStateMachine, 2, 7, 8);

        pITransition = pIStateMachine->pVTbl->AddTransitionById(pIStateMachine, 8, 8, 9);
        pITransition = pIStateMachine->pVTbl->AddTransitionById(pIStateMachine, 9, 9, 10);
        pITransition = pIStateMachine->pVTbl->AddTransitionById(pIStateMachine, 10, 10, 11);

        /* Вывод конечного автомата */
        pILog->pVTbl->InfoFormat(pILog, "StateMachine [%s]", pIStateMachine->pVTbl->get_Name(pIStateMachine));

        /* Вывод управляющей таблицы */
        pITransitionTable = pIStateMachine->pVTbl->get_TransitionTable(pIStateMachine);
        if (pITransitionTable != 0) {
            pIColumns = pITransitionTable->pVTbl->get_Columns(pITransitionTable);

            printf("Table [%s]\n", pITransitionTable->pVTbl->get_Name(pITransitionTable));
            pILog->pVTbl->InfoFormat(pILog, "Table [%s]", pITransitionTable->pVTbl->get_Name(pITransitionTable));
            Line = pIString->pVTbl->Append(pIString, Line, "+-------+");
            Headers = pIString->pVTbl->Append(pIString, Headers, "| S \\ E |");
            for (indexColumn = 0; indexColumn < pIColumns->pVTbl->Count(pIColumns); indexColumn++) {
                pIColumn = (IEcoData1Column*)pIColumns->pVTbl->Item(pIColumns, indexColumn);
                Line = pIString->pVTbl->Append(pIString, Line, "--");
                Headers = pIString->pVTbl->Append(pIString, Headers, "  ");
                Headers = pIString->pVTbl->Append(pIString, Headers, pIColumn->pVTbl->get_Name(pIColumn));
                Headers = pIString->pVTbl->Append(pIString, Headers, "  |");
                Line = pIString->pVTbl->Append(pIString, Line, "---+");
            }
            printf("%s\n", Line);
            pILog->pVTbl->InfoFormat(pILog, "%s", Line);

            printf("%s\n", Headers);
            pILog->pVTbl->InfoFormat(pILog, "%s", Headers);

            printf("%s\n", Line);
            pILog->pVTbl->InfoFormat(pILog, "%s", Line);

            pIString->pVTbl->Free(pIString, Headers);
            Headers = 0;

            pIRows = pITransitionTable->pVTbl->get_Rows(pITransitionTable);
            for (indexRow = 0; indexRow < pIRows->pVTbl->Count(pIRows); indexRow++) {
                Headers = pIString->pVTbl->Append(pIString, Headers, "|");
                pIRow = (IEcoData1Row*)pIRows->pVTbl->Item(pIRows, indexRow);
                Headers = pIString->pVTbl->Append(pIString, Headers, "   ");
                ptrStr = pIString->pVTbl->ConvertIntToString(pIString, indexRow);
                Headers = pIString->pVTbl->Append(pIString, Headers, ptrStr);
                pIString->pVTbl->Free(pIString, ptrStr);
                Headers = pIString->pVTbl->Append(pIString, Headers, "   |");
                for (indexColumn = 0; indexColumn < pIColumns->pVTbl->Count(pIColumns); indexColumn++) {
                    if (pIRow->pVTbl->IsNullByIndex(pIRow, indexColumn)) {
                        Headers = pIString->pVTbl->Append(pIString, Headers, "     |");
                    } else {
                        Headers = pIString->pVTbl->Append(pIString, Headers, "  ");
                        Headers = pIString->pVTbl->Append(pIString, Headers, (char_t*)pIRow->pVTbl->get_ItemByIndex(pIRow, indexColumn));
                        Headers = pIString->pVTbl->Append(pIString, Headers, "  |");
                    }
                }

                printf("%s\n", Headers);

                pILog->pVTbl->InfoFormat(pILog, "%s", Headers);

                printf("%s\n", Line);
                pILog->pVTbl->InfoFormat(pILog, "%s", Line);
                pIString->pVTbl->Free(pIString, Headers);
                Headers = 0;
            }
            pIString->pVTbl->Free(pIString, Line);
            Line = 0;
        }

        printf("Processing Finite State Machine\n");

        /* Получение интерфейса обработчика событий конечного автомата */
        pIEventProcessing = pIFSM->pVTbl->get_EventProcessing(pIFSM, pIStateMachine);
        /* Проверка */
        if (pIEventProcessing != 0) {
            pIEventProcessing->pVTbl->ResetStateMachine(pIEventProcessing);
            pIState = pIEventProcessing->pVTbl->get_CurrentState(pIEventProcessing);

            printf("Processing Start => Initial State [%s]\n", pIState->pVTbl->get_Name(pIState));
            pILog->pVTbl->InfoFormat(pILog, "Processing Start => Initial State [%s]", pIState->pVTbl->get_Name(pIState));
            pIState = pIEventProcessing->pVTbl->InvokeById(pIEventProcessing, 0);

            printf("Processing Invoke \"(\" => Next State [%s]\n", pIState->pVTbl->get_Name(pIState));
            pILog->pVTbl->InfoFormat(pILog, "Processing Invoke \"(\" => Next State [%s]", pIState->pVTbl->get_Name(pIState));
            pIState = pIEventProcessing->pVTbl->InvokeByName(pIEventProcessing, "S");

            printf("Processing Invoke \"S\" => Next State [%s]\n", pIState->pVTbl->get_Name(pIState));
            pILog->pVTbl->InfoFormat(pILog, "Processing Invoke \"S\" => Next State [%s]", pIState->pVTbl->get_Name(pIState));
            pIState = pIEventProcessing->pVTbl->InvokeByEvent(pIEventProcessing, pIEvent);

            printf("Processing Invoke \")\" => Next State [%s]\n", pIState->pVTbl->get_Name(pIState));
            pILog->pVTbl->InfoFormat(pILog, "Processing Invoke \")\" => Next State [%s]", pIState->pVTbl->get_Name(pIState));

            pIState = pIEventProcessing->pVTbl->InvokeBySymbol(pIEventProcessing, (byte_t*)L"i", 0x07, 0x08);
            printf("Processing Invoke \"i\" => Next State [%s]\n", pIState->pVTbl->get_Name(pIState));
            pILog->pVTbl->InfoFormat(pILog, "Processing Invoke \")\" => Next State [%s]", pIState->pVTbl->get_Name(pIState));

            pIState = pIEventProcessing->pVTbl->InvokeBySymbol(pIEventProcessing, (byte_t*)L"w", 0x07, 0x08);
            printf("Processing Invoke \"w\" => Next State [%s]\n", pIState->pVTbl->get_Name(pIState));
            pILog->pVTbl->InfoFormat(pILog, "Processing Invoke \")\" => Next State [%s]", pIState->pVTbl->get_Name(pIState));

            pIState = pIEventProcessing->pVTbl->InvokeBySymbol(pIEventProcessing, (byte_t*)L"o", 0x07, 0x08);
            printf("Processing Invoke \"o\" => Next State [%s]\n", pIState->pVTbl->get_Name(pIState));
            pILog->pVTbl->InfoFormat(pILog, "Processing Invoke \")\" => Next State [%s]", pIState->pVTbl->get_Name(pIState));

            pIState = pIEventProcessing->pVTbl->InvokeBySymbol(pIEventProcessing, (byte_t*)L"r", 0x07, 0x08);
            printf("Processing Invoke \"r\" => Next State [%s]\n", pIState->pVTbl->get_Name(pIState));
            pILog->pVTbl->InfoFormat(pILog, "Processing Invoke \")\" => Next State [%s]", pIState->pVTbl->get_Name(pIState));

            pIState = pIEventProcessing->pVTbl->InvokeBySymbol(pIEventProcessing, (byte_t*)L"d", 0x07, 0x08);
            printf("Processing Invoke \"d\" => Next State [%s]\n", pIState->pVTbl->get_Name(pIState));
            pILog->pVTbl->InfoFormat(pILog, "Processing Invoke \")\" => Next State [%s]", pIState->pVTbl->get_Name(pIState));

            pIState = pIEventProcessing->pVTbl->InvokeBySymbol(pIEventProcessing, (byte_t*)L"a", 0x07, 0x08);
            printf("Processing Invoke \"a\" => Next State [%s]\n", pIState->pVTbl->get_Name(pIState));
            pILog->pVTbl->InfoFormat(pILog, "Processing Invoke \")\" => Next State [%s]", pIState->pVTbl->get_Name(pIState));

            printf("Processing End => Final State [%s]\n", pIState->pVTbl->get_Name(pIState));
            pILog->pVTbl->InfoFormat(pILog, "Processing End => Final State [%s]", pIState->pVTbl->get_Name(pIState));
            pIEventProcessing->pVTbl->Release(pIEventProcessing);
        }

        pIStateMachine->pVTbl->Release(pIStateMachine);
    }

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение интерфейса работы со строкой */
    if (pIString != 0) {
        pIString->pVTbl->Release(pIString);
    }

    /* Освобождение тестируемого интерфейса */
    if (pIFSM != 0) {
        pIFSM->pVTbl->Release(pIFSM);
    }

    /* Освобождение интерфейса для работы с журналом */
    if (pILog != 0) {
        pILog->pVTbl->Release(pILog);
    }

    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

