/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoC89Grammar
 * </сводка>
 *
 * <описание>
 *   Данный файл описывает прототипы функций описания грамматики для C89
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoFSM1.h"
#include "IEcoBNF1.h"

IEcoFSM1StateMachine* GetFAForLAOfLua (IEcoFSM1* pIFSM);
IEcoBNF1* GetBNFForSAOfLua(IEcoBNF1* pIBNF);
