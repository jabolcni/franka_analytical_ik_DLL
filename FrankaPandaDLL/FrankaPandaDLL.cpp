// FrankaPandaDLL.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "FrankaPandaDLL.h"
#include "franka_ik_He.hpp"


// This is an example of an exported variable
// FRANKAPANDADLL_API int nFrankaPandaDLL=0;

// This is an example of an exported function.
// FRANKAPANDADLL_API int fnFrankaPandaDLL(void)
// {
//    return 0;
// }

FRANKAPANDADLL_API void franka_IK(double* q, double* TF, double q7, double* q0, bool limit, bool flange)
{

    std::array<double, 7> qq;
    std::array<double, 16> TFF;
    std::array<double, 7> qq0;

    std::copy(q0, q0 + 7, qq0.begin());
    std::copy(TF, TF + 16, TFF.begin());

    qq = franka_IK_EE_CC(TFF, q7, qq0, limit, flange);

    std::copy(qq.begin(), qq.end(), q);

}

FRANKAPANDADLL_API void franka_IK_f(float* q, float* TF, float q7, float* q0, bool limit, bool flange)
{

    std::array<double, 7> qq;
    std::array<double, 16> TFF;
    std::array<double, 7> qq0;

    std::copy(q0, q0 + 7, qq0.begin());
    std::copy(TF, TF + 16, TFF.begin());

    qq = franka_IK_EE_CC(TFF, (double)q7, qq0, limit, flange);

    std::copy(qq.begin(), qq.end(), q);

}

// This is the constructor of a class that has been exported.
CFrankaPandaDLL::CFrankaPandaDLL()
{
    return;
}
