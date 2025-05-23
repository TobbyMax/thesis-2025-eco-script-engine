/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoFSM1
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

#ifndef __I_ECO_FINITE_STATE_MACHINE_1_H__
#define __I_ECO_FINITE_STATE_MACHINE_1_H__

#include "IEcoBase1.h"
#include "IEcoList1.h"
#include "IEcoData1.h"
#include "IEcoFSM1State.h"
#include "IEcoFL1.h"

/* IEcoFSM1Event IID = {1BFBB309-B33F-4E86-AABE-0C41ED5E256C} */
#ifndef __IID_IEcoFSM1Event
static const UGUID IID_IEcoFSM1Event = {0x01, 0x10, {0x1B, 0xFB, 0xB3, 0x09, 0xB3, 0x3F, 0x4E, 0x86, 0xAA, 0xBE, 0x0C, 0x41, 0xED, 0x5E, 0x25, 0x6C} };
#endif /* __IID_IEcoFSM1Event */

typedef struct IEcoFSM1Event* IEcoFSM1EventPtr_t;

typedef struct IEcoFSM1EventVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoFSM1EventPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoFSM1EventPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoFSM1EventPtr_t me);

    /* IEcoFSM1Event */
    char_t* (ECOCALLMETHOD *get_Name)(/* in */ IEcoFSM1EventPtr_t me);
    int16_t (ECOCALLMETHOD *get_Id)(/* in */ IEcoFSM1EventPtr_t me);
    bool_t (ECOCALLMETHOD *IsNull)(/* in */ IEcoFSM1EventPtr_t me);
    void (ECOCALLMETHOD *set_Null)(/* in */ IEcoFSM1EventPtr_t me, /* in */ bool_t isNull);
    bool_t (ECOCALLMETHOD *IsSymbolClass)(/* in */ IEcoFSM1EventPtr_t me);
    IEcoFL1SymbolSet* (ECOCALLMETHOD *AddSymbolSet)(/* in */ IEcoFSM1EventPtr_t me, /* in */ char_t* Name);
    IEcoFL1SymbolSet* (ECOCALLMETHOD *AddExistingSymbolSet)(/* in */ IEcoFSM1EventPtr_t me, /* in */ IEcoFL1SymbolSet* symbolSet);
    IEcoFL1SymbolSet* (ECOCALLMETHOD *get_SymbolSet)(/* in */ IEcoFSM1EventPtr_t me, /* in */ uint32_t index);
    IEcoList1* (ECOCALLMETHOD *get_SymbolSets)(/* in */ IEcoFSM1EventPtr_t me);
    void* (ECOCALLMETHOD *get_Parameter)(/* in */ IEcoFSM1EventPtr_t me);
    void (ECOCALLMETHOD *set_Parameter)(/* in */ IEcoFSM1EventPtr_t me, /* in */ void* value);

} IEcoFSM1EventVTbl, *IEcoFSM1EventVTblPtr;

interface IEcoFSM1Event {
    struct IEcoFSM1EventVTbl *pVTbl;
} IEcoFSM1Event;

/* IEcoFSM1Transition IID = {00C3032A-56F2-4474-B4FD-6F837D907909} */
#ifndef __IID_IEcoFSM1Transition
static const UGUID IID_IEcoFSM1Transition = {0x01, 0x10, {0x00, 0xC3, 0x03, 0x2A, 0x56, 0xF2, 0x44, 0x74, 0xB4, 0xFD, 0x6F, 0x83, 0x7D, 0x90, 0x79, 0x09} };
#endif /* __IID_IEcoFSM1Transition */

typedef struct IEcoFSM1Transition* IEcoFSM1TransitionPtr_t;

typedef struct IEcoFSM1TransitionVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoFSM1TransitionPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoFSM1TransitionPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoFSM1TransitionPtr_t me);

    /* IEcoFSM1Transition */
    char_t* (ECOCALLMETHOD *get_Name)(/* in */ IEcoFSM1TransitionPtr_t me);
    void (ECOCALLMETHOD *set_Name)(/* in */ IEcoFSM1TransitionPtr_t me, /* in */ char_t* Name);
    int16_t (ECOCALLMETHOD *get_Id)(/* in */ IEcoFSM1TransitionPtr_t me);
    void* (ECOCALLMETHOD *get_Parameter)(/* in */ IEcoFSM1TransitionPtr_t me);
    void (ECOCALLMETHOD *set_Parameter)(/* in */ IEcoFSM1TransitionPtr_t me, /* in */ void* value);
    IEcoFSM1Event* (ECOCALLMETHOD *get_Event)(/* in */ IEcoFSM1TransitionPtr_t me);
    IEcoFSM1State* (ECOCALLMETHOD *get_Source)(/* in */ IEcoFSM1TransitionPtr_t me);
    IEcoFSM1State* (ECOCALLMETHOD *get_Target)(/* in */ IEcoFSM1TransitionPtr_t me);

} IEcoFSM1TransitionVTbl, *IEcoFSM1TransitionVTblPtr;

interface IEcoFSM1Transition {
    struct IEcoFSM1TransitionVTbl *pVTbl;
} IEcoFSM1Transition;

/* IEcoFSM1StateMachine IID = {6B73BD3F-22F6-462E-AC29-F5C1214E775E} */
#ifndef __IID_IEcoFSM1StateMachine
static const UGUID IID_IEcoFSM1StateMachine = {0x01, 0x10, {0x6B, 0x73, 0xBD, 0x3F, 0x22, 0xF6, 0x46, 0x2E, 0xAC, 0x29, 0xF5, 0xC1, 0x21, 0x4E, 0x77, 0x5E} };
#endif /* __IID_IEcoFSM1StateMachine */

typedef struct IEcoFSM1StateMachine* IEcoFSM1StateMachinePtr_t;

typedef struct IEcoFSM1StateMachineVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoFSM1StateMachinePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoFSM1StateMachinePtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoFSM1StateMachinePtr_t me);

    /* IEcoFSM1StateMachine */
    char_t* (ECOCALLMETHOD *get_Name)(/* in */ IEcoFSM1StateMachinePtr_t me);
    int16_t (ECOCALLMETHOD *get_Id)(/* in */ IEcoFSM1StateMachinePtr_t me);
    IEcoFL1Alphabet* (ECOCALLMETHOD *get_Alphabet)(/* in */ IEcoFSM1StateMachinePtr_t me);
    IEcoFSM1State* (ECOCALLMETHOD *AddState)(/* in */ IEcoFSM1StateMachinePtr_t me, /* in */ char_t* Name);
    IEcoList1* (ECOCALLMETHOD *get_States)(/* in */ IEcoFSM1StateMachinePtr_t me);
    IEcoFSM1Event* (ECOCALLMETHOD *AddEvent)(/* in */ IEcoFSM1StateMachinePtr_t me, /* in */ char_t* Name, /* in */ int16_t Id, /* in */ bool_t isNull);
    IEcoList1* (ECOCALLMETHOD *get_Events)(/* in */ IEcoFSM1StateMachinePtr_t me);
    IEcoFSM1Transition* (ECOCALLMETHOD *AddTransition)(/* in */ IEcoFSM1StateMachinePtr_t me, /* in */ IEcoFSM1Event* Event, /* in */ IEcoFSM1State* Source, /* in */ IEcoFSM1State* Target);
    IEcoFSM1Transition* (ECOCALLMETHOD *AddTransitionById)(/* in */ IEcoFSM1StateMachinePtr_t me, /* in */ int16_t EventId, /* in */ int16_t SourceStateId, /* in */ int16_t TargetStateId);
    IEcoList1* (ECOCALLMETHOD *get_Transitions)(/* in */ IEcoFSM1StateMachinePtr_t me);
    bool_t (ECOCALLMETHOD *Flip)(/* in */ IEcoFSM1StateMachinePtr_t me);
    IEcoData1Table* (ECOCALLMETHOD *get_TransitionTable)(/* in */ IEcoFSM1StateMachinePtr_t me);
    IEcoFL1Alphabet* (ECOCALLMETHOD *AddAlphabet)(/* in */ IEcoFSM1StateMachinePtr_t me, char_t* Name);

} IEcoFSM1StateMachineVTbl, *IEcoFSM1StateMachineVTblPtr;

interface IEcoFSM1StateMachine {
    struct IEcoFSM1StateMachineVTbl *pVTbl;
} IEcoFSM1StateMachine;

/* IEcoFSM1EventProcessing IID = {A768CE5B-8B4C-4873-80F9-8FCC5365A855} */
#ifndef __IID_IEcoFSM1EventProcessing
static const UGUID IID_IEcoFSM1EventProcessing = {0x01, 0x10, {0xA7, 0x68, 0xCE, 0x5B, 0x8B, 0x4C, 0x48, 0x73, 0x80, 0xF9, 0x8F, 0xCC, 0x53, 0x65, 0xA8, 0x55} };
#endif /* __IID_IEcoFSM1EventProcessing */

typedef struct IEcoFSM1EventProcessing* IEcoFSM1EventProcessingPtr_t;

typedef struct IEcoFSM1EventProcessingVTbl {

    /* IEcoFSM1EventProcessing */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoFSM1EventProcessingPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoFSM1EventProcessingPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoFSM1EventProcessingPtr_t me);

    /* IEcoFSM1EventProcessing */
    IEcoFSM1StateMachine* (ECOCALLMETHOD *get_StateMachine)(/* in */ IEcoFSM1EventProcessingPtr_t me);
    IEcoFSM1State* (ECOCALLMETHOD *ResetStateMachine)(/* in */ IEcoFSM1EventProcessingPtr_t me);
    IEcoFSM1State* (ECOCALLMETHOD *get_CurrentState)(/* in */ IEcoFSM1EventProcessingPtr_t me);
    IEcoFSM1State* (ECOCALLMETHOD *IsInitialState)(/* in */ IEcoFSM1EventProcessingPtr_t me);
    IEcoFSM1State* (ECOCALLMETHOD *IsFinalState)(/* in */ IEcoFSM1EventProcessingPtr_t me);
    IEcoFSM1State* (ECOCALLMETHOD *InvokeByEvent)(/* in */ IEcoFSM1EventProcessingPtr_t me, /* in */ IEcoFSM1Event* Event);
    IEcoFSM1State* (ECOCALLMETHOD *InvokeById)(/* in */ IEcoFSM1EventProcessingPtr_t me, /* in */ int16_t Id);
    IEcoFSM1State* (ECOCALLMETHOD *InvokeByName)(/* in */ IEcoFSM1EventProcessingPtr_t me, /* in */ char_t* Name);
    IEcoFSM1State* (ECOCALLMETHOD *InvokeBySymbol)(/* in */ IEcoFSM1EventProcessingPtr_t me, /* in */ byte_t* Symbol, /* in */ uint8_t lengthBits, /* in */ uint8_t offsetBits);

} IEcoFSM1EventProcessingVTbl, *IEcoFSM1EventProcessingVTblPtr;

interface IEcoFSM1EventProcessing {
    struct IEcoFSM1EventProcessingVTbl *pVTbl;
} IEcoFSM1EventProcessing;

/* IEcoFSM1 IID = {7ACB8256-EEB3-40FA-8E83-9A9AF03464D5} */
#ifndef __IID_IEcoFSM1
static const UGUID IID_IEcoFSM1 = {0x01, 0x10, {0x7A, 0xCB, 0x82, 0x56, 0xEE, 0xB3, 0x40, 0xFA, 0x8E, 0x83, 0x9A, 0x9A, 0xF0, 0x34, 0x64, 0xD5} };
#endif /* __IID_IEcoFSM1 */

typedef struct IEcoFSM1* IEcoFSM1Ptr_t;

typedef struct IEcoFSM1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoFSM1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoFSM1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoFSM1Ptr_t me);

    /* IEcoFSM1 */
    IEcoFSM1StateMachine* (ECOCALLMETHOD *CreateStateMachine)(/* in */ IEcoFSM1Ptr_t me, /* in */ char_t* Name);
    IEcoFSM1EventProcessing* (ECOCALLMETHOD *get_EventProcessing)(/* in */ IEcoFSM1Ptr_t me, /* in */ IEcoFSM1StateMachine* StateMachine);
} IEcoFSM1VTbl, *IEcoFSM1VTblPtr;

interface IEcoFSM1 {
    struct IEcoFSM1VTbl *pVTbl;
} IEcoFSM1;

#endif /* __I_ECO_FINITE_STATE_MACHINE_1_H__ */
