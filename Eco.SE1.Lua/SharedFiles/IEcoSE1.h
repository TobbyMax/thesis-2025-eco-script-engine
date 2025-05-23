/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoSE1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoSE1
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __I_ECO_SCRIPT_ENGINE_1_LUA_H__
#define __I_ECO_SCRIPT_ENGINE_1_LUA_H__

#include "IEcoBase1.h"
#include "IEcoSE1LuaContext.h"

/* IEcoSE1 IID = {3BBB11F2-75CF-432A-A548-45F3DBFCAAB5} */
#ifndef __IID_IEcoSE1Lua
static const UGUID IID_IEcoSE1Lua = {0x01, 0x10, {0x3B, 0xBB, 0x11, 0xF2, 0x75, 0xCF, 0x43, 0x2A, 0xA5, 0x48, 0x45, 0xF3, 0xDB, 0xFC, 0xAA, 0xB5}};
#endif /* __IID_IEcoSE1Lua */

typedef struct IEcoSE1* IEcoSE1LuaPtr_t;

typedef struct IEcoSE1LuaVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoSE1LuaPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoSE1LuaPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoSE1LuaPtr_t me);

    /* IEcoSE1 */
    int32_t (ECOCALLMETHOD *EvalString)(/* in */IEcoSE1LuaPtr_t me, const char* script, void** result);
    int32_t (ECOCALLMETHOD *EvalFile)(/* in */IEcoSE1LuaPtr_t me, const char* path, void** result);

    void* (ECOCALLMETHOD *Get)(/* in */IEcoSE1LuaPtr_t me, /* in */const char* key);
    int32_t (ECOCALLMETHOD *Put)(/* in */IEcoSE1LuaPtr_t me, /* in */const char* key, /* in */void* value);

    IEcoMap1* (ECOCALLMETHOD *get_Bindings)(/* in */ IEcoSE1LuaPtr_t me, int32_t scope);
    int32_t (ECOCALLMETHOD *set_Bindings)(/* in */ IEcoSE1LuaPtr_t me, IEcoMap1* pBindingsMap, int32_t scope);

    IEcoSE1ScriptContext* (ECOCALLMETHOD *get_Context)(/* in */ IEcoSE1LuaPtr_t me);
    void (ECOCALLMETHOD *set_Context)(/* in */ IEcoSE1LuaPtr_t me, /* in */ IEcoSE1ScriptContext* pContext);

} IEcoSE1LuaVTbl, *IEcoSE1LuaVTblPtr_t;

interface IEcoSE1 {
    struct IEcoSE1LuaVTbl *pVTbl;
} IEcoSE1;


#endif /* __I_ECO_SCRIPT_ENGINE_1_LUA_H__ */
