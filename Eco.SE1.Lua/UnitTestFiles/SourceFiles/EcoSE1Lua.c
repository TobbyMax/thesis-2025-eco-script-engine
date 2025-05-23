/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoSE1Lua
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
//#include "IEcoSystemInformation1.h"
#include "IEcoCommandArguments1.h"
#include "IdEcoMemoryManager1.h"
#include "IEcoInterfaceBus1.h"
#include "IdEcoString1.h"
#include "IdEcoStack1.h"
#include "IdEcoFileSystemManagement1.h"
//#include "IdEcoPushdownAutomata1.h"
#include "IdEcoLexicalAnalyzer1.h"
#include "IdEcoSyntaxAnalyzer1.h"
#include "IdEcoLR1.h"
#include "IdEcoAST1.h"
//#include "IdEcoAST1.h"
#include "IdEcoBNF1.h"
#include "IdEcoMacroProcessor1.h"
#include "IdEcoCodeGenerator1.h"
//#include "IdEcoEmitterLLVMIR1.h"
//#include "IdEcoEmitterI8086.h"
#include "IdEcoEmitterI80686.h"
#include "IdEcoLinker1.h"
//#include "IdEcoOMF1.h"
#include "IdEcoPECOFF1.h"
#include "IdEcoFSM1.h"
#include "IdEcoLog1.h"
#include "IdEcoList1.h"
#include "IEcoLog1FileAffiliate.h"
#include "EcoLua1Grammar.h"
#include "EcoOutputDiagnostic.h"

#define voidptr_t void
//#include "IdEcoProcessManager1.h"
//#include "IdEcoMutex1.h"
#include "../../../Eco.EmitterLLVMIR1/SharedFiles/IEcoEmitterLLVMIR1.h"

#include <stdio.h>

//#define IID_IEcoCodeGenerator1 IID_IEcoToolchainCodeGenerator1
//#define IID_IEcoLinker1 IID_IEcoToolchainLinker1
//#define CID_EcoCodeGenerator1 CID_EcoToolchainCodeGenerator1
//#define CID_EcoLinker1 CID_EcoToolchainLinker1
//#define CID_EcoEmitterLLVMIR1 CID_EcoToolchainEmitterLLVMIR1
//#define CID_EcoEmitterI80686 CID_EcoToolchainEmitterI80686
//
//#define IEcoCodeGenerator1 IEcoToolchainCodeGenerator1
//#define IEcoLinker1 IEcoToolchainLinker1
//#define IEcoEmitter1 IEcoToolchainEmitter1

// Code simplifier, to get rid of doubling component name and ->
#define COMP_CALL(comp, method, ...) comp->pVTbl->method(comp, __VA_ARGS__)

#define I(comp) comp->pVTbl->

void removeChar(char_t* pStr, char_t ch) {
    char_t* pRes = pStr;

    if (pStr == 0) {
        return;
    }

    while (*pStr) {
        if (*pStr != ch)
            *pRes++ = *pStr;
        pStr++;
    }
    *pRes = '\0';
}

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
    IEcoCommandArguments1* pICmdArg = 0;
    uint32_t iArgIndex = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    /* Указатель на интерфейс работы сo строкой */
    IEcoString1* pIStr = 0;
    /* Указатель на интерфейс работы с журналом */
    IEcoLog1* pILog = 0;
    IEcoLog1FileAffiliate* pIFileAffiliate = 0;
    /* Указатель на интерфейс работы с файлами */
    IEcoFileManager1* pIFileManager = 0;
    IEcoList1* pISourceFiles = 0;
    uint32_t iSourceIndex = 0;
    char_t* pszSearchFileName = 0;
    char_t* pszSourceFileName = 0;
    char_t* pszOutputFileName = 0;
    char_t* pszSourceFileExt = 0;
    char_t* pszSourceName = 0;
    char_t* pszSearchPath = 0;
    char_t* pszObjName = 0;
    char_t* pszIRName = 0;
    /* Интерфейсы для работы с грамматикой */
    IEcoBNF1* pILuaGrammarLex = 0;
    IEcoBNF1* pILuaGrammarSyn = 0;
    IEcoBNF1* pIAsmGrammarLex = 0;
    IEcoBNF1* pIAsmGrammarSyn = 0;
    IEcoBNF1Rule* pIRule = 0;
    IEcoBNF1Element* pIElement = 0;
    uint32_t indexSet = 0;
    uint32_t indexHeaders = 0;
    bool_t bOptional = 0;

    /* Интерфейсы для работы с лексическим анализом */
    IEcoLexicalAnalyzer1* pILexer = 0;
    IEcoLexicalAnalyzer1Scanner* pIScanner = 0;
    IEcoLexicalAnalyzer1Token* pIToken = 0;
    IEcoLexicalAnalyzer1Token* pIOutToken = 0;
    IEcoLexicalAnalyzer1Token* pIPreToken = 0;
    IEcoStack1* pIScannerList = 0;
    IEcoStack1* pITokenList = 0;
    uint32_t iTokenIndex = 0;
    /* Интерфейсы для работы с синтаксическим анализом */
    IEcoSyntaxAnalyzer1* pISyntax = 0;
    IEcoSyntaxAnalyzer1Parser* pILuaParser = 0;
    IEcoSyntaxAnalyzer1Parser* pIParser = 0;
    IEcoUnknown* pIUnkAlgorithm = 0;
    IEcoParser1LRk* pILRkAlgorithm = 0;
    IEcoParser1Action* pIAction = 0;

    char_t* mainTokenSource = 0;
    /* Интерфейсы для работы с препроцессором */
    IEcoMacroProcessor1* pIAsmPreprocessor = 0;
    IEcoMacroProcessor1* pILuaPreprocessor = 0;
    IEcoMacroProcessor1* pIPreprocessor = 0;
    IEcoList1* pIMacroExpTokenList = 0;
    IEcoMacroProcessor1Processing* pIPreProcessing = 0;
    IEcoMacroProcessor1Result* pIPreResult = 0;
    char_t* pszMacroKey = 0;
    char_t* pszMacroValue = 0;
    /* Интерфейсы для работы с абстрактным синтаксическим деревом */
    IEcoAST1* pIAST = 0;
    IEcoFSM1* pIFSM = 0;
    IEcoFSM1StateMachine* pIFA = 0;
    IEcoCodeGenerator1* pICodeGen = 0;
    IEcoEmitter1* pIEmitter = 0;
    IEcoLinker1* pILinker = 0;
    IEcoList1* pIObjFiles = 0;
    IEcoList1* pISearchHeaderPaths = 0;
    /* Переменные входного потока */
    uint16_t iActiveLang = 0;
    bool_t useLLVM = 0;
    int32_t optLevel = OptLevelDefault;

//    IEcoProcessManager1* pIProcessMgr = 0;
//    IEcoProcess1* pIProcess = 0;
    uint32_t i = 0;
    char_t* clangCmdString = 0;

//    IEcoEmitterLLVMIR1* pIEcoEmitterLLVMIR1 = 0;
    IEcoAST1SyntaxObject* pISyntaxObject = 0;

    /* Проверка и создание системного интерфейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem, (void **)&pISys);
        if (result != 0 && pISys == 0) {
            /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с аргументами командной строки */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoCommandArguments1, (void **)&pICmdArg);
    if (result != 0 || pICmdArg == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса для работы со строкой */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (void **)&pIStr);
    if (result != 0 || pIStr == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**)&pIMem);
    if (result != 0 || pIMem == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса для работы с журналом */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1, (void**) &pILog);
    if (result != 0|| pILog == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1FileAffiliate, (void**) &pIFileAffiliate);
    if (result != 0|| pIFileAffiliate == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }
    pILog->pVTbl->AddAffiliate(pILog, (IEcoLog1Affiliate*)pIFileAffiliate);
    pIFileAffiliate->pVTbl->Release(pIFileAffiliate);

    /* Получение интерфейса для работы с конечным автоматом */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoFSM1, 0, &IID_IEcoFSM1, (void **)&pIFSM);
    if (result != 0 || pIFSM == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

/******************************************************************************************** НАСТРОЙКА ********************************************************************************************/

    /* Получение интерфейса управление файлами */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoFileSystemManagement1, 0, &IID_IEcoFileManager1, (void**) &pIFileManager);
    if (result != 0 || pIFileManager == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса по работе со списком сканеров */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoStack1, 0, &IID_IEcoStack1, (void**) &pIScannerList);
    /* Проверка */
    if (result != 0 || pIScannerList == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса по работе со списком токенов */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoStack1, 0, &IID_IEcoStack1, (void**)&pITokenList);
    /* Проверка */
    if (result != 0 || pITokenList == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса по работе со списком исходных файлов */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**) &pISourceFiles);
    /* Проверка */
    if (result != 0 || pISourceFiles == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса по работе со списком путей поиска заголовочных файлов */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**) &pISearchHeaderPaths);
    /* Проверка */
    if (result != 0 || pISearchHeaderPaths == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Добавляем исходные файлы в список для компиляции под Windows */
    for(iArgIndex = 1; iArgIndex < pICmdArg->pVTbl->get_Count(pICmdArg); iArgIndex++) {
        pszSourceFileName = pICmdArg->pVTbl->get_Arg(pICmdArg, iArgIndex);
        /* Проверка ключа /OUT */
        if (pIStr->pVTbl->Compare(pIStr, pszSourceFileName, "/OUT") == 0) {
            iArgIndex++;
            if (iArgIndex < pICmdArg->pVTbl->get_Count(pICmdArg)) {
                pszOutputFileName = pICmdArg->pVTbl->get_Arg(pICmdArg, iArgIndex);
                printf("Output file: %s\n", pszOutputFileName);
            }
        }
            /* Проверка ключа /OUT */
        else if (pIStr->pVTbl->Compare(pIStr, pszSourceFileName, "/I") == 0) {
            iArgIndex++;
            if (iArgIndex < pICmdArg->pVTbl->get_Count(pICmdArg)) {
                pszSearchPath = pICmdArg->pVTbl->get_Arg(pICmdArg, iArgIndex);
                pISearchHeaderPaths->pVTbl->Add(pISearchHeaderPaths, pszSearchPath);
            }
        }
        else if (pIStr->pVTbl->Compare(pIStr, pszSourceFileName, "/USE_LLVM") == 0) {
            useLLVM = 1;
        }
        else if (pIStr->pVTbl->Compare(pIStr, pszSourceFileName, "/O") == 0) {
            if (iArgIndex + 1 < pICmdArg->pVTbl->get_Count(pICmdArg)) {
                pszSourceFileName = pICmdArg->pVTbl->get_Arg(pICmdArg, iArgIndex + 1);
                optLevel = pIStr->pVTbl->ConvertDecToInt(pIStr, pszSourceFileName);
                iArgIndex += 1;
            }
        }
        else {
            pISourceFiles->pVTbl->Add(pISourceFiles, pszSourceFileName);
        }
    }

    /* Получение интерфейса по работе со списком для объектных файлов */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**) &pIObjFiles);
    /* Проверка */
    if (result != 0 || pIObjFiles == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса по работе с грамматикой лексического разбора Lua 1.0 */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoBNF1, 0, &IID_IEcoBNF1, (void**) &pILuaGrammarLex);
    /* Проверка */
    if (result != 0 || pILuaGrammarLex == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* ВАРИАНТ 1: Формирование правил лексического анализа для Lua с помощью конечного автомата */
    pIFA = GetFAForLAOfLua(pIFSM);
    /* Вывод диагностической/отладочной информации */
    //OutputDiagnosticInfoOfFA(ECO_LANG_Lua, pILog, pIStr, pIFA);
    /* ИЛИ */
    /* ВАРИАНТ 2: Формирование правил лексического анализа для Lua с помощью регулярной грамматики */
    //pIRG = GetRGForLAOfLua();
    /* ИЛИ */
    /* ВАРИАНТ 3: Формирование правил лексического анализа для Lua с помощью регулярных выражений */
    //pIRE = GetREForLAOfLua();
    /* ИЛИ */
    /* ВАРИАНТ 4: Формирование правил лексического анализа для Lua с помощью BNF формы - описывающий как регулярную грамматику так и контекстно-свободную грамматику */
    //pIBNF = GetBNFForLAOfLua();


    /* Получение интерфейса по работе с лексическим анализом */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLexicalAnalyzer1, 0, &IID_IEcoLexicalAnalyzer1, (void**) &pILexer);
    /* Проверка */
    if (result != 0 || pILexer == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса по работе с препроцессором для Lua */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMacroProcessor1, 0, &IID_IEcoMacroProcessor1, (void**) &pILuaPreprocessor);
    /* Проверка */
    if (result != 0 || pILuaPreprocessor == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Настройка препроцессора для Lua */
    /* Настраиваем препроцессорную обработку удаления токенов не используемых в синтаксическом анализе */
    /* Удаление комментариев comment */
    pILuaPreprocessor->pVTbl->set_DeletitionCommandByTokenId(pILuaPreprocessor, 106);
    pILuaPreprocessor->pVTbl->set_DeletitionCommandByTokenId(pILuaPreprocessor, 120);
    /* Удаление новой строки new-line, но не внутри строк */
    pILuaPreprocessor->pVTbl->set_DeletitionCommandByTokenId(pILuaPreprocessor, 129);
    /* Удаление пробелов white-space и табуляций */
    pILuaPreprocessor->pVTbl->set_DeletitionCommandByTokenId(pILuaPreprocessor, 130);

    /* Получение интерфейса по работе с синтаксическим анализом */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoSyntaxAnalyzer1, 0, &IID_IEcoSyntaxAnalyzer1, (void**) &pISyntax);
    /* Проверка */
    if (result != 0 || pISyntax == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация алгоритма для анализа */
    pISyntax->pVTbl->RegisterAlgorithm(pISyntax, &CID_EcoLR1, "LR1");
    /* Устанавливаем алгоритм по умолчанию */
    pISyntax->pVTbl->set_DefaultAlgorithm(pISyntax, "LR1");

    /* Получение интерфейса по работе с грамматикой синтаксического разбора Lua */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoBNF1, 0, &IID_IEcoBNF1, (void**) &pILuaGrammarSyn);
    /* Проверка */
    if (result != 0 || pILuaGrammarSyn == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }


    /* Формирование правил синтаксического анализа для Lua */
    pILuaGrammarSyn = GetBNFForSAOfLua(pILuaGrammarSyn);
    /* Вывод диагностической/отладочной информации */
    OutputDiagnosticInfoOfBNF(ECO_LANG_LUA, pILog, pIStr, pILuaGrammarSyn);

    /* Получение интерфейса синтаксического разбора согласно заданным правилам для Lua */
    pILuaParser = pISyntax->pVTbl->get_Parser(pISyntax, pILuaGrammarSyn, 0);
    /* Получение интерфейса алгоритма синтаксического разбора */
    pIUnkAlgorithm = pILuaParser->pVTbl->get_Algorithm(pILuaParser);
    result = pIUnkAlgorithm->pVTbl->QueryInterface(pIUnkAlgorithm, &IID_IEcoParser1LRk, (void**) &pILRkAlgorithm);
    /* Проверка */
    if (result == 0 && pILRkAlgorithm != 0) {
        /* Вывод диагностической/отладочной информации */
        OutputDiagnosticInfoOfLRk(ECO_LANG_LUA, pILog, pIMem, pIStr, pILRkAlgorithm);
    }

    /* Получение интерфейса по работе с генератором кода */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCodeGenerator1, 0, &IID_IEcoCodeGenerator1, (void**) &pICodeGen);
    /* Проверка */
    if (result != 0 || pICodeGen == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация архитектуры для генерации кода */

    /* Регистрируем эмитер для архитектуры I80686 */
    pICodeGen->pVTbl->RegisterEmitter(pICodeGen, &CID_EcoEmitterI80686, ECO_CG_1_AT_I80686);

    /* Регистрация форматов для генерации */

    /* Регистрируем формат объектного файла PECOFF */
    pICodeGen->pVTbl->RegisterFileFormat(pICodeGen, &CID_EcoPECOFF1, ECO_CG_1_FT_PECOFF);

    /* Переключение на интерфейс синтаксического разбора для Lua */
    pIParser = pILuaParser;

/******************************************************************************************** КОМПИЛЯЦИЯ ********************************************************************************************/

    /* Цикл обработки файлов с исходным кодом */
    for (iSourceIndex = 0; iSourceIndex < pISourceFiles->pVTbl->Count(pISourceFiles); iSourceIndex++) {
        /* Получаем имя файла из списка */
        pszSourceFileName = (char_t*)pISourceFiles->pVTbl->Item(pISourceFiles, iSourceIndex);
        printf("Scan file %i: %s\n", iSourceIndex, pszSourceFileName);
        /* Извлекаем расширение файла из имени */
        pszSourceFileExt = pIStr->pVTbl->SearchLastCharacter(pIStr, pszSourceFileName, '.');
        /* Извлекаем имя без расширения */
        pszSourceName = pIStr->pVTbl->Substring(pIStr, pszSourceFileName, 0, pszSourceFileExt-pszSourceFileName );
        /* Проверяем тип расширения для выбора грамматики лексического анализа */
        if (pIStr->pVTbl->Compare(pIStr, pszSourceFileExt, ".lua") == 0) {
            /* Получение интерфейса лексического разбора согласно заданным правилам для Lua */
            //pIScanner = pILexer->new_FileScannerByBNF(pILexer, pILuaGrammarLex, pszSourceFileName);
            pIScanner = pILexer->pVTbl->new_FileScannerByFA(pILexer, pIFA, pszSourceFileName);
            /* Переключение на интерфейс обработчика препроцессора для Lua */
            /* Вывод диагностической/отладочной информации */
            //OutputDiagnosticInfoOfScanner(ECO_LANG_LUA, pILog, pIStr, pIScanner);
            pIPreProcessing = pILuaPreprocessor->pVTbl->get_Processing(pILuaPreprocessor);
            /* Переключение на интерфейс синтаксического разбора для Lua */
            pIParser = pILuaParser;
            iActiveLang = ECO_LANG_LUA;
        }
        else {
            /* Вывод об ошибки "Неподдерживаемое расширение файла!" и продолжаем обработку следующих файлов */
            continue;
        }
        /* Основной цикл чтения и обработки входной последовательности */
        do {
            char* token = 0;
            /* Лексический анализ */
            if (pITokenList->pVTbl->Count(pITokenList) == 0) {
                pIToken = pIScanner->pVTbl->Scan(pIScanner);
                if (pIToken == 0) {
                    /* Освобождение интерфейсов */
                    pIScanner->pVTbl->Release(pIScanner);
                    break;
                }
                token = pIToken->pVTbl->get_Description(pIToken);
            }
            else {
                pIToken = (IEcoLexicalAnalyzer1Token*)pITokenList->pVTbl->Pop(pITokenList);
            }
            /* Вывод диагностической/отладочной информации */
            OutputDiagnosticInfoOfScannerStep(iActiveLang, pILog, pIStr, pIToken);

            /* Если у входного потока отсутствуют токены, то проверяем в стеке предыдущий обработчик входной последовательности */
            if (pIToken == 0) {
                if (pIScannerList->pVTbl->Count(pIScannerList) > 0) {
                    /* Извлекаем из стека предыдущий обработчик */
                    pIScanner->pVTbl->Release(pIScanner);
                    pIScanner = (IEcoLexicalAnalyzer1Scanner*)pIScannerList->pVTbl->Pop(pIScannerList);
                    /* Возврат на прежний цикл обработки */
                    continue;
                }
                else {
                    /* Иначе переходим к обработке завершающего токена */
                    pIScanner->pVTbl->Release(pIScanner);
                    break;
                }
            }


            /* Препроцессорная обработка */
            pIPreResult = pIPreProcessing->pVTbl->InvokeByToken(pIPreProcessing, pIToken);

            uint16_t res = pIPreResult->pVTbl->get_Type(pIPreResult);
            /* Если результатом препроцессорной обработки является отбрасывание токенов входного потока, то токен удаляется */
            if (pIPreResult->pVTbl->get_Type(pIPreResult) == ECO_MACROPROCESSOR_TYPE_DELETITION) {
                /* Вывод информации препроцессорной обработки */
                pILog->pVTbl->Info(pILog, "Preprocessing - token deleted");
                /* Освобождение интерфейсов */
                pIPreResult->pVTbl->Release(pIPreResult);
                pIToken->pVTbl->Release(pIToken);
                /* Переход на начало цикла обработки */
                continue;
            }

            ///* Проверка режима обработки макроопределения */
            //if (pIPreProcessing->pVTbl->IsExpand(pIPreProcessing) == 1) {
            //	/* Если результатом препроцессорной обработки является макровызов (the expansion of macro invocations),
            //		  то читаем аргументы макро вызова */
            //	if (pIPreResult->pVTbl->get_Type(pIPreResult) == ECO_MACROPROCESSOR_TYPE_INVOCATION) {
            //		/* Переход на начало цикла обработки */
            //		pIPreResult->pVTbl->Release(pIPreResult);
            //		pIToken->pVTbl->Release(pIToken);
            //		continue;
            //	}
            //}

            /* Если результатом препроцессорной обработки является открытие нового входного потока,
                  то заносим текущий обработчик лексического разбора в стек для последующей обработки */
            if (pIPreResult->pVTbl->get_Type(pIPreResult) == ECO_MACROPROCESSOR_TYPE_INVOCATION && pIPreResult->pVTbl->get_Command(pIPreResult) == ECO_MACROPROCESSOR_COMMAND_INCLUDE) {
                /* Получаем имя файла из списка аргументов */
                pIMacroExpTokenList = (IEcoList1*)pIPreResult->pVTbl->get_Object(pIPreResult);
                if (pIMacroExpTokenList != 0) {
                    if (pIMacroExpTokenList->pVTbl->Count(pIMacroExpTokenList) > 1 && pIStr->pVTbl->Compare(pIStr, pIToken->pVTbl->get_Description(pIToken), "new-line") == 0) {
                        pIPreToken = (IEcoLexicalAnalyzer1Token*)pIMacroExpTokenList->pVTbl->Item(pIMacroExpTokenList, 1);
                        pszSourceFileName = pIPreToken->pVTbl->get_Lexeme(pIPreToken);
                        removeChar(pszSourceFileName, '\"');
                        /* Извлекаем расширение файла из имени */
                        pszSourceFileExt = pIStr->pVTbl->SearchLastCharacter(pIStr, pszSourceFileName, '.');
                        /* Проверяем тип расширения для выбора грамматики лексического анализа */
                        if (pIStr->pVTbl->Compare(pIStr, pszSourceFileExt, ".inc") == 0) {
                            /* Получение интерфейса лексического разбора согласно заданным правилам для ассемблера */
                            pIScanner = pILexer->pVTbl->new_FileScannerByBNF(pILexer, pIAsmGrammarLex, pszSourceFileName);
                        }
                        else if (pIStr->pVTbl->Compare(pIStr, pszSourceFileExt, ".h") == 0) {
                            pIScannerList->pVTbl->Push(pIScannerList, pIScanner);
                            /* Получение интерфейса лексического разбора согласно заданным правилам для Lua */
                            for (indexHeaders = 0; indexHeaders < pISearchHeaderPaths->pVTbl->Count(pISearchHeaderPaths); indexHeaders++) {
                                pszSearchFileName = pIStr->pVTbl->Clone(pIStr, (char_t*)pISearchHeaderPaths->pVTbl->Item(pISearchHeaderPaths, indexHeaders));
                                pszSearchFileName = pIStr->pVTbl->Append(pIStr, pszSearchFileName, "\\");
                                pszSearchFileName = pIStr->pVTbl->Append(pIStr, pszSearchFileName, pszSourceFileName);
                                pIScanner = pILexer->pVTbl->new_FileScannerByFA(pILexer, pIFA, pszSearchFileName);
                                if (pIScanner != 0) {
                                    break;
                                }
                            }
                            if (pIScanner == 0) {
                                pILog->pVTbl->ErrorFormat(pILog, "ERROR: cannot find file %s", pszSourceFileName);
                            }
                        }
                        else {
                            /* Вывод об ошибки и выход из цикла */
                            printf("ERROR! unknown file extension!");
                            pILog->pVTbl->ErrorFormat(pILog, "ERROR: %s - unknown file extension!", pszSourceFileExt);
                            break;
                        }
                    }
                    pIMacroExpTokenList = 0;
                }

                /* Проверка интерфейса на случай если файл не был найден */
                if (pIScanner != 0) {
                    /* Переход на новый цикл обработки */
                    continue;
                }
                else {
                    /* Вывод об ошибки и выход из цикла */
                    break;
                }
            } else if (COMP_CALL(pIPreResult, get_Command) == ECO_MACROPROCESSOR_COMMAND_DEFINE) {
                /* Получаем агрументы */
                pIMacroExpTokenList = (IEcoList1*)COMP_CALL(pIPreResult, get_Object);
                if (pIMacroExpTokenList != 0) {
                    if (COMP_CALL(pIMacroExpTokenList, Count) > 1 && COMP_CALL(pIStr, Compare, COMP_CALL(pIToken, get_Description), "new-line") == 0) {
                        pIPreToken = (IEcoLexicalAnalyzer1Token*)COMP_CALL(pIMacroExpTokenList, Item, 1);
                        pszMacroKey = COMP_CALL(pIPreToken, get_Lexeme);
                        // 2-nd arg is whitespace
                        pIPreToken = (IEcoLexicalAnalyzer1Token*)COMP_CALL(pIMacroExpTokenList, Item, 3);
                        pszMacroValue = COMP_CALL(pIPreToken, get_Lexeme);
                        COMP_CALL(pILuaPreprocessor, Predefine, pszMacroKey, pszMacroValue);
                    }
                    pszMacroKey = 0;
                    pszMacroValue = 0;
                    pIMacroExpTokenList = 0;
                }

                /* Проверка интерфейса на случай если файл не был найден */
                if (pIScanner != 0) {
                    /* Переход на новый цикл обработки */
                    continue;
                }
                else {
                    /* Вывод об ошибки и выход из цикла */
                    break;
                }
            } else if (COMP_CALL(pIPreResult, get_Command) == ECO_MACROPROCESSOR_COMMAND_UNDEF) {
                /* Получаем агрументы */
                pIMacroExpTokenList = (IEcoList1*)COMP_CALL(pIPreResult, get_Object);
                if (pIMacroExpTokenList != 0) {
                    if (COMP_CALL(pIMacroExpTokenList, Count) > 1 && COMP_CALL(pIStr, Compare, COMP_CALL(pIToken, get_Description), "new-line") == 0) {
                        pIPreToken = (IEcoLexicalAnalyzer1Token*)COMP_CALL(pIMacroExpTokenList, Item, 1);
                        pszMacroKey = COMP_CALL(pIPreToken, get_Lexeme);
                        COMP_CALL(pILuaPreprocessor, Undefine, pszMacroKey);
                    }
                    pIMacroExpTokenList = 0;
                }

                /* Проверка интерфейса на случай если файл не был найден */
                if (pIScanner != 0) {
                    /* Переход на новый цикл обработки */
                    continue;
                }
                else {
                    /* Вывод об ошибки и выход из цикла */
                    break;
                }
            } else if (COMP_CALL(pIPreResult, get_Command) == ECO_MACROPROCESSOR_COMMAND_LINE) {
                /* Получаем агрументы */
                pIMacroExpTokenList = (IEcoList1*)COMP_CALL(pIPreResult, get_Object);
                if (pIMacroExpTokenList != 0) {
                    if (COMP_CALL(pIMacroExpTokenList, Count) > 1 && COMP_CALL(pIStr, Compare, COMP_CALL(pIToken, get_Description), "new-line") == 0) {
                        pIPreToken = (IEcoLexicalAnalyzer1Token*)COMP_CALL(pIMacroExpTokenList, Item, 1);
                        pszMacroKey = COMP_CALL(pIPreToken, get_Lexeme);
                        COMP_CALL(pILuaPreprocessor, Predefine, "__LINE__", pszMacroKey);
                        // 2-nd arg is whitespace
                        if (COMP_CALL(pIMacroExpTokenList, Count) > 3) {
                            pIPreToken = (IEcoLexicalAnalyzer1Token*)COMP_CALL(pIMacroExpTokenList, Item, 3);
                            pszMacroValue = COMP_CALL(pIPreToken, get_Lexeme);
                            removeChar(pszMacroValue, '\"');
                            COMP_CALL(pILuaPreprocessor, Predefine, "__FILE__", pszMacroValue);
                        }
                    }
                    pszMacroKey = 0;
                    pszMacroValue = 0;
                    pIMacroExpTokenList = 0;
                }

                /* Проверка интерфейса на случай если файл не был найден */
                if (pIScanner != 0) {
                    /* Переход на новый цикл обработки */
                    continue;
                }
                else {
                    /* Вывод об ошибки и выход из цикла */
                    break;
                }
            } else if (COMP_CALL(pIPreResult, get_Command) == ECO_MACROPROCESSOR_COMMAND_ERROR) {
                /* Получаем агрументы */
                pIMacroExpTokenList = (IEcoList1*)COMP_CALL(pIPreResult, get_Object);
                if (pIMacroExpTokenList != 0) {
                    if (COMP_CALL(pIMacroExpTokenList, Count) > 1 && COMP_CALL(pIStr, Compare, COMP_CALL(pIToken, get_Description), "new-line") == 0) {
                        for (iArgIndex = 0; iArgIndex < COMP_CALL(pIMacroExpTokenList, Count); iArgIndex++) {
                            pIPreToken = (IEcoLexicalAnalyzer1Token*)COMP_CALL(pIMacroExpTokenList, Item, iArgIndex);
                            pszMacroKey = COMP_CALL(pIStr, Append, pszMacroKey, COMP_CALL(pIPreToken, get_Lexeme));
                        }
                        // add newline at the end
                        pszMacroKey = COMP_CALL(pIStr, Append, pszMacroKey, COMP_CALL(pIToken, get_Lexeme));
                        // take column by first #error argument now, not by directive
                        pIPreToken = (IEcoLexicalAnalyzer1Token*)COMP_CALL(pIMacroExpTokenList, Item, 0);
                        printf("%s:%d:%d: error: #error%s", COMP_CALL(pIPreToken, get_Source), COMP_CALL(pIPreToken, get_Line), COMP_CALL(pIPreToken, get_Column), pszMacroKey);
                        system("pause");
                        return -1;
                    }
                    pszMacroKey = 0;
                    pIMacroExpTokenList = 0;
                }

                // Required for processing more than oneword!!
                /* Проверка интерфейса на случай если файл не был найден */
                if (pIScanner != 0) {
                    /* Переход на новый цикл обработки */
                    continue;
                }
                else {
                    /* Вывод об ошибки и выход из цикла */
                    break;
                }
            } else if (COMP_CALL(pIPreResult, get_Command) == ECO_MACROPROCESSOR_COMMAND_IFDEF) {
                /* Получаем агрументы */
                pIMacroExpTokenList = (IEcoList1*)COMP_CALL(pIPreResult, get_Object);
                if (pIMacroExpTokenList != 0) {
                    if (COMP_CALL(pIMacroExpTokenList, Count) > 1 && COMP_CALL(pIStr, Compare, COMP_CALL(pIToken, get_Description), "new-line") == 0) {
                        pIPreToken = (IEcoLexicalAnalyzer1Token*)COMP_CALL(pIMacroExpTokenList, Item, 1);
                        pszMacroKey = COMP_CALL(pIPreToken, get_Lexeme);
                        if (COMP_CALL(pILuaPreprocessor, IsDefined, pszMacroKey)) {
                        } else {
                        }
                    }
                    pIMacroExpTokenList = 0;
                }

                /* Проверка интерфейса на случай если файл не был найден */
                if (pIScanner != 0) {
                    /* Переход на новый цикл обработки */
                    continue;
                }
                else {
                    /* Вывод об ошибки и выход из цикла */
                    break;
                }
            } else if (COMP_CALL(pIPreResult, get_Command) == ECO_MACROPROCESSOR_COMMAND_IFNDEF) {
                /* Получаем агрументы */
                pIMacroExpTokenList = (IEcoList1*)COMP_CALL(pIPreResult, get_Object);
                if (pIMacroExpTokenList != 0) {
                    if (COMP_CALL(pIMacroExpTokenList, Count) > 1 && COMP_CALL(pIStr, Compare, COMP_CALL(pIToken, get_Description), "new-line") == 0) {
                        pIPreToken = (IEcoLexicalAnalyzer1Token*)COMP_CALL(pIMacroExpTokenList, Item, 1);
                        pszMacroKey = COMP_CALL(pIPreToken, get_Lexeme);
                        if (!COMP_CALL(pILuaPreprocessor, IsDefined, pszMacroKey)) {
                        } else {
                        }
                    }
                    pIMacroExpTokenList = 0;
                }

                /* Проверка интерфейса на случай если файл не был найден */
                if (pIScanner != 0) {
                    /* Переход на новый цикл обработки */
                    continue;
                }
                else {
                    /* Вывод об ошибки и выход из цикла */
                    break;
                }
            } else if (COMP_CALL(pIPreResult, get_Command) == ECO_MACROPROCESSOR_COMMAND_ENDIF) {
                /* Получаем агрументы */
                pIMacroExpTokenList = (IEcoList1*)COMP_CALL(pIPreResult, get_Object);
                if (pIMacroExpTokenList != 0) {
                    if (COMP_CALL(pIMacroExpTokenList, Count) > 1 && COMP_CALL(pIStr, Compare, COMP_CALL(pIToken, get_Description), "new-line") == 0) {

                    }
                    pIMacroExpTokenList = 0;
                }

                /* Проверка интерфейса на случай если файл не был найден */
                if (pIScanner != 0) {
                    /* Переход на новый цикл обработки */
                    continue;
                }
                else {
                    /* Вывод об ошибки и выход из цикла */
                    break;
                }
            }

            /* Если результатом препроцессорной обработки является макрорасширение (macroexpansion) входного потока,
                 то возвращается один или несколько токенов исходного языка, как список (IEcoList1*) */
            if (pIPreResult->pVTbl->get_Type(pIPreResult) == ECO_MACROPROCESSOR_TYPE_EXPANSION) {
                pIMacroExpTokenList = (IEcoList1*)pIPreResult->pVTbl->get_Object(pIPreResult);
            }

            if (pIMacroExpTokenList != 0) {
                /* Токены перебираются в обратном порядке и добавляются в стек для последующего парсинга*/
                for (iTokenIndex = pIMacroExpTokenList->pVTbl->Count(pIMacroExpTokenList) - 1; iTokenIndex < pIMacroExpTokenList->pVTbl->Count(pIMacroExpTokenList); iTokenIndex--) {
                    pIToken = (IEcoLexicalAnalyzer1Token*)pIMacroExpTokenList->pVTbl->Item(pIMacroExpTokenList, iTokenIndex);
                    pITokenList->pVTbl->Push(pITokenList, pIToken);
                }
                pIMacroExpTokenList->pVTbl->Clear(pIMacroExpTokenList);
                pIMacroExpTokenList->pVTbl->Release(pIMacroExpTokenList);
                pIMacroExpTokenList = 0;
            }
                /* Если макро операции не выполнялись, то возвращается входной токен исходного языка, где pIToken == pIPreResult->get_Object(pIPreResult)*/
            else if (pIPreResult->pVTbl->get_Type(pIPreResult) == ECO_MACROPROCESSOR_TYPE_PASS) {
                /* Синтаксический анализ */
                while (1) {
                    if (pIStr->pVTbl->Compare(pIStr, pIStr->pVTbl->SearchLastCharacter(pIStr, pIToken->pVTbl->get_Source(pIToken), '.'), ".h") != 0 &&
                        pIStr->pVTbl->Compare(pIStr, pIToken->pVTbl->get_Description(pIToken), "None") == 0 || pIStr->pVTbl->Compare(pIStr, pIToken->pVTbl->get_Description(pIToken), "None") != 0) {
                        pIAction = pIParser->pVTbl->Parse(pIParser, pIToken);
                    }
                    OutputDiagnosticInfoOfParserStep(iActiveLang, pILog, pIStr, pIAction);
                    if (pIAction == 0) {
                        /* Вывод об ошибки и выход из цикла */
                        printf("ERROR! Null Action!\n");
                        break;
                    }
                    if (pIAction->pVTbl->get_Type(pIAction) != ECO_ACTION_PROCESSING_TYPE_REDUCE) {
                        pIAction->pVTbl->Release(pIAction);
                        break;
                    }
                    pIAction->pVTbl->Release(pIAction);
                }
                pIToken->pVTbl->Release(pIToken);
                /* Вывод диагностической/отладочной информации */
            }

            pIPreResult->pVTbl->Release(pIPreResult);

        } while (1);

        /* Получение интерфейса по работе с абстрактным синтаксическим деревом */
        pIAST = pIParser->pVTbl->get_AST(pIParser);
        OutputDiagnosticInfoOfAST(ECO_LANG_LUA, pILog, pIMem, pIStr, pIAST);

        /* Формирование имени объектного файла */
        pszObjName = pIStr->pVTbl->Append(pIStr, pszObjName, pszSourceName);
        pszObjName = pIStr->pVTbl->Append(pIStr, pszObjName, ".obj");

//        if (useLLVM) {
//            pISyntaxObject = (IEcoAST1SyntaxObject*)pIAST->pVTbl->get_TranslationUnit(pIAST);
//            if (pISyntaxObject == 0) {
//                goto Release;
//            }
//
//            result = pIEcoEmitterLLVMIR1->pVTbl->EmitCode(pIEcoEmitterLLVMIR1, pISyntaxObject);
//            if (result != 0) {
//                goto Release;
//            }
//
//            pszIRName = pIStr->pVTbl->Append(pIStr, pszIRName, pszSourceName);
//            pszIRName = pIStr->pVTbl->Append(pIStr, pszIRName, ".ll");
//            result = pIEcoEmitterLLVMIR1->pVTbl->WriteIRFile(pIEcoEmitterLLVMIR1, pszIRName);
//            result = pIEcoEmitterLLVMIR1->pVTbl->WriteObjectFile(pIEcoEmitterLLVMIR1, pszObjName, (EmitterLLVMIROptLevel)optLevel);
//        }
//        else {
            /* Генерация кода архитектуры I80686 */
            result = pICodeGen->pVTbl->Generate(pICodeGen, pIAST, ECO_CG_1_AT_I80686, 0, &pIEmitter);

            /* Запись кода в объектный файл формата PECOFF */
            result = pICodeGen->pVTbl->WriteObjectFile(pICodeGen, pIEmitter, ECO_CG_1_FT_PECOFF, 0, pszObjName);
//        }`

        /* Добавляем объектный файл в список связывания */
        pIObjFiles->pVTbl->Add(pIObjFiles, pszObjName);
        pIStr->pVTbl->Free(pIStr, pszSourceName);
    }

/******************************************************************************************** СВЯЗЫВАНИЕ ********************************************************************************************/

        /* Получение интерфейса по работе со связыванием объектного кода */
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLinker1, 0, &IID_IEcoLinker1, (void**) &pILinker);
        /* Проверка */
        if (result != 0 || pILinker == 0) {
            /* Освобождение в случае ошибки */
            goto Release;
        }

        /* Регистрация форматов для связывания */

        /* Регистрация Microsoft Portable Executable and Common Object File Format */
        pILinker->pVTbl->RegisterFileFormat(pILinker, &CID_EcoPECOFF1, ECO_L_1_FT_PECOFF);

        /* Связывание */
        printf("Linker - create EXE file for Windows platform\n");
        pILog->pVTbl->Info(pILog, "Linker - create EXE file for Windows platform");

        result = pILinker->pVTbl->LinkToFile(pILinker, ECO_L_1_FT_PECOFF, 0, pIObjFiles, 0, ECO_L_1_FT_PECOFF, pszOutputFileName);

    pICmdArg->pVTbl->Release(pICmdArg);

Release:

    /* Освобождение интерфейса код-генератора */
    if (pICodeGen != 0) {
        pICodeGen->pVTbl->Release(pICodeGen);
    }

    /* Освобождение интерфейса парсера */
    if (pILRkAlgorithm != 0) {
        pILRkAlgorithm->pVTbl->Release(pILRkAlgorithm);
    }
    if (pILuaParser != 0) {
        // pILuaParser->pVTbl->Release(pILuaParser);
    }

    /* Освобождение интерфейса для работы с грамматикой С89 */
    if (pILuaGrammarSyn != 0) {
        pILuaGrammarSyn->pVTbl->Release(pILuaGrammarSyn);
    }

    /* Освобождение интерфейся для работы с синтаксическим анализатором */
    if (pISyntax != 0) {
        pISyntax->pVTbl->Release(pISyntax);
    }

    /* Получение интерфейса для работы с препроцессингом */
    if (pILuaPreprocessor != 0) {
        pILuaPreprocessor->pVTbl->Release(pILuaPreprocessor);
    }

    /* Освобождение интерфейса для работы с лексическим анализатором */
    if (pILexer != 0) {
        pILexer->pVTbl->Release(pILexer);
    }

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение интерфейса конечного автомата */
    if (pIFA != 0) {
        pIFA->pVTbl->Release(pIFA);
    }

    /* интерфейса по работе с грамматикой лексического разбора Lua */
    if (pILuaGrammarLex != 0) {
        pILuaGrammarLex->pVTbl->Release(pILuaGrammarLex);
    }

    /* Освобождение интерфейса по работе со списком  для объектных файлов */
    if (pIObjFiles != 0) {
        pIObjFiles->pVTbl->Release(pIObjFiles);
    }

    /* Освобождение интерфейса по работе со списком исходных файлов */
    if (pISourceFiles != 0) {
        pISourceFiles->pVTbl->Clear(pISourceFiles);
        pISourceFiles->pVTbl->Release(pISourceFiles);
    }

    /* Освобождение интерфейса со списком токенов */
    if (pITokenList != 0) {
        pITokenList->pVTbl->Clear(pITokenList);
        pITokenList->pVTbl->Release(pITokenList);
    }

    /* Освобождение интерфейса по работе со списком сканеров */
    if (pIScannerList != 0) {
        pIScannerList->pVTbl->Clear(pIScannerList);
        pIScannerList->pVTbl->Release(pIScannerList);
    }

    /* Освобождение интерфейса для работы с файлами */
    if (pIFileManager != 0) {
        pIFileManager->pVTbl->Release(pIFileManager);
    }

    /* Освобождение интерфейса для работы с конечным автоматом */
    if (pIFSM != 0) {
        pIFSM->pVTbl->Release(pIFSM);
    }

    /* Освобождение интерфейса для работы с журналом*/
    if (pILog != 0) {
        pILog->pVTbl->Release(pILog);
    }

    /* Освобождение интерфейса для работы со строкой */
    if (pIStr != 0) {
        pIStr->pVTbl->Release(pIStr);
    }

    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}
