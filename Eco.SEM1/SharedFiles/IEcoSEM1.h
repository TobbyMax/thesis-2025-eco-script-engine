/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoSEM1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoSEM1
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

#ifndef __I_ECO_SCRIPT_ENGINE_MANAGER_1_H__
#define __I_ECO_SCRIPT_ENGINE_MANAGER_1_H__

#include "IEcoBase1.h"
#include "IEcoSE1.h"

/* IEcoSEM1 IID = {E6E96975-7686-48C3-B075-5143CE324AAC} */
#ifndef __IID_IEcoSEM1
static const UGUID IID_IEcoSEM1 = {0x01, 0x10, {0xE6, 0xE9, 0x69, 0x75, 0x76, 0x86, 0x48, 0xC3, 0xB0, 0x75, 0x51, 0x43, 0xCE, 0x32, 0x4A, 0xAC}};
#endif /* __IID_IEcoSEM1 */

typedef struct IEcoSEM1* IEcoSEM1Ptr_t;

typedef struct IEcoSEM1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoSEM1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoSEM1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoSEM1Ptr_t me);

    /* IEcoSEM1 */
    // Bindings operations
    int32_t (ECOCALLMETHOD *set_Bindings)(/* in */ IEcoSEM1Ptr_t* me, IEcoMap1* pBindingsMap);
    IEcoMap1* (ECOCALLMETHOD *get_Bindings)(/* in */ IEcoSEM1Ptr_t* me);

    // Global key-value store
    int32_t (ECOCALLMETHOD *Put)(/* in */ IEcoSEM1Ptr_t* me, /* in */ const char* key, /* in */ void* value);
    void* (ECOCALLMETHOD *Get)(/* in */ IEcoSEM1Ptr_t* me, /* in */ const char* key);

    // Engine operations
    IEcoSE1* (ECOCALLMETHOD *GetEngineByName)(/* in */ IEcoSEM1Ptr_t* me, /* in */ const char* shortName);
    IEcoSE1* (ECOCALLMETHOD *GetEngineByExtension)(/* in */ IEcoSEM1Ptr_t* me, /* in */ const char* extension);
    IEcoSE1* (ECOCALLMETHOD *GetEngineByMimeType)(/* in */ IEcoSEM1Ptr_t* me, /* in */ const char* mimeType);
    int32_t (ECOCALLMETHOD *RegisterEngineName)(/* in */ IEcoSEM1Ptr_t* me, /* in */ const char* shortName, /* in */ IEcoSE1* pEngine);
    int32_t (ECOCALLMETHOD *RegisterEngineExtension)(/* in */ IEcoSEM1Ptr_t* me, /* in */ const char* extension, /* in */ IEcoSE1* pEngine);
    int32_t (ECOCALLMETHOD *RegisterEngineMimeType)(/* in */ IEcoSEM1Ptr_t* me, /* in */ const char* mimeType, /* in */ IEcoSE1* pEngine);
    IEcoList1* (ECOCALLMETHOD *GetEngines)(/* in */ IEcoSEM1Ptr_t* me);

} IEcoSEM1VTbl, *IEcoSEM1VTblPtr_t;

interface IEcoSEM1 {
    struct IEcoSEM1VTbl *pVTbl;
} IEcoSEM1;


#endif /* __I_ECO_SCRIPT_ENGINE_MANAGER_1_H__ */
