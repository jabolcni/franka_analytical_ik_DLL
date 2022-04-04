// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the FRANKAPANDADLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// FRANKAPANDADLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef FRANKAPANDADLL_EXPORTS
#define FRANKAPANDADLL_API __declspec(dllexport)
#else
#define FRANKAPANDADLL_API __declspec(dllimport)
#endif

// This class is exported from the dll
class FRANKAPANDADLL_API CFrankaPandaDLL {
public:
	CFrankaPandaDLL(void);
	// TODO: add your methods here.
};

//extern FRANKAPANDADLL_API int nFrankaPandaDLL;

FRANKAPANDADLL_API void franka_IK(double* q, double* TF, double q7, double* q0, bool limit, bool flange);
FRANKAPANDADLL_API void franka_IK_f(float* q, float* TF, float q7, float* q0, bool limit, bool flange);
