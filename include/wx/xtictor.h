/////////////////////////////////////////////////////////////////////////////
// Name:        wx/xtictor.h
// Purpose:     XTI constructors
// Author:      Stefan Csomor
// Modified by: Francesco Montorsi
// Created:     27/07/03
// RCS-ID:      $Id: xti.h 47299 2007-07-10 15:58:27Z FM $
// Copyright:   (c) 1997 Julian Smart
//              (c) 2003 Stefan Csomor
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _XTICTOR_H_
#define _XTICTOR_H_

#include "wx/defs.h"

#if wxUSE_EXTENDED_RTTI

#include "wx/string.h"
#include "wx/xvariant.h"

class WXDLLIMPEXP_BASE wxObject;
class WXDLLIMPEXP_BASE wxClassInfo;
class WXDLLIMPEXP_BASE wxDynamicClassInfo;
class WXDLLIMPEXP_BASE wxHashTable;
class WXDLLIMPEXP_BASE wxHashTable_Node;
class WXDLLIMPEXP_BASE wxObjectRefData;
class WXDLLIMPEXP_BASE wxEvent;
class WXDLLIMPEXP_BASE wxEvtHandler;

// ----------------------------------------------------------------------------
// Constructor Bridges
// ----------------------------------------------------------------------------

// A constructor bridge allows to call a ctor with an arbitrary number
// or parameters during runtime
class WXDLLIMPEXP_BASE wxObjectAllocatorAndCreator
{
public:
    virtual ~wxObjectAllocatorAndCreator() { }
    virtual bool Create(wxObject * &o, wxxVariant *args) = 0;
};

// a direct constructor bridge calls the operator new for this class and
// passes all params to the constructor. Needed for classes that cannot be
// instantiated using alloc-create semantics
class WXDLLIMPEXP_BASE wxObjectAllocator : public wxObjectAllocatorAndCreator
{
public:
    virtual bool Create(wxObject * &o, wxxVariant *args) = 0;
};


// ----------------------------------------------------------------------------
// Constructor Bridges for all Numbers of Params
// ----------------------------------------------------------------------------

// no params

template<typename Class>
struct wxObjectAllocatorAndCreator_0 : public wxObjectAllocatorAndCreator
{
    bool Create(wxObject * &o, wxxVariant *)
    {
        Class *obj = wx_dynamic_cast(Class*, o);
        return obj->Create();
    }
};

struct wxObjectAllocatorAndCreator_Dummy : public wxObjectAllocatorAndCreator
{
    bool Create(wxObject *&, wxxVariant *)
    {
        return true;
    }
};

#define wxCONSTRUCTOR_0(klass) \
    wxObjectAllocatorAndCreator_0<klass> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = { NULL }; \
    const int klass::ms_constructorPropertiesCount = 0;

#define wxCONSTRUCTOR_DUMMY(klass) \
    wxObjectAllocatorAndCreator_Dummy constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = { NULL }; \
    const int klass::ms_constructorPropertiesCount = 0;

// direct constructor version

template<typename Class>
struct wxDirectConstructorBridge_0 : public wxObjectAllocator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        o = new Class( );
        return o != NULL;
    }
};

#define wxDIRECT_CONSTRUCTOR_0(klass) \
    wxDirectConstructorBridge_0<klass> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = { NULL }; \
    const int klass::ms_constructorPropertiesCount = 0;


// 1 param

template<typename Class, typename T0>
struct wxObjectAllocatorAndCreator_1 : public wxObjectAllocatorAndCreator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        Class *obj = wx_dynamic_cast(Class*, o);
        return obj->Create(
            args[0].wxTEMPLATED_MEMBER_CALL(Get, T0)
            );
    }
};

#define wxCONSTRUCTOR_1(klass,t0,v0) \
    wxObjectAllocatorAndCreator_1<klass,t0> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = { wxT(#v0) }; \
    const int klass::ms_constructorPropertiesCount = 1;

// direct constructor version

template<typename Class, typename T0>
struct wxDirectConstructorBridge_1 : public wxObjectAllocator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        o = new Class(
            args[0].wxTEMPLATED_MEMBER_CALL(Get, T0)
            );
        return o != NULL;
    }
};

#define wxDIRECT_CONSTRUCTOR_1(klass,t0,v0) \
    wxDirectConstructorBridge_1<klass,t0,t1> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = { wxT(#v0) }; \
    const int klass::ms_constructorPropertiesCount = 1;


// 2 params

template<typename Class,
typename T0, typename T1>
struct wxObjectAllocatorAndCreator_2 : public wxObjectAllocatorAndCreator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        Class *obj = wx_dynamic_cast(Class*, o);
        return obj->Create(
            args[0].wxTEMPLATED_MEMBER_CALL(Get, T0),
            args[1].wxTEMPLATED_MEMBER_CALL(Get, T1)
            );
    }
};

#define wxCONSTRUCTOR_2(klass,t0,v0,t1,v1) \
    wxObjectAllocatorAndCreator_2<klass,t0,t1> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = { wxT(#v0), wxT(#v1)  }; \
    const int klass::ms_constructorPropertiesCount = 2;

// direct constructor version

template<typename Class,
typename T0, typename T1>
struct wxDirectConstructorBridge_2 : public wxObjectAllocator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        o = new Class(
            args[0].wxTEMPLATED_MEMBER_CALL(Get, T0),
            args[1].wxTEMPLATED_MEMBER_CALL(Get, T1)
            );
        return o != NULL;
    }
};

#define wxDIRECT_CONSTRUCTOR_2(klass,t0,v0,t1,v1) \
    wxDirectConstructorBridge_2<klass,t0,t1> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = { wxT(#v0), wxT(#v1)  }; \
    const int klass::ms_constructorPropertiesCount = 2;


// 3 params

template<typename Class,
typename T0, typename T1, typename T2>
struct wxObjectAllocatorAndCreator_3 : public wxObjectAllocatorAndCreator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        Class *obj = wx_dynamic_cast(Class*, o);
        return obj->Create(
            args[0].wxTEMPLATED_MEMBER_CALL(Get, T0),
            args[1].wxTEMPLATED_MEMBER_CALL(Get, T1),
            args[2].wxTEMPLATED_MEMBER_CALL(Get, T2)
            );
    }
};

#define wxCONSTRUCTOR_3(klass,t0,v0,t1,v1,t2,v2) \
    wxObjectAllocatorAndCreator_3<klass,t0,t1,t2> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = { wxT(#v0), wxT(#v1), wxT(#v2)  }; \
    const int klass::ms_constructorPropertiesCount = 3;

// direct constructor version

template<typename Class,
typename T0, typename T1, typename T2>
struct wxDirectConstructorBridge_3 : public wxObjectAllocator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        o = new Class(
            args[0].wxTEMPLATED_MEMBER_CALL(Get, T0),
            args[1].wxTEMPLATED_MEMBER_CALL(Get, T1),
            args[2].wxTEMPLATED_MEMBER_CALL(Get, T2)
            );
        return o != NULL;
    }
};

#define wxDIRECT_CONSTRUCTOR_3(klass,t0,v0,t1,v1,t2,v2) \
    wxDirectConstructorBridge_3<klass,t0,t1,t2> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = { wxT(#v0), wxT(#v1), wxT(#v2) }; \
    const int klass::ms_constructorPropertiesCount = 3;


// 4 params

template<typename Class,
typename T0, typename T1, typename T2, typename T3>
struct wxObjectAllocatorAndCreator_4 : public wxObjectAllocatorAndCreator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        Class *obj = wx_dynamic_cast(Class*, o);
        return obj->Create(
            args[0].wxTEMPLATED_MEMBER_CALL(Get, T0),
            args[1].wxTEMPLATED_MEMBER_CALL(Get, T1),
            args[2].wxTEMPLATED_MEMBER_CALL(Get, T2),
            args[3].wxTEMPLATED_MEMBER_CALL(Get, T3)
            );
    }
};

#define wxCONSTRUCTOR_4(klass,t0,v0,t1,v1,t2,v2,t3,v3) \
    wxObjectAllocatorAndCreator_4<klass,t0,t1,t2,t3> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = \
        { wxT(#v0), wxT(#v1), wxT(#v2), wxT(#v3)  }; \
    const int klass::ms_constructorPropertiesCount = 4;

// direct constructor version

template<typename Class,
typename T0, typename T1, typename T2, typename T3>
struct wxDirectConstructorBridge_4 : public wxObjectAllocator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        o = new Class(
            args[0].wxTEMPLATED_MEMBER_CALL(Get, T0),
            args[1].wxTEMPLATED_MEMBER_CALL(Get, T1),
            args[2].wxTEMPLATED_MEMBER_CALL(Get, T2),
            args[3].wxTEMPLATED_MEMBER_CALL(Get, T3)
            );
        return o != NULL;
    }
};

#define wxDIRECT_CONSTRUCTOR_4(klass,t0,v0,t1,v1,t2,v2,t3,v3) \
    wxDirectConstructorBridge_4<klass,t0,t1,t2,t3> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = \
        { wxT(#v0), wxT(#v1), wxT(#v2), wxT(#v3)  }; \
    const int klass::ms_constructorPropertiesCount = 4;


// 5 params

template<typename Class,
typename T0, typename T1, typename T2, typename T3, typename T4>
struct wxObjectAllocatorAndCreator_5 : public wxObjectAllocatorAndCreator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        Class *obj = wx_dynamic_cast(Class*, o);
        return obj->Create(
            args[0].wxTEMPLATED_MEMBER_CALL(Get, T0),
            args[1].wxTEMPLATED_MEMBER_CALL(Get, T1),
            args[2].wxTEMPLATED_MEMBER_CALL(Get, T2),
            args[3].wxTEMPLATED_MEMBER_CALL(Get, T3),
            args[4].wxTEMPLATED_MEMBER_CALL(Get, T4)
            );
    }
};

#define wxCONSTRUCTOR_5(klass,t0,v0,t1,v1,t2,v2,t3,v3,t4,v4) \
    wxObjectAllocatorAndCreator_5<klass,t0,t1,t2,t3,t4> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = \
        { wxT(#v0), wxT(#v1), wxT(#v2), wxT(#v3), wxT(#v4)  }; \
    const int klass::ms_constructorPropertiesCount = 5;

// direct constructor version

template<typename Class,
typename T0, typename T1, typename T2, typename T3, typename T4>
struct wxDirectConstructorBridge_5 : public wxObjectAllocator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        o = new Class(
            args[0].wxTEMPLATED_MEMBER_CALL(Get, T0),
            args[1].wxTEMPLATED_MEMBER_CALL(Get, T1),
            args[2].wxTEMPLATED_MEMBER_CALL(Get, T2),
            args[3].wxTEMPLATED_MEMBER_CALL(Get, T3),
            args[4].wxTEMPLATED_MEMBER_CALL(Get, T4)
            );
        return o != NULL;
    }
};

#define wxDIRECT_CONSTRUCTOR_5(klass,t0,v0,t1,v1,t2,v2,t3,v3,t4,v4) \
    wxDirectConstructorBridge_5<klass,t0,t1,t2,t3,t4> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = \
        { wxT(#v0), wxT(#v1), wxT(#v2), wxT(#v3), wxT(#v4) }; \
    const int klass::ms_constructorPropertiesCount = 5;


// 6 params

template<typename Class,
typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
struct wxObjectAllocatorAndCreator_6 : public wxObjectAllocatorAndCreator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        Class *obj = wx_dynamic_cast(Class*, o);
        return obj->Create(
            args[0].wxTEMPLATED_MEMBER_CALL(Get, T0),
            args[1].wxTEMPLATED_MEMBER_CALL(Get, T1),
            args[2].wxTEMPLATED_MEMBER_CALL(Get, T2),
            args[3].wxTEMPLATED_MEMBER_CALL(Get, T3),
            args[4].wxTEMPLATED_MEMBER_CALL(Get, T4),
            args[5].wxTEMPLATED_MEMBER_CALL(Get, T5)
            );
    }
};

#define wxCONSTRUCTOR_6(klass,t0,v0,t1,v1,t2,v2,t3,v3,t4,v4,t5,v5) \
    wxObjectAllocatorAndCreator_6<klass,t0,t1,t2,t3,t4,t5> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = \
        { wxT(#v0), wxT(#v1), wxT(#v2), wxT(#v3), wxT(#v4), wxT(#v5)  }; \
    const int klass::ms_constructorPropertiesCount = 6;

// direct constructor version

template<typename Class,
typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
struct wxDirectConstructorBridge_6 : public wxObjectAllocator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        o = new Class(
            args[0].wxTEMPLATED_MEMBER_CALL(Get, T0),
            args[1].wxTEMPLATED_MEMBER_CALL(Get, T1),
            args[2].wxTEMPLATED_MEMBER_CALL(Get, T2),
            args[3].wxTEMPLATED_MEMBER_CALL(Get, T3),
            args[4].wxTEMPLATED_MEMBER_CALL(Get, T4),
            args[5].wxTEMPLATED_MEMBER_CALL(Get, T5)
            );
        return o != NULL;
    }
};

#define wxDIRECT_CONSTRUCTOR_6(klass,t0,v0,t1,v1,t2,v2,t3,v3,t4,v4,t5,v5) \
    wxDirectConstructorBridge_6<klass,t0,t1,t2,t3,t4,t5> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = { wxT(#v0), wxT(#v1), \
        wxT(#v2), wxT(#v3), wxT(#v4), wxT(#v5)  }; \
    const int klass::ms_constructorPropertiesCount = 6;


// 7 params

template<typename Class,
typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
struct wxObjectAllocatorAndCreator_7 : public wxObjectAllocatorAndCreator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        Class *obj = wx_dynamic_cast(Class*, o);
        return obj->Create(
            args[0].wxTEMPLATED_MEMBER_CALL(Get, T0),
            args[1].wxTEMPLATED_MEMBER_CALL(Get, T1),
            args[2].wxTEMPLATED_MEMBER_CALL(Get, T2),
            args[3].wxTEMPLATED_MEMBER_CALL(Get, T3),
            args[4].wxTEMPLATED_MEMBER_CALL(Get, T4),
            args[5].wxTEMPLATED_MEMBER_CALL(Get, T5),
            args[6].wxTEMPLATED_MEMBER_CALL(Get, T6)
            );
    }
};

#define wxCONSTRUCTOR_7(klass,t0,v0,t1,v1,t2,v2,t3,v3,t4,v4,t5,v5,t6,v6) \
    wxObjectAllocatorAndCreator_7<klass,t0,t1,t2,t3,t4,t5,t6> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = { wxT(#v0), wxT(#v1), \
        wxT(#v2), wxT(#v3), wxT(#v4), wxT(#v5), wxT(#v6) }; \
    const int klass::ms_constructorPropertiesCount = 7;

// direct constructor version

template<typename Class,
typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
struct wxDirectConstructorBridge_7 : public wxObjectAllocator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        o = new Class(
            args[0].wxTEMPLATED_MEMBER_CALL(Get, T0),
            args[1].wxTEMPLATED_MEMBER_CALL(Get, T1),
            args[2].wxTEMPLATED_MEMBER_CALL(Get, T2),
            args[3].wxTEMPLATED_MEMBER_CALL(Get, T3),
            args[4].wxTEMPLATED_MEMBER_CALL(Get, T4),
            args[3].wxTEMPLATED_MEMBER_CALL(Get, T5),
            args[4].wxTEMPLATED_MEMBER_CALL(Get, T6)
            );
        return o != NULL;
    }
};

#define wxDIRECT_CONSTRUCTOR_7(klass,t0,v0,t1,v1,t2,v2,t3,v3,t4,v4,t5,v5,t6,v6) \
    wxDirectConstructorBridge_7<klass,t0,t1,t2,t3,t4,t5,t6> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = \
        { wxT(#v0), wxT(#v1), wxT(#v2), wxT(#v3), wxT(#v4), wxT(#v5), wxT(#v6) }; \
    const int klass::ms_constructorPropertiesCount = 7;


// 8 params

template<typename Class,
typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, \
typename T6, typename T7>
struct wxObjectAllocatorAndCreator_8 : public wxObjectAllocatorAndCreator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        Class *obj = wx_dynamic_cast(Class*, o);
        return obj->Create(
            args[0].wxTEMPLATED_MEMBER_CALL(Get, T0),
            args[1].wxTEMPLATED_MEMBER_CALL(Get, T1),
            args[2].wxTEMPLATED_MEMBER_CALL(Get, T2),
            args[3].wxTEMPLATED_MEMBER_CALL(Get, T3),
            args[4].wxTEMPLATED_MEMBER_CALL(Get, T4),
            args[5].wxTEMPLATED_MEMBER_CALL(Get, T5),
            args[6].wxTEMPLATED_MEMBER_CALL(Get, T6),
            args[7].wxTEMPLATED_MEMBER_CALL(Get, T7)
            );
    }
};

#define wxCONSTRUCTOR_8(klass,t0,v0,t1,v1,t2,v2,t3,v3,t4,v4,t5,v5,t6,v6,t7,v7) \
    wxObjectAllocatorAndCreator_8<klass,t0,t1,t2,t3,t4,t5,t6,t7> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = \
        { wxT(#v0), wxT(#v1), wxT(#v2), wxT(#v3), wxT(#v4), wxT(#v5), wxT(#v6), wxT(#v7) }; \
    const int klass::ms_constructorPropertiesCount = 8;

// direct constructor version

template<typename Class,
typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, \
typename T6, typename T7>
struct wxDirectConstructorBridge_8 : public wxObjectAllocator
{
    bool Create(wxObject * &o, wxxVariant *args)
    {
        o = new Class(
            args[0].wxTEMPLATED_MEMBER_CALL(Get, T0),
            args[1].wxTEMPLATED_MEMBER_CALL(Get, T1),
            args[2].wxTEMPLATED_MEMBER_CALL(Get, T2),
            args[3].wxTEMPLATED_MEMBER_CALL(Get, T3),
            args[4].wxTEMPLATED_MEMBER_CALL(Get, T4),
            args[3].wxTEMPLATED_MEMBER_CALL(Get, T5),
            args[4].wxTEMPLATED_MEMBER_CALL(Get, T6),
            args[4].wxTEMPLATED_MEMBER_CALL(Get, T7)
            );
        return o != NULL;
    }
};

#define wxDIRECT_CONSTRUCTOR_8(klass,t0,v0,t1,v1,t2,v2,t3,v3,t4,v4,t5,v5,t6,v6,t7,v7) \
    wxDirectConstructorBridge_8<klass,t0,t1,t2,t3,t4,t5,t6,t7> constructor##klass; \
    wxObjectAllocatorAndCreator* klass::ms_constructor = &constructor##klass; \
    const wxChar *klass::ms_constructorProperties[] = \
        { wxT(#v0), wxT(#v1), wxT(#v2), wxT(#v3), wxT(#v4), wxT(#v5), wxT(#v6), wxT(#v7) }; \
    const int klass::ms_constructorPropertiesCount = 8;

#endif      // wxUSE_EXTENDED_RTTI
#endif      // _XTICTOR_H_
