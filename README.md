# FrankaPandaDLL

## Summary
This is a VS project for compiling a DLL of project ffall007/franka_analytical_ik.

## Introduction

This is a Visual Studio project (Microsoft Visual Studio Enterprise 2019) for compiling a DLL of a code for analytical Inverse Kinematics (IK) solver for Franka Emika Panda published by Yanhao He and Steven Liu. Original project is published on https://github.com/ffall007/franka_analytical_ik/blob/main/README.md. If you want to cite the IK project you should cite the authors Yanhao He and Steven Liu (please go to their github page). 

The aim of the project was to compile DLL so that IK solver can be used in Unity project for Franka Panda Emika vizualization. Unity project will also be soon availible on GitHub.

## DLL compiling

Example of instruction for creating DLL is published on 
https://levelup.gitconnected.com/integrating-native-c-c-libraries-with-unity-as-plugins-a-step-by-step-guide-17ad70c2e3b4.

### Decorated names of functions

Typically, the C++ compiler generates a decorated name for DLL functions and when you want to call the function you need to call it by its decorated name. See [documentation] (https://docs.microsoft.com/en-us/dotnet/api/system.entrypointnotfoundexception?view=net-6.0)

When you compile the DLL decorated name of the functions will change. To find out the decorated name, you need to use DUMPBIN function on the compiled DLL. Example id bellow

Calling
```console
C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\VC\Tools\MSVC\14.29.30133\bin\Hostx64\x64>dumpbin /EXPORTS C:\Users\student\Documents\TestDLL\Assets\Plugins\FrankaPandaDLL.dll
```
Returns 

```console
Microsoft (R) COFF/PE Dumper Version 14.29.30141.0
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file C:\Users\student\Documents\TestDLL\Assets\Plugins\FrankaPandaDLL.dll

File Type: DLL

  Section contains the following exports for FrankaPandaDLL.dll

    00000000 characteristics
    FFFFFFFF time date stamp
        0.00 version
           1 ordinal base
           5 number of functions
           5 number of names

    ordinal hint RVA      name

          1    0 0002893B ??0CFrankaPandaDLL@@QEAA@XZ = @ILT+10550(??0CFrankaPandaDLL@@QEAA@XZ)
          2    1 00027F59 ??4CFrankaPandaDLL@@QEAAAEAV0@$$QEAV0@@Z = @ILT+8020(??4CFrankaPandaDLL@@QEAAAEAV0@$$QEAV0@@Z)
          3    2 00028864 ??4CFrankaPandaDLL@@QEAAAEAV0@AEBV0@@Z = @ILT+10335(??4CFrankaPandaDLL@@QEAAAEAV0@AEBV0@@Z)
          4    3 000271D5 ?franka_IK@@YAXPEAN0N0_N1@Z = @ILT+4560(?franka_IK@@YAXPEAN0N0_N1@Z)
          5    4 00027734 ?franka_IK_f@@YAXPEAM0M0_N1@Z = @ILT+5935(?franka_IK_f@@YAXPEAM0M0_N1@Z)

  Summary

        1000 .00cfg
        1000 .data
        1000 .idata
        1000 .msvcjmc
        9000 .pdata
       17000 .rdata
        1000 .reloc
        1000 .rsrc
       56000 .text
       25000 .textbss
```

For this example decorated name for function `franka_IK` is `franka_IK@@YAXPEAN0N0_N1@Z`.

## Usage

Project contains two wrapper function for IK code. They are essentially the same, first takes double data type values of variables, while the second floats data types of variables.

```cpp
void franka_IK(double* q, double* TF, double q7, double* q0, bool limit, bool flange)
```

```cpp
void franka_IK_f(float* q, float* TF, float q7, float* q0, bool limit, bool flange)
```

Wrapper functions make call to a function
```cpp
std::array<double, 7> franka_IK_EE_CC ( std::array<double, 16> O_T_EE_array,
                                        double q7,
                                        std::array<double, 7> q_actual_array,
                                        bool limit, bool flange)
```

## Changes

Few changes have nevertheless been made to function 

```cpp
std::array<double, 7> franka_IK_EE_CC ( std::array<double, 16> O_T_EE_array,
                                        double q7,
                                        std::array<double, 7> q_actual_array,
                                        bool limit, bool flange)
```

Original version returned *NaN* values for joint angles if the calculated values were outside of joint limits. Current version returns either max or min joint value. You can also ignore joint limits by setting `bool limit` variable to `false`. With variable `bool flange` you can choose whether you want to calculate IK for flange or you want to include fingers in calculation of IK. The difference is:

```cpp
    if (flange)
        d7e = 0.107;
    else
        d7e = 0.2104;
```

## Error `EntryPointNotFoundException`

If you get error `EntryPointNotFoundException` you need to call the functions by its decorated name. See section *Decorated names of functions* of this documentation file.

