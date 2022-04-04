# FrankaPandaDLL

This is a Visual Studio project (Microsoft Visual Studio Enterprise 2019) for compiling a DLL of a code for analytical Inverse Kinematics (IK) solver for Franka Emika Panda published by Yanhao He and Steven Liu. Original project is published on https://github.com/ffall007/franka_analytical_ik/blob/main/README.md. If you want to cite the IK project you should cite the authors Yanhao He and Steven Liu (please go to their github page). 



FRANKAPANDADLL_API void franka_IK(double* q, double* TF, double q7, double* q0, bool limit, bool flange)

FRANKAPANDADLL_API void franka_IK_f(float* q, float* TF, float q7, float* q0, bool limit, bool flange)