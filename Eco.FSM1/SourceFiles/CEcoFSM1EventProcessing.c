/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoFSM1EventProcessing
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoFSM1EventProcessing
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "CEcoFSM1EventProcessing.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoFSM1EventProcessing
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFSM1EventProcessing_2C4F446F_QueryInterface(/* in */ IEcoFSM1EventProcessingPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoFSM1EventProcessing_2C4F446F* pCMe = (CEcoFSM1EventProcessing_2C4F446F*)me;

    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoFSM1EventProcessing) ) {
        *ppv = &pCMe->m_pVTblIEventProcessing;
        pCMe->m_pVTblIEventProcessing->AddRef((IEcoFSM1EventProcessing*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEventProcessing;
        pCMe->m_pVTblIEventProcessing->AddRef((IEcoFSM1EventProcessing*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoFSM1EventProcessing
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFSM1EventProcessing_2C4F446F_AddRef(/* in */ IEcoFSM1EventProcessingPtr_t me) {
    CEcoFSM1EventProcessing_2C4F446F* pCMe = (CEcoFSM1EventProcessing_2C4F446F*)me;

    if (me == 0 ) {
        return -1;
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
 *   Функция Release для интерфейса IEcoFSM1EventProcessing
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFSM1EventProcessing_2C4F446F_Release(/* in */ IEcoFSM1EventProcessingPtr_t me) {
    CEcoFSM1EventProcessing_2C4F446F* pCMe = (CEcoFSM1EventProcessing_2C4F446F*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoFSM1EventProcessing_2C4F446F((IEcoFSM1EventProcessing*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция get_StateMachine
 * </сводка>
 *
 * <описание>
 *   Функция возвращает интерфейс конечного автомата
 * </описание>
 *
 */
IEcoFSM1StateMachine* ECOCALLMETHOD CEcoFSM1EventProcessing_2C4F446F_get_StateMachine(/* in */ IEcoFSM1EventProcessingPtr_t me) {
    CEcoFSM1EventProcessing_2C4F446F* pCMe = (CEcoFSM1EventProcessing_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_pIStateMachine;
}

/*
 *
 * <сводка>
 *   Функция ResetStateMachine
 * </сводка>
 *
 * <описание>
 *   Функция сбрасывает конечный автомат и возвращает начальное состояние
 * </описание>
 *
 */
IEcoFSM1State* ECOCALLMETHOD CEcoFSM1EventProcessing_2C4F446F_ResetStateMachine(/* in */ IEcoFSM1EventProcessingPtr_t me) {
    CEcoFSM1EventProcessing_2C4F446F* pCMe = (CEcoFSM1EventProcessing_2C4F446F*)me;
    IEcoList1* pIStates = 0;
    IEcoFSM1State* pIState = 0;
    uint32_t index = 0;

    if (me == 0 ) {
        return 0;
    }

    pIStates = pCMe->m_pIStateMachine->pVTbl->get_States(pCMe->m_pIStateMachine);
    if (pIStates->pVTbl->Count(pIStates) > 0) {
        for (index = 0; index < pIStates->pVTbl->Count(pIStates); index++) {
            pIState = (IEcoFSM1State*)pIStates->pVTbl->Item(pIStates, index);
            if (pIState->pVTbl->IsInitial(pIState)) {
                pCMe->m_pICurrentState = pIState;
                break;
            }
        }
    }

    return pCMe->m_pICurrentState;
}

/*
 *
 * <сводка>
 *   Функция get_CurrentState
 * </сводка>
 *
 * <описание>
 *   Функция возвращает текущее состояние конечного автомата
 * </описание>
 *
 */
IEcoFSM1State* ECOCALLMETHOD CEcoFSM1EventProcessing_2C4F446F_get_CurrentState(/* in */ IEcoFSM1EventProcessingPtr_t me) {
    CEcoFSM1EventProcessing_2C4F446F* pCMe = (CEcoFSM1EventProcessing_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_pICurrentState;
}

/*
 *
 * <сводка>
 *   Функция IsInitialState
 * </сводка>
 *
 * <описание>
 *   Функция проверяет и возвращает начальное состояние конечного автомата в случае успеха
 * </описание>
 *
 */
IEcoFSM1State* ECOCALLMETHOD CEcoFSM1EventProcessing_2C4F446F_IsInitialState(/* in */ IEcoFSM1EventProcessingPtr_t me) {
    CEcoFSM1EventProcessing_2C4F446F* pCMe = (CEcoFSM1EventProcessing_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    if (pCMe->m_pICurrentState != 0 && pCMe->m_pIInitialState != 0) {
        if ( pCMe->m_pICurrentState->pVTbl->get_Id(pCMe->m_pICurrentState) == pCMe->m_pIInitialState->pVTbl->get_Id(pCMe->m_pIInitialState)) {
            return pCMe->m_pICurrentState;
        }
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция IsFinalState
 * </сводка>
 *
 * <описание>
 *   Функция проверяет и возвращает конечное состояние конечного автомата в случае успеха
 * </описание>
 *
 */
IEcoFSM1State* ECOCALLMETHOD CEcoFSM1EventProcessing_2C4F446F_IsFinalState(/* in */ IEcoFSM1EventProcessingPtr_t me) {
    CEcoFSM1EventProcessing_2C4F446F* pCMe = (CEcoFSM1EventProcessing_2C4F446F*)me;
    if (me == 0 ) {
        return 0;
    }

    if (pCMe->m_pICurrentState != 0 && pCMe->m_pIFinalState != 0) {
        if ( pCMe->m_pICurrentState->pVTbl->get_Id(pCMe->m_pICurrentState) == pCMe->m_pIFinalState->pVTbl->get_Id(pCMe->m_pIFinalState)) {
            return pCMe->m_pICurrentState;
        }
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция InvokeByEvent
 * </сводка>
 *
 * <описание>
 *   Функция обрабатывает событие и возвращает следующее состояние конечного автомата в случае успеха
 * </описание>
 *
 */
IEcoFSM1State* ECOCALLMETHOD CEcoFSM1EventProcessing_2C4F446F_InvokeByEvent(/* in */ IEcoFSM1EventProcessingPtr_t me, /* in */ IEcoFSM1Event* pIEvent) {
    CEcoFSM1EventProcessing_2C4F446F* pCMe = (CEcoFSM1EventProcessing_2C4F446F*)me;

    /* Проверка */
    if (me == 0 && pIEvent != 0) {
        return 0;
    }

    pCMe->m_pICurrentState = me->pVTbl->InvokeById(me, pIEvent->pVTbl->get_Id(pIEvent));

    return pCMe->m_pICurrentState;
}

/*
 *
 * <сводка>
 *   Функция InvokeById
 * </сводка>
 *
 * <описание>
 *   Функция обрабатывает событие и возвращает следующее состояние конечного автомата в случае успеха
 * </описание>
 *
 */
IEcoFSM1State* ECOCALLMETHOD CEcoFSM1EventProcessing_2C4F446F_InvokeById(/* in */ IEcoFSM1EventProcessingPtr_t me, /* in */ int16_t Id) {
    CEcoFSM1EventProcessing_2C4F446F* pCMe = (CEcoFSM1EventProcessing_2C4F446F*)me;
    IEcoFSM1Event* pIEvent = 0;
    IEcoFSM1State* pIState = 0;
    IEcoFSM1Transition* pITransition = 0;
    IEcoList1* pIStates = 0;
    IEcoList1* pITransitions = 0;
    uint32_t index = 0;
/*    bool_t isPop = 0;
    bool_t isPush = 0;
    uchar_t* pszInput = 0;
    uchar_t pushed = 0;
    uchar_t poped = 0;
    uchar_t top = 0;
    uchar_t* pszParametr = 0;*/

    /* Проверка указателей */
    if (me == 0) {
        return 0;
    }

    pIStates = pCMe->m_pIStateMachine->pVTbl->get_States(pCMe->m_pIStateMachine);
    pITransitions = pCMe->m_pIStateMachine->pVTbl->get_Transitions(pCMe->m_pIStateMachine);
    if (pCMe->m_pICurrentState == 0) {
        for (index = 0; index < pIStates->pVTbl->Count(pIStates); index++) {
            pIState = (IEcoFSM1State*)pIStates->pVTbl->Item(pIStates, index);
            if (pIState->pVTbl->IsInitial(pIState)) {
                pCMe->m_pICurrentState = pIState;
                break;
            }
        }
    }

    for (index = 0; index < pITransitions->pVTbl->Count(pITransitions); index++) {
        pITransition = (IEcoFSM1Transition*)pITransitions->pVTbl->Item(pITransitions, index);
        pIState = pITransition->pVTbl->get_Source(pITransition);
        if (pIState->pVTbl->get_Id(pIState) == pCMe->m_pICurrentState->pVTbl->get_Id(pCMe->m_pICurrentState)) {
            pIEvent = pITransition->pVTbl->get_Event(pITransition);
            if (pIEvent->pVTbl->get_Id(pIEvent) == Id) {
                pCMe->m_pICurrentState = pITransition->pVTbl->get_Target(pITransition);
                break;
            }
            else {
                continue;
            }
        }
    }

    return pCMe->m_pICurrentState;
}

/*
 *
 * <сводка>
 *   Функция InvokeByName
 * </сводка>
 *
 * <описание>
 *   Функция обрабатывает событие и возвращает следующее состояние конечного автомата в случае успеха
 * </описание>
 *
 */
IEcoFSM1State* ECOCALLMETHOD CEcoFSM1EventProcessing_2C4F446F_InvokeByName(/* in */ IEcoFSM1EventProcessingPtr_t me, /* in */ char_t* Name) {
    CEcoFSM1EventProcessing_2C4F446F* pCMe = (CEcoFSM1EventProcessing_2C4F446F*)me;
    IEcoList1* pIEvents = 0;
    IEcoFSM1Event* pIEvent = 0;
    uint32_t indexEvent = 0;

    /* Проверка */
    if (me == 0 ) {
        return 0;
    }

    pIEvents = pCMe->m_pIStateMachine->pVTbl->get_Events(pCMe->m_pIStateMachine);
    if (pIEvents != 0) {
        for( indexEvent = 0; indexEvent < pIEvents->pVTbl->Count(pIEvents); indexEvent++) {
            pIEvent = (IEcoFSM1Event*)pIEvents->pVTbl->Item(pIEvents, indexEvent);
            if (pCMe->m_pIString->pVTbl->Compare(pCMe->m_pIString, pIEvent->pVTbl->get_Name(pIEvent), Name) == 0) {
                pCMe->m_pICurrentState = me->pVTbl->InvokeById(me, pIEvent->pVTbl->get_Id(pIEvent));
                break;
            }
        }
    }

    return pCMe->m_pICurrentState;
}


/*
 *
 * <сводка>
 *   Функция InvokeBySymbol
 * </сводка>
 *
 * <описание>
 *   Функция обрабатывает событие и возвращает следующее состояние конечного автомата в случае успеха
 * </описание>
 *
 */
IEcoFSM1State* ECOCALLMETHOD CEcoFSM1EventProcessing_2C4F446F_InvokeBySymbol(/* in */ IEcoFSM1EventProcessingPtr_t me, /* in */ byte_t* Symbol, /* in */ uint8_t lengthBits, /* in */ uint8_t offsetBits) {
    CEcoFSM1EventProcessing_2C4F446F* pCMe = (CEcoFSM1EventProcessing_2C4F446F*)me;
    IEcoList1* pIEvents = 0;
    IEcoList1* pISymbolSets = 0;
    IEcoFSM1Event* pIEvent = 0;
    IEcoFL1SymbolSet* pISymbolSet = 0;
    uint32_t indexEvent = 0;
    uint32_t indexSymbolSet = 0;
    bool_t isExist = 0;
    byte_t* symbol = 0;

    /* Проверка */
    if (me == 0 ) {
        return 0;
    }

    symbol = pCMe->m_pIString->pVTbl->Substring(pCMe->m_pIString, (char_t*)Symbol, 0, 1);

    if (pCMe->m_pICurrentWord != 0) {
        pCMe->m_pICurrentState = pCMe->m_pICurrentWord->pVTbl->InvokeBySymbol(pCMe->m_pICurrentWord, symbol, lengthBits, offsetBits);
        if (pCMe->m_pICurrentWord->pVTbl->IsFinished(pCMe->m_pICurrentWord) == 1) {
            pCMe->m_pICurrentWord = 0;
        }

        return pCMe->m_pICurrentState;
    }

    pIEvents = pCMe->m_pIStateMachine->pVTbl->get_Events(pCMe->m_pIStateMachine);
    if (pIEvents != 0) {
        for( indexEvent = 0; indexEvent < pIEvents->pVTbl->Count(pIEvents); indexEvent++) {
            pIEvent = (IEcoFSM1Event*)pIEvents->pVTbl->Item(pIEvents, indexEvent);

            char_t* name = pIEvent->pVTbl->get_Name(pIEvent);
            bool_t isSymbolClass = pIEvent->pVTbl->IsSymbolClass(pIEvent);
            if (isSymbolClass == 0 && (
                    pIEvent->pVTbl->get_Id(pIEvent) == *Symbol ||
                    pCMe->m_pIString->pVTbl->Compare(pCMe->m_pIString, pIEvent->pVTbl->get_Name(pIEvent), Symbol) == 0
                    )
            ) {
                isExist = 1;
            } else if (isSymbolClass != 0) {
                pISymbolSets = pIEvent->pVTbl->get_SymbolSets(pIEvent);
                for(indexSymbolSet = 0; indexSymbolSet < pISymbolSets->pVTbl->Count(pISymbolSets); indexSymbolSet++) {
                    pISymbolSet = (IEcoFL1SymbolSet*) pISymbolSets->pVTbl->Item(pISymbolSets, indexSymbolSet);
                    if (pISymbolSet->pVTbl->IsExist(pISymbolSet, symbol, lengthBits, offsetBits) == 1) {
                        if (pISymbolSet->pVTbl->IsWord(pISymbolSet) == 1) {
                            pCMe->m_pICurrentWord = pISymbolSet;
                        }
                        isExist = 1;
                        break;
                    }
                }
            }

            if (isExist == 1) {
                pCMe->m_pICurrentState = me->pVTbl->InvokeById(me, pIEvent->pVTbl->get_Id(pIEvent));
                if (pCMe->m_pICurrentWord != 0) {
                    pCMe->m_pICurrentWord->pVTbl->set_WordState(pCMe->m_pICurrentWord, pCMe->m_pICurrentState);
                    pCMe->m_pICurrentState = pCMe->m_pICurrentWord->pVTbl->InvokeBySymbol(pCMe->m_pICurrentWord, symbol, lengthBits, offsetBits);
                }
                break;
            }
        }
    }

    return pCMe->m_pICurrentState;
}

/* Create Virtual Table */
IEcoFSM1EventProcessingVTbl g_xA768CE5B8B4C487380F98FCC5365A855VTbl_2C4F446F = {
    CEcoFSM1EventProcessing_2C4F446F_QueryInterface,
    CEcoFSM1EventProcessing_2C4F446F_AddRef,
    CEcoFSM1EventProcessing_2C4F446F_Release,
    CEcoFSM1EventProcessing_2C4F446F_get_StateMachine,
    CEcoFSM1EventProcessing_2C4F446F_ResetStateMachine,
    CEcoFSM1EventProcessing_2C4F446F_get_CurrentState,
    CEcoFSM1EventProcessing_2C4F446F_IsInitialState,
    CEcoFSM1EventProcessing_2C4F446F_IsFinalState,
    CEcoFSM1EventProcessing_2C4F446F_InvokeByEvent,
    CEcoFSM1EventProcessing_2C4F446F_InvokeById,
    CEcoFSM1EventProcessing_2C4F446F_InvokeByName,
    CEcoFSM1EventProcessing_2C4F446F_InvokeBySymbol
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
int16_t ECOCALLMETHOD createCEcoFSM1EventProcessing_2C4F446F(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* in */ IEcoFSM1StateMachine* StateMachine, /* out */ IEcoFSM1EventProcessing** ppIEventProcessing) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoFSM1EventProcessing_2C4F446F* pCMe = 0;

    /* Проверка указателей */
    if (ppIEventProcessing == 0 || pIUnkSystem == 0 || StateMachine == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (voidptr_t*)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (voidptr_t*)&pIBus);

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (voidptr_t*) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoFSM1EventProcessing_2C4F446F*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoFSM1EventProcessing_2C4F446F));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoFSM1EventProcessing */
    pCMe->m_pVTblIEventProcessing = &g_xA768CE5B8B4C487380F98FCC5365A855VTbl_2C4F446F;

    pCMe->m_pIString = 0;
    /* Сохраняем указателя на конечный автомат */
    pCMe->m_pICurrentState = 0;
    pCMe->m_pIInitialState = 0;
    pCMe->m_pIFinalState = 0;
    pCMe->m_pIStateMachine = StateMachine;
    pCMe->m_pIStateMachine->pVTbl->AddRef(pCMe->m_pIStateMachine);

    /* Получение интерфейса для работы со строкой */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (voidptr_t*)&pCMe->m_pIString);
    if (result != 0 || pCMe->m_pIString == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoFSM1EventProcessing_2C4F446F((IEcoFSM1EventProcessing*)pCMe);
    }

    //pIStates = pCMe->m_pIStateMachine->pVTbl->get_States(pCMe->m_pIStateMachine);
    //if (pIStates->Count(pIStates) > 0) {
    //    for (index = 0; index < pIStates->Count(pIStates); index++) {
    //        pIState = (IEcoFSM1State*)pIStates->Item(pIStates, index);
    //        if (pIState->IsInitial(pIState)) {
    //            pCMe->m_pICurrentState = pIState;
    //            break;
    //        }
    //    }
    //    pCMe->m_pICurrentState = (IEcoFSM1State*)pIStates->Item(pIStates, 0);
    //    pCMe->m_pIInitialState = (IEcoFSM1State*)pIStates->Item(pIStates, 0);
    //    pCMe->m_pIFinalState = (IEcoFSM1State*)pIStates->Item(pIStates, pIStates->Count(pIStates)-1);
    //}

    /* Возврат указателя на интерфейс */
    *ppIEventProcessing = (IEcoFSM1EventProcessing*)pCMe;

    /* Освобождение интерфейсной шиной */
    pIBus->pVTbl->Release(pIBus);

    return 0;
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
void ECOCALLMETHOD deleteCEcoFSM1EventProcessing_2C4F446F(/* in */ IEcoFSM1EventProcessing* pIEventProcessing) {
    CEcoFSM1EventProcessing_2C4F446F* pCMe = (CEcoFSM1EventProcessing_2C4F446F*)pIEventProcessing;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEventProcessing != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_pIStateMachine != 0 ) {
           pCMe->m_pIStateMachine->pVTbl->Release(pCMe->m_pIStateMachine);
        }
        if ( pCMe->m_pIString != 0 ) {
            pCMe->m_pIString->pVTbl->Release(pCMe->m_pIString);
        }

        if (pCMe->m_pISys != 0) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
