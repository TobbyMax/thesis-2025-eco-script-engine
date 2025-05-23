/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoSE1Lua
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoSE1Lua
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_SCRIPT_ENGINE_1_LUA_H__
#define __C_ECO_SCRIPT_ENGINE_1_LUA_H__

#include "IEcoString1.h"
#include "IEcoSE1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoLexicalAnalyzer1.h"
#include "IdEcoSyntaxAnalyzer1.h"
#include "IdEcoLR1.h"
#include "IdEcoAST1.h"
#include "IdEcoBNF1.h"
#include "IdEcoMacroProcessor1.h"
#include "IdEcoCodeGenerator1.h"
#include "IdEcoFSM1.h"
#include "IdEcoLog1.h"
#include "IdEcoList1.h"
#include "IEcoLog1FileAffiliate.h"


typedef struct CEcoSE1Lua_8E62028C {

    /* Таблица функций интерфейса IEcoSE1 */
    IEcoSE1LuaVTbl* m_pVTblIEcoSE1Lua;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    IEcoSE1ScriptContext* m_pIScriptContext;
    IEcoFSM1StateMachine* m_pIFA;
    IEcoBNF1* m_pIBNF;
    IEcoParser1LRk* m_pILRkAlgorithm;
    IEcoLexicalAnalyzer1* m_pILexer;
    IEcoSyntaxAnalyzer1* m_pISyntaxAnalyzer;
    IEcoSyntaxAnalyzer1Parser* m_pIParser;
    IEcoLog1* m_pILog;
    IEcoAST1* m_pIAST;
    IEcoFileManager1* m_pIFileManager;
    IEcoStack1* m_pITokenList;
    IEcoMacroProcessor1* m_pIPreprocessor;
    IEcoCodeGenerator1* m_pICodeGenerator;
    IEcoString1* m_pIString;

} CEcoSE1Lua_8E62028C, *CEcoSE1Lua_8E62028CPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoSE1Lua_8E62028C(/*in*/ IEcoSE1LuaPtr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoSE1Lua_8E62028C(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoSE1LuaPtr_t* ppIEcoSE1Lua);
/* Удаление */
void ECOCALLMETHOD deleteCEcoSE1Lua_8E62028C(/* in */ IEcoSE1LuaPtr_t pIEcoSE1Lua);

#endif /* __C_ECO_SCRIPT_ENGINE_1_LUA_H__ */
