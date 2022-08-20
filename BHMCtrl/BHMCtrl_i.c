/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Mar 22 14:11:55 1999
 */
/* Compiler settings for C:\wxz\BHMCtrl\BHMCtrl.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IBHMTimeEditCtrl = {0x389612AE,0xD16F,0x11D2,{0x9C,0xE8,0x00,0x80,0xC8,0x76,0x3F,0xA4}};


const IID LIBID_BHMCTRLLib = {0x389612A0,0xD16F,0x11D2,{0x9C,0xE8,0x00,0x80,0xC8,0x76,0x3F,0xA4}};


const IID DIID__IBHMTimeEditCtrlEvents = {0x389612B0,0xD16F,0x11D2,{0x9C,0xE8,0x00,0x80,0xC8,0x76,0x3F,0xA4}};


const CLSID CLSID_BHMTimeEditCtrl = {0x389612AF,0xD16F,0x11D2,{0x9C,0xE8,0x00,0x80,0xC8,0x76,0x3F,0xA4}};


const CLSID CLSID_TEPpg = {0xDECC1F80,0xE05F,0x11D2,{0xA7,0xFE,0x00,0x80,0xC8,0x76,0x3F,0xA4}};


#ifdef __cplusplus
}
#endif

