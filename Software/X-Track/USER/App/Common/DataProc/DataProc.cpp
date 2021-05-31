#include "DataProc.h"
#include "../HAL/HAL.h"

static DataCenter dataCenter("Bilibili");

DataCenter* DataProc::Center()
{
    return &dataCenter;
}

void DataProc_Init()
{

#define DP_DEF(NodeName, bufferSize)\
    Account* act##NodeName = new Account(#NodeName, &dataCenter, bufferSize);
#  include "DP_LIST.inc"
#undef DP_DEF
    
#define DP_DEF(NodeName, bufferSize)\
do{\
    extern void DP_##NodeName##_Init(Account* act);\
    DP_##NodeName##_Init(act##NodeName);\
}while(0)
#  include "DP_LIST.inc"
#undef DP_DEF
}