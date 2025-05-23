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

#ifndef __I_ECO_SCRIPT_ENGINE_1_SCRIPT_CONTEXT_H__
#define __I_ECO_SCRIPT_ENGINE_1_SCRIPT_CONTEXT_H__

#include "IEcoBase1.h"
#include "IEcoMap1.h"

/* IEcoSE1ScriptContext IID = {3BBB11F2-75CF-432A-A548-45F3DBFCAAB6} */
#ifndef __IID_IEcoSE1ScriptContext
static const UGUID IID_IEcoSE1ScriptContext = {0x01, 0x10, {0x3B, 0xBB, 0x11, 0xF2, 0x75, 0xCF, 0x43, 0x2A, 0xA5, 0x48, 0x45, 0xF3, 0xDB, 0xFC, 0xAA, 0xB6}};
#endif /* __IID_IEcoSE1ScriptContext */

#define ECO_SCRIPT_ENGINE_1_SCOPE_ENGINE 100
#define ECO_SCRIPT_ENGINE_1_SCOPE_GLOBAL 200

typedef struct IEcoSE1ScriptContext IEcoSE1ScriptContext;
typedef struct IEcoSE1ScriptContext* IEcoSE1ScriptContextPtr_t;

typedef struct IEcoSE1ScriptContextVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoSE1ScriptContextPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoSE1ScriptContextPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoSE1ScriptContextPtr_t me);

    /* IEcoSE1ScriptContext */
    int32_t (ECOCALLMETHOD *set_Bindings)(/* in */ IEcoSE1ScriptContextPtr_t me, /* in */ IEcoMap1* pBindingsMap, /* in */ int32_t scope);
    IEcoMap1* (ECOCALLMETHOD *get_Bindings)(/* in */ IEcoSE1ScriptContextPtr_t me, /* in */ int32_t scope);

    // Attribute operations
    int32_t (ECOCALLMETHOD *set_Attribute)(/* in */ IEcoSE1ScriptContextPtr_t me, /* in */ const char* name, /* in */ void* value, /* in */ int32_t scope);
    void* (ECOCALLMETHOD *get_Attribute)(/* in */ IEcoSE1ScriptContextPtr_t me, /* in */ const char* name, /* in */ int32_t scope);
    void* (ECOCALLMETHOD *RemoveAttribute)(/* in */ IEcoSE1ScriptContextPtr_t me, /* in */ const char* name, /* in */ int32_t scope);
    void* (ECOCALLMETHOD *GetAttributeInAnyScope)(/* in */ IEcoSE1ScriptContextPtr_t me, /* in */ const char* name);
    int32_t (ECOCALLMETHOD *GetScopeByAttribute)(/* in */ IEcoSE1ScriptContextPtr_t me, /* in */ const char* name);

} IEcoSE1ScriptContextVTbl, *IEcoSE1ScriptContextVTblPtr_t;

interface IEcoSE1ScriptContext {
        struct IEcoSE1ScriptContextVTbl *pVTbl;
} IEcoSE1ScriptContext;

#endif /* __I_ECO_SCRIPT_ENGINE_1_SCRIPT_CONTEXT_H__ */

