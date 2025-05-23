/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoSE1Lua_8E62028C
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoSE1Lua_8E62028C
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IdEcoString1.h"
#include "IdEcoStack1.h"
#include "CEcoSE1LuaGrammar.h"
#include "CEcoSE1LuaContext.h"
#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoSE1Lua.h"

#define COMP_CALL(comp, method, ...) comp->pVTbl->method(comp, __VA_ARGS__)

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoSE1
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoSE1Lua_8E62028C_QueryInterface(/* in */ IEcoSE1LuaPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoSE1Lua_8E62028C* pCMe = (CEcoSE1Lua_8E62028C*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoSE1Lua) ) {
        *ppv = &pCMe->m_pVTblIEcoSE1Lua;
        pCMe->m_pVTblIEcoSE1Lua->AddRef((IEcoSE1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoSE1Lua;
        pCMe->m_pVTblIEcoSE1Lua->AddRef((IEcoSE1*)pCMe);
    }
    else {
        *ppv = 0;
        return ERR_ECO_NOINTERFACE;
    }
    return ERR_ECO_SUCCESES;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoSE1
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoSE1Lua_8E62028C_AddRef(/* in */ IEcoSE1LuaPtr_t me) {
    CEcoSE1Lua_8E62028C* pCMe = (CEcoSE1Lua_8E62028C*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoSE1
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoSE1Lua_8E62028C_Release(/* in */ IEcoSE1LuaPtr_t me) {
    CEcoSE1Lua_8E62028C* pCMe = (CEcoSE1Lua_8E62028C*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoSE1Lua_8E62028C((IEcoSE1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция EvalString
 * </сводка>
 *
 * <описание>
 *   Функция для выполнения Lua-скрипта, переданного в виде строки.
 * </описание>
 *
 */
static int32_t ECOCALLMETHOD CEcoSE1Lua_8E62028C_EvalString(/* in */ IEcoSE1LuaPtr_t me, /* in */ const char* script, void** result) {
    CEcoSE1Lua_8E62028C* pCMe = (CEcoSE1Lua_8E62028C*)me;

    /* Проверка указателей */
    if (me == 0 || script == 0) {
        return ERR_ECO_POINTER;
    }

    /* Выполнение Lua-скрипта */
    /* TODO: Реализовать выполнение Lua-скрипта */
    return 0;
}

/*
 * <сводка>
 *   Функция EvalFile
 * </сводка>
 *
 * <описание>
 *   Функция для выполнения Lua-скрипта, переданного в виде файла.
 * </описание>
 *
 */
static int32_t ECOCALLMETHOD CEcoSE1Lua_8E62028C_EvalFile(/* in */ IEcoSE1LuaPtr_t me, /* in */ const char* path, void** result) {
    CEcoSE1Lua_8E62028C* pCMe = (CEcoSE1Lua_8E62028C*)me;
    IEcoLexicalAnalyzer1Scanner* pIScanner = 0;
    IEcoMacroProcessor1Processing* pIPreProcessing = 0;
    IEcoMacroProcessor1Result* pIPreResult = 0;
    IEcoSyntaxAnalyzer1Parser* pIParser;
    IEcoLexicalAnalyzer1Token* pIToken;
    IEcoParser1Action* pIAction;
    IEcoAST1* pIAST;
    char* fileExt = 0;

    /* Проверка указателей */
    if (me == 0 || path == 0) {
        return ERR_ECO_POINTER;
    }

    /* Выполнение Lua-скрипта */
        /* Извлекаем расширение файла из имени */
        fileExt =pCMe->m_pIString->pVTbl->SearchLastCharacter(pCMe->m_pIString, path, '.');
        /* Проверяем тип расширения для выбора грамматики лексического анализа */
        if (pCMe->m_pIString->pVTbl->Compare(pCMe->m_pIString, fileExt, ".lua") == 0) {;
            pIScanner = pCMe->m_pILexer->pVTbl->new_FileScannerByFA(pCMe->m_pILexer, pCMe->m_pIFA, path);
            pIPreProcessing = pCMe->m_pIPreprocessor->pVTbl->get_Processing(pCMe->m_pIPreprocessor);
            /* Переключение на интерфейс синтаксического разбора для Lua */
            pIParser = pCMe->m_pIParser;
        }
        else {
            /* Ошибка "Неподдерживаемое расширение файла!" */
            return -1;
        }
        /* Основной цикл чтения и обработки входной последовательности */
        do {
            char* token = 0;
            /* Лексический анализ */
            if (pCMe->m_pITokenList->pVTbl->Count(pCMe->m_pITokenList) == 0) {
                pIToken = pIScanner->pVTbl->Scan(pIScanner);
                if (pIToken == 0) {
                    /* Освобождение интерфейсов */
                    pIScanner->pVTbl->Release(pIScanner);
                    break;
                }
                token = pIToken->pVTbl->get_Description(pIToken);
            }
            else {
                pIToken = (IEcoLexicalAnalyzer1Token*)pCMe->m_pITokenList->pVTbl->Pop(pCMe->m_pITokenList);
            }

            if (pIToken == 0) {
                pIScanner->pVTbl->Release(pIScanner);
                break;
            }

            /* Препроцессорная обработка */
            pIPreResult = pIPreProcessing->pVTbl->InvokeByToken(pIPreProcessing, pIToken);

            uint16_t res = pIPreResult->pVTbl->get_Type(pIPreResult);
            /* Если результатом препроцессорной обработки является отбрасывание токенов входного потока, то токен удаляется */
            if (pIPreResult->pVTbl->get_Type(pIPreResult) == ECO_MACROPROCESSOR_TYPE_DELETITION) {
                /* Вывод информации препроцессорной обработки */
//                pCMe->m_pILog->pVTbl->Info( pCMe->m_pILog, "Preprocessing - token deleted");
                /* Освобождение интерфейсов */
                pIPreResult->pVTbl->Release(pIPreResult);
                pIToken->pVTbl->Release(pIToken);
                /* Переход на начало цикла обработки */
                continue;
            }

            /* Если макро операции не выполнялись, то возвращается входной токен исходного языка, где pIToken == pIPreResult->get_Object(pIPreResult)*/
            else if (pIPreResult->pVTbl->get_Type(pIPreResult) == ECO_MACROPROCESSOR_TYPE_PASS) {
                /* Синтаксический анализ */
                while (1) {
                    if (pCMe->m_pIString->pVTbl->Compare(pCMe->m_pIString, pCMe->m_pIString->pVTbl->SearchLastCharacter(pCMe->m_pIString, pIToken->pVTbl->get_Source(pIToken), '.'), ".h") != 0 &&
                        pCMe->m_pIString->pVTbl->Compare(pCMe->m_pIString, pIToken->pVTbl->get_Description(pIToken), "None") == 0 || pCMe->m_pIString->pVTbl->Compare(pIStr, pIToken->pVTbl->get_Description(pIToken), "None") != 0) {
                        pIAction = pIParser->pVTbl->Parse(pIParser, pIToken);
                    }
                    if (pIAction == 0) {
                        /* Вывод об ошибки и выход из цикла */
//                        printf("ERROR! Null Action!\n");
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

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Get
 * </сводка>
 *
 * <описание>
 *   Функция для получения значения по ключу.
 * </описание>
 *
 */
static void* ECOCALLMETHOD CEcoSE1Lua_8E62028C_Get(/* in */IEcoSE1LuaPtr_t me, /* in */const char* key) {
    CEcoSE1Lua_8E62028C* pCMe = (CEcoSE1Lua_8E62028C*)me;

    /* Проверка указателей */
    if (me == 0 || key == 0) {
        return 0;
    }

    /* Получение значения по ключу */
    return pCMe->m_pIScriptContext->pVTbl->get_Attribute(pCMe->m_pIScriptContext, key, ECO_SCRIPT_ENGINE_1_SCOPE_ENGINE);
}

/*
 *
 * <сводка>
 *   Функция Put
 * </сводка>
 *
 * <описание>
 *   Функция для установки значения по ключу.
 * </описание>
 *
 */
static int32_t ECOCALLMETHOD CEcoSE1Lua_8E62028C_Put(/* in */IEcoSE1LuaPtr_t me, /* in */const char* key, /* in */void* value) {
    CEcoSE1Lua_8E62028C* pCMe = (CEcoSE1Lua_8E62028C*)me;

    /* Проверка указателей */
    if (me == 0 || key == 0 || value == 0) {
        return ERR_ECO_POINTER;
    }

    /* Установка значения по ключу */
    pCMe->m_pIScriptContext->pVTbl->set_Attribute(pCMe->m_pIScriptContext, key, value, ECO_SCRIPT_ENGINE_1_SCOPE_ENGINE);
    return 0;
}

/*
 * <сводка>
 *   Функция get_Bindings
 * </сводка>
 *
 * <описание>
 *   Функция для получения привязок.
 * </описание>
 *
 */
static IEcoMap1* ECOCALLMETHOD CEcoSE1Lua_8E62028C_get_Bindings(/* in */ IEcoSE1LuaPtr_t me, int32_t scope) {
    CEcoSE1Lua_8E62028C* pCMe = (CEcoSE1Lua_8E62028C*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0;
    }

    /* Получение привязок */
    return pCMe->m_pIScriptContext->pVTbl->get_Bindings(pCMe->m_pIScriptContext, scope);
}

/*
 * <сводка>
 *   Функция set_Bindings
 * </сводка>
 *
 * <описание>
 *   Функция для установки привязок.
 * </описание>
 *
 */
static int32_t ECOCALLMETHOD CEcoSE1Lua_8E62028C_set_Bindings(/* in */ IEcoSE1LuaPtr_t me, IEcoMap1* pBindingsMap, int32_t scope) {
    CEcoSE1Lua_8E62028C *pCMe = (CEcoSE1Lua_8E62028C *) me;
    IEcoMap1* pBindings = 0;

    /* Проверка указателей */
    if (me == 0 || pBindingsMap == 0) {
        return ERR_ECO_POINTER;
    }

    /* Установка привязок */
    return pCMe->m_pIScriptContext->pVTbl->set_Bindings(pCMe->m_pIScriptContext, pBindingsMap, scope);
}

/*
 * <сводка>
 *   Функция get_Context
 * </сводка>
 *
 * <описание>
 *   Функция для получения контекста скрипта.
 * </описание>
 *
 */
static IEcoSE1ScriptContext* ECOCALLMETHOD CEcoSE1Lua_8E62028C_get_Context(/* in */ IEcoSE1LuaPtr_t me) {
    CEcoSE1Lua_8E62028C* pCMe = (CEcoSE1Lua_8E62028C*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0;
    }

    /* Возврат контекста скрипта */
    return pCMe->m_pIScriptContext;
}

/*
 * <сводка>
 *   Функция set_Context
 * </сводка>
 *
 * <описание>
 *   Функция для установки контекста скрипта.
 * </описание>
 *
 */
static void ECOCALLMETHOD CEcoSE1Lua_8E62028C_set_Context(/* in */ IEcoSE1LuaPtr_t me, /* in */ IEcoSE1ScriptContext* pContext) {
    CEcoSE1Lua_8E62028C* pCMe = (CEcoSE1Lua_8E62028C*)me;

    /* Проверка указателей */
    if (me == 0 || pContext == 0) {
        return; /* ERR_ECO_POINTER */
    }
    if (pCMe->m_pIScriptContext != 0) {
        /* Освобождение предыдущего контекста */
        pCMe->m_pIScriptContext->pVTbl->Release(pCMe->m_pIScriptContext);
    }

    /* Установка контекста скрипта */
    pContext->pVTbl->AddRef(pContext);
    pCMe->m_pIScriptContext = pContext;
}


/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCEcoSE1Lua_8E62028C(/*in*/ IEcoSE1LuaPtr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CEcoSE1Lua_8E62028C* pCMe = (CEcoSE1Lua_8E62028C*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = ERR_ECO_POINTER;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;



    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return result;
}

/* Create Virtual Table IEcoSE1 */
IEcoSE1LuaVTbl g_x3BBB11F275CF432AA54845F3DBFCAAB5VTbl_8E62028C = {
    CEcoSE1Lua_8E62028C_QueryInterface,
    CEcoSE1Lua_8E62028C_AddRef,
    CEcoSE1Lua_8E62028C_Release,
    CEcoSE1Lua_8E62028C_EvalString,
    CEcoSE1Lua_8E62028C_EvalFile,
    CEcoSE1Lua_8E62028C_Get,
    CEcoSE1Lua_8E62028C_Put,
    CEcoSE1Lua_8E62028C_get_Bindings,
    CEcoSE1Lua_8E62028C_set_Bindings,
    CEcoSE1Lua_8E62028C_get_Context,
    CEcoSE1Lua_8E62028C_set_Context
};




/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCEcoSE1Lua_8E62028C(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoSE1LuaPtr_t* ppIEcoSE1Lua) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoSE1Lua_8E62028C* pCMe = 0;
    IEcoLog1FileAffiliate* pIFileAffiliate = 0;
    IEcoUnknown* pIUnkAlgorithm;
    IEcoFSM1* pIFSM = 0;
    IEcoBNF1* pILuaGrammarSyn = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;

    /* Проверка указателей */
    if (ppIEcoSE1Lua == 0 || pIUnkSystem == 0) {
        return result; /* ERR_ECO_POINTER */
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);
    /* Проверка */
    if (result != 0 || pISys == 0) {
        return ERR_ECO_NOSYSTEM;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    /* Проверка */
    if (result != 0 || pIBus == 0) {
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_NOBUS;
    }

    /* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);
    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение в случае ошибки */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_GET_MEMORY_ALLOCATOR;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoSE1Lua_8E62028C*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoSE1Lua_8E62028C));
    if (pCMe == 0) {
        /* Освобождение в случае ошибки */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_OUTOFMEMORY;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoSE1 */
    pCMe->m_pVTblIEcoSE1Lua = &g_x3BBB11F275CF432AA54845F3DBFCAAB5VTbl_8E62028C;

    /* Создание контекста скрипта */
    result = createCEcoSE1LuaContext_8E62028C((IEcoUnknown*)pCMe->m_pISys, 0, &pCMe->m_pIScriptContext);
    if (result != 0 || pCMe->m_pIScriptContext == 0) {
        deleteCEcoSE1Lua_8E62028C((IEcoSE1*)pCMe);
    }

    /* Получение интерфейса для работы со строкой */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (void **)&pCMe->m_pIString);
    if (result != 0 || pCMe->m_pIString == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoSE1Lua_8E62028C((IEcoSE1*)pCMe);
    }

    /* Получение интерфейса для работы с журналом */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1, (void**) &pCMe->m_pILog);
    if (result != 0|| pCMe->m_pILog == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        deleteCEcoSE1Lua_8E62028C((IEcoSE1*)pCMe);
    }

    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1FileAffiliate, (void**) &pIFileAffiliate);
    if (result != 0|| pIFileAffiliate == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        deleteCEcoSE1Lua_8E62028C((IEcoSE1*)pCMe);
    }
    pCMe->m_pILog->pVTbl->AddAffiliate(pCMe->m_pILog, (IEcoLog1Affiliate*)pIFileAffiliate);
    pIFileAffiliate->pVTbl->Release(pIFileAffiliate);

    /* Получение интерфейса для работы с конечным автоматом */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoFSM1, 0, &IID_IEcoFSM1, (void **)&pIFSM);
    if (result != 0 || pIFSM == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        deleteCEcoSE1Lua_8E62028C((IEcoSE1*)pCMe);
    }
    pCMe->m_pIFA = GetFAForLAOfLua(pIFSM);

    /* Получение интерфейса управление файлами */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoFileSystemManagement1, 0, &IID_IEcoFileManager1, (void**) &pCMe->m_pIFileManager);
    if (result != 0 || pCMe->m_pIFileManager == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoSE1Lua_8E62028C((IEcoSE1*)pCMe);
    }

    /* Получение интерфейса по работе со списком токенов */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoStack1, 0, &IID_IEcoStack1, (void**)&pCMe->m_pITokenList);
    /* Проверка */
    if (result != 0 || pCMe->m_pITokenList == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoSE1Lua_8E62028C((IEcoSE1*)pCMe);
    }

    /* Получение интерфейса по работе с лексическим анализом */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLexicalAnalyzer1, 0, &IID_IEcoLexicalAnalyzer1, (void**) &pCMe->m_pILexer);
    /* Проверка */
    if (result != 0 || pCMe->m_pILexer == 0) {
        /* Освобождение в случае ошибки */
       deleteCEcoSE1Lua_8E62028C((IEcoSE1*)pCMe);
    }

    /* Получение интерфейса по работе с препроцессором для Lua */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMacroProcessor1, 0, &IID_IEcoMacroProcessor1, (void**) &pCMe->m_pIPreprocessor);
    /* Проверка */
    if (result != 0 || pCMe->m_pIPreprocessor == 0) {
        /* Освобождение в случае ошибки */
       deleteCEcoSE1Lua_8E62028C((IEcoSE1*)pCMe);
    }

    /* Настраиваем препроцессорную обработку удаления токенов не используемых в синтаксическом анализе */
    /* Удаление комментариев comment */
    pCMe->m_pIPreprocessor->pVTbl->set_DeletitionCommandByTokenId(pCMe->m_pIPreprocessor, 106);
    pCMe->m_pIPreprocessor->pVTbl->set_DeletitionCommandByTokenId(pCMe->m_pIPreprocessor, 120);
    /* Удаление новой строки new-line, но не внутри строк */
    pCMe->m_pIPreprocessor->pVTbl->set_DeletitionCommandByTokenId(pCMe->m_pIPreprocessor, 129);
    /* Удаление пробелов white-space и табуляций */
    pCMe->m_pIPreprocessor->pVTbl->set_DeletitionCommandByTokenId(pCMe->m_pIPreprocessor, 130);

    /* Получение интерфейса по работе с синтаксическим анализом */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoSyntaxAnalyzer1, 0, &IID_IEcoSyntaxAnalyzer1, (void**) &pCMe->m_pISyntaxAnalyzer);
    /* Проверка */
    if (result != 0 || pCMe->m_pISyntaxAnalyzer == 0) {
        /* Освобождение в случае ошибки */
       deleteCEcoSE1Lua_8E62028C((IEcoSE1*)pCMe);
    }

    /* Регистрация алгоритма для анализа */
    pCMe->m_pISyntaxAnalyzer->pVTbl->RegisterAlgorithm(pCMe->m_pISyntaxAnalyzer, &CID_EcoLR1, "LR1");
    /* Устанавливаем алгоритм по умолчанию */
    pCMe->m_pISyntaxAnalyzer->pVTbl->set_DefaultAlgorithm(pCMe->m_pISyntaxAnalyzer, "LR1");

    /* Получение интерфейса по работе с грамматикой синтаксического разбора Lua */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoBNF1, 0, &IID_IEcoBNF1, (void**) &pILuaGrammarSyn);
    /* Проверка */
    if (result != 0 || pILuaGrammarSyn == 0) {
        /* Освобождение в случае ошибки */
       deleteCEcoSE1Lua_8E62028C((IEcoSE1*)pCMe);
    }

    /* Формирование правил синтаксического анализа для Lua */
    pILuaGrammarSyn = GetBNFForSAOfLua(pILuaGrammarSyn);

    /* Получение интерфейса синтаксического разбора согласно заданным правилам для Lua */
    pCMe->m_pIParser = pCMe->m_pISyntaxAnalyzer->pVTbl->get_Parser(pCMe->m_pISyntaxAnalyzer, pILuaGrammarSyn, 0);
    /* Получение интерфейса алгоритма синтаксического разбора */
    pIUnkAlgorithm = pCMe->m_pIParser->pVTbl->get_Algorithm(pCMe->m_pIParser);
    result = pIUnkAlgorithm->pVTbl->QueryInterface(pIUnkAlgorithm, &IID_IEcoParser1LRk, (void**) &pCMe->m_pILRkAlgorithm);
    /* Проверка */
    if (result != 0 || pCMe->m_pILRkAlgorithm == 0) {
        deleteCEcoSE1Lua_8E62028C((IEcoSE1*)pCMe);
    }

    /* Получение интерфейса по работе с генератором кода */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCodeGenerator1, 0, &IID_IEcoCodeGenerator1, (void**) &pCMe->m_pICodeGenerator);
    /* Проверка */
    if (result != 0 || pCMe->m_pICodeGenerator == 0) {
        /* Освобождение в случае ошибки */
       deleteCEcoSE1Lua_8E62028C((IEcoSE1*)pCMe);
    }

    /* Возврат указателя на интерфейс */
    *ppIEcoSE1Lua = (IEcoSE1*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return ERR_ECO_SUCCESES;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCEcoSE1Lua_8E62028C(/* in */ IEcoSE1LuaPtr_t pIEcoSE1Lua) {
    CEcoSE1Lua_8E62028C* pCMe = (CEcoSE1Lua_8E62028C*)pIEcoSE1Lua;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoSE1Lua != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_pIScriptContext != 0 ) {
            pCMe->m_pIScriptContext->pVTbl->Release(pCMe->m_pIScriptContext);
        }
        if ( pCMe->m_pILog != 0 ) {
            pCMe->m_pILog->pVTbl->Release(pCMe->m_pILog);
        }
        if ( pCMe->m_pIString != 0 ) {
            pCMe->m_pIString->pVTbl->Release(pCMe->m_pIString);
        }
        if ( pCMe->m_pIFA != 0 ) {
            pCMe->m_pIFA->pVTbl->Release(pCMe->m_pIFA);
        }
        if ( pCMe->m_pIFileManager != 0 ) {
            pCMe->m_pIFileManager->pVTbl->Release(pCMe->m_pIFileManager);
        }
        if ( pCMe->m_pITokenList != 0 ) {
            pCMe->m_pITokenList->pVTbl->Release(pCMe->m_pITokenList);
        }
        if ( pCMe->m_pILexer != 0 ) {
            pCMe->m_pILexer->pVTbl->Release(pCMe->m_pILexer);
        }
        if ( pCMe->m_pIPreprocessor != 0 ) {
            pCMe->m_pIPreprocessor->pVTbl->Release(pCMe->m_pIPreprocessor);
        }
        if ( pCMe->m_pISyntaxAnalyzer != 0 ) {
            pCMe->m_pISyntaxAnalyzer->pVTbl->Release(pCMe->m_pISyntaxAnalyzer);
        }
        if ( pCMe->m_pIParser != 0 ) {
            pCMe->m_pIParser->pVTbl->Release(pCMe->m_pIParser);
        }
        if ( pCMe->m_pILRkAlgorithm != 0 ) {
            pCMe->m_pILRkAlgorithm->pVTbl->Release(pCMe->m_pILRkAlgorithm);
        }
        if ( pCMe->m_pICodeGenerator != 0 ) {
            pCMe->m_pICodeGenerator->pVTbl->Release(pCMe->m_pICodeGenerator);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
