
/* Module definition and import interface */

#ifndef Py_IMPORT_H
#define Py_IMPORT_H
#ifdef __cplusplus
extern "C" {
#endif

PyAPI_FUNC(long) PyImport_GetMagicNumber(void);
PyAPI_FUNC(PyObject *) PyImport_ExecCodeModule(char *name, PyObject *co);
PyAPI_FUNC(PyObject *) PyImport_ExecCodeModuleEx(
	char *name, PyObject *co, char *pathname);
PyAPI_FUNC(PyObject *) PyImport_GetModuleDict(void);
PyAPI_FUNC(PyObject *) PyImport_AddModule(char *name);
PyAPI_FUNC(PyObject *) PyImport_ImportModule(char *name);
PyAPI_FUNC(PyObject *) PyImport_ImportModuleEx(
	char *name, PyObject *globals, PyObject *locals, PyObject *fromlist);
PyAPI_FUNC(PyObject *) PyImport_Import(PyObject *name);
PyAPI_FUNC(PyObject *) PyImport_ReloadModule(PyObject *m);
PyAPI_FUNC(void) PyImport_Cleanup(void);
PyAPI_FUNC(int) PyImport_ImportFrozenModule(char *);

PyAPI_FUNC(struct filedescr *) _PyImport_FindModule(
	const char *, PyObject *, char *, size_t, FILE **, PyObject **);
PyAPI_FUNC(int) _PyImport_IsScript(struct filedescr *);
PyAPI_FUNC(void) _PyImport_ReInitLock(void);

PyAPI_FUNC(PyObject *)_PyImport_FindExtension(char *, char *);
PyAPI_FUNC(PyObject *)_PyImport_FixupExtension(char *, char *);

struct _inittab {
    char *name;
    void (*initfunc)(void);
};

#ifndef EFI_LOADABLE_MODULE
PyAPI_DATA(struct _inittab *) PyImport_Inittab;
#else
PyAPI_DATA(struct _inittab *) *pPyImport_Inittab;
#define PyImport_Inittab (*pPyImport_Inittab)
#endif

PyAPI_FUNC(int) PyImport_AppendInittab(char *name, void (*initfunc)(void));
PyAPI_FUNC(int) PyImport_ExtendInittab(struct _inittab *newtab);

struct _frozen {
    char *name;
    unsigned char *code;
    int size;
};

/* Embedding apps may change this pointer to point to their favorite
   collection of frozen modules: */

#ifndef EFI_LOADABLE_MODULE
PyAPI_DATA(struct _frozen *) PyImport_FrozenModules;
#else
PyAPI_DATA(struct _frozen *) *pPyImport_FrozenModules;
#define PyImport_FrozenModules (*pPyImport_FrozenModules)
#endif

#ifdef __cplusplus
}
#endif
#endif /* !Py_IMPORT_H */
