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

#ifndef __C_ECO_SCRIPT_ENGINE_1_LUA_CONTEXT_H__
#define __C_ECO_SCRIPT_ENGINE_1_LUA_CONTEXT_H__

#include "IEcoSE1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoSE1LuaContext_8E62028C {

    /* Таблица функций интерфейса IEcoSE1 */
    IEcoSE1ScriptContext* m_pVTblIEcoSE1ScriptContext;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Интерфейсная шина */
    IEcoInterfaceBus1* m_pIBus;

    /* Данные экземпляра */
    uint32_t* m_Id;
    /* map[EcoMap1]EcoMap1 - map наборов атрибутов по id scope */
    IEcoMap1* m_pIBindingsMap;

} CEcoSE1LuaContext_8E62028C, *CEcoSE1LuaContext_8E62028CPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoSE1LuaContext_8E62028C(/*in*/ IEcoSE1ScriptContextPtr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoSE1LuaContext_8E62028C(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoSE1LuaContextPtr_t* ppIEcoSE1Lua);
/* Удаление */
void ECOCALLMETHOD deleteCEcoSE1LuaContext_8E62028C(/* in */ IEcoSE1ScriptContextPtr_t pIEcoSE1Lua);

#endif /* __C_ECO_SCRIPT_ENGINE_1_LUA_CONTEXT_H__ */
