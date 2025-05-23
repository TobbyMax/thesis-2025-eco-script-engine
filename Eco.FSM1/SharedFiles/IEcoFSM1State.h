/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoFSM1State
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoFSM1
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

#ifndef __I_ECO_FINITE_STATE_MACHINE_1_STATE_H__
#define __I_ECO_FINITE_STATE_MACHINE_1_STATE_H__

#include "IEcoBase1.h"

/* IEcoFSM1State IID = {6242C2A9-31D9-4FB9-A1CB-8AC693AD6EB4} */
#ifndef __IID_IEcoFSM1State
static const UGUID IID_IEcoFSM1State = {0x01, 0x10, {0x62, 0x42, 0xC2, 0xA9, 0x31, 0xD9, 0x4F, 0xB9, 0xA1, 0xCB, 0x8A, 0xC6, 0x93, 0xAD, 0x6E, 0xB4} };
#endif /* __IID_IEcoFSM1State */

typedef struct IEcoFSM1State* IEcoFSM1StatePtr_t;

typedef struct IEcoFSM1StateVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoFSM1StatePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoFSM1StatePtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoFSM1StatePtr_t me);

    /* IEcoFSM1State */
    int16_t (ECOCALLMETHOD *get_Id)(/* in */ IEcoFSM1StatePtr_t me);
    char_t* (ECOCALLMETHOD *get_Name)(/* in */ IEcoFSM1StatePtr_t me);
    void (ECOCALLMETHOD *set_Name)(/* in */ IEcoFSM1StatePtr_t me, /* in */ char_t* Name);
    bool_t (ECOCALLMETHOD *IsInitial)(/* in */ IEcoFSM1StatePtr_t me);
    void (ECOCALLMETHOD *set_Initial)(/* in */ IEcoFSM1StatePtr_t me, /* in */ bool_t isInitial);
    bool_t (ECOCALLMETHOD *IsFinal)(/* in */ IEcoFSM1StatePtr_t me);
    void (ECOCALLMETHOD *set_Final)(/* in */ IEcoFSM1StatePtr_t me, /* in */ bool_t isFinal);
    bool_t (ECOCALLMETHOD *IsTrap)(/* in */ IEcoFSM1StatePtr_t me);
    void (ECOCALLMETHOD *set_Trap)(/* in */ IEcoFSM1StatePtr_t me, /* in */ bool_t isTrap);
    void* (ECOCALLMETHOD *get_Parameter)(/* in */ IEcoFSM1StatePtr_t me);
    void (ECOCALLMETHOD *set_Parameter)(/* in */ IEcoFSM1StatePtr_t me, /* in */ void* value);

} IEcoFSM1StateVTbl, *IEcoFSM1StateVTblPtr;

interface IEcoFSM1State {
    struct IEcoFSM1StateVTbl *pVTbl;
} IEcoFSM1State;

#endif /* __I_ECO_FINITE_STATE_MACHINE_1_STATE_H__ */